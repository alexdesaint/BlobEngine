//
// Created by alexa on 30/03/2018.
//
#include <BlobEngine/CollisionDetectorException.hpp>
#include <SFML/Graphics.hpp>
#include <BlobEngine/Hit.hpp>
#include <BlobEngine/CollisionDetector.hpp>
#include <utility>
#include <iostream>

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
			line.setSize(sf::Vector2f(speed.length(), 1));
			line.setOrigin(0, 0);
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
			line.setSize(sf::Vector2f(speed.length(), 1));
			line.setOrigin(0, 0);
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
														   Circle object,
														   Vec2f frameMove,
														   std::deque<Point2f> trajectoryComputed) :
			errorMsg(errorMsg),
			trajectoryComputed(std::move(trajectoryComputed)),
			object(object),
			frameMove(frameMove) {
		std::cout << errorMsg << std::endl;
		
		for (CircleDynamic *target : circleDynamicList) {
			this->circleDynamicList.emplace_back(target->mainCircle);
		}
		
		for (CircleStatic *target : circleStaticList) {
			this->circleStaticList.emplace_back(target->mainCircle);
		}
		
		for (LineStatic *target : lineStaticList) {
			this->lineStaticList.emplace_back(target->lines);
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

			for (auto &target : circleStaticList) {
				sf::CircleShape shape;
				shape.setFillColor(sf::Color::Green);

				shape.setPosition(target.position.x, target.position.y);
				shape.setOrigin(target.rayon, target.rayon);
				shape.setRadius(target.rayon);
				
				window.draw(shape);
			}

			for (auto &target : lineStaticList) {
				sf::ConvexShape shape;

				shape.setPointCount(target.size());

				size_t count = 0;
				for (auto point : target) {
					shape.setPoint(count, sf::Vector2f(point.x, point.y));

					count++;
				}


				shape.setFillColor(sf::Color::Green);
				
				window.draw(shape);
			}

			for (auto &target : circleDynamicList) {
				sf::CircleShape shape;
				shape.setFillColor(sf::Color::Blue);

				shape.setPosition(target.position.x, target.position.y);
				shape.setOrigin(target.rayon, target.rayon);
				shape.setRadius(target.rayon);
				
				window.draw(shape);
			}
			
			sf::CircleShape shape;
			shape.setFillColor(sf::Color::Red);

			shape.setPosition(object.position.x, object.position.y);
			shape.setOrigin(object.rayon, object.rayon);
			shape.setRadius(object.rayon);
			
			window.draw(shape);

			StaticLine s(object.position, object.position + frameMove, sf::Color::Magenta);
			
			s.draw(&window);

			for (auto &line : trajectoryComputed) {
				sf::RectangleShape shape1(sf::Vector2f(1, 1));

				shape1.setPosition(line.x, line.y);
				//shape1.setOrigin(2, 2);
				shape1.setFillColor(sf::Color::Yellow);

				window.draw(shape1);
			}
			
			window.display();
		}
	}
	
}