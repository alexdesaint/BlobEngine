#include <BomberBlob/Explosion.hpp>

using namespace sf;

bool Explosion::update() {
	if(!arrived) {
		if(b2Distance(positionInitial, getPositionb2()) > distanceMax) {
			arrived = true;
			setSpeed(b2Vec2());
		}
	}

	return clock.getElapsedTime().asSeconds() > 0.75f;
}

Explosion::Explosion(b2Vec2 positionInitial, b2Vec2 dirrection, float distanceMax, b2World *world) :
		distanceMax(distanceMax),
		positionInitial(positionInitial),
		DynamicCircle(positionInitial.x, positionInitial.y, 4, &userData, world){

	dirrection.Normalize();
	dirrection *= maxSpeed;
	setSpeed(dirrection);

	rayon = 4;

	shape.setRadius(rayon);
	shape.setOrigin(rayon, rayon);
	shape.setPosition(Vector2f(positionInitial.x, positionInitial.y));
	shape.setFillColor(Color::Red);
	//shape.setTexture(&texture);

	rectShape.setSize(Vector2f(8, 8));
	rectShape.setPosition(Vector2f(positionInitial.x, positionInitial.y));
	rectShape.setOrigin(Vector2f(4, 4));
	rectShape.setRotation(std::atan2(dirrection.y, dirrection.x) * 180 / b2_pi);
	texture.loadFromFile("../data/Explosion.bmp");
	rectShape.setTexture(&texture);

}

bool Explosion::draw(sf::RenderWindow *window) {
	bool r = update();
	shape.setPosition(getPosition());
	window->draw(shape);

	rectShape.setSize(Vector2f(b2Distance(positionInitial, getPositionb2()) + 4, 8));
	window->draw(rectShape);
	return r;
}
