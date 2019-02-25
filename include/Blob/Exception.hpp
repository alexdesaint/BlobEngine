#ifndef BLOBENGINE_BLOBEXCEPTION_HPP
#define BLOBENGINE_BLOBEXCEPTION_HPP

#include <exception>
#include <utility>
#include <string>

class Exception : public std::exception {
private:
	const std::string errorMsg;

public:
	//explicit Exception(const char *errorMsg) : errorMsg(errorMsg){}

	explicit Exception(std::string errorMsg) : errorMsg(std::move(errorMsg)) {}

	const char *what() const noexcept override {
		return errorMsg.c_str();
	}
};

#endif //BLOBENGINE_BLOBEXCEPTION_HPP
