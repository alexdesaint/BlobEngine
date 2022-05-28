#pragma once

#include "bgfx/bgfx.h"
#include <Blob/Material.hpp>
#include <Blob/RenderOptions.hpp>
#include <Blob/Shader.hpp>
#include <Blob/Texture.hpp>
#include <Blob/VertexBuffer.hpp>
#include <memory>
#include <string>
#include <unordered_map>

#include <bgfx/platform.h>

namespace Blob {
class Context {
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

        if (!bgfx::init())
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
};
} // namespace Blob
