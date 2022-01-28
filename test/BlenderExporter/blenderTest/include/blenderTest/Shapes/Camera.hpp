#pragma once
#include <Blob/Shape.hpp>
namespace blenderTest::Shapes {
struct Camera : public Blob::Shape {
    Camera() :
        Blob::Shape(Blob::ModelTransform{
            {0.6859206557273865,
             -0.32401347160339355,
             0.6515582203865051,
             7.358891487121582},
            {0.7276763319969177,
             0.305420845746994,
             -0.6141703724861145,
             -6.925790786743164},
            {0.0, 0.8953956365585327, 0.44527140259742737, 4.958309173583984},
            {0.0, 0.0, 0.0, 1.0}}) {}
};
} // namespace blenderTest::Shapes
