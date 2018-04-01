//
// Created by alexa on 30/03/2018.
//
#include <BlobEngine/CollisionDetectorException.hpp>
#include <SFML/Graphics.hpp>
#include <BlobEngine/Hit.hpp>
#include <BlobEngine/CollisionDetector.hpp>
#include <utility>

namespace BlobEngine {
	
	class StaticLine {
	private:
		sf::RectangleShape line;
		sf::CircleShape base;
	public:
		explicit StaticLine(int x, int y, int mx, int my, sf::Color color) {
			Vec2f speed = Vec2f(Point2f(x, y), Point2f(mx, my));
			
			line.setFillColor(color);
			line.setPosition(x, y);
			line.setSize(sf::Vector2f(speed.length(), 4));
			line.setOrigin(0, 2);
			line.setRotation(speed.getOrientationDeg());
			
			base.setFillColor(color);
			base.setPosition(x, y);
			base.setRadius(2);
			base.setOrigin(2, 2);
		}
		
		explicit StaticLine(Point2f o, Point2f d, sf::Color color) {
			Vec2f speed = Vec2f(o, d);
			
			line.setFillColor(color);
			
			line.setPosition(o.x, o.y);
			line.setSize(sf::Vector2f(speed.length(), 4));
			line.setOrigin(0, 2);
			line.setRotation(speed.getOrientationDeg());
			
			base.setFillColor(color);
			base.setPosition(o.x, o.y);
			base.setRadius(2);
			base.setOrigin(2, 2);
		}
		
		void draw(sf::RenderWindow *window) {
			window->draw(line);
			window->draw(base);
		}
		
		void update(float length, float orient) {
			line.setSize(sf::Vector2f(length, 4));
			line.setRotation(orient);
		}
	};
	
	CollisionDetectorException::CollisionDetectorException(const char *errorMsg,
														   std::deque<CircleStatic *> circleStaticList,
														   std::deque<CircleDynamic *> circleDynamicList,
														   std::deque<LineStatic *> lineStaticList,
														   CircleDynamic object,
														   std::deque<Line> trajectoryComputed) :
			errorMsg(errorMsg),
			trajectoryComputed(std::move(trajectoryComputed)),
			object(object) {
		
		for (CircleDynamic *target : circleDynamicList) {
			this->circleDynamicList.emplace_back(*target);
		}
		
		for (CircleStatic *target : circleStaticList) {
			this->circleStaticList.emplace_back(*target);
		}
		
		for (LineStatic *target : lineStaticList) {
			this->lineStaticList.emplace_back(*target);
		}
	}
	
	void  CollisionDetectorException::showDebugWindow(){
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		
		sf::RenderWindow window(sf::VideoMode(800, 400), "BlobEngine test", sf::Style::Close, settings);
		
		window.setFramerateLimit(60);
		
		while (window.isOpen()) {
			window.clear();
			
			sf::Keyboard::Key Key;
			sf::Event event{};
			sf::Mouse::Button mouseButton;
			
			while (window.pollEvent(event)) {
				switch (event.type) {
					case sf::Event::Closed :
						window.close();
						break;
					case sf::Event::KeyPressed :
					case sf::Event::KeyReleased :
					default:
						break;
				}
			}
			
			for (CircleStatic &target : circleStaticList) {
				sf::CircleShape shape;
				shape.setFillColor(sf::Color::Green);
				
				shape.setPosition(target.mainCircle.position.x, target.mainCircle.position.y);
				shape.setOrigin(target.mainCircle.rayon, target.mainCircle.rayon);
				shape.setRadius(target.mainCircle.rayon);
				
				window.draw(shape);
			}
			
			for (LineStatic &target : lineStaticList) {
				sf::RectangleShape shape;
				shape.setFillColor(sf::Color::Green);
				
				shape.setSize(sf::Vector2f(20, 20));
				shape.setOrigin(10, 10);
				
				shape.setPosition(sf::Vector2f(target.lines.front().pointA.x - 10, target.lines.front().pointA.y - 10));
				
				window.draw(shape);
			}
			
			for (CircleDynamic &target : circleDynamicList) {
				sf::CircleShape shape;
				shape.setFillColor(sf::Color::Blue);
				
				shape.setPosition(target.mainCircle.position.x, target.mainCircle.position.y);
				shape.setOrigin(target.mainCircle.rayon, target.mainCircle.rayon);
				shape.setRadius(target.mainCircle.rayon);
				
				window.draw(shape);
			}
			
			sf::CircleShape shape;
			shape.setFillColor(sf::Color::Red);
			
			shape.setPosition(object.mainCircle.position.x, object.mainCircle.position.y);
			shape.setOrigin(object.mainCircle.rayon, object.mainCircle.rayon);
			shape.setRadius(object.mainCircle.rayon);
			
			window.draw(shape);
			
			StaticLine s(object.mainCircle.position, object.mainCircle.position + object.speed, sf::Color::Magenta);
			
			s.draw(&window);
			
			for (Line &line : trajectoryComputed){
				StaticLine s(line.pointA, line.pointB, sf::Color::Yellow);
				
				s.draw(&window);
			}
			
			window.display();
		}
	}
	
}