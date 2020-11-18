#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

namespace Blob::glTF2 {
    /**
     * Image data used to create a texture. Image can be referenced by URI or bufferView index. mimeType is required in
     * the latter case.
     */
    class Image {
    public:
        std::string uri; ///< The uri of the image.

        std::string mimeType; ///< The image's MIME type.

        int bufferView = -1; ///< The index of the bufferView that contains the image. Use this instead of the image's uri
        ///< property.

        std::string name; ///< The user-defined name of this object.

        Image(const nlohmann::json &j, const std::string &path);

        friend std::ostream &operator<<(std::ostream &s, const Image &a);
    };
}
