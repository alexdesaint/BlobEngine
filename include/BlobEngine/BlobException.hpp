//
// Created by alexa on 16/03/2018.
//

#ifndef BLOBENGINE_BLOBEXCEPTION_HPP
#define BLOBENGINE_BLOBEXCEPTION_HPP

#include <exception>

class BlobException : public std::exception {
private:
	const char *errorMsg;

public:
	explicit BlobException(const char *errorMsg) : errorMsg(errorMsg){}

	const char* what() const throw() override {
		return errorMsg;
	}
};

#endif //BLOBENGINE_BLOBEXCEPTION_HPP
