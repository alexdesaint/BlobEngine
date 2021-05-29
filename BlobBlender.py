import bpy
import idprop
import os
import math
import numpy as np

def print3dData(data):
    return '{' + ",\n ".join(['{' + ", ".join(['{' + ", ".join(map(str, d2)) + '}' for d2 in d1]) + '}' for d1 in data]) + '}'
def print2dData(data):
    return ",\n".join(['{' + ", ".join(map(str, d)) + '}' for d in data]) + '\n'
def print1dData(data):
    return ", ".join(map(str, data))

class NativeType:
    def __init__(self, name):
        self.name = name
    def __str__(self):
        return self.name

float_t = NativeType("float")
int32_t = NativeType("int")
uint16_t = NativeType("uint16_t")
string_t = NativeType("std::string")

Buffer_t = NativeType("Blob::Core::Buffer")
Attribute_t = NativeType("Blob::GL::VertexArrayObject")
RenderOptions_t = NativeType("Blob::Core::RenderOptions")

class Parameter:
    def __init__(self, name, type, init = None, preQualif = "", midQualif = "", postQualif = "", indent = 0):
        self.name = name
        self.type = type
        self.init = init
        self.indent = indent
        if preQualif != "":
            preQualif += " "
        if midQualif != "":
            midQualif += " "
        self.preQualif = preQualif
        self.midQualif = midQualif
        self.postQualif = postQualif
    def __str__(self):
        ret = ""
        ret += self.preQualif + str(self.type.name) + " " + self.midQualif + self.name + self.postQualif
        if self.init:
            ret += '{' + self.init + '}'
        ret += ";\n"
        return ret

class Struct:
    def __init__(self, name, parents = {}, content = [], indent = 0):
        self.name = name
        self.parents = parents
        self.content = content
        self.indent = indent

    def __str__(self):
        ret = ""
        ret += "struct " + self.name
        if self.parents:
            ret += " : "
        ret += ", ".join([str(access) + " " + parent.name for parent, access in self.parents.items()])
        ret += " {\n"
        ret += "".join(["    " + str(c) for c in self.content])
        ret += "};\n"
        return ret
        
class Function:
    def __init__(self, name, ret = None, parameters = [], constructorInit = {}, content = [], indent = 0):
        self.name = name
        self.ret = ret
        self.parameters = parameters
        self.constructorInit = constructorInit
        self.content = content
        self.indent = indent

    def __str__(self):
        ret = ""
        if self.ret:
            ret += str(self.ret) + " "
        ret = self.name
        ret += "() {\n"
        ret += "    " + "\n    ".join(self.content) + '\n'
        ret += "}\n"
        return ret

def codeMesh(mesh):
    mesh.calc_loop_triangles()
    dataSize = len(mesh.loop_triangles) * 3
    name = mesh.name.replace('.', '_')
        
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
                print_console('WARNING', 'Could not calculate tangents. Please try to triangulate the mesh first.')
    
    tex_coord_max = 0
    if mesh.uv_layers.active:
        tex_coord_max = len(mesh.uv_layers)
    
    color_max = 0
    color_max = len(mesh.vertex_colors)
        
    use_morph_normals = False
        
    dataType = [('x', np.float32), ('y', np.float32), ('z', np.float32)]
    dataStruct = Struct("Data", {}, [Parameter("x", float_t), Parameter("y", float_t), Parameter("z", float_t)])
    if use_normals:
        dataType += [('nx', np.float32), ('ny', np.float32), ('nz', np.float32)]
        dataStruct.content += [Parameter("nx", float_t), Parameter("ny", float_t), Parameter("nz", float_t)]
    if use_tangents:
        dataType += [('tx', np.float32), ('ty', np.float32), ('tz', np.float32), ('tw', np.float32)]
        dataStruct.content += [Parameter("tx", float_t), Parameter("ty", float_t), Parameter("tz", float_t)]
    for uv_i in range(tex_coord_max):
        dataType += [('uv%dx' % uv_i, np.float32), ('uv%dy' % uv_i, np.float32)]
        dataStruct.content += [Parameter('uv%dx' % uv_i, float_t), Parameter('uv%dy' % uv_i, float_t)]
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
    
    code = ""
    code += "struct " + name + " : public Blob::Core::Mesh {\n"
    attributes = Struct("Attributes", content = [])
    if attributes.content:
        print("Not empty")
    attributes.content.append(dataStruct)
    
    data = np.empty(dataSize, dtype=np.dtype(dataType))
    
    cursor = 0
    for loop_triangle in mesh.loop_triangles:
        for loop_index in loop_triangle.loops:
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
                data[cursor]['uv%dx' % uv_i] = mesh.uv_layers[uv_i].data[loop_index].uv[0]
                data[cursor]['uv%dy' % uv_i] = mesh.uv_layers[uv_i].data[loop_index].uv[1]
            for col_i in range(color_max):
                data[cursor]['color%dr' % col_i] = mesh.vertex_colors[col_i].data[loop_index].color[0]
                data[cursor]['color%dg' % col_i] = mesh.vertex_colors[col_i].data[loop_index].color[1]
                data[cursor]['color%db' % col_i] = mesh.vertex_colors[col_i].data[loop_index].color[2]
                data[cursor]['color%da' % col_i] = mesh.vertex_colors[col_i].data[loop_index].color[3]
            cursor += 1
    
    indiceData, indice = np.unique(data, return_inverse=True, axis=0)

    attributes.content.append(Parameter("data", dataStruct, '\n' + print2dData(indiceData), preQualif = "const", postQualif = '[' + str(dataSize) + ']'))
    
    attributes.content.append(Parameter("indices", uint16_t, print1dData(indice), preQualif = "const", postQualif = '[' + str(len(indice)) + ']'))
    
    attributes.content.append(Parameter("buffer", Buffer_t, init = "(const uint8_t *) data, sizeof(data)"))
    attributes.content.append(Parameter("attribute", Attribute_t))
    attributes.content.append(Parameter("renderOptions", RenderOptions_t, "indices, " +  str(len(indice)) + ""))
    constructorCode = [
        "attribute.setBuffer(buffer, sizeof(data[0]));",
        "attribute.setArray<float>(3, Blob::Core::Shader::POSITION, offsetof(Data, x));",
        "attribute.setArray<float>(3, Blob::Core::Shader::NORMAL, offsetof(Data, nx));"
    ]
    if color_max:
        constructorCode.append("attribute.setArray<float>(4, Blob::Core::Shader::COLOR_0, offsetof(Data, color0r));")
        
    attributes.content.append(Function("Attributes", content = constructorCode))
    
    code += str(attributes)
    code += "    inline static std::unique_ptr<Attributes> attributes;\n"
    code += "    Blob::Core::Primitive primitive;\n"
    albedo = False
    for keyName, prop in mesh.items():
        propType = float_t
        if type(prop) == idprop.types.IDPropertyArray:
            if keyName == "albedo":
                albedo = True
            code += str(Parameter(keyName, propType, print1dData(prop.to_list()), postQualif = '[' + str(len(prop.to_list())) + ']'))
        if type(prop) == idprop.types.IDPropertyGroup:
            continue
        
    for material in mesh.materials:
        if "SingleColor" in material.name and albedo:
            code += "    Blob::Materials::" + material.name + " material{{albedo}};\n"
        else:
            code += "    Blob::Materials::" + material.name + " material;\n"
    code += "    explicit " + name + "() : Blob::Core::Mesh(primitive) {\n"
    code += "        if (!attributes)\n"
    code += "            attributes = std::make_unique<Attributes>();\n"
    for material in mesh.materials:
        code += "        primitive.setMaterial(&material);\n"
    code += "        primitive.setRenderOptions(&attributes->renderOptions);\n"
    code += "        primitive.setVertexArrayObject(&attributes->attribute);\n"
    code += "    }\n"
    code += "};\n"
    return code

def codeObject(object):
    code = ""
    if type(object.data) != bpy.types.Mesh:
        return code
    meshName = object.data.name.replace('.', '_')
    name = object.name.replace('.', '_')
    code += "class " + name + " : public Blob::Core::Shape {\n"
    code += "public:\n"
    code += "    Meshes::" + meshName + " mesh_" + meshName + ";\n"
    code += "    " + name + "() :\n"
    code += "        Blob::Core::Shape(mesh_" + meshName + ", Blob::Maths::ModelTransform(" + ", ".join(['{' + ", ".join(map(str, vec)) + '}' for vec in object.matrix_local]) + ")) {}\n"
    code += '};\n'
    return code

fileName = bpy.path.display_name_from_filepath(bpy.data.filepath)
filePath = bpy.path.abspath("//") + fileName + ".hpp"

if os.path.exists(filePath):
      os.remove(filePath)
with open(filePath, "a") as f:
    f.seek(0)
    f.write("#include <Blob/Core/Mesh.hpp>\n")
    f.write("#include <Blob/Core/Buffer.hpp>\n")
    f.write("#include <Blob/Core/Scene.hpp>\n")
    f.write("#include <Blob/Materials.hpp>\n")
    f.write("namespace Meshes {\n")
    for mesh in bpy.data.meshes:
        f.write(codeMesh(mesh))
    f.write("}\n")
    f.write("class Porject" + fileName + " {\n")
    f.write("public:\n")
    f.write("    struct {\n")
    for mesh in bpy.data.meshes:
        name = mesh.name.replace('.', '_')
        f.write("        Meshes::" + name + " " + name + ";\n")
    f.write("    } meshes;\n")
    constructor = []
    for object in bpy.data.objects:
        args = []
        shapeName = object.name.replace('.', '_')
        for child in object.children:
            childName = child.name.replace('.', '_')
            constructor.append("        " + shapeName + ".addChild(" + childName + ");\n")
        if type(object.data) == bpy.types.Mesh:
            meshName = object.data.name.replace('.', '_')
            args.append("meshes." + meshName)
        if object.instance_collection:
            for child in object.instance_collection.objects:
                childName = child.name.replace('.', '_')
                constructor.append("        " + shapeName + ".addChild(" + childName + ");\n")
        args.append("Blob::Maths::ModelTransform{" + ", ".join(['{' + ", ".join(map(str, vec)) + '}' for vec in object.matrix_local]) + "}")
            
        f.write("    Blob::Core::Shape " + shapeName + "{" + ", ".join(args) + "};\n")
    for scene in bpy.data.scenes:
        sceneName = scene.name.replace('.', '_')
        for object in scene.objects:
            if object.parent != None:
                continue
            objectName = object.name.replace('.', '_')
            constructor.append("        " + sceneName + ".addShape(" + objectName + ");\n")
        f.write("    Blob::Core::Scene " + sceneName + ";\n")
    f.write("    Porject" + fileName + "() {\n")
    for c in constructor:
        f.write(c)
    f.write("    }\n")
    f.write("};\n")