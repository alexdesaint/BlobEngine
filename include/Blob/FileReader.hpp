#pragma once
#include <fstream>
#include <string>
#include <vector>

namespace Blob::Reader {
class FileReader {
private:
    std::ifstream inFile;
    std::streampos size = 0;

public:
    explicit FileReader(const std::string &FilePath);

    ~FileReader();

    void load(const std::string &FilePath);

    unsigned char readNextByte();

    std::string getString(int length);

    static std::vector<uint8_t> loadBinaryFile(const std::string &filename);

    template<typename T>
    T readNextBytes() {
        T r = 0;
        inFile.read(reinterpret_cast<char *>(&r), sizeof(T));

        return r;
    }

    bool EOFReached();

    void restart();

    void goTo(size_t pos);

    std::string toString();

    std::string getLine();

    size_t getSize() const;

    friend std::ostream &operator<<(std::ostream &s, FileReader &a);

    static std::string getFileExtention(const std::string &file) {
        return file.substr(file.find_last_of('.') + 1);
    }

    static std::string getFilePath(const std::string &file) {
        return file.substr(0, file.find_last_of("/\\") + 1);
    }

    static std::string getFileName(const std::string &file) {
        auto b = file.find_last_of("/\\") + 1;
        return file.substr(b, file.find_last_of('.') - b);
    }
};
} // namespace Blob::Reader
