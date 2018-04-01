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
		
		std::deque<Line> trajectoryComputed{};
		
		std::deque<CircleStatic> circleStaticList{};
		std::deque<CircleDynamic> circleDynamicList{};
		std::deque<LineStatic> lineStaticList{};
		CircleDynamic object;
	
	public:
		
		explicit CollisionDetectorException(const char*,
											std::deque<CircleStatic*>,
											std::deque<CircleDynamic*>,
											std::deque<LineStatic*>,
											CircleDynamic,
											std::deque<Line>);
		
		void showDebugWindow();
		
		const char *what() const throw() override {
			return errorMsg;
		}
	};
}
#endif //BLOBENGINE_COLLISIONDETECTOREXCEPTION_HPP
