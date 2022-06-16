#pragma once
#include <Blob/Shape.hpp>
#include <blenderTest/Meshes.hpp>
namespace blenderTest::Shapes {
struct Camera {
    constexpr static std::string_view name{"Camera"};
    constexpr static std::string_view getStringProperties(std::string_view key)    {
        return "";
    }
    static Blob::Shape get(Blob::Context &context)    {
        return {
            {
            },
            {
                {0.6859206557273865, -0.32401347160339355, 0.6515582203865051, 7.358891487121582},
                {0.7276763319969177, 0.305420845746994, -0.6141703724861145, -6.925790786743164},
                {0.0, 0.8953956365585327, 0.44527140259742737, 4.958309173583984},
                {0.0, 0.0, 0.0, 1.0},
            },
        };
    }
};
}
