#include <BlobEngine/BlobGL/Graphic.hpp>
#include <BlobEngine/Shape.hpp>

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

#include <glm/mat4x4.hpp>

using namespace std;

namespace BlobEngine::glTF2 {

	class Asset {
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
				Accessor accessor;

				explicit Attributes(JsonExplorer explorer) {
					accessor.load(explorer.getInt("POSITION"), explorer);
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
	};

	class Shape {
	public:
		vector<Shape> children;
		Mesh mesh;

		// déjà dans Shape
		glm::mat4 matrix{};
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
	};

	class SceneManager {
	public:

		vector<Scene> scenes;

		int defaultScene = 0;

		explicit SceneManager(const string &file) {

			JsonExplorer baseNode(file);

			Asset a(baseNode.getObject("asset"));

			if (baseNode.hasMember("asset"))
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

		Scene* getScene(unsigned int num) {
			return &scenes[num];
		}
	};
}

int main(int argc, char *argv[]) {

	try {

		BlobEngine::Graphic graphic(640, 480);

		//BlobEngine::Shape shape("../data/sphere.obj");
		//BlobEngine::Shape shape("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");

		BlobEngine::glTF2::SceneManager sm("../../gitClone/glTF-Sample-Models/2.0/TriangleWithoutIndices/glTF/TriangleWithoutIndices.gltf");

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

			/*float angle = BlobEngine::getTime();

			float mod = std::cos(angle) / 2 + 1;

			shape.setScale(mod, mod, mod);
			shape.setRotation(angle * 40, 0.f, 1.f, 0.f);
			shape.rotate(angle * 40, 1.f, 0.f, 0.f);
			shape.setPosition(0, 1, 0);
			graphic.draw(shape);
*/
			//shape.setPosition(1, 0, 0);
			graphic.draw(triangle->shaderProgram.getProgram(), triangle->mesh.getVAO(), 0, 9);

			//shape.setPosition(0, 0, 1);
			//graphic.draw(shape);

			graphic.display();

		}

	} catch (BlobException &exception) {
		std::cout << exception.what() << std::endl;
	}

	return 0;
}

