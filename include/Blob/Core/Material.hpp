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
template<class ...Args>
class MaterialBase : protected GL::Material {
public:
    /// This function will be called before the draw
    /// \param pt oui
    /// \param vt non
    /// \param mt pas toujours
    virtual void applyMaterial(const Args &...) const = 0;

    virtual ~MaterialBase() = default;
};

typedef MaterialBase<Maths::ProjectionTransform, Maths::ViewTransform, Maths::Mat4> Material;
typedef MaterialBase<Maths::Mat3, Maths::Mat3, Maths::Mat3> Material2D;

} // namespace Blob::Core
