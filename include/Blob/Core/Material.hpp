#pragma once

#include <Blob/Core/Shader.hpp>
#include <Blob/Core/Texture.hpp>
#include <Blob/GL/Material.hpp>

namespace Blob::Core {
class Window;

/// A combinason of shader, color, texture or array to defines the optical properties of an object.
/**
 * Detailed description.
 * - oui
 * - non
 * # Titre
 * > Citation
 * *gras* **pas gras**
 */
class Material : protected GL::Material {
public:

    /// This function will be called before the draw
    /// \param pt oui
    /// \param vt non
    /// \param mt pas toujours
    virtual void applyMaterial(const Maths::ProjectionTransform &pt, const Maths::ViewTransform &vt, const Maths::Mat4 &mt) const = 0;

    virtual ~Material() = default;
};

} // namespace Blob::Core

