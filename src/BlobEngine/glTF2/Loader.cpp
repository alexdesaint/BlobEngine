#include <BlobEngine/glTF2/Loader.hpp>

#include <BlobEngine/BlobException.hpp>
#include <BlobEngine/FileReader.hpp>
#include <BlobEngine/BlobGL/VertexBufferObject.hpp>
#include <BlobEngine/BlobGL/VertexArrayObject.hpp>

#include <BlobEngine/glTF2/JsonExplorer.hpp>

#include <array>
#include <list>
#include <iostream>

#include <glm/mat4x4.hpp>

using namespace std;

namespace BlobEngine::glTF2 {

	class Asset{
	private:
		string version;

	public:
		explicit Asset(JsonExplorer j) {

			//j.goIn("asset");

			version = j.getString("version");

			cout << version << endl;

			if (version != "2.0")
				throw BlobException(string("glTF : can't load version ") + version);
		}
	};

	class Buffer {
	public:

		string uri; //!< The uri of the buffer. Can be a filepath, a data uri, etc. (required)
		size_t byteLength = 0; //!< The length of the buffer in bytes. (default: 0)

		vector<GLubyte> data;

		void load(int num, JsonExplorer explorer) {
			explorer.goToBaseNode();

			explorer.goToArrayElement("buffers", num);

			uri = explorer.getString("uri");

			if (explorer.hasMember("byteLength"))
				byteLength = static_cast<size_t>(explorer.getInt("byteLength"));

			cout << FileReader::getFilePath(JsonExplorer::path) + uri << endl;

			FileReader fileReader(FileReader::getFilePath(JsonExplorer::path) + uri);

			if (fileReader.getSize() != byteLength)
				throw BlobException("File typeSize don't fit");

			data.resize(byteLength);

			for (int i = 0; i < byteLength; i++)
				data[i] = fileReader.readNextByte();

			for(unsigned char &i : data)
				std::cout << hex << uppercase << (unsigned int) i << ' ';

			cout << endl;
		}
	};

	//! A view into a buffer generally representing a subset of the buffer.
	class BufferView  : public BlobGL::VertexBufferObject  {
	public:
		Buffer buffer; //! The ID of the buffer. (required)
		int byteOffset{}; //! The offset into the buffer in bytes. (required)
		int byteLength = 0; //! The length of the bufferView in bytes. (default: 0)

		enum Target {
			BufferViewTarget_ARRAY_BUFFER = 34962,
			BufferViewTarget_ELEMENT_ARRAY_BUFFER = 34963
		};

		Target target = BufferViewTarget_ARRAY_BUFFER; //! The target that the WebGL buffer should be bound to.

		void load(int num, JsonExplorer explorer) {

			//loading Json Data
			explorer.goToBaseNode();

			explorer.goToArrayElement("bufferViews", num);

			byteOffset = explorer.getInt("byteOffset");

			if (explorer.hasMember("byteLength"))
				byteLength = explorer.getInt("byteLength");

			target = static_cast<Target>(explorer.getInt("target"));

			buffer.load(explorer.getInt("buffer"), explorer);

			// Creating VBO

			setData(buffer.data);

		}
	};

class Accessor : public BlobGL::VertexArrayObject {
	public:
		enum Type {
			SCALAR = 1, VEC2 = 2, VEC3 = 3, VEC4 = 4, MAT2 = 4, MAT3 = 9, MAT4 = 16
		};

	private:

		static const size_t NUM_TYPE = 7;

		struct TypeInfo {
			const char *name;
			Type type;
		};

		static const TypeInfo typeInfos[NUM_TYPE];

	public:

		enum ComponentType {
			ComponentType_BYTE = 5120,
			ComponentType_UNSIGNED_BYTE = 5121,
			ComponentType_SHORT = 5122,
			ComponentType_UNSIGNED_SHORT = 5123,
			ComponentType_UNSIGNED_INT = 5125,
			ComponentType_FLOAT = 5126
		};

		static Type getType(const char *str) {
			for (auto typeInfo : typeInfos) {
				if (strcmp(typeInfo.name, str) == 0) {
					return typeInfo.type;
				}
			}
			//TODO throw exeption when gatType fail
			return SCALAR;
		}

		BufferView bufferView;            //!< The ID of the bufferView. (required)
		unsigned int byteOffset;        //!< The offset relative to the start of the bufferView in bytes. (required)
		ComponentType componentType;    //!< The datatype of components in the attribute. (required)
		unsigned int count;                //!< The number of attributes referenced by this accessor. (required)
		Type type;                        //!< Specifies if the attribute is a scalar, vector, or matrix. (required)
		vector<float> max;                //!< Maximum value of each component in this attribute.
		vector<float> min;                //!< Minimum value of each component in this attribute.

		void load(int num, JsonExplorer explorer) {

			//Json loading
			explorer.goToBaseNode();

			explorer.goToArrayElement("accessors", num);

			bufferView.load(explorer.getInt("bufferView"), explorer);

			componentType = (ComponentType) explorer.getInt("componentType");

			type = getType(explorer.getString("type").c_str());

			byteOffset = static_cast<unsigned int>(explorer.getInt("byteOffset"));

			count = static_cast<unsigned int>(explorer.getInt("count"));

			//VAO
			addBuffer(bufferView, type, 0, 0);
		}
	};

	const Accessor::TypeInfo Accessor::typeInfos[NUM_TYPE] = {
			{"SCALAR", SCALAR},
			{"VEC2",   VEC2},
			{"VEC3",   VEC3},
			{"VEC4",   VEC4},
			{"MAT2",   MAT2},
			{"MAT3",   MAT3},
			{"MAT4",   MAT4}
	};

	class Mesh {
	private:
		class Primitive {
		private:

			class Attributes {
			public:
				Accessor position;

				explicit Attributes(JsonExplorer explorer) {
					position.load(explorer.getInt("POSITION"), explorer);
				}
			};

		public:

			Attributes attributes;

			explicit Primitive(JsonExplorer explorer) : attributes(explorer.getObject("attributes")) {

			}
		};

		vector<Primitive> primitives;

	public:
		void load(int num, JsonExplorer explorer) {
			explorer.goToBaseNode();

			explorer.goToArrayElement("meshes", num);

			int size = explorer.getArraySize("primitives");

			for (unsigned int i = 0; i < size; i++) {
				primitives.emplace_back(explorer.getArrayObject("primitives", i));
			}
		}
	};

	class Node {
	public:
		vector<Node> children;
		Mesh mesh;

		glm::mat4 matrix{};
		glm::vec3 translation{};
		glm::vec4 rotation{};
		glm::vec3 scale{};

		explicit Node(int num, JsonExplorer explorer) {
			explorer.goToBaseNode();

			explorer.goToArrayElement("nodes", num);

			mesh.load(explorer.getInt("mesh"), explorer);
		}
	};

	class Scene {
	public:

		vector<Node> nodes;

		explicit Scene(JsonExplorer explorer) {

			int size = explorer.getArraySize("nodes");

			for (unsigned int i = 0; i < size; i++) {
				nodes.emplace_back(explorer.getArrayInt("nodes", i), explorer);
			}

		}
	};

	class SceneManager {
	public:

		vector<Scene> scenes;

		int defaultScene = 0;

		explicit SceneManager(const string &file) {

			JsonExplorer baseNode(file);

			Asset a(baseNode.getObject("asset"));

			if(baseNode.hasMember("asset"))
				cout << "working" << endl;
			else
				cout << "not working" << endl;

			if (baseNode.hasMember("scene"))
				defaultScene = baseNode.getInt("scene");

			if (baseNode.hasMember("version"))
				defaultScene = baseNode.getInt("scene");

			JsonExplorer scenesObject = baseNode.getArray("scenes");

			int size = scenesObject.getArraySize();

			for (unsigned int i = 0; i < size; i++) {
				scenes.emplace_back(scenesObject.getArrayObject(i));
			}
		}
	};

	Loader::Loader(const string &path) {

		SceneManager sceneManager(path);
	}
}