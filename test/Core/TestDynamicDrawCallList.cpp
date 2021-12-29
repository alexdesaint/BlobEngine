#include "Blob/Core/Primitive.hpp"
#include "Blob/Maths.inl"
#include <Blob/Core/DynamicDrawCallList.hpp>

using namespace Blob;

int main() {
    DynamicDrawCallList dynamicDrawCallList;
    Primitive p;

    std::pair<Mat4, void *> matTests[] = {
        {Mat4{1}, (void *) 1},
        {Mat4{2}, (void *) 2},
        {Mat4{3}, (void *) 3},
        {Mat4{4}, (void *) 4},
        {Mat4{5}, (void *) 5},
        {Mat4{6}, (void *) 6},
        {Mat4{7}, (void *) 7},
        {Mat4{8}, (void *) 8},
        {Mat4{9}, (void *) 9},
    };

    for (const auto &[mat, id] : matTests)
        dynamicDrawCallList.add(id, &p, mat);

    dynamicDrawCallList.remove((void *) 5, &p);

    dynamicDrawCallList.add((void *) 11, &p, Mat4{11});

    std::cout << dynamicDrawCallList << std::endl;
}