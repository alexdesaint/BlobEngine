#include <Blob/glTF2/SceneManager.hpp>

#include <Blob/Reader/FileReader.hpp>

#include <iostream>
#include <fstream>

using namespace std;

using json = nlohmann::json;

/*
 * use https://github.com/KhronosGroup/glTF/tree/master/specification/2.0#properties-reference
 *
 * scene --> Shape
 * node --> Shape
 * mesh
 *   primitive --> renderable
 * accessor
 * bufferView--> VBO
 * buffer --> FileReader
 *
 *  Current status :
    accessor                    Done
        sparse                  Todo
            indices             Todo
            values              Todo
    animation                   Todo
        animation sampler       Todo
        channel                 Todo
            target              Todo
    asset                       Done
    buffer                      Done
    bufferView                  Done
    camera                      Todo
        orthographic            Todo
        perspective             Todo
    extension                   not to be done
    extras                      not to be done
    image                       Done
    material                    Done
        normalTextureInfo       Done
        occlusionTextureInfo    Done
        pbrMetallicRoughness    Done
    mesh                        Done
        primitive               Done
    node                        Done
    sampler                     Done
    scene                       Done
    skin                        Todo
    texture                     Done
    textureInfo                 Done

 */

namespace Blob::glTF2 {

    void from_json(const nlohmann::json &j, SceneManager &p) {
    }

    SceneManager::SceneManager(const std::string &file) {

        std::ifstream i(file);
        json j;
        i >> j;

        std::string path = Reader::FileReader::getFilePath(file);

        //version check
        asset.load(j["asset"]);

        // buffer part
        for (const json &js : j["buffers"])
            buffers.emplace_back(js, path);

        for (const json &js : j["bufferViews"])
            bufferViews.emplace_back(js, buffers);

        // material part
        for (const json &js : j["images"])
            images.emplace_back(js, path);

        for (const json &js : j["samplers"])
            samplers.emplace_back(js);

        for (const json &js : j["textures"])
            textures.emplace_back(js, images, samplers);

        for (const json &js : j["materials"])
            materials.emplace_back(js, textures);

        // model part
        for (const json &js : j["accessors"])
            accessors.emplace_back(js, bufferViews);

        for (const json &js : j["meshes"])
            meshes.emplace_back(js, accessors, materials);

        for (const json &js : j["nodes"])
            nodes.emplace_back(js, meshes);

        for (auto &s : nodes)
            s.setChildren(nodes);

        for (const json &js : j["scenes"])
            scenes.emplace_back(js, nodes);

        createVBO();
    }

    std::ostream &operator<<(std::ostream &s, const SceneManager &a) {
		s << "SceneManager {" << endl;

		s << a.asset;

        // buffer part
        for (const auto &b : a.buffers)
            s << b;

        for (const auto &b : a.bufferViews)
            s << b;

        // material part
        for (const auto &b : a.images)
            s << b;

        for (const auto &b : a.samplers)
            s << b;

        for (const auto &b : a.textures)
            s << b;

        for (const auto &b : a.materials)
            s << b;

        // model part
        for (const auto &b : a.accessors)
            s << b;

        for (const auto &b : a.meshes)
            s << b;

        for (const auto &b : a.nodes)
            s << b;

        for (const auto &b : a.scenes)
            s << b;

		s << "}" << endl;
		return s;
	}


    void SceneManager::createVBO() {
        //get the size of the buffer

        size_t size = 0;
        for (const auto &m : meshes) {
            for (const auto &p : m.primitives) {

            	// indices :
                if(p.indices != -1)
                    size += accessors[p.indices].bufferViewIt->byteLength;

                // attributes :
                for (const auto &a : p.attributes)
                    size += accessors[a.second].bufferViewIt->byteLength;
            }
        }

        cout << "VBO creation" << endl;
        cout << "size : " << size << endl;

        //local buffer creation
        vector<uint8_t> buffer(size);
        size_t cursor = 0;

        //buffer assign values :
        for (const auto &m : meshes) {
            for (const auto &p : m.primitives){

            	// Reading indices :
                if(p.indices != -1) {
                    Reader::FileReader fileReader(accessors[p.indices].bufferViewIt->bufferIt->uri);

                    fileReader.goTo(accessors[p.indices].bufferViewIt->byteOffset + accessors[p.indices].byteOffset);

                    // set cursor as new offset
                    // TODO

                    for (int i = 0; i < accessors[p.indices].count * accessors[p.indices].type; i++)
                        buffer[cursor] = fileReader.readNextByte();
                }

                // Reading Data :
				for (const auto &a : p.attributes) {
					// TODO
				}
            }
        }
    }
}
