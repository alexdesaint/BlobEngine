#include <Blob/Buffer.hpp>

#include <Blob/Exception.hpp>

#include <bx/file.h>

namespace Blob {
void Buffer::setData(const std::string &file) {
    static bx::FileReader reader;
    bx::Error error;

    if (bx::open(&reader, file.c_str()), &error) {
        uint32_t size = (uint32_t) bx::getSize(&reader);
        memory = bgfx::alloc(size + 1);
        bx::read(&reader, memory->data, size, bx::ErrorAssert{});
        bx::close(&reader);
        memory->data[memory->size - 1] = '\0';
    } else
        throw Blob::Exception(std::string("Could not read file ") + error.getMessage().getPtr() + " " + file);
}
} // namespace Blob
