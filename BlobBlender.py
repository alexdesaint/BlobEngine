import bpy
import idprop
import os
import math
import numpy as np
from pathlib import Path
import shutil


def print3dData(data):
    return '{' + ",\n ".join(['{' + ", ".join(['{' + ", ".join(map(str, d2)) + '}' for d2 in d1]) + '}' for d1 in data]) + '}'


def print2dData(data):
    return ",\n".join(['{' + ", ".join(map(str, d)) + '}' for d in data]) + '\n'


def print2dDataNot0(data):
    return ",\n".join(['{' + ", ".join(map(str, d[d != 'material'])) + '}' for d in data]) + '\n'


def print1dData(data):
    return ", ".join(map(str, data))


def nameFormat(name):
    return name.replace('.', '_').replace(' ', '_')


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
    def __init__(self, name, type, init=None, preQualif="", midQualif="", postQualif="", static=False):
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

    def getHeader(self, indent=0):
        ret = getIndent(indent)
        if self.static:
            ret += "static "
        ret += self.preQualif + \
            str(self.type.name) + " " + self.midQualif + \
            self.name + self.postQualif
        if not self.static and self.init:
            ret += '{' + self.init + '}'
        ret += ";\n"
        return ret

    def getCore(self, namespace):
        ret = ""
        if self.static and self.init:
            ret += self.preQualif + self.type.getType() + " " + namespace + self.name + \
                self.postQualif + '{' + self.init + '};\n'
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

    def getHeader(self, indent=0):
        ret = getIndent(indent) + "struct " + self.name

        if self.parents:
            ret += " : "
        ret += ", ".join([str(access) + " " + str(parent)
                         for parent, access in self.parents.items()])
        ret += " {\n"
        ret += "".join([c.getHeader(indent + 1) for c in self.content])
        ret += getIndent(indent) + "};\n"
        return ret

    def getCore(self, namespace=None):
        if namespace:
            return "".join([c.getCore(namespace + self.name + "::") for c in self.content])
        else:
            return "".join([c.getCore(self.name + "::") for c in self.content])


class Function:
    def __init__(self, name, ret=None, parameters=[], constructorInit=[], content=[]):
        self.name = name
        self.ret = ret
        self.parameters = parameters
        self.constructorInit = constructorInit
        self.content = content

    def getHeader(self, indent=0):
        ret = getIndent(indent)
        if self.ret:
            ret += str(self.ret) + " "
        ret += self.name
        ret += "();\n"
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
        ret += "{\n"
        ret += "    " + "\n    ".join(self.content) + '\n'
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
                    'WARNING', 'Could not calculate tangents. Please try to triangulate the mesh first.')

    tex_coord_max = 0
    if mesh.uv_layers.active:
        tex_coord_max = len(mesh.uv_layers)

    color_max = 0
    color_max = len(mesh.vertex_colors)

    use_morph_normals = False

    dataType = [('material', np.int64), ('x', np.float32),
                ('y', np.float32), ('z', np.float32)]
    dataStruct = Struct("Data", {}, [Parameter("x", float_t), Parameter(
        "y", float_t), Parameter("z", float_t)], [])
    if use_normals:
        dataType += [('nx', np.float32), ('ny', np.float32),
                     ('nz', np.float32)]
        dataStruct.content += [Parameter("nx", float_t),
                               Parameter("ny", float_t), Parameter("nz", float_t)]
    if use_tangents:
        dataType += [('tx', np.float32), ('ty', np.float32),
                     ('tz', np.float32), ('tw', np.float32)]
        dataStruct.content += [Parameter("tx", float_t),
                               Parameter("ty", float_t), Parameter("tz", float_t)]
    for uv_i in range(tex_coord_max):
        dataType += [('uv%dx' % uv_i, np.float32),
                     ('uv%dy' % uv_i, np.float32)]
        dataStruct.content += [Parameter('uv%dx' % uv_i,
                                         float_t), Parameter('uv%dy' % uv_i, float_t)]
    for col_i in range(color_max):
        dataType += [
            ('color%dr' % col_i, np.float32),
            ('color%dg' % col_i, np.float32),
            ('color%db' % col_i, np.float32),
            ('color%da' % col_i, np.float32),
        ]
        dataStruct.content += [
            Parameter('color%dr' % col_i, float_t),
            Parameter('colog%dr' % col_i, float_t),
            Parameter('colob%dr' % col_i, float_t),
            Parameter('coloa%dr' % col_i, float_t)
        ]
    if use_morph_normals:
        for morph_i, _ in enumerate(key_blocks):
            dataType += [
                ('morph%dnx' % morph_i, np.float32),
                ('morph%dny' % morph_i, np.float32),
                ('morph%dnz' % morph_i, np.float32),
            ]
            dataStruct.content += [
                Parameter('morph%dnx' % col_i, float_t),
                Parameter('morph%dny' % col_i, float_t),
                Parameter('morph%dnz' % col_i, float_t)
            ]

    attributes = Struct("Attributes", content=[], parents={
                        "Blob::Asset<Attributes>": "public"})
    dataStruct.namespace.append(name)
    dataStruct.namespace.append("Attributes")
    attributes.content.append(dataStruct)

    # ⋊> ~/D/kenney_citykitroads rm -r kenney_citykitroads/ ~/projects/JustOneMoreTime/assets/kenney_citykitroads && blender -b kenney_citykitroads.blend -P ~/projects/JustOneMoreTime/libs/BlobEngine/BlobBlender.py && cp -r kenney_citykitroads ~/projects/JustOneMoreTime/assets/

    data = np.empty(dataSize, dtype=np.dtype(dataType))
    materialIndices = {}
    cursor = 0
    for loop_triangle in mesh.loop_triangles:
        materialIndices[loop_triangle.material_index] = loop_triangle.material_index
        for loop_index in loop_triangle.loops:
            data[cursor]['material'] = loop_triangle.material_index
            data[cursor]['x'] = mesh.vertices[mesh.loops[loop_index].vertex_index].co[0]
            data[cursor]['y'] = mesh.vertices[mesh.loops[loop_index].vertex_index].co[1]
            data[cursor]['z'] = mesh.vertices[mesh.loops[loop_index].vertex_index].co[2]
            if use_normals:
                data[cursor]['nx'] = mesh.loops[loop_index].normal[0]
                data[cursor]['ny'] = mesh.loops[loop_index].normal[1]
                data[cursor]['nz'] = mesh.loops[loop_index].normal[2]
            if use_tangents:
                data[cursor]['tx'] = mesh.loops[loop_index].tangent[0]
                data[cursor]['ty'] = mesh.loops[loop_index].tangent[1]
                data[cursor]['tz'] = mesh.loops[loop_index].tangent[2]
            for uv_i in range(tex_coord_max):
                data[cursor]['uv%dx' %
                             uv_i] = mesh.uv_layers[uv_i].data[loop_index].uv[0]
                data[cursor]['uv%dy' %
                             uv_i] = mesh.uv_layers[uv_i].data[loop_index].uv[1]
            for col_i in range(color_max):
                data[cursor]['color%dr' %
                             col_i] = mesh.vertex_colors[col_i].data[loop_index].color[0]
                data[cursor]['color%dg' %
                             col_i] = mesh.vertex_colors[col_i].data[loop_index].color[1]
                data[cursor]['color%db' %
                             col_i] = mesh.vertex_colors[col_i].data[loop_index].color[2]
                data[cursor]['color%da' %
                             col_i] = mesh.vertex_colors[col_i].data[loop_index].color[3]
            cursor += 1

    indiceData, indice = np.unique(data, return_inverse=True, axis=0)

    indicePerMaterial = {}
    for matId in materialIndices:
        indicePerMaterial[matId] = indice[indiceData[indice]
                                          ['material'] == matId]

    attributes.content.append(Parameter("data", dataStruct, '\n' + print2dData(
        indiceData[list(indiceData.dtype.names)[1:]]), preQualif="const", postQualif='[' + str(dataSize) + ']', static=True))

    for matId, indices in indicePerMaterial.items():
        lenIndices = str(len(indices))
        idStr = str(matId)
        attributes.content.append(Parameter("indices" + idStr, uint16_t, print1dData(
            indices), preQualif="const", postQualif='[' + lenIndices + ']', static=True))
        attributes.content.append(Parameter(
            "renderOptions" + str(matId), RenderOptions_t, "indices" + idStr + ", " + lenIndices))

    attributes.content.append(
        Parameter("buffer", Buffer_t, init="(const uint8_t *) data, sizeof(data)"))
    attributes.content.append(Parameter("attribute", Attribute_t))
    constructorCode = [
        "attribute.setBuffer(buffer, sizeof(data[0]));",
        "attribute.setArray<float>(3, Blob::AttributeLocation::POSITION, offsetof(Data, x));",
        "attribute.setArray<float>(3, Blob::AttributeLocation::NORMAL, offsetof(Data, nx));"
    ]
    if color_max:
        constructorCode.append(
            "attribute.setArray<float>(4, Blob::AttributeLocation::COLOR_0, offsetof(Data, color0r));")

    attributes.content.append(Function("Attributes", content=constructorCode))

    meshStruct = Struct(name, {"Blob::Mesh": "public"}, [
        attributes,
        Parameter("attributes", NativeType("Attributes::Intance"), "Attributes::getInstance()")])

    albedo = False
    for keyName, prop in mesh.items():
        propType = float_t
        if type(prop) == idprop.types.IDPropertyArray:
            if keyName == "albedo":
                albedo = True
            meshStruct.content.append(Parameter(keyName, propType, print1dData(
                prop.to_list()), postQualif='[' + str(len(prop.to_list())) + ']'))
        if type(prop) == idprop.types.IDPropertyGroup:
            continue

    for material in mesh.materials:
        matName = nameFormat(material.name)
        if "SingleColor" in material.name and albedo:
            meshStruct.content.append(
                Parameter(matName,  NativeType("Materials::" + matName), "{albedo}"))
        else:
            meshStruct.content.append(
                Parameter(matName, NativeType("Materials::" + matName)))

    meshConstructor = Function(name, None, [], [], [])

    for matId, indices in indicePerMaterial.items():
        primitiveName = "primitive" + str(matId)
        meshStruct.content.append(Parameter(primitiveName, Primitive_t))
        meshConstructor.content.append(
            primitiveName + ".material = &" + nameFormat(mesh.materials[matId].name) + ";")
        meshConstructor.content.append(
            primitiveName + ".renderOptions = &attributes->renderOptions" + str(matId) + ";")
        meshConstructor.content.append(
            primitiveName + ".vertexArrayObject = &attributes->attribute;")
        meshConstructor.content.append(
            "addPrimitive(" + primitiveName + ");")

    meshStruct.content.append(meshConstructor)

    return meshStruct.getHeader(), meshStruct.getCore()


projectName = bpy.path.display_name_from_filepath(bpy.data.filepath)
mainFolder = bpy.path.abspath("//") + projectName + "/"
headerFolder = mainFolder + "include/"
srcFolder = mainFolder + "src/"
mainHeader = headerFolder + projectName + ".hpp"
mainCore = srcFolder + projectName + ".cpp"
CMakeLists = mainFolder + "CMakeLists.txt"

Path(headerFolder).mkdir(parents=True, exist_ok=True)
Path(srcFolder).mkdir(parents=True, exist_ok=True)

cppFiles = []
headerFiles = []

materialsStruct = []
for material in bpy.data.materials:
    name = nameFormat(material.name)
    constructor = Function(
        name, None, [], ["Blob::Materials::SingleColor(Blob::Color::RGBA{" + print1dData(material.diffuse_color) + "})"], [])
    materialsStruct.append(Struct(name, content=[constructor], parents={
        "Blob::Materials::SingleColor": "public"}))

with open(headerFolder + "Materials.hpp", "w") as f:
    f.write("#pragma once\n")
    f.write("#include <Blob/Materials.hpp>\n")
    f.write("namespace Materials {\n")
    for material in materialsStruct:
        f.write(material.getHeader())
    f.write("}\n")

with open(srcFolder + "Materials.cpp", "w") as f:
    f.write("#include <Materials.hpp>\n")
    f.write("namespace Materials {\n")
    for material in materialsStruct:
        f.write(material.getCore())
    f.write("}\n")
    cppFiles.append("src/Materials.cpp")

for mesh in bpy.data.meshes:
    name = nameFormat(mesh.name)
    headerCode, coreCode = codeMesh(mesh)
    with open(headerFolder + name + ".hpp", "w") as f:
        headerFiles.append(name + ".hpp")
        f.write("#pragma once\n")
        f.write("#include <Blob/Core/AttributeLocation.hpp>\n")
        f.write("#include <Blob/Core/Mesh.hpp>\n")
        f.write("#include <Blob/Core/Buffer.hpp>\n")
        f.write("#include <Materials.hpp>\n")
        f.write("namespace Project" + projectName + "::Meshes {\n")
        f.write(headerCode)
        f.write("}\n")
    with open(srcFolder + name + ".cpp", "w") as f:
        cppFiles.append("src/" + name + ".cpp")
        f.write("#include <" + name + ".hpp>\n")
        f.write("namespace Project" + projectName + "::Meshes {\n")
        f.write(coreCode)
        f.write("}\n")

allMeshesType = Struct("AllMeshes")
for mesh in bpy.data.meshes:
    name = nameFormat(mesh.name)
    allMeshesType.content.append(
        Parameter(name, NativeType("Meshes::" + name)))
project = Struct("Project" + projectName,
                 content=[Parameter("meshes", allMeshesType)])
constructor = Function(project.name)
for object in bpy.data.objects:
    args = []
    shapeName = nameFormat(object.name)
    for child in object.children:
        childName = nameFormat(child.name)
        constructor.content.append(shapeName + ".addChild(" + childName + ");")
    if type(object.data) == bpy.types.Mesh:
        meshName = nameFormat(object.data.name)
        args.append("meshes." + meshName)
    if object.instance_collection:
        for child in object.instance_collection.objects:
            childName = nameFormat(child.name)
            constructor.content.append(
                shapeName + ".addChild(" + childName + ");")
    args.append("Blob::ModelTransform{" + ", ".join(
        ['{' + ", ".join(map(str, vec)) + '}' for vec in object.matrix_local]) + "}")
    project.content.append(Parameter(shapeName, Shape_t, init=", ".join(args)))

for scene in bpy.data.scenes:
    sceneName = nameFormat(scene.name)
    for object in scene.objects:
        if object.parent != None:
            continue
        objectName = nameFormat(object.name)
        constructor.content.append(
            sceneName + ".addShape(" + objectName + ");")
    project.content.append(Parameter(sceneName, Scene_t))

project.content.append(constructor)

with open(mainHeader, "w") as f:
    f.write("#pragma once\n")
    f.write("#include <Blob/Core/Mesh.hpp>\n")
    f.write("#include <Blob/Core/Buffer.hpp>\n")
    f.write("#include <Blob/Core/Scene.hpp>\n")
    f.write("#include <Blob/Materials.hpp>\n")
    for h in headerFiles:
        f.write("#include <" + h + ">\n")

    f.write("namespace Project" + projectName + " {\n")

    f.write(allMeshesType.getHeader())
    f.write(project.getHeader())
    f.write("}\n")

with open(mainCore, "w") as f:
    f.write("#include <" + projectName + ".hpp>\n")

    f.write("namespace Project" + projectName + " {\n")
    cppFiles.append("src/" + projectName + ".cpp")
    f.write(project.getCore())
    f.write("}\n")


with open(CMakeLists, "w") as f:
    f.write("add_library(" + projectName + " STATIC " + " ".join(cppFiles) + ")\n")
    f.write("target_link_libraries(" + projectName + " Blob)\n")
    f.write("target_include_directories(" + projectName + " PUBLIC include/)")
