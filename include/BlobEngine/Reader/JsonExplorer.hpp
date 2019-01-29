//
// Created by Muta on 11/07/2018.
//

#ifndef BLOBENGINE_OBJECT_HPP
#define BLOBENGINE_OBJECT_HPP

#include <string>

namespace rapidjson {
	template<typename CharType>
	struct UTF8;

	class CrtAllocator;

	template<typename BaseAllocator>
	class MemoryPoolAllocator;

	template<typename Encoding, typename Allocator>
	class GenericValue;

	typedef GenericValue<UTF8<char>, MemoryPoolAllocator<CrtAllocator>> Value;

	template<typename Encoding, typename Allocator, typename StackAllocator>
	class GenericDocument;

	typedef GenericDocument<UTF8<char>, MemoryPoolAllocator<CrtAllocator>, CrtAllocator> Document;
}

typedef rapidjson::Value *JsonNode;

namespace Blob::Reader {

	class JsonExplorer {
	private:

		JsonNode value;

		JsonNode getRapidArray(const char *name);

	public:
		static std::string path;

		JsonExplorer();

		explicit JsonExplorer(JsonNode node);

		explicit JsonExplorer(std::string file);

		~JsonExplorer();

		void goToBaseNode();

		void goIn(const char *name);

		void goToArrayElement(const char *name, int num);

		bool hasMember(const char *name);

		int getArraySize();

		int getArraySize(const char *name);

		int getArrayInt(const char *name, int num);

		float getArrayFloat(const char *name, int num);

		std::string getArrayString(const char *name, int num);

		int getInt(const char *name);

		std::string getString(const char *name);

		JsonExplorer getObject(const char *name);

		JsonExplorer getArrayObject(int num);

		JsonExplorer getArrayObject(const char *name, int num);

		JsonExplorer getArray(const char *name);

		void printType();

		void printMembers();
	};
}

#endif //BLOBENGINE_OBJECT_HPP
