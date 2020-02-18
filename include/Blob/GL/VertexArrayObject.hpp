#ifndef BLOBENGINE_VERTEXARRAY_HPP
#define BLOBENGINE_VERTEXARRAY_HPP

#include <Blob/GL/VertexBufferObject.hpp>

namespace Blob::GL {

    class VertexArrayObject {
    private:

        uint32_t vertexArrayObject;

    public:
        uint32_t getVertexArrayObject() const;

        VertexArrayObject();

        VertexArrayObject(const VertexArrayObject &) = delete;

        ~VertexArrayObject();

        void setBuffer(const VertexBufferObject &vbo, int32_t stride, uint32_t dataOffset = 0, uint32_t pos = 0);

        void setIndicesBuffer(const VertexBufferObject &vbo);

        void setArray(uint32_t numValuePerArray, uint32_t outPosition, uint32_t dataType,
                      uint32_t relativeOffset, bool normalized = false, uint32_t pos = 0);

        template<class C, typename T>
        void setArray();
    };

    template
}


#endif //BLOBENGINE_VERTEXARRAY_HPP
