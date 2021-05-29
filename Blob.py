import numpy as np

def print3dData(data):
    return '{' + ",\n ".join(['{' + ", ".join(['{' + ", ".join(map(str, d2)) + '}' for d2 in d1]) + '}' for d1 in data]) + '}'
def print2dData(data):
    return '{' + ",\n ".join(['{' + ", ".join(map(str, d)) + '}' for d in data]) + '}'
def print1dData(data):
    return '{' + ", ".join(map(str, data)) + '}'

use_normals= True
use_tangents= False
tex_coord_max = 0
color_max = 1
use_morph_normals = False

#dataType = [('vertex_index', np.uint32)]
dataType = [('x', np.float32), ('y', np.float32), ('z', np.float32)]
if use_normals:
    dataType += [('nx', np.float32), ('ny', np.float32), ('nz', np.float32)]
if use_tangents:
    dataType += [('tx', np.float32), ('ty', np.float32), ('tz', np.float32), ('tw', np.float32)]
for uv_i in range(tex_coord_max):
    dataType += [('uv%dx' % uv_i, np.float32), ('uv%dy' % uv_i, np.float32)]
for col_i in range(color_max):
    dataType += [
        ('color%dr' % col_i, np.float32),
        ('color%dg' % col_i, np.float32),
        ('color%db' % col_i, np.float32),
        ('color%da' % col_i, np.float32),
    ]
if use_morph_normals:
    for morph_i, _ in enumerate(key_blocks):
        dataType += [
            ('morph%dnx' % morph_i, np.float32),
            ('morph%dny' % morph_i, np.float32),
            ('morph%dnz' % morph_i, np.float32),
        ]

data = np.empty(4, dtype=np.dtype(dataType))

data[0] = (8.0, -8.0, -1.0, 0.0, 0.0, -1.0, 0.5607843399047852, 0.3137255012989044, 0.1882352977991104, 1.0)
data[1] = (-8.0, -8.0, -1.0, 0.0, 0.0, -1.0, 0.5607843399047852, 0.3137255012989044, 0.1882352977991104, 1.0)
data[2] = (-8.0, 8.0, -1.0, 0.0, 0.0, -1.0, 0.5607843399047852, 0.3137255012989044, 0.1882352977991104, 1.0)
data[3] = (8.0, -8.0, -1.0, -0.0, -0.0, -1.0, 0.5607843399047852, 0.3137255012989044, 0.1882352977991104, 1.0)

print(data[0][:])

print(dataType)
print(print2dData(data))

indiceData, indice = np.unique(data, return_inverse=True)

print(indice)
print(print2dData(indiceData))
