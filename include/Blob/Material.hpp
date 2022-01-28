#pragma once

#include "Blob/Maths.hpp"
#include <Blob/Shader.hpp>
#include <Blob/Texture.hpp>

namespace Blob {
class Window;

/// A combinason of shader, color, texture or array to defines the optical
/// properties of an object.
/**
 * Detailed description.
 * - oui
 * - non
 * # Titre
 * > Citation
 * *gras* **pas gras**
 */
class Material {
public:
    /// This function will be called before the draw
    /// \param pt oui
    /// \param vt non
    /// \param mt pas toujours
    virtual void applyMaterial() const = 0;

    virtual ~Material() = default;
};

} // namespace Blob
