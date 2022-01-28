#pragma once
#include <Blob/Materials.hpp>
namespace blenderTest::Materials {
struct Dots_Stroke : public Blob::Materials::PBRSingleColor {
    Dots_Stroke() : Blob::Materials::PBRSingleColor(Blob::Color::RGBA{0.800000011920929, 0.800000011920929, 0.800000011920929, 1.0}){}
};
}
