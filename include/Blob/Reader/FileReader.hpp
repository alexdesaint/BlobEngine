#ifndef BLOBENGINE_FILEREADER_HPP
#define BLOBENGINE_FILEREADER_HPP

#include <string>
#include <fstream>

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
	};
}

#endif //BLOBENGINE_FILEREADER_HPP
