#ifndef BLOBENGINE_BLOBEXCEPTION_HPP
#define BLOBENGINE_BLOBEXCEPTION_HPP

#include <exception>
#include <utility>
#include <string>

class BlobException : public std::exception {
private:
	const std::string errorMsg;

public:
	//explicit BlobException(const char *errorMsg) : errorMsg(errorMsg){}

	explicit BlobException(std::string errorMsg) : errorMsg(std::move(errorMsg)) {}

	const char *what() const noexcept override {
		return errorMsg.c_str();
	}
};

#endif //BLOBENGINE_BLOBEXCEPTION_HPP
