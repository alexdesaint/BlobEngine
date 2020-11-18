#pragma once

#include <cstdint>
#include <cstddef>

namespace Blob::GL {

template<typename T>
uint32_t getType();

template<>
uint32_t getType<int8_t>();
template<>
uint32_t getType<int16_t>();
template<>
uint32_t getType<int32_t>();
template<>
uint32_t getType<uint8_t>();
template<>
uint32_t getType<uint16_t>();
template<>
uint32_t getType<uint32_t>();
template<>
uint32_t getType<float>();
template<>
uint32_t getType<double>();

size_t getTypeSize(uint32_t type);

} // namespace Blob::GL