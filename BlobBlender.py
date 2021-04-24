import bpy

mesh = bpy.context.object.data
if mesh.uv_layers.active != None:
    uv_layer = mesh.uv_layers.active.data
else:
    uv_layer = None
if mesh.vertex_colors.active != None:
    color_layer = mesh.vertex_colors.active.data
else:
    color_layer = None

print()
print(mesh.name)
print(len(color_layer))

mesh.calc_loop_triangles()

print('float[]')

for loop_triangle in mesh.loop_triangles:
    for i in range(3):
        print('{')
        print('    {' + ", ".join(map(str, mesh.vertices[loop_triangle.vertices[i]].co)) + '}')
        print('    {' + ", ".join(map(str, color_layer[loop_triangle.loops[i]].color)) + '}')
        print('    {' + ", ".join(map(str, loop_triangle.normal)) + '}')
        print('},')