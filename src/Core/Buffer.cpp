#include <Blob/Core/Buffer.hpp>
#include <Blob/Reader/FileReader.hpp>

namespace Blob {

Buffer::Buffer(const std::string &file) {
    Reader::FileReader fileReader(file);
    dataSize = fileReader.getSize();

    std::vector<uint8_t> bytes(dataSize);

    for (size_t i = 0; i < dataSize; i++)
        bytes[i] = fileReader.readNextByte();

    setData(bytes);
}

} // namespace Blob