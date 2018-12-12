#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/BlobGL/Shape.hpp>
#include <BlobEngine/Reader/FileReader.hpp>
#include <BlobEngine/Time.hpp>
#include <BlobEngine/BlobException.hpp>
#include <iostream>
//#include <BlobEngine/glTF2/Loader.hpp>

#include <BlobEngine/BlobException.hpp>

#include <BlobEngine/BlobGL/VertexBufferObject.hpp>
#include <BlobEngine/BlobGL/VertexArrayObject.hpp>

#include <BlobEngine/Reader/JsonExplorer.hpp>

#include <array>
#include <list>
#include <iostream>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/mat4x4.hpp>
#include <glm/gtx/string_cast.hpp>

using namespace std;

using namespace BlobEngine::Reader;
using namespace BlobEngine::BlobGL;
using namespace BlobEngine;

namespace BlobEngine::glTF2 {

	class Asset {
	private:
		string version;

	public:
		explicit Asset(JsonExplorer j) {

			//j.goIn("asset");

			version = j.getString("version");

			if (version != "2.0")
				throw BlobException(string("glTF : can't load version ") + version);
		}

		friend std::ostream& operator<<(std::ostream &s, const Asset &a) {
			s << "Asset : " << a.version << std::endl;
			return s;
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

			uri = BlobEngine::FileReader::getFilePath(JsonExplorer::path) + explorer.getString("uri");

			if (explorer.hasMember("byteLength"))
				byteLength = static_cast<size_t>(explorer.getInt("byteLength"));

			FileReader fileReader(uri);

			if (fileReader.getSize() != byteLength)
				throw BlobException("File typeSize don't fit");

			data.resize(byteLength);

			for (int i = 0; i < byteLength; i++)
				data[i] = fileReader.readNextByte();
		}

		friend std::ostream& operator<<(std::ostream &s, const Buffer &a) {
			s << "Buffer {" << std::endl;

			s << a.uri << endl << "byteLength : " << a.byteLength << endl << "data : ";
			for(const GLubyte &i : a.data)
				s << hex << uppercase << (unsigned int) i << ' ';

			s << endl;
			s << "}" << endl;
			return s;
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

		friend std::ostream& operator<<(std::ostream &s, const BufferView &a) {
			s << "BufferView {" << std::endl;

			s << "byteOffset : " << a.byteOffset << endl;
			s << "byteOffset : " << a.byteLength << endl;
			s << a.buffer;
			s << "}" << endl;
			return s;
		}
	};

	enum ComponentType {
		ComponentType_BYTE = 5120,
		ComponentType_UNSIGNED_BYTE = 5121,
		ComponentType_SHORT = 5122,
		ComponentType_UNSIGNED_SHORT = 5123,
		ComponentType_UNSIGNED_INT = 5125,
		ComponentType_FLOAT = 5126
	};

	std::ostream& operator<<(std::ostream& out, ComponentType value) {
		switch (value) {
			case ComponentType_BYTE:
				out << "ComponentType_BYTE";
				break;
			case ComponentType_UNSIGNED_BYTE:
				out << "ComponentType_UNSIGNED_BYTE";
				break;
			case ComponentType_SHORT:
				out << "ComponentType_SHORT";
				break;
			case ComponentType_UNSIGNED_SHORT:
				out << "ComponentType_UNSIGNED_SHORT";
				break;
			case ComponentType_UNSIGNED_INT:
				out << "ComponentType_UNSIGNED_INT";
				break;
			case ComponentType_FLOAT:
				out << "ComponentType_FLOAT";
				break;
			default:
				out << "ComponentType_NOT_REFERENCED";
				break;
		}

		return out;
	}

	class Accessor : public BlobGL::VertexArrayObject {
	public:
		enum Type {
			SCALAR = 1, VEC2 = 2, VEC3 = 3, VEC4 = 4, MAT2 = 4, MAT3 = 9, MAT4 = 16
		};

		static const size_t NUM_TYPE = 7;

		struct TypeInfo {
			const char *name;
			Type type;
		};

		static const TypeInfo typeInfos[NUM_TYPE];



		static Type getType(const char *str) {
			for(auto typeInfo : typeInfos) {
				if(strcmp(typeInfo.name, str) == 0) {
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
			cout << bufferView;

			addBuffer(bufferView, type, 0, 0);
		}

		friend std::ostream& operator<<(std::ostream &s, const Accessor &a) {

			s << "Accessor {" << std::endl;

			s << "byteOffset : " << a.byteOffset << endl;
			s << "componentType : " << a.componentType << endl;
			s << "count : " << a.count << endl;
			s << "type : " << a.type << endl;

			s << "max : " ;
			for(auto &m : a.max)
				s << m << " ";
			s << endl;

			s << "min : " ;
			for(auto &m : a.min)
				s << m << " ";
			s << endl;

			s << a.bufferView;

			s << "}" << endl;
			return s;
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
				Accessor accessor;

				explicit Attributes(JsonExplorer explorer) {
					accessor.load(explorer.getInt("POSITION"), explorer);
				}

				friend std::ostream& operator<<(std::ostream &s, const Attributes &a) {

					s << "Attributes {" << endl;

					s << a.accessor;

					s << "}" << endl;
					return s;
				}
			};

		public:

			Attributes attributes;

			explicit Primitive(JsonExplorer explorer) : attributes(explorer.getObject("attributes")) {

			}

			friend std::ostream& operator<<(std::ostream &s, const Primitive &a) {

				s << "Primitive {" << endl;

				s << a.attributes;

				s << "}" << endl;
				return s;
			}
		};

		vector<Primitive> primitives;

	public:
		void load(int num, JsonExplorer explorer) {
			//load Json
			explorer.goToBaseNode();

			explorer.goToArrayElement("meshes", num);

			int size = explorer.getArraySize("primitives");

			for (unsigned int i = 0; i < size; i++) {
				primitives.emplace_back(explorer.getArrayObject("primitives", i));
			}
		}

		GLuint getVAO() {
			return primitives[0].attributes.accessor.getVertexArrayObject();
		}

		friend std::ostream& operator<<(std::ostream &s, const Mesh &a) {

			s << "Mesh {" << endl;
			for(auto p : a.primitives)
				s << p;

			s << "}" << endl;
			return s;
		}
	};

	class Shape {
	public:
		vector<Shape> children;
		Mesh mesh;

		// déjà dans Shape
		glm::mat4 matrix{1};
		glm::vec3 translation{};
		glm::vec4 rotation{};
		glm::vec3 scale{};

		ShaderProgram shaderProgram;

		GLint mvpLocation{};

		explicit Shape(int num, JsonExplorer explorer) {
			explorer.goToBaseNode();

			explorer.goToArrayElement("nodes", num);

			mesh.load(explorer.getInt("mesh"), explorer);
		}

		friend std::ostream& operator<<(std::ostream &s, const Shape &a) {
			s << "Shape {" << endl;

			s << glm::to_string(a.matrix) << endl;
			s << glm::to_string(a.translation) << endl;
			s << glm::to_string(a.rotation) << endl;
			s << glm::to_string(a.scale) << endl;
			s << a.mesh;

			s << "}" << endl;
			return s;
		}
	};

	class Scene {
	public:

		vector<Shape> nodes;

		explicit Scene(JsonExplorer explorer) {

			int size = explorer.getArraySize("nodes");

			for (unsigned int i = 0; i < size; i++) {
				nodes.emplace_back(explorer.getArrayInt("nodes", i), explorer);
			}

		}

		Shape* getShape(unsigned int num) {
			return &nodes[num];
		}

		friend std::ostream& operator<<(std::ostream &s, const Scene &a) {
			s << "Scene {" << endl;
			for(const Shape &node : a.nodes)
				s << node;

			s << "}" << endl;
			return s;

		}
	};

	class SceneManager {
	public:

		vector<Scene> scenes;

		int defaultScene = 0;

		JsonExplorer baseNode;
		Asset asset;

		explicit SceneManager(const string &file) :
				baseNode(file),
				asset(baseNode.getObject("asset"))

		{
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

		Scene* getScene(unsigned int num) {
			return &scenes[num];
		}

		friend std::ostream& operator<<(std::ostream &s, const SceneManager &a) {
			s << "SceneManager {" << endl;

			s << a.asset;

			for(const Scene &scene : a.scenes)
				s << scene;

			s << "}" << endl;
			return s;
		}
	};
}

int main(int argc, char *argv[]) {

	try {

		BlobEngine::Graphic graphic(640, 480);

		//BlobEngine::Shape shape("../data/sphere.obj");
		//BlobEngine::Shape shape("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");

		BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");

		//cout << sm;
/*
		BlobEngine::glTF2::Scene *mainScene = sm.getScene(0);

		BlobEngine::glTF2::Shape *triangle = mainScene->getShape(0);

		triangle->shaderProgram.addVertexShader(R"(
#version 410

layout(location = 0) in vec3 vertex_position;
uniform mat4 mvp;
// use z position to shader darker to help perception of distance
out float dist;

void main() {
	gl_Position = mvp * vec4 (vertex_position, 1.0);
	dist = vertex_position.z;//1.0 - (-pos_eye.z / 10.0);
}

		)");

		triangle->shaderProgram.addFragmentShader(R"(
#version 410

in float dist;
out vec4 frag_colour;

void main() {
	frag_colour = vec4 (1.0, 0.0, 0.0, 1.0);
	// use z position to shader darker to help perception of distance
	frag_colour.xyz *= dist;
}
		)");

		triangle->shaderProgram.linkShaders();

		while (graphic.isOpen()) {
			graphic.clear();
*/
			/*float angle = BlobEngine::getTime();

			float mod = std::cos(angle) / 2 + 1;

			shape.setScale(mod, mod, mod);
			shape.setRotation(angle * 40, 0.f, 1.f, 0.f);
			shape.rotate(angle * 40, 1.f, 0.f, 0.f);
			shape.setPosition(0, 1, 0);
			graphic.draw(shape);
*/
			/*
			//shape.setPosition(1, 0, 0);
			graphic.draw(triangle->shaderProgram.getProgram(), triangle->mesh.getVAO(), 0, 9);

			//shape.setPosition(0, 0, 1);
			//graphic.draw(shape);

			graphic.display();

		}
*/
	} catch (BlobException &exception) {
		std::cout << exception.what() << std::endl;
	}

	return 0;
}

