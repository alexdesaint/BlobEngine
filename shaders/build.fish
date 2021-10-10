#!/bin/fish
cd (dirname (status --current-filename))

mkdir -p ../include/Blob/Shaders/Vert
mkdir -p ../include/Blob/Shaders/Frag
mkdir -p ../include/Blob/Shaders/Geom

set vertEntrys mainNonInstanced mainInstanced mainInstancedColor
set fragEntrys singleColor singleTexture PBRsingleColor PBRsingleTexture PBRcolorArray

for i in $vertEntrys
    set file "../include/Blob/Shaders/Vert/"$i".hpp"
    echo $i
    glslangValidator --target-env opengl -S vert -e $i --sep main vert.glsl --vn $i -o $file
    sed -i s/const/constexpr/ $file
end

for i in $fragEntrys
    set file "../include/Blob/Shaders/Frag/"$i".hpp"
    echo $i
    glslangValidator --target-env opengl -S frag -e $i --sep main frag.glsl --vn $i -o $file
    sed -i s/const/constexpr/ $file
end

glslangValidator --target-env opengl normal.vert --vn normal_vert -o "../include/Blob/Shaders/Vert/normal.hpp"
sed -i s/const/constexpr/ "../include/Blob/Shaders/Vert/normal.hpp"
glslangValidator --target-env opengl normal.geom --vn normal_geom -o "../include/Blob/Shaders/Geom/normal.hpp"
sed -i s/const/constexpr/ "../include/Blob/Shaders/Geom/normal.hpp"

glslangValidator --target-env opengl water.vert --vn water_vert -o "../include/Blob/Shaders/Vert/water.hpp"
sed -i s/const/constexpr/ "../include/Blob/Shaders/Vert/water.hpp"
glslangValidator --target-env opengl water.geom --vn water_geom -o "../include/Blob/Shaders/Geom/water.hpp"
sed -i s/const/constexpr/ "../include/Blob/Shaders/Geom/water.hpp"
