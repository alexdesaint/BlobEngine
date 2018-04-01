//
// Created by alexa on 30/03/2018.
//

#ifndef BLOBENGINE_COLLISIONDETECTOREXCEPTION_HPP
#define BLOBENGINE_COLLISIONDETECTOREXCEPTION_HPP

#include <exception>
#include <deque>

#include "CollisionDetector.hpp"

namespace BlobEngine {
	class CollisionDetectorException : public std::exception {
	private:
		const char *errorMsg;

		std::deque<Point2f> trajectoryComputed{};

		std::deque<Circle> circleStaticList{};
		std::deque<Circle> circleDynamicList{};
		std::deque<std::deque<Point2f>> lineStaticList{};
		Circle object;
		Vec2f frameMove;
	
	public:
		
		explicit CollisionDetectorException(const char*,
											std::deque<CircleStatic*>,
											std::deque<CircleDynamic*>,
											std::deque<LineStatic*>,
											Circle object,
											Vec2f frameMove,
											std::deque<Point2f>);
		
		void showDebugWindow();
		
		const char *what() const throw() override {
			return errorMsg;
		}
	};
}
#endif //BLOBENGINE_COLLISIONDETECTOREXCEPTION_HPP
