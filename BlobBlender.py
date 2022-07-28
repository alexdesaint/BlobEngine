import bpy
import idprop
import os
import numpy as np
from pathlib import Path

# blender -b file.blend -P libs/BlobEngine/BlobBlender.py


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

    def getHeader(self):
        return self.name

    def getCore(self, namespace):
        return self.name

    def getType(self):
        return self.name


float_t = NativeType("float")
int32_t = NativeType("int")
uint16_t = NativeType("uint16_t")
auto_t = NativeType("auto")
char_t = NativeType("char")
string_view_t = NativeType("std::string_view")

Attribute_t = NativeType("std::unique_ptr<Blob::VertexBuffer>")
VertexLayout_t = NativeType("Blob::VertexLayout")
RenderOptions_t = NativeType("std::unique_ptr<Blob::RenderOptions>")
Shape_t = NativeType("Blob::Shape")
Scene_t = NativeType("Blob::Scene")
Mesh_t = NativeType("Blob::Mesh")


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
        inline=False,
        constexpr=False,
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
        self.inline = inline
        self.constexpr = constexpr
        if constexpr:
            self.static = True
            self.inline = True

    def getHeader(self, indent=0):
        ret = getIndent(indent)
        if self.constexpr:
            ret += "constexpr "
        if self.static:
            if self.inline and not self.constexpr:
                ret += "inline "
            ret += "static "
        ret += self.preQualif
        ret += str(self.type.name)
        ret += " "
        ret += self.midQualif
        ret += self.name
        ret += self.postQualif

        if self.inline and self.init:
            ret += "{" + self.init + "}"
        ret += ";\n"
        return ret

    def getCore(self, namespace):
        ret = ""
        if not self.inline and self.init:
            ret += self.preQualif
            ret += self.type.getType()
            ret += " "
            ret += namespace
            ret += self.name
            ret += self.postQualif
            ret += "{"
            ret += self.init
            ret += "};\n"

        return ret


class Struct:
    def __init__(self, name, parents={}, namespace=[], content=[], localContent=[]):
        self.name = name
        self.parents = parents
        self.namespace = namespace
        self.content = content
        self.localContent = localContent

    def getType(self):
        if self.namespace:
            return "::".join(self.namespace) + "::" + self.name
        else:
            return self.name

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
        ret = ""
        if not namespace:
            namespace = ""

        ret += "".join([c.getHeader(0) for c in self.localContent])
        ret += "".join(
            [c.getCore(namespace + self.name + "::") for c in self.localContent]
        )
        ret += "".join([c.getCore(namespace + self.name + "::") for c in self.content])

        return ret


class Function:
    def __init__(
        self,
        name,
        ret=None,
        parameters=[],
        preQualif="",
        constructorInit=[],
        content=[],
        static=False,
        inline=False,
        constexpr=False,
    ):
        self.name = name
        self.ret = ret
        if preQualif != "":
            preQualif += " "
        self.preQualif = preQualif
        self.parameters = parameters
        self.constructorInit = constructorInit
        self.content = content
        self.static = static
        self.inline = inline
        self.constexpr = constexpr

    def getHeader(self, indent=0):
        ret = getIndent(indent)
        ret += self.preQualif
        if self.constexpr:
            ret += "constexpr "
        if self.static:
            ret += "static "
        if self.ret:
            ret += str(self.ret.name) + " "
        ret += self.name
        ret += "("
        if self.parameters:
            ret += ", ".join(self.parameters)
        ret += ")"
        if self.inline:
            if self.constructorInit:
                ret += ": " + ", ".join(self.constructorInit)
            if not self.content:
                ret += "{}\n"
            else:
                ret += getIndent(indent) + "{\n"
                ret += (
                    getIndent(indent + 1)
                    + ("\n" + getIndent(indent + 1)).join(self.content)
                    + "\n"
                )
                ret += getIndent(indent) + "}\n"
        else:
            ret += ";\n"
        return ret

    def getCore(self, namespace):
        ret = ""
        if not self.inline:
            if self.constexpr:
                ret += "constexpr "
            if self.ret:
                ret += str(self.ret.name) + " "
            ret += namespace + self.name
            ret += "("
            if self.parameters:
                ret += ", ".join(self.parameters)
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


def setGetNameProperties(name):
    return [
        Parameter(
            "name",
            string_view_t,
            '"' + name + '"',
            constexpr=True,
        )
    ]


def setGetStringProperties(items):
    ret = Function(
        "getStringProperties",
        NativeType("std::string_view"),
        ["std::string_view key"],
        "",
        [],
        [],
        True,
        True,
        True,
    )
    for key, value in items:
        if isinstance(value, str):
            ret.content.append('if (key == "' + key + '") return "' + value + '";')
    ret.content.append('return "";')
    return [ret]


def codeMesh(mesh: bpy.types.Mesh):
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
        else:
            print("ERROR NO UV")

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
        [],
        [Parameter("x", float_t), Parameter("y", float_t), Parameter("z", float_t)],
        [],
    )

    meshStruct = Struct(name, {}, [], [], [])

    meshStruct.content += setGetNameProperties(name)
    meshStruct.content += setGetStringProperties(mesh.items())

    meshGetter = Function("get", Mesh_t, ["Blob::Context &context"], "", [], [], True)

    meshGetter.content.append("Blob::VertexLayout vertexLayout;")
    meshGetter.content.append("vertexLayout.begin();")
    meshGetter.content.append("vertexLayout.add<float>(bgfx::Attrib::Position, 3);")

    if use_normals:
        dataType += [("nx", np.float32), ("ny", np.float32), ("nz", np.float32)]
        dataStruct.content += [
            Parameter("nx", float_t),
            Parameter("ny", float_t),
            Parameter("nz", float_t),
        ]
        meshGetter.content.append("vertexLayout.add<float>(bgfx::Attrib::Normal, 3);")
    if use_tangents:
        dataType += [
            ("tx", np.float32),
            ("ty", np.float32),
            ("tz", np.float32),
        ]
        dataStruct.content += [
            Parameter("tx", float_t),
            Parameter("ty", float_t),
            Parameter("tz", float_t),
        ]
        meshGetter.content.append("vertexLayout.add<float>(bgfx::Attrib::Tangent, 3);")
    for uv_i in range(tex_coord_max):
        dataType += [("uv%dx" % uv_i, np.float32), ("uv%dy" % uv_i, np.float32)]
        dataStruct.content += [
            Parameter("uv%dx" % uv_i, float_t),
            Parameter("uv%dy" % uv_i, float_t),
        ]
        meshGetter.content.append(
            "vertexLayout.add<float>(bgfx::Attrib::TexCoord0, 2);"
        )
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
        meshGetter.content.append("vertexLayout.add<float>(bgfx::Attrib::Color0, 4);")
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

    meshGetter.content.append("vertexLayout.end();")

    meshStruct.localContent.append(dataStruct)

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

    meshStruct.localContent.append(
        Parameter(
            "data",
            dataStruct,
            "\n" + print2dData(indiceData[list(indiceData.dtype.names)[1:]]),
            preQualif="const",
            postQualif="[" + str(len(indiceData)) + "]",
            static=False,
            inline=True,
        )
    )

    meshGetter.content.append(
        Attribute_t.getType()
        + " &"
        + name
        + "VertexBuffer"
        + ' = context.vertexBuffers["'
        + name
        + '"];'
    )
    meshGetter.content.append("if(!" + name + "VertexBuffer)")
    meshGetter.content.append(
        "    "
        + name
        + "VertexBuffer"
        + " = std::make_unique<Blob::VertexBuffer>(Blob::Buffer{data"
        + "}, vertexLayout);"
    )

    meshConstructor = "return " + Mesh_t.name + "{{\n"
    for matId, indices in indicePerMaterial.items():
        lenIndices = str(len(indices))
        try:
            primitiveName = nameFormat(mesh.materials[matId].name)
        except:
            print("No material")
            continue
        meshStruct.localContent.append(
            Parameter(
                "indices" + primitiveName,
                uint16_t,
                print1dData(indices),
                preQualif="const",
                postQualif="[" + lenIndices + "]",
                static=False,
                inline=True,
            )
        )
        roName = primitiveName + "Ro"
        meshGetter.content.append(
            RenderOptions_t.getType()
            + " &"
            + roName
            + ' = context.renderOptions["'
            + name
            + primitiveName
            + '"];'
        )
        meshGetter.content.append("if(!" + roName + ")")
        meshGetter.content.append(
            "    "
            + roName
            + " = std::make_unique<Blob::RenderOptions>(Blob::Buffer{indices"
            + primitiveName
            + "});"
        )

        meshConstructor += (
            "        {"
            + "\n            Blob::Materials::pbrSingleColor(context, Blob::Color{"
            + print1dData(mesh.materials[matId].diffuse_color)
            + "}),\n            "
            + name
            + "VertexBuffer.get(),\n            "
            + roName
            + ".get(),\n        },\n"
        )

    meshGetter.content.append(meshConstructor + "    }};")
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
    meshStruct.content.append(meshGetter)

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

meshSrcFolder = srcFolder + "Meshes/"
meshHeaderFolder = headerFolder + "Meshes/"
Path(meshSrcFolder).mkdir(parents=True, exist_ok=True)
Path(meshHeaderFolder).mkdir(parents=True, exist_ok=True)

shapeHeaderFolder = headerFolder + "Shapes/"
Path(shapeHeaderFolder).mkdir(parents=True, exist_ok=True)

sceneHeaderFolder = headerFolder + "Scenes/"
Path(sceneHeaderFolder).mkdir(parents=True, exist_ok=True)

cppFiles = []
existingFiles = set()
for file in Path(mainFolder).rglob("*"):
    if file.is_file():
        existingFiles.add(file)

meshes = []
for mesh in bpy.data.meshes:
    if "BlobEnabled" in mesh and not mesh["BlobEnabled"]:
        continue

    name = nameFormat(mesh.name)
    meshes.append(name)
    headerCode, coreCode = codeMesh(mesh)

    data = ""
    data += "#include <" + projectName + "/Meshes/" + name + ".hpp>\n"
    data += "#include <Blob/Materials.hpp>\n"
    data += "namespace " + projectName + "::Meshes {\n"
    data += coreCode
    data += "}\n"
    cppFiles.append("src/Meshes/" + name + ".cpp")
    updateIfDifferent(meshSrcFolder + name + ".cpp", data, existingFiles)

    data = ""
    data += "#pragma once\n"
    data += "#include <Blob/Mesh.hpp>\n"
    data += "#include <Blob/Context.hpp>\n"
    data += "namespace " + projectName + "::Meshes {\n"
    data += headerCode
    data += "}\n"
    updateIfDifferent(meshHeaderFolder + name + ".hpp", data, existingFiles)

data = ""
data += "#pragma once\n"
for name in meshes:
    data += "#include <" + projectName + "/Meshes/" + name + ".hpp>\n"
data += "namespace " + projectName + "::Meshes {\n"
data += """
struct BlenderProperties {
    std::string_view name;
    Blob::Mesh (*get)(Blob::Context &);

    constexpr BlenderProperties(std::string_view name,
                               Blob::Mesh (*get)(Blob::Context &)) :
        name(name), get(get) {}
};
"""
data += Function(
    "getAllMeshes",
    NativeType("std::array<BlenderProperties, " + str(len(meshes)) + ">"),
    [],
    "",
    [],
    ["return {"]
    + [
        "    BlenderProperties{" + name + "::name, &" + name + "::get},"
        for name in meshes
    ]
    + ["};"],
    False,
    True,
    True,
).getHeader()
data += "}\n"
updateIfDifferent(headerFolder + "Meshes.hpp", data, existingFiles)

for object in bpy.data.objects:
    args = []
    name = nameFormat(object.name)

    shapeStruct = Struct(name, {}, [], [], [])
    shapeStruct.content += setGetNameProperties(name)
    shapeStruct.content += setGetStringProperties(object.items())
    toInclude = []

    shapeGetter = Function(
        "get",
        Shape_t,
        ["Blob::Context &context"],
        "",
        [],
        [],
        True,
        True,
    )
    shapeGetter.content.append("return {")
    if type(object.data) == bpy.types.Mesh:
        typeName = nameFormat(object.data.name)
        attributeName = "mesh_" + typeName
        shapeGetter.content.append("    Meshes::" + typeName + "::get(context),")

    shapeGetter.content.append("    {")

    for child in object.children:
        typeName = nameFormat(child.name)
        toInclude.append("Shapes/" + typeName)
        shapeGetter.content.append("        Shapes::" + typeName + "::get(context),")
    if object.instance_collection:
        for child in object.instance_collection.objects:
            childName = nameFormat(child.name)
            childName = "shape_" + childName
            toInclude.append("Shapes/" + childName)
            shapeStruct.content.append(
                Parameter(childName, NativeType("Shapes::" + childName))
            )
            shapeGetter.content.append(
                "        Shapes::" + typeName + "::get(context),"
            )

    shapeGetter.content.append("    },")
    shapeGetter.content.append("    {")
    for vec in object.matrix_local:
        shapeGetter.content.append("        {" + ", ".join(map(str, vec)) + "},")
    shapeGetter.content.append("    },")
    shapeGetter.content.append("};")
    shapeStruct.content.append(shapeGetter)

    data = ""
    data += "#pragma once\n"
    data += "#include <Blob/Shape.hpp>\n"
    data += "#include <" + projectName + "/Meshes.hpp>\n"
    for include in toInclude:
        data += "#include <" + projectName + "/" + include + ".hpp>\n"
    data += "namespace " + projectName + "::Shapes {\n"
    data += shapeStruct.getHeader()
    data += "}\n"
    updateIfDifferent(shapeHeaderFolder + name + ".hpp", data, existingFiles)

for scene in bpy.data.scenes:
    sceneName = nameFormat(scene.name)
    for object in scene.objects:
        if object.parent != None:
            continue
        objectName = nameFormat(object.name)
        # constructor.content.append(sceneName + ".addShape(" + objectName + ");")

data = ""
data += "add_library(" + projectName + " STATIC " + "\n    ".join(cppFiles) + ")\n"
data += "target_link_libraries(" + projectName + " Blob)\n"
data += "target_include_directories(" + projectName + " PUBLIC include/)"
updateIfDifferent(mainFolder + "CMakeLists.txt", data, existingFiles)

for file in existingFiles:
    print("Removing: ", file)
    os.remove(file)
