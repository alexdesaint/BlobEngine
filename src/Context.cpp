#include "bx/file.h"
#include <Blob/Context.hpp>

#include <bx/debug.h>

namespace Blob {

void Context::fatal(const char *_filePath, uint16_t _line, bgfx::Fatal::Enum _code, const char *_str) {
    bx::debugPrintf("Fatal error: 0x%08x: %s", _code, _str);

    if (bgfx::Fatal::DebugCheck == _code) {
        bx::debugBreak();
    } else {
        abort();
    }
}

void Context::traceVargs(const char *_filePath, uint16_t _line, const char *_format, va_list _argList) {
    // bx::debugPrintf("%s (%d): ", _filePath, _line);
    // bx::debugPrintfVargs(_format, _argList);
}

void Context::profilerBegin(const char *name, uint32_t abgr, const char *filePath, uint16_t line) {}

void Context::profilerBeginLiteral(const char *name, uint32_t abgr, const char *filePath, uint16_t line) {}

void Context::profilerEnd() {}

uint32_t Context::cacheReadSize(uint64_t id) { return 0; }

bool Context::cacheRead(uint64_t id, void *data, uint32_t size) { return false; }

void Context::cacheWrite(uint64_t id, const void *data, uint32_t size) {}

void Context::screenShot(const char *_filePath,
                         uint32_t _width,
                         uint32_t _height,
                         uint32_t _pitch,
                         const void *_data,
                         uint32_t _size,
                         bool _yflip) {
    const int32_t len = strlen(_filePath) + 5;
    char *filePath = (char *) alloca(len);
    bx::strCopy(filePath, len, _filePath);
    bx::strCat(filePath, len, ".tga");

    bx::FileWriter writer;
    if (bx::open(&writer, filePath)) {
        // bimg::imageWriteTga(&writer, _width, _height, _pitch, _data, false, _yflip);
        bx::close(&writer);
    }
}

void Context::captureBegin(uint32_t width,
                           uint32_t height,
                           uint32_t pitch,
                           bgfx::TextureFormat::Enum format,
                           bool yflip) {
    BX_TRACE("Warning: using capture without callback (a.k.a. pointless).");
}

void Context::captureEnd() {}

void Context::captureFrame(const void *data, uint32_t size) {}

} // namespace Blob
