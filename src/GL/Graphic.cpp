//blobEngine
#include <Blob/Exception.hpp>
#include <Blob/GL/Renderable.hpp>
#include <Blob/GL/Graphic.hpp>
#include <Blob/GL/Shapes.hpp>

//std
#include <iostream>

// GLFW
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//glm
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//imgui
#include <imgui.h>

static void GLAPIENTRY openglCallbackFunction(
        GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar *message,
        const void *userParam
) {
    (void) source;
    (void) type;
    (void) id;
    (void) length;
    (void) userParam;

    switch (severity) {
        case GL_DEBUG_SEVERITY_NOTIFICATION :
            //std::cout << "Notification :" << std::endl << message << std::endl;
            break;
        case GL_DEBUG_SEVERITY_LOW:
            std::cout << "Low severity Error :" << std::endl << message;
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            std::cout << "Medium severity Error :" << std::endl << message;
            break;
        case GL_DEBUG_SEVERITY_HIGH:
            std::cout << "High severity Error :" << std::endl << message << std::endl;
            abort();
        default:
            std::cout << "Unknow Error severity :" << std::endl << message;
            break;
    }
}

namespace Blob::GL {

    void framebuffer_size_callback(GLFWwindow *window, int w, int h) {
        auto g = (Graphic *) glfwGetWindowUserPointer(window);
        g->resize(w, h);
    }

    void GLFWErrorCallback(int error, const char *description) {
        std::cout << "GLFW Error " << error << " : " << description;
    }

    void Graphic::enableDebugCallBack() {
        // Enable the debug callback

        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(openglCallbackFunction, nullptr);
        glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
    }

    Graphic::Graphic(bool fullScreen, unsigned int w, unsigned int h) :
            width(w),
            height(h),
            cameraPosition(0, 0, 2),
            cameraLookAt(0, 0, 0),
            cameraUp(0, 0, 1),
            cameraAngle(PI / 4) {

        glfwSetErrorCallback(GLFWErrorCallback);

        static const int GLmajor = 4;
        static const int GLminor = 5;

        if (!glfwInit())
            throw Exception("Can't init glfw");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLmajor);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLminor);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwWindowHint(GLFW_SAMPLES, 8);

        if (fullScreen) {
            const GLFWvidmode *mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwWindowHint(GLFW_RED_BITS, mode->redBits);
            glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
            glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
            glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

            width = mode->width;
            height = mode->height;

            window = glfwCreateWindow(width, height, "My Title", glfwGetPrimaryMonitor(), nullptr);
        } else {
            window = glfwCreateWindow(width, height, "My Title", nullptr, nullptr);
        }

        if (!window) {
            glfwTerminate();
            throw Exception("Can't open window");
        }

        glfwMakeContextCurrent((GLFWwindow *) window);
        glfwSwapInterval(1);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) throw Exception("Fail to load openGL");

        if (GLmajor != GLVersion.major || GLminor != GLVersion.minor)
            throw Exception("Fail to load the right version of OpenGL. Loaded version : " +
                            std::to_string(GLVersion.major) + "." + std::to_string(GLVersion.minor) +
                            " instead of " + std::to_string(GLmajor) + "." + std::to_string(GLminor) +
                            ". System version : " + (char *) glGetString(GL_VERSION));

        enableDebugCallBack();

        //general settings
        glFrontFace(GL_CW);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //pour faire des lignes
        glClearColor(0.2, 0.2, 0.2, 1.0);
        glViewport(0, 0, w, h);
        glCullFace(GL_FRONT);
        //alpha
        glEnable(GL_BLEND);
        glBlendEquation(GL_FUNC_ADD);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        Controls::init(window);

        ImGuiIO &io = ImGui::GetIO();
        io.BackendRendererName = "BlobEngine";

        //user pointer
        glfwSetWindowUserPointer((GLFWwindow *) window, this);
        glfwSetFramebufferSizeCallback((GLFWwindow *) window, framebuffer_size_callback);

        projectionMatrix = glm::perspective(cameraAngle, width / (GLfloat) height, cameraRange.x, cameraRange.y);
        viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);

        //create Froms ans defaults shaders
        Shapes::init();

        //imgui
        projectionMatrix2D =
                {
                        2.0f / (width), 0.0f, 0.0f, 0.0f,
                        0.0f, 2.0f / (-height), 0.0f, 0.0f,
                        0.0f, 0.0f, -1.0f, 0.0f,
                        -1.f, 1.f, 0.0f, 1.0f,
                };
        io.DisplayFramebufferScale = getFrameBufferSize() / getSize();
        io.DisplaySize = getSize();

        io.IniFilename = nullptr;

        imguiFontTexture = new Texture();
        rebuildFontImGUI();

        imguiRenderable = new Renderable();
        imguiRenderable->scissorTest = true;
        imguiRenderable->cullFace = false;
        imguiRenderable->depthTest = false;

        imguiRenderable->setShaderProgram(*Shaders::Shader_2D_POSITION_TEXCOORD_0_COLOR_0);

        imguiRenderable->setArrayVAO(2, "Position", GL_FLOAT, (uint32_t) offsetof(ImDrawVert, pos));
        imguiRenderable->setArrayVAO(2, "TexturePosition", GL_FLOAT, (uint32_t) offsetof(ImDrawVert, uv));
        imguiRenderable->setArrayVAO(4, "Color", GL_UNSIGNED_BYTE, (uint32_t) offsetof(ImDrawVert, col), true);

        lastFrameTime = std::chrono::high_resolution_clock::now();
    }

    Graphic::~Graphic() {
        Shapes::destroy();
        ImGui::DestroyContext();
        delete imguiFontTexture;
        delete imguiRenderable;

        glfwDestroyWindow((GLFWwindow *) window);
        glfwTerminate();
    }

    void Graphic::clear() {
        glDisable(GL_SCISSOR_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }

    float Graphic::display() {
        glfwSwapBuffers((GLFWwindow *) window);

        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> diff = now - lastFrameTime;
        ImGui::GetIO().DeltaTime = diff.count();
        fpsCouner = fpsCouner + diff;
        lastFrameTime = now;

        if (!(++frameCount % 60)) {
            std::string name = "Test : " + std::to_string(60 / fpsCouner.count()) + " FPS";
            fpsCouner = std::chrono::duration<float>::zero();
            glfwSetWindowTitle((GLFWwindow *) window, name.c_str());
        }

        glfwPollEvents();
        Controls::updateControllers();

        timeF = diff.count();
        return timeF;
    }

    void Graphic::resize(unsigned int w, unsigned int h) {
        height = h;
        width = w;

        projectionMatrix = glm::perspective(cameraAngle, width / (GLfloat) height, cameraRange.x, cameraRange.y);

        projectionMatrix2D =
                {
                        2.0f / (width), 0.0f, 0.0f, 0.0f,
                        0.0f, 2.0f / (-height), 0.0f, 0.0f,
                        0.0f, 0.0f, -1.0f, 0.0f,
                        -1.f, 1.f, 0.0f, 1.0f,
                };

        glViewport(0, 0, w, h);

        int ww, hh;
        glfwGetWindowSize((GLFWwindow *) window, &ww, &hh);

        if (ww != w || hh != h)
            glfwSetWindowSize((GLFWwindow *) window, w, h);

        ImGuiIO &io = ImGui::GetIO();
        io.DisplayFramebufferScale = getFrameBufferSize() / getSize();
        io.DisplaySize = getSize();
    }

    std::ostream &operator<<(std::ostream &out, const glm::mat4 &vec) {

        for (int i = 0; i < 4; i++)
            out << vec[i].x << " " << vec[i].y << " " << vec[i].z << " " << vec[i].w << std::endl;
        return out;
    }

    void Graphic::draw(const Renderable &renderable, glm::mat4 shapeModel) {
        if (renderable.shaderProgram == nullptr)
            throw Exception("Error on Graphic::draw : No shader program set");

        if (renderable.cullFace)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);

        if (renderable.scissorTest)
            glEnable(GL_SCISSOR_TEST);
        else
            glDisable(GL_SCISSOR_TEST);

        if (renderable.depthTest)
            glEnable(GL_DEPTH_TEST);
        else
            glDisable(GL_DEPTH_TEST);


        glUseProgram(renderable.shaderProgram->getProgram());
        glBindVertexArray(renderable.vao.getVertexArrayObject());

        glUniformMatrix4fv(renderable.shaderProgram->projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
        glUniformMatrix4fv(renderable.shaderProgram->view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
        glUniformMatrix4fv(renderable.shaderProgram->model, 1, GL_FALSE,
                           glm::value_ptr(shapeModel * renderable.getModelMatrix()));

        if (renderable.texture != nullptr) {
            glBindTexture(GL_TEXTURE_2D, renderable.texture->texture);
            glUniform2f(renderable.shaderProgram->textureScale, renderable.textureScale.x,
                        renderable.textureScale.y);
        }

        if (renderable.indexed)
            glDrawElements(GL_TRIANGLES, renderable.numOfIndices, renderable.indicesType, renderable.indices);
        else
            glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Graphic::draw(const Renderable &renderable, int numOfElements, uint64_t elementOffset, glm::mat4 shapeModel) {

        if (renderable.shaderProgram == nullptr)
            throw Exception("Error on Graphic::draw : No shader program set");

        if (renderable.cullFace)
            glEnable(GL_CULL_FACE);
        else
            glDisable(GL_CULL_FACE);

        if (renderable.scissorTest)
            glEnable(GL_SCISSOR_TEST);
        else
            glDisable(GL_SCISSOR_TEST);

        if (renderable.depthTest)
            glEnable(GL_DEPTH_TEST);
        else
            glDisable(GL_DEPTH_TEST);

        glUseProgram(renderable.shaderProgram->getProgram());
        glBindVertexArray(renderable.vao.getVertexArrayObject());

        glUniformMatrix4fv(renderable.shaderProgram->projection, 1, GL_FALSE, glm::value_ptr(projectionMatrix2D));
        glUniformMatrix4fv(renderable.shaderProgram->view, 1, GL_FALSE, glm::value_ptr(viewMatrix));
        glUniformMatrix4fv(renderable.shaderProgram->model, 1, GL_FALSE,
                           glm::value_ptr(shapeModel * renderable.getModelMatrix()));

        if (renderable.texture != nullptr) {
            glBindTexture(GL_TEXTURE_2D, renderable.texture->texture);
            glUniform2f(renderable.shaderProgram->textureScale, renderable.textureScale.x,
                        renderable.textureScale.y);
        }

        if (renderable.indexed)
            glDrawElements(GL_TRIANGLES, numOfElements, renderable.indicesType, &renderable.indices[elementOffset]);
        else
            glDrawArrays(GL_TRIANGLES, elementOffset, numOfElements);
    }

    void Graphic::draw(const Shape &shape, glm::mat4 sceneModel) {
        glm::mat4 modelMatrix = sceneModel * shape.getModelMatrix();

        /*std::cout << "mat :" << std::endl << modelMatrix;

        std::cout << "r :" << std::endl;
        for(Renderable *r : shape.renderables)
            std::cout << std::hex << r << " ";
        std::cout << std::endl;
*/
        for (auto r : shape.shapes)
            draw(*r, modelMatrix);

        for (auto r : shape.renderables)
            draw(*r, modelMatrix);
    }

    void Graphic::draw(const Scene &scene) {
        glm::mat4 modelMatrix = scene.getModelMatrix();
/*
		std::cout << "mat :" << std::endl << modelMatrix;

		std::cout << "r :" << std::endl;
		for(Shape *r : scene.shapes)
			std::cout << std::hex << r << " ";
		std::cout << std::endl;
*/
        for (auto r : scene.shapes)
            draw(*r, modelMatrix);
    }

    void Graphic::drawImGUI() {
        ImGui::Render();
        ImDrawData *drawData = ImGui::GetDrawData();

        ImGuiIO &io = ImGui::GetIO();

        VertexBufferObject imguiVBO;

        drawData->ScaleClipRects(io.DisplayFramebufferScale);

        int fb_height = (int) (drawData->DisplaySize.y * io.DisplayFramebufferScale.y);
        //

        unsigned int sizeTot = 0;
        for (int n = 0; n < drawData->CmdListsCount; n++) {
            const ImDrawList *cmd_list = drawData->CmdLists[n];

            sizeTot += cmd_list->VtxBuffer.Size;
        }

        if (sizeTot > 0)
            imguiVBO.setData(nullptr, sizeTot * sizeof(ImDrawVert), true);

        unsigned int offset = 0;

        for (int n = 0; n < drawData->CmdListsCount; n++) {
            ImDrawList *cmd_list = drawData->CmdLists[n];
            size_t idx_buffer_offset = 0;

            imguiVBO.setSubData((uint8_t *) cmd_list->VtxBuffer.Data, cmd_list->VtxBuffer.Size * sizeof(ImDrawVert),
                                offset * sizeof(ImDrawVert));

            imguiRenderable->setBuffer(imguiVBO, sizeof(ImDrawVert), offset * sizeof(ImDrawVert));

            imguiRenderable->setIndices(cmd_list->IdxBuffer.Data, cmd_list->IdxBuffer.Size, GL_UNSIGNED_SHORT);

            for (int cmd_i = 0; cmd_i < cmd_list->CmdBuffer.Size; cmd_i++) {
                const ImDrawCmd *pcmd = &cmd_list->CmdBuffer[cmd_i];

                glScissor((int) pcmd->ClipRect.x, (int) (fb_height - pcmd->ClipRect.w),
                          (int) (pcmd->ClipRect.z - pcmd->ClipRect.x), (int) (pcmd->ClipRect.w - pcmd->ClipRect.y));

                imguiRenderable->setTexture(*(Texture *) pcmd->TextureId);
                draw(*imguiRenderable, pcmd->ElemCount, idx_buffer_offset);

                idx_buffer_offset += pcmd->ElemCount;
            }
        }
    }

    void Graphic::rebuildFontImGUI() {
        unsigned char *pixels;
        int w, h;
        ImGuiIO &io = ImGui::GetIO();
        io.Fonts->GetTexDataAsRGBA32(&pixels, &w, &h);
        imguiFontTexture->setRGBA32data(pixels, w, h);
        io.Fonts->TexID = (ImTextureID) imguiFontTexture;
        if (!io.Fonts->IsBuilt())
            throw Exception("imgui Fonts not build");
    }

    bool Graphic::isOpen() const {
        return !(glfwWindowShouldClose((GLFWwindow *) window) || quit);
    }

    std::ostream &operator<<(std::ostream &s, const Graphic &a) {
        s << glGetString(GL_VENDOR) << std::endl <<
          glGetString(GL_RENDERER) << std::endl <<
          glGetString(GL_VERSION) << std::endl <<
          glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
        return s;
    }

    void Graphic::setCameraPosition(float x, float y, float z) {
        cameraPosition = glm::vec3(x, y, z);

        viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
    }

    void Graphic::setCameraRange(Blob::Vec2f range) {
        cameraRange = range;

        projectionMatrix = glm::perspective(cameraAngle, width / (GLfloat) height, cameraRange.x, cameraRange.y);
    }

    void Graphic::setCameraLookAt(float x, float y, float z) {
        cameraLookAt = glm::vec3(x, y, z);

        viewMatrix = glm::lookAt(cameraPosition, cameraLookAt, cameraUp);
    }

    void Graphic::setCameraAngle(float camAngle) {
        Graphic::cameraAngle = camAngle;
        projectionMatrix = glm::perspective(camAngle, width / (GLfloat) height, cameraRange.x, cameraRange.y);
    }

    void Graphic::setOrthoProjection(float left, float right, float bottom, float top, float zNear, float zFar) {
        projectionMatrix = glm::ortho(left, right, bottom, top, zNear, zFar);
    }

    std::array<float, 3> Graphic::getWorldPosition() {
        ImGuiIO &io = ImGui::GetIO();

        Vec2f mousePos = io.MousePos;
        mousePos = mousePos / getSize() * 2;
        mousePos.x = mousePos.x - 1;
        mousePos.y = 1 - mousePos.y;

        /*//Look at test
        glm::vec4 posCamera(50, 50, 15, 1);

        ImGui::Text("World pos : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
        posCamera = (projectionMatrix * viewMatrix) * posCamera;
        ImGui::Text("camera pos : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
        posCamera = posCamera / posCamera.w;
        ImGui::Text("camera rerange : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, (posCamera.z + 1) / 2);
        posCamera = glm::inverse(projectionMatrix * viewMatrix) * posCamera;
        ImGui::Text("inverse : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
        posCamera = posCamera / posCamera.w;
        ImGui::Text("inverse rerange : %.3f, %.3f, %.3f", posCamera.x, posCamera.y, posCamera.z);
        //
        */

        float z;

        glReadPixels((int) io.MousePos.x, height - (int) io.MousePos.y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &z);

        z = (z * 2) - 1;

        glm::vec4 pos(mousePos.x, mousePos.y, z, 1);

        pos = glm::inverse(projectionMatrix * viewMatrix) * pos;
        pos = pos / pos.w;

        return {pos.x, pos.y, pos.z};
    }

    Blob::Vec2f Graphic::getFrameBufferSize() {
        int display_w, display_h;
        glfwGetFramebufferSize((GLFWwindow *) window, &display_w, &display_h);
        return {(float) display_w, (float) display_h};
    }

    void Graphic::close() {
        quit = true;
    }
}

float Blob::GL::Graphic::timeF = 0;
const float &Blob::GL::Graphic::timeFlow = timeF;