#include <Blob/Reader/FileReader.hpp>

#include <Blob/Core/Exception.hpp>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

namespace Blob::Reader {

FileReader::FileReader(const std::string &FilePath) {
    inFile.open(FilePath, std::ios::in | std::ios::binary | std::ios::ate);
    if (!inFile.is_open())
        throw Exception("FileReader : cannot open the file");

    size = inFile.tellg();
    inFile.seekg(0, std::ios::beg);
}

FileReader::~FileReader() {
    inFile.close();
}

void FileReader::load(const std::string &FilePath) {
    if (!inFile.is_open())
        inFile.close();

    inFile.open(FilePath, std::ios::in | std::ios::binary | std::ios::ate);
    if (!inFile.is_open())
        throw Exception("FileReader : cannot open the file");

    size = inFile.tellg();
    inFile.seekg(0, std::ios::beg);
}

unsigned char FileReader::readNextByte() {
    return static_cast<unsigned char>(inFile.get());
}

std::string FileReader::getString(int length) {

    std::vector<char> buffer(length + 1);

    inFile.read(buffer.data(), length);

    buffer[length] = '\0';

    return std::string(buffer.begin(), buffer.end());
}

std::vector<uint8_t> FileReader::loadBinaryFile(const std::string &filename) {
    std::vector<uint8_t> buffer;

    std::ifstream file(filename,
                       std::ios::in | std::ios::binary | std::ios::ate);
    if (file.is_open()) {
        std::streampos size = file.tellg();
        buffer.resize(size);
        file.seekg(0, std::ios::beg);
        file.read((char *) buffer.data(), size);
        file.close();
    } else
        std::cout << "Unable to open file : " << filename;
    return buffer;
}

std::string FileReader::toString() {
    std::stringstream buffer;

    buffer << inFile.rdbuf();

    return buffer.str();
}

std::string FileReader::getLine() {
    std::string str;

    std::getline(inFile, str);

    return str;
}

bool FileReader::EOFReached() {
    return inFile.tellg() >= size;
}

void FileReader::restart() {
    inFile.seekg(0, std::ios::beg);
}

void FileReader::goTo(size_t pos) {
    inFile.seekg(pos);
}

size_t FileReader::getSize() const {
    return static_cast<size_t>(size);
}

std::ostream &operator<<(std::ostream &s, FileReader &a) {
    auto pos = a.inFile.tellg();
    a.restart();

    int cpt = 0;
    while (!a.EOFReached()) {
        s << std::hex << std::uppercase << std::setw(2) << std::setfill('0')
          << (unsigned int) a.readNextByte();

        cpt++;

        if (cpt % 2 == 0)
            s << ' ';

        if (cpt % 16 == 0) {
            s << std::endl;
            cpt = 0;
        }
    }

    s << std::dec << std::endl;

    a.inFile.seekg(pos);

    return s;
}

} // namespace Blob::Reader