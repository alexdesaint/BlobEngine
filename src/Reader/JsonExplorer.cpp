#include <BlobEngine/Reader/JsonExplorer.hpp>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/istreamwrapper.h>

#include <BlobEngine/BlobException.hpp>

#include <fstream>
#include <iostream>

using namespace std;
using rapidjson::Document;
using rapidjson::Value;

namespace Blob::Reader {

	Document document;

	string JsonExplorer::path;

	JsonNode JsonExplorer::getRapidArray(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsArray())
			throw BlobException(string("Member ") + name + " is not an array");

		return &(*value)[name];
	}

	JsonExplorer::JsonExplorer() : value(&document) {

	}

	JsonExplorer::JsonExplorer(Value *node) : value(node) {

	}

	JsonExplorer::JsonExplorer(std::string p) : value(&document) {

		ifstream ifs(p);

		path = p;

		if (!ifs.is_open())
			throw BlobException("can't open the file");

		rapidjson::IStreamWrapper isw(ifs);

		document.ParseStream(isw);

	}

	JsonExplorer::~JsonExplorer() {

	}

	void JsonExplorer::goToBaseNode() {
		value = &document;
	}

	void JsonExplorer::goIn(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsObject() && !(*value)[name].IsArray())
			throw BlobException(string("Member ") + name + " is not an object");

		value = &(*value)[name];
	}

	void JsonExplorer::goToArrayElement(const char *name, int num) {
		goIn(name);

		if (!value->IsArray())
			throw BlobException(string("Member is not an array"));

		if (value->Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		value = &(*value)[num];
	}

	bool JsonExplorer::hasMember(const char *name) {
		return value->HasMember(name);
	}

	int JsonExplorer::getArraySize() {

		if (!value->IsArray())
			throw BlobException(string("Member is not an array"));

		return value->Size();
	}

	int JsonExplorer::getArraySize(const char *name) {

		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsArray())
			throw BlobException(string("Member is not an array"));

		return (*value)[name].Size();
	}

	int JsonExplorer::getArrayInt(const char *name, int num) {
		rapidjson::Value &n = *getRapidArray(name);

		if (n.Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		if (!n[num].IsInt())
			throw BlobException(string("Member ") + name + " is not an int");

		return n[num].GetInt();
	}

	float JsonExplorer::getArrayFloat(const char *name, int num) {
		rapidjson::Value &n = *getRapidArray(name);

		if (n.Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		if (!n[num].IsFloat())
			throw BlobException(string("Member ") + name + " is not an float");

		return n[num].GetFloat();
	}

	string JsonExplorer::getArrayString(const char *name, int num) {
		rapidjson::Value &n = *getRapidArray(name);

		if (n.Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		if (!n[num].IsString())
			throw BlobException(string("Member ") + name + " is not an string");

		return n[num].GetString();
	}

	JsonExplorer JsonExplorer::getArrayObject(int num) {

		if (!value->IsArray())
			throw BlobException(string("Member is not an array"));

		if (value->Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		return JsonExplorer(&(*value)[num]);
	}

	JsonExplorer JsonExplorer::getArrayObject(const char *name, int num) {
		rapidjson::Value &n = *getRapidArray(name);

		if (n.Size() < num + 1)
			throw BlobException(string("Error : num out of bound"));

		if (!n[num].IsObject())
			throw BlobException(string("Member ") + name + " is not an object");

		return JsonExplorer(&n[num]);
	}

	JsonExplorer JsonExplorer::getArray(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsArray())
			throw BlobException(string("Member ") + name + " is not an array");

		return JsonExplorer(&(*value)[name]);
	}

	int JsonExplorer::getInt(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsInt())
			throw BlobException(string("Member ") + name + " is not an int");

		return (*value)[name].GetInt();
	}

	string JsonExplorer::getString(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsString())
			throw BlobException(string("Member ") + name + " is not a string");

		return (*value)[name].GetString();
	}

	JsonExplorer JsonExplorer::getObject(const char *name) {
		if (!value->HasMember(name))
			throw BlobException(string("Member ") + name + " can't be found");

		if (!(*value)[name].IsObject())
			throw BlobException(string("Member ") + name + " is not an Json object");

		return JsonExplorer(&(*value)[name]);
	}

	void JsonExplorer::printType() {
		switch (value->GetType()) {
			case rapidjson::kNullType:
				std::cout << "NullType";
				break;
			case rapidjson::kFalseType:
				std::cout << "FalseType";
				break;
			case rapidjson::kTrueType:
				std::cout << "TrueType";
				break;
			case rapidjson::kObjectType:
				std::cout << "ObjectType";
				break;
			case rapidjson::kArrayType:
				std::cout << "ArrayType";
				break;
			case rapidjson::kStringType:
				std::cout << "StringType";
				break;
			case rapidjson::kNumberType:
				std::cout << "NumberType";
				break;
		}

		std::cout << endl;
	}

	void JsonExplorer::printMembers() {
		for (rapidjson::Value::MemberIterator itr = value->MemberBegin(); itr != value->MemberEnd(); ++itr) {
			std::cout << itr->name.GetString() << endl;
		}
	}
}