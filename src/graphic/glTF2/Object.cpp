#include <BlobEngine/glTF2/Object.hpp>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>
#include <BlobEngine/BlobException.hpp>

#include <fstream>

using namespace std;
using rapidjson::Document;
using rapidjson::Value;

namespace BlobEngine::glTF2 {

	Document document;

	string Object::path;

	Object::Object() : value(&document) {

	}

	Object::Object(Value *node) : value(node) {

	}

	Object::Object(std::string p) : value(&document) {

		ifstream ifs(p);

		path = p;

		if (!ifs.is_open())
			throw BlobException("can't open the file");

		rapidjson::IStreamWrapper isw(ifs);

		document.ParseStream(isw);

	}

	Object::~Object() {

	}

	JsonNode Object::getBaseNode() {
		return &document;
	}

	void Object::goTo(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsObject() && !(*value)[name].IsArray())
			throw BlobException(string("Member ") + name + " is not an object");

		value = &(*value)[name];
	}

	void Object::goToArrayElement(const char *name, int num) {
		goTo(name);

		value = getArrayObject(num);
	}

	bool Object::hasMember(const char *name) {
		return value->HasMember(name);
	}

	int Object::getArraySize() {
		if (!value->IsArray())
			throw BlobException(string("Member is not an array"));

		return value->Size();
	}

	int Object::getArraySize(const char *name) {
		if (!(*value)[name].IsArray())
			throw BlobException(string("Member is not an array"));

		return (*value)[name].Size();
	}

	int Object::getArrayInt(const char *name, int num) {
		rapidjson::Value &n = *getArray(name);

		if (n.Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		if (!n[num].IsInt())
			throw BlobException(string("Member ") + name + " is not an int");

		return n[num].GetInt();
	}

	string Object::getArrayString(const char *name, int num) {
		rapidjson::Value &n = *getArray(name);

		if (n.Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		if (!n[num].IsString())
			throw BlobException(string("Member ") + name + " is not an string");

		return n[num].GetString();
	}

	JsonNode Object::getArrayObject(int num) {

		if (!value->IsArray())
			throw BlobException(string("Member is not an array"));

		if (value->Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		return &value[num];
	}

	JsonNode Object::getArrayObject(const char *name, int num) {
		rapidjson::Value &n = *getArray(name);

		if (n.Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		if (!n[num].IsObject())
			throw BlobException(string("Member ") + name + " is not an object");

		return &n[num];
	}

	JsonNode Object::getArray(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsArray())
			throw BlobException(string("Member ") + name + " is not an array");

		return &(*value)[name];
	}

	int Object::getInt(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsInt())
			throw BlobException(string("Member ") + name + " is not an int");

		return (*value)[name].GetInt();
	}

	string Object::getString(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsString())
			throw BlobException(string("Member ") + name + " is not a string");

		return (*value)[name].GetString();
	}

	JsonNode Object::getObject(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsObject())
			throw BlobException(string("Member ") + name + " is not an Json object");

		return &(*value)[name];
	}
}