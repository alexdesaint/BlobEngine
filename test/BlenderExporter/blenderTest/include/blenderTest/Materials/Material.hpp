#pragma once
#include <Blob/Materials.hpp>
namespace blenderTest::Materials {
struct Material : public Blob::Materials::PBRSingleColor {
    Material() : Blob::Materials::PBRSingleColor(Blob::Color::RGBA{0.800000011920929, 0.800000011920929, 0.800000011920929, 1.0}){}
};
}
