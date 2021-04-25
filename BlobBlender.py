import bpy
import os
import math

def codeMesh(mesh):
    mesh.calc_loop_triangles()
    dataSize = len(mesh.loop_triangles) * 3
    name = mesh.name.replace('.', '_')
    if mesh.uv_layers.active != None:
        uv_layer = mesh.uv_layers.active.data
    else:
        uv_layer = None
    if mesh.vertex_colors.active != None:
        color_layer = mesh.vertex_colors.active.data
    else:
        color_layer = None
    code = ""
    code += "struct " + name + " : public Blob::Core::Mesh {\n"
    code += "    struct Attributes {\n"
    code += "        struct Data {\n"
    code += "            float pos[3];\n"
    code += "            float normal[3];\n"
    if color_layer != None:
        code += "            float color[4];\n"
    code += "        };\n"
    code += "        const Data data[" + str(dataSize) + "] = {\n"
    
    for loop_triangle in mesh.loop_triangles:
        for loop_index in loop_triangle.loops:
            data = []
            data.append('{' + ", ".join(map(str, mesh.vertices[mesh.loops[loop_index].vertex_index].co)) + '}')
            data.append('{' + ", ".join(map(str, loop_triangle.normal)) + '}')
            if color_layer != None:
                data.append('{' + ", ".join(map(str, color_layer[loop_index].color)) + '}')
            code += '            {' + ", ".join(data) + '},\n'
            
    code += "        };\n"
    code += "        Blob::Core::Buffer buffer{(const uint8_t *) data, sizeof(data)};\n"
    code += "        Blob::GL::VertexArrayObject attribute;\n"
    code += "        Blob::Core::RenderOptions renderOptions{" + str(dataSize) + "};\n"
    code += "        Attributes() {\n"
    code += "            attribute.setBuffer(buffer, sizeof(data[0]));\n"
    code += "            attribute.setArray<float>(3, Blob::Core::Shader::POSITION, offsetof(Data, pos));\n"
    code += "            attribute.setArray<float>(3, Blob::Core::Shader::NORMAL, offsetof(Data, normal));\n"
    if color_layer != None:
        code += "            attribute.setArray<float>(4, Blob::Core::Shader::COLOR_0, offsetof(Data, color));\n"
    code += "        }\n"
    code += "    };\n"
    code += "    inline static std::unique_ptr<Attributes> attributes;\n"
    code += "    Blob::Core::Primitive primitive;\n"
    for material in mesh.materials:
        code += "    Blob::Materials::" + material.name + " material;\n"
    #if mesh.material != None:
    code += "    explicit " + name + "() : Blob::Core::Mesh(primitive) {\n"
    code += "        if (!attributes)\n"
    code += "            attributes = std::make_unique<Attributes>();\n"
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