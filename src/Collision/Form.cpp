#include <Blob/Collision/Forms.hpp>

namespace Blob {

typedef Vec2<> vec2;

//-----------------------------------------------------------------------------
// Triple product expansion is used to calculate perpendicular normal vectors
// which kinda 'prefer' pointing towards the Origin in Minkowski space

vec2 tripleProduct(vec2 a, vec2 b, vec2 c) {

    //    vec2 r;

    //    float ac = a.x * c.x + a.y * c.y; // perform a.dot(c)
    //    float bc = b.x * c.x + b.y * c.y; // perform b.dot(c)

    // perform b * a.dot(c) - a * b.dot(c)
    //    r.x = b.x * ac - a.x * bc;
    //    r.y = b.y * ac - a.y * bc;
    return b * a.dot(c) - a * b.dot(c);
}

//-----------------------------------------------------------------------------
// This is to compute average center (roughly). It might be different from
// Center of Gravity, especially for bodies with nonuniform density,
// but this is ok as initial direction of simplex search in GJK.

vec2 Form::average() const {
    vec2 avg = {};
    for (const auto &p : vertices)
        avg += p;
    avg /= vertices.size();
    return avg;
}

//-----------------------------------------------------------------------------
// Get furthest vertex along a certain direction

size_t indexOfFurthestPoint(const vec2 *vertices, size_t count, vec2 d) {

    float maxProduct = d.dot(vertices[0]);
    size_t index = 0;
    for (size_t i = 1; i < count; i++) {
        float product = d.dot(vertices[i]);
        if (product > maxProduct) {
            maxProduct = product;
            index = i;
        }
    }
    return index;
}

//-----------------------------------------------------------------------------
// Minkowski sum support function for GJK

vec2 support(const vec2 *vertices1,
             size_t count1,
             const vec2 *vertices2,
             size_t count2,
             vec2 d) {

    // get furthest point of first body along an arbitrary direction
    size_t i = indexOfFurthestPoint(vertices1, count1, d);

    // get furthest point of second body along the opposite direction
    size_t j = indexOfFurthestPoint(vertices2, count2, d.negate());

    // subtract (Minkowski sum) the two points to see if bodies 'overlap'
    return vertices1[i] - vertices2[j];
}

//-----------------------------------------------------------------------------
// The GJK yes/no test

bool Form::overlap(const Form &form) const {
    const vec2 *vertices1 = vertices.data();
    size_t count1 = vertices.size();
    const vec2 *vertices2 = form.vertices.data();
    size_t count2 = form.vertices.size();

    size_t index = 0; // index of current vertex of simplex
    vec2 a, b, c, d, ao, ab, ac, abperp, acperp, simplex[3];

    vec2 position1 = average();      // not a CoG but
    vec2 position2 = form.average(); // it's ok for GJK )

    // initial direction from the center of 1st body to the center of 2nd body
    d = position1 - position2;

    // if initial direction is zero – set it to any arbitrary axis (we choose X)
    if ((d.x == 0) && (d.y == 0))
        d.x = 1.f;

    // set the first support as initial point of the new simplex
    a = simplex[0] = support(vertices1, count1, vertices2, count2, d);

    if (a.dot(d) <= 0)
        return false; // no collision

    d = a.negate(); // The next search direction is always towards the origin,
                    // so the next search direction is negate(a)

    while (true) {
        //        iter_count++;

        a = simplex[++index] = support(vertices1, count1, vertices2, count2, d);

        if (a.dot(d) <= 0)
            return 0; // no collision

        ao = a.negate(); // from point A to Origin is just negative A

        // simplex has 2 points (a line segment, not a triangle yet)
        if (index < 2) {
            b = simplex[0];
            ab = b - a;                    // from point A to B
            d = tripleProduct(ab, ao, ab); // normal to AB towards Origin
            if (d.length2() == 0)
                d = ab.rotate();
            continue; // skip to next iteration
        }

        b = simplex[1];
        c = simplex[0];
        ab = b - a; // from point A to B
        ac = c - a; // from point A to C

        acperp = tripleProduct(ab, ac, ac);

        if (acperp.dot(ao) >= 0) {

            d = acperp; // new direction is normal to AC towards Origin

        } else {

            abperp = tripleProduct(ac, ab, ab);

            if (abperp.dot(ao) < 0)
                return true; // collision

            simplex[0] = simplex[1]; // swap first element (point C)

            d = abperp; // new direction is normal to AB towards Origin
        }

        simplex[1] = simplex[2]; // swap element in the middle (point B)
        --index;
    }

    return 0;
}

} // namespace Blob
