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

namespace BlobEngine::glTF2 {

	class Object {
	private:

		JsonNode value;

	protected:
		static std::string path;

		Object();

		explicit Object(JsonNode node);

		explicit Object(std::string file);

		~Object();

		static JsonNode getBaseNode();

		void goTo(const char *name);

		void goToArrayElement(const char *name, int num);

		bool hasMember(const char *name);

		int getArraySize();

		int getArraySize(const char *name);

		int getArrayInt(const char *name, int num);

		std::string getArrayString(const char *name, int num);

		int getInt(const char *name);

		std::string getString(const char *name);

		JsonNode getObject(const char *name);

		JsonNode getArrayObject(int num);

		JsonNode getArrayObject(const char *name, int num);

		JsonNode getArray(const char *name);
	};
}

#endif //BLOBENGINE_OBJECT_HPP
