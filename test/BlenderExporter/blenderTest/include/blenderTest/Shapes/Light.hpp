#pragma once
#include <Blob/Shape.hpp>
#include <blenderTest/Meshes.hpp>
namespace blenderTest::Shapes {
struct Light : public Blob::Shape {
    Light(Blob::Context &context): , Blob::Shape(Blob::ModelTransform{{-0.29086464643478394, -0.7711008191108704, 0.5663931965827942, 4.076245307922363}, {0.9551711678504944, -0.1998833566904068, 0.21839119493961334, 1.0054539442062378}, {-0.05518905818462372, 0.6045247316360474, 0.7946722507476807, 5.903861999511719}, {0.0, 0.0, 0.0, 1.0}}){}
};
}
