//blobEngine
#include <Blob/GL/Graphic.hpp>

namespace Blob::GL {

    // TODO: ?????????????
    /*
    std::ostream &operator<<(std::ostream &out, const glm::mat4 &vec) {

        for (int i = 0; i < 4; i++)
            out << vec[i].x << " " << vec[i].y << " " << vec[i].z << " " << vec[i].w << std::endl;
        return out;
    }

    void Graphic::draw(const Shape &shape, glm::mat4 sceneModel) {
        glm::mat4 modelMatrix = sceneModel * shape.getModelMatrix();

        /*std::cout << "mat :" << std::endl << modelMatrix;

        std::cout << "r :" << std::endl;
        for(Renderable *r : shape.renderables)
            std::cout << std::hex << r << " ";
        std::cout << std::endl;

        for (auto r : shape.shapes)
            draw(*r, modelMatrix);

        for (auto r : shape.renderables)
            draw(*r, modelMatrix);
    }

    void Graphic::draw(const Scene &scene) {
        glm::mat4 modelMatrix = scene.getModelMatrix();

		std::cout << "mat :" << std::endl << modelMatrix;

		std::cout << "r :" << std::endl;
		for(Shape *r : scene.shapes)
			std::cout << std::hex << r << " ";
		std::cout << std::endl;

        for (auto r : scene.shapes)
            draw(*r, modelMatrix);
    }
*/
}
