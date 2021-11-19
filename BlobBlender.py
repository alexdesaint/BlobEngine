import bpy
import idprop
import os
import math
import numpy as np
from pathlib import Path
import shutil


def print3dData(data):
    return (
        "{"
        + ",\n ".join(
            [
                "{"
                + ", ".join(["{" + ", ".join(map(str, d2)) + "}" for d2 in d1])
                + "}"
                for d1 in data
            ]
        )
        + "}"
    )


def print2dData(data):
    return ",\n".join(["{" + ", ".join(map(str, d)) + "}" for d in data]) + "\n"


def print1dData(data):
    return ", ".join(map(str, data))


def nameFormat(name):
    ret = (
        name.replace(".", "_")
        .replace(" ", "_")
        .replace("(", "_")
        .replace(")", "_")
        .replace("-", "_")
    )
    if ret[0].isdigit():
        ret = "_" + ret
    return ret


class NativeType:
    def __init__(self, name):
        self.name = name

    def getInlineHeader(self):
        return self.name

    def getHeader(self):
        return self.name

    def getCore(self, namespace):
        return self.name

    def getType(self):
        return self.name


float_t = NativeType("float")
int32_t = NativeType("int")
uint16_t = NativeType("uint16_t")
string_t = NativeType("std::string")

Buffer_t = NativeType("Blob::Buffer")
Attribute_t = NativeType("Blob::GL::VertexArrayObject")
RenderOptions_t = NativeType("Blob::RenderOptions")
Shape_t = NativeType("Blob::Shape")
Scene_t = NativeType("Blob::Scene")
Primitive_t = NativeType("Blob::Primitive")


def getIndent(size):
    ret = ""
    for i in range(size):
        ret += "    "
    return ret


class Parameter:
    def __init__(
        self,
        name,
        type,
        init=None,
        preQualif="",
        midQualif="",
        postQualif="",
        static=False,
    ):
        self.name = name
        self.type = type
        self.init = init
        if preQualif != "":
            preQualif += " "
        if midQualif != "":
            midQualif += " "
        self.preQualif = preQualif
        self.midQualif = midQualif
        self.postQualif = postQualif
        self.static = static

    def getInlineHeader(self, indent=0):
        ret = getIndent(indent)
        if self.static:
            ret += "inline static "
        ret += self.preQualif
        ret += str(self.type.name)
        ret += " "
        ret += self.midQualif
        ret += self.name
        ret += self.postQualif
        if self.init:
            ret += "{"
            ret += self.init
            ret += "};\n"

        if not self.static and self.init:
            ret += "{" + self.init + "}"
        ret += ";\n"
        return ret

    def getHeader(self, indent=0):
        ret = getIndent(indent)
        if self.static:
            ret += "static "
        ret += (
            self.preQualif
            + str(self.type.name)
            + " "
            + self.midQualif
            + self.name
            + self.postQualif
        )
        if not self.static and self.init:
            ret += "{" + self.init + "}"
        ret += ";\n"
        return ret

    def getCore(self, namespace):
        ret = ""
        if self.static and self.init:
            ret += (
                self.preQualif
                + self.type.getType()
                + " "
                + namespace
                + self.name
                + self.postQualif
                + "{"
                + self.init
                + "};\n"
            )
        return ret


class Struct:
    def __init__(self, name, parents={}, content=[], namespace=[]):
        self.name = name
        self.parents = parents
        self.content = content
        self.namespace = namespace

    def getType(self):
        if self.namespace:
            return "::".join(self.namespace) + "::" + self.name
        else:
            return self.name

    def getInlineHeader(self, indent=0):
        ret = getIndent(indent) + "struct " + self.name

        if self.parents:
            ret += " : "
        ret += ", ".join(
            [str(access) + " " + str(parent) for parent, access in self.parents.items()]
        )
        ret += " {\n"
        ret += "".join([c.getInlineHeader(indent + 1) for c in self.content])
        ret += getIndent(indent) + "};\n"
        return ret

    def getHeader(self, indent=0):
        ret = getIndent(indent) + "struct " + self.name

        if self.parents:
            ret += " : "
        ret += ", ".join(
            [str(access) + " " + str(parent) for parent, access in self.parents.items()]
        )
        ret += " {\n"
        ret += "".join([c.getHeader(indent + 1) for c in self.content])
        ret += getIndent(indent) + "};\n"
        return ret

    def getCore(self, namespace=None):
        if namespace:
            return "".join(
                [c.getCore(namespace + self.name + "::") for c in self.content]
            )
        else:
            return "".join([c.getCore(self.name + "::") for c in self.content])


class Function:
    def __init__(self, name, ret=None, parameters=[], constructorInit=[], content=[]):
        self.name = name
        self.ret = ret
        self.parameters = parameters
        self.constructorInit = constructorInit
        self.content = content

    def getInlineHeader(self, indent=0):
        ret = getIndent(indent)
        if self.ret:
            ret += str(self.ret) + " "
        ret += self.name
        ret += "("
        if self.parameters:
            ", ".join(self.parameters)
        ret += ") "
        if self.constructorInit:
            ret += ": " + ", ".join(self.constructorInit)
        if not self.content:
            ret += "{}\n"
        else:
            ret += "{\n"
            ret += "    " + "\n    ".join(self.content) + "\n"
            ret += "}\n"
        return ret

    def getHeader(self, indent=0):
        ret = getIndent(indent)
        if self.ret:
            ret += str(self.ret) + " "
        ret += self.name
        ret += "("
        if self.parameters:
            ", ".join(self.parameters)
        ret += ");\n"
        return ret

    def getCore(self, namespace):
        ret = ""
        if self.ret:
            ret += str(self.ret) + " "
        ret = namespace + self.name
        ret += "("
        if self.parameters:
            ", ".join(self.parameters)
        ret += ") "
        if self.constructorInit:
            ret += ": " + ", ".join(self.constructorInit)
        if not self.content:
            ret += "{}\n"
        else:
            ret += "{\n"
            ret += "    " + "\n    ".join(self.content) + "\n"
            ret += "}\n"
        return ret


def codeMesh(mesh):
    mesh.calc_loop_triangles()
    dataSize = len(mesh.loop_triangles) * 3
    name = nameFormat(mesh.name)

    use_normals = True
    if use_normals:
        mesh.calc_normals()
        mesh.create_normals_split()
        mesh.calc_normals_split()

    use_tangents = False
    if use_normals and use_tangents:
        if mesh.uv_layers.active and len(mesh.uv_layers) > 0:
            try:
                mesh.calc_tangents()
                use_tangents = True
            except Exception:
                print(
                    "WARNING",
                    "Could not calculate tangents. Please try to triangulate the mesh first.",
                )

    tex_coord_max = 0
    if mesh.uv_layers.active:
        tex_coord_max = len(mesh.uv_layers)

    color_max = 0
    color_max = len(mesh.vertex_colors)

    use_morph_normals = False

    dataType = [
        ("material", np.int64),
        ("x", np.float32),
        ("y", np.float32),
        ("z", np.float32),
    ]
    dataStruct = Struct(
        "Data",
        {},
        [Parameter("x", float_t), Parameter("y", float_t), Parameter("z", float_t)],
        [],
    )
    if use_normals:
        dataType += [("nx", np.float32), ("ny", np.float32), ("nz", np.float32)]
        dataStruct.content += [
            Parameter("nx", float_t),
            Parameter("ny", float_t),
            Parameter("nz", float_t),
        ]
    if use_tangents:
        dataType += [
            ("tx", np.float32),
            ("ty", np.float32),
            ("tz", np.float32),
            ("tw", np.float32),
        ]
        dataStruct.content += [
            Parameter("tx", float_t),
            Parameter("ty", float_t),
            Parameter("tz", float_t),
        ]
    for uv_i in range(tex_coord_max):
        dataType += [("uv%dx" % uv_i, np.float32), ("uv%dy" % uv_i, np.float32)]
        dataStruct.content += [
            Parameter("uv%dx" % uv_i, float_t),
            Parameter("uv%dy" % uv_i, float_t),
        ]
    for col_i in range(color_max):
        dataType += [
            ("color%dr" % col_i, np.float32),
            ("color%dg" % col_i, np.float32),
            ("color%db" % col_i, np.float32),
            ("color%da" % col_i, np.float32),
        ]
        dataStruct.content += [
            Parameter("color%dr" % col_i, float_t),
            Parameter("colog%dr" % col_i, float_t),
            Parameter("colob%dr" % col_i, float_t),
            Parameter("coloa%dr" % col_i, float_t),
        ]
    if use_morph_normals:
        for morph_i, _ in enumerate(key_blocks):
            dataType += [
                ("morph%dnx" % morph_i, np.float32),
                ("morph%dny" % morph_i, np.float32),
                ("morph%dnz" % morph_i, np.float32),
            ]
            dataStruct.content += [
                Parameter("morph%dnx" % col_i, float_t),
                Parameter("morph%dny" % col_i, float_t),
                Parameter("morph%dnz" % col_i, float_t),
            ]

    attributes = Struct(
        "Attributes", content=[], parents={"Blob::Asset<Attributes>": "public"}
    )
    dataStruct.namespace.append(name)
    dataStruct.namespace.append("Attributes")
    attributes.content.append(dataStruct)

    data = np.empty(dataSize, dtype=np.dtype(dataType))
    materialIndices = {}
    cursor = 0
    for loop_triangle in mesh.loop_triangles:
        materialIndices[loop_triangle.material_index] = loop_triangle.material_index
        for loop_index in loop_triangle.loops:
            data[cursor]["material"] = loop_triangle.material_index
            data[cursor]["x"] = mesh.vertices[mesh.loops[loop_index].vertex_index].co[0]
            data[cursor]["y"] = mesh.vertices[mesh.loops[loop_index].vertex_index].co[1]
            data[cursor]["z"] = mesh.vertices[mesh.loops[loop_index].vertex_index].co[2]
            if use_normals:
                data[cursor]["nx"] = mesh.loops[loop_index].normal[0]
                data[cursor]["ny"] = mesh.loops[loop_index].normal[1]
                data[cursor]["nz"] = mesh.loops[loop_index].normal[2]
            if use_tangents:
                data[cursor]["tx"] = mesh.loops[loop_index].tangent[0]
                data[cursor]["ty"] = mesh.loops[loop_index].tangent[1]
                data[cursor]["tz"] = mesh.loops[loop_index].tangent[2]
            for uv_i in range(tex_coord_max):
                data[cursor]["uv%dx" % uv_i] = (
                    mesh.uv_layers[uv_i].data[loop_index].uv[0]
                )
                data[cursor]["uv%dy" % uv_i] = (
                    mesh.uv_layers[uv_i].data[loop_index].uv[1]
                )
            for col_i in range(color_max):
                data[cursor]["color%dr" % col_i] = (
                    mesh.vertex_colors[col_i].data[loop_index].color[0]
                )
                data[cursor]["color%dg" % col_i] = (
                    mesh.vertex_colors[col_i].data[loop_index].color[1]
                )
                data[cursor]["color%db" % col_i] = (
                    mesh.vertex_colors[col_i].data[loop_index].color[2]
                )
                data[cursor]["color%da" % col_i] = (
                    mesh.vertex_colors[col_i].data[loop_index].color[3]
                )
            cursor += 1

    indiceData, indice = np.unique(data, return_inverse=True, axis=0)

    indicePerMaterial = {}
    for matId in materialIndices:
        indicePerMaterial[matId] = indice[indiceData[indice]["material"] == matId]

    attributes.content.append(
        Parameter(
            "data",
            dataStruct,
            "\n" + print2dData(indiceData[list(indiceData.dtype.names)[1:]]),
            preQualif="const",
            postQualif="[" + str(dataSize) + "]",
            static=True,
        )
    )

    for matId, indices in indicePerMaterial.items():
        lenIndices = str(len(indices))
        idStr = str(matId)
        attributes.content.append(
            Parameter(
                "indices" + idStr,
                uint16_t,
                print1dData(indices),
                preQualif="const",
                postQualif="[" + lenIndices + "]",
                static=True,
            )
        )
        attributes.content.append(
            Parameter(
                "renderOptions" + str(matId),
                RenderOptions_t,
                "indices" + idStr + ", " + lenIndices,
            )
        )

    attributes.content.append(
        Parameter("buffer", Buffer_t, init="(const uint8_t *) data, sizeof(data)")
    )
    attributes.content.append(Parameter("attribute", Attribute_t))
    constructorCode = [
        "attribute.setBuffer(buffer, sizeof(data[0]));",
        "attribute.setArray<float>(3, Blob::AttributeLocation::POSITION, offsetof(Data, x));",
        "attribute.setArray<float>(3, Blob::AttributeLocation::NORMAL, offsetof(Data, nx));",
    ]
    if color_max:
        constructorCode.append(
            "attribute.setArray<float>(4, Blob::AttributeLocation::COLOR_0, offsetof(Data, color0r));"
        )

    attributes.content.append(Function("Attributes", content=constructorCode))

    meshStruct = Struct(
        name,
        {"Blob::Mesh": "public"},
        [
            attributes,
            Parameter(
                "attributes",
                NativeType("Attributes::Intance"),
                "Attributes::getInstance()",
            ),
        ],
    )

    albedo = False
    for keyName, prop in mesh.items():
        propType = float_t
        if type(prop) == idprop.types.IDPropertyArray:
            if keyName == "albedo":
                albedo = True
            meshStruct.content.append(
                Parameter(
                    keyName,
                    propType,
                    print1dData(prop.to_list()),
                    postQualif="[" + str(len(prop.to_list())) + "]",
                )
            )
        if type(prop) == idprop.types.IDPropertyGroup:
            continue

    for material in mesh.materials:
        matName = nameFormat(material.name)
        meshStruct.content.append(
            Parameter(matName, NativeType("Materials::" + matName))
        )

    meshConstructor = Function(name, None, [], [], [])

    for matId, indices in indicePerMaterial.items():
        primitiveName = "primitive" + str(matId)
        meshStruct.content.append(Parameter(primitiveName, Primitive_t))
        meshConstructor.content.append(
            primitiveName
            + ".material = &"
            + nameFormat(mesh.materials[matId].name)
            + ";"
        )
        meshConstructor.content.append(
            primitiveName
            + ".renderOptions = &attributes->renderOptions"
            + str(matId)
            + ";"
        )
        meshConstructor.content.append(
            primitiveName + ".vertexArrayObject = &attributes->attribute;"
        )
        meshConstructor.content.append("addPrimitive(" + primitiveName + ");")

    meshStruct.content.append(meshConstructor)

    return meshStruct.getHeader(), meshStruct.getCore()


def updateIfDifferent(filename, data, allFiles):
    allFiles.discard(Path(filename))
    if os.path.isfile(filename):
        with open(filename, "r") as f:
            if data == f.read():
                return
    print("Updating ", filename)
    with open(filename, "w") as f:
        f.write(data)


projectName = bpy.path.display_name_from_filepath(bpy.data.filepath)
projectName = nameFormat(projectName)
mainFolder = bpy.path.abspath("//") + projectName + "/"
headerFolder = mainFolder + "include/" + projectName + "/"
srcFolder = mainFolder + "src/"

meshHeaderFolder = headerFolder + "Meshes/"
meshSrcFolder = srcFolder + "Meshes/"
Path(meshHeaderFolder).mkdir(parents=True, exist_ok=True)
Path(meshSrcFolder).mkdir(parents=True, exist_ok=True)

materialHeaderFolder = headerFolder + "Materials/"
Path(materialHeaderFolder).mkdir(parents=True, exist_ok=True)

shapeHeaderFolder = headerFolder + "Shapes/"
Path(shapeHeaderFolder).mkdir(parents=True, exist_ok=True)

sceneHeaderFolder = headerFolder + "Scenes/"
Path(sceneHeaderFolder).mkdir(parents=True, exist_ok=True)

cppFiles = []
existingsFiles = set()
for file in Path(mainFolder).rglob("*"):
    if file.is_file():
        existingsFiles.add(file)

materialsStruct = []
for material in bpy.data.materials:
    name = nameFormat(material.name)
    constructor = Function(
        name,
        None,
        [],
        [
            "Blob::Materials::PBRSingleColor(Blob::Color::RGBA{"
            + print1dData(material.diffuse_color)
            + "})"
        ],
        [],
    )
    materialsStruct = Struct(
        name,
        content=[constructor],
        parents={"Blob::Materials::PBRSingleColor": "public"},
    )

    data = ""
    data += "#pragma once\n"
    data += "#include <Blob/Materials.hpp>\n"
    data += "namespace " + projectName + "::Materials {\n"
    data += materialsStruct.getInlineHeader()
    data += "}\n"
    updateIfDifferent(materialHeaderFolder + name + ".hpp", data, existingsFiles)

for mesh in bpy.data.meshes:
    name = nameFormat(mesh.name)
    headerCode, coreCode = codeMesh(mesh)

    data = ""
    data += "#pragma once\n"
    data += "#include <Blob/Core/AttributeLocation.hpp>\n"
    data += "#include <Blob/Core/Mesh.hpp>\n"
    data += "#include <Blob/Core/Buffer.hpp>\n"
    for material in mesh.materials:
        matName = nameFormat(material.name)
        data += "#include <" + projectName + "/Materials/" + matName + ".hpp>\n"
    data += "namespace " + projectName + "::Meshes {\n"
    data += headerCode
    data += "}\n"
    updateIfDifferent(meshHeaderFolder + name + ".hpp", data, existingsFiles)

    data = ""
    data += "#include <" + projectName + "/Meshes/" + name + ".hpp>\n"
    data += "namespace " + projectName + "::Meshes {\n"
    data += coreCode
    data += "}\n"
    cppFiles.append("src/Meshes/" + name + ".cpp")
    updateIfDifferent(meshSrcFolder + name + ".cpp", data, existingsFiles)

for object in bpy.data.objects:
    args = []
    name = nameFormat(object.name)

    shapeStruct = Struct(name, {"Blob::Shape": "public"}, [], [])
    toInclude = []

    shapeInit = "Blob::Shape("
    if type(object.data) == bpy.types.Mesh:
        typeName = nameFormat(object.data.name)
        attributeName = "mesh_" + typeName
        toInclude.append("Meshes/" + typeName)
        shapeInit += attributeName + ", "
        shapeStruct.content.append(
            Parameter(attributeName, NativeType("Meshes::" + typeName))
        )
    shapeInit += (
        "Blob::ModelTransform{"
        + ", ".join(
            ["{" + ", ".join(map(str, vec)) + "}" for vec in object.matrix_local]
        )
        + "}"
    )
    shapeInit += ")"
    constructor = Function(name, None, [], [shapeInit], [])
    shapeStruct.content.append(constructor)

    for child in object.children:
        typeName = nameFormat(child.name)
        attributeName = "shape_" + typeName
        toInclude.append("Shapes/" + typeName)
        shapeStruct.content.append(
            Parameter(attributeName, NativeType("Shapes::" + typeName))
        )
        constructor.content.append("addChild(" + attributeName + ");")
    if object.instance_collection:
        for child in object.instance_collection.objects:
            childName = nameFormat(child.name)
            childName = "shape_" + childName
            toInclude.append("Shapes/" + childName)
            shapeStruct.content.append(
                Parameter(childName, NativeType("Shapes::" + childName))
            )
            constructor.content.append("addChild(" + childName + ");")

    data = ""
    data += "#pragma once\n"
    data += "#include <Blob/Core/Shape.hpp>\n"
    for include in toInclude:
        data += "#include <" + projectName + "/" + include + ".hpp>\n"
    data += "namespace " + projectName + "::Shapes {\n"
    data += shapeStruct.getInlineHeader()
    data += "}\n"
    updateIfDifferent(shapeHeaderFolder + name + ".hpp", data, existingsFiles)

for scene in bpy.data.scenes:
    sceneName = nameFormat(scene.name)
    for object in scene.objects:
        if object.parent != None:
            continue
        objectName = nameFormat(object.name)
        constructor.content.append(sceneName + ".addShape(" + objectName + ");")

data = ""
data += "add_library(" + projectName + " STATIC " + "\n    ".join(cppFiles) + ")\n"
data += "target_link_libraries(" + projectName + " Blob)\n"
data += "target_include_directories(" + projectName + " PUBLIC include/)"
updateIfDifferent(mainFolder + "CMakeLists.txt", data, existingsFiles)

for file in existingsFiles:
    print("Removing: ", file)
    os.remove(file)
