#pragma once

#include "Blob/Maths.hpp"
#include "bgfx/bgfx.h"
#include <Blob/RenderOptions.hpp>
#include <Blob/Shader.hpp>
#include <Blob/Texture.hpp>
#include <Blob/VertexBuffer.hpp>
#include <memory>
#include <string>
#include <unordered_map>

#include <bgfx/platform.h>

namespace Blob {
class Context : private bgfx::CallbackI {
public:
    std::unordered_map<std::string, std::unique_ptr<Shader>> shaders;
    std::unordered_map<std::string, std::unique_ptr<Texture>> textures;
    std::unordered_map<std::string, std::unique_ptr<RenderOptions>> renderOptions;
    std::unordered_map<std::string, std::unique_ptr<VertexBuffer>> vertexBuffers;
    std::unordered_map<std::string, std::unique_ptr<UniformSampler>> uniformSamplers;
    std::unordered_map<std::string, std::unique_ptr<Uniform>> uniforms;

    Context(void *ndt, void *nwh) {
        bgfx::PlatformData pd;
        pd.ndt = ndt;
        pd.nwh = nwh;
        bgfx::setPlatformData(pd);

        bgfx::renderFrame();

        bgfx::Init init;
        init.debug = false;
        init.callback = this;

        if (!bgfx::init(init))
            throw Blob::Exception("Failed to init bgfx");
    }

    ~Context() {
        shaders.clear();
        textures.clear();
        renderOptions.clear();
        vertexBuffers.clear();
        uniformSamplers.clear();
        uniforms.clear();
        bgfx::shutdown();
    }

private:
    void fatal(const char *filePath, uint16_t line, bgfx::Fatal::Enum code, const char *str) final;

    void traceVargs(const char *filePath, uint16_t line, const char *format, va_list argList) final;

    void profilerBegin(const char *name, uint32_t abgr, const char *filePath, uint16_t line) final;

    void profilerBeginLiteral(const char *name,
                              uint32_t abgr,
                              const char *filePath,
                              uint16_t line) final;

    void profilerEnd() final;

    uint32_t cacheReadSize(uint64_t id) final;

    bool cacheRead(uint64_t id, void *data, uint32_t size) final;

    void cacheWrite(uint64_t id, const void *data, uint32_t size) final;

    void screenShot(const char *filePath,
                    uint32_t width,
                    uint32_t height,
                    uint32_t pitch,
                    const void *data,
                    uint32_t size,
                    bool yflip) final;

    void captureBegin(uint32_t width,
                      uint32_t height,
                      uint32_t pitch,
                      bgfx::TextureFormat::Enum format,
                      bool yflip) final;

    void captureEnd() final;

    void captureFrame(const void *data, uint32_t size) final;
};
} // namespace Blob
