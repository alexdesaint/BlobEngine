#ifndef BLOBENGINE_GRAPHIC_HPP
#define BLOBENGINE_GRAPHIC_HPP

#include <Blob/GL/ShaderProgram.hpp>
#include <Blob/GL/VertexArrayObject.hpp>
#include <Blob/GL/Scene.hpp>
#include <Blob/Geometrie.hpp>
#include <Blob/Controls.hpp>

#include <glm/mat4x4.hpp>

#include <ostream>
#include <chrono>
#include <array>

namespace Blob::GL {

    class Graphic {
    private:

        bool quit = false;
        unsigned int frameCount = 0;

        void *window;

        int width, height;

        glm::mat4 projectionMatrix{};
        glm::mat4 projectionMatrix2D{};
        glm::mat4 viewMatrix{};

        //view matrix
        glm::vec3 cameraPosition; // Camera position in World Space
        glm::vec3 cameraLookAt; // and looks at the origin
        glm::vec3 cameraUp;  // Head is up (set to 0,-1,0 to look upside-down)

        //projection matrix
        Vec2f cameraRange = {1, 100};
        float cameraAngle;

        //imgui
        Texture *imguiFontTexture;
        Renderable *imguiRenderable;

        std::chrono::high_resolution_clock::time_point lastFrameTime;
        std::chrono::duration<float> fpsCouner{0};

        void enableDebugCallBack();

    public:
        explicit Graphic(bool fullScreen = true, unsigned int w = 800, unsigned int h = 450);

        ~Graphic();

        void clear();

        float display();

        void resize(unsigned int w, unsigned int h);

        Blob::Vec2f getSize() { return {(float) width, (float) height}; }

        void draw(const Renderable &renderable, glm::mat4 shapeModel = glm::mat4(1.0));

        void
        draw(const Renderable &renderable, int numOfElements, uint64_t offset, glm::mat4 shapeModel = glm::mat4(1.0));

        void draw(const Shape &shape, glm::mat4 sceneModel = glm::mat4(1.0));

        void draw(const Scene &scene);

        void drawImGUI();

        void rebuildFontImGUI();

        bool isOpen() const;

        friend std::ostream &operator<<(std::ostream &s, const Graphic &a);

        void setCameraPosition(float x, float y, float z);

        void setCameraRange(Vec2f range);

        void setCameraLookAt(float x, float y, float z);

        void setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar);

        void setCameraAngle(float cameraAngle);

        std::array<float, 3> getWorldPosition();

        Blob::Vec2f getFrameBufferSize();

        void close();
    };
}

#endif //BLOBENGINE_GRAPHIC_HPP