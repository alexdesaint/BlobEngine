#include <BlobEngine/Reader/FileReader.hpp>

#include <BlobEngine/BlobException.hpp>
#include <sstream>
#include <iostream>

namespace BlobEngine {

	FileReader::FileReader(const std::string &FilePath) {
		inFile.open(FilePath, std::ios::in | std::ios::binary | std::ios::ate);
		if (!inFile.is_open())
			throw BlobException("FileReader : cannot open the file");

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
			throw BlobException("FileReader : cannot open the file");

		size = inFile.tellg();
		inFile.seekg(0, std::ios::beg);
	}

	unsigned char FileReader::readNextByte() {
		return static_cast<unsigned char>(inFile.get());
	}

	std::string FileReader::getString(int length) {

		char buffer[length + 1];

		inFile.read(buffer, length);

		buffer[length] = '\0';

		return std::string(buffer);
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

	size_t FileReader::getSize() const {
		return static_cast<size_t>(size);
	}
}