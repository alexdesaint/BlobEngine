#include <Blob/Geometrie.hpp>

namespace Blob::Maths {
bool Rectangle::overlapBigger(const Rectangle &r) const {

    float xdiff = size.x / 2;
    float ydiff = size.y / 2;
    float rxdiff = r.size.x / 2;
    float rydiff = r.size.y / 2;

    return ((position.x - xdiff <= r.position.x + rxdiff) && (position.x - xdiff >= r.position.x - rxdiff) &&
            (position.y - ydiff <= r.position.y + rydiff) && (position.y - ydiff >= r.position.y - rydiff)) ||
           ((position.x + xdiff <= r.position.x + rxdiff) && (position.x + xdiff >= r.position.x - rxdiff) &&
            (position.y - ydiff <= r.position.y + rydiff) && (position.y - ydiff >= r.position.y - rydiff)) ||
           ((position.x - xdiff <= r.position.x + rxdiff) && (position.x - xdiff >= r.position.x - rxdiff) &&
            (position.y + ydiff <= r.position.y + rydiff) && (position.y + ydiff >= r.position.y - rydiff)) ||
           ((position.x + xdiff <= r.position.x + rxdiff) && (position.x + xdiff >= r.position.x - rxdiff) &&
            (position.y + ydiff <= r.position.y + rydiff) && (position.y + ydiff >= r.position.y - rydiff));
}

std::list<Vec2i> Rectangle::rasterize() {
    std::list<Vec2i> points;
    int startx = (int) (position.x - size.x / 2);
    int endx = (int) (position.x + size.x / 2);
    int starty = (int) (position.y - size.y / 2);
    int endy = (int) (position.y + size.y / 2);

    for (int i = startx; i <= endx; i++) {
        for (int j = starty; j <= endy; j++)
            points.emplace_back(i, j);
    }

    return points;
}

std::array<Vec2f, 4> Rectangle::getPoints() {
    return {position + size / 2, position - size / 2, position + size.rotate() / 2, position - size.rotate() / 2};
}

bool Rectangle::overlap(const Rectangle &r) {
    return r.overlapBigger(*this) || overlapBigger(r);
}
bool Rectangle::overlap(const Circle &r) {
    return false;
}
bool Rectangle::overlap(const Line &r) {
    return false;
}

/*const Point2f &Rectangle::getPosition() const {
    return position;
}

const Vec2f &Rectangle::getSize() const {
    return size;
}

void Rectangle::setPosition(const Point2f &position) {
    Rectangle::position = position;
}

void Rectangle::setSize(const Vec2f &size) {
    Rectangle::size = size;
}*/

} // namespace Blob::Maths