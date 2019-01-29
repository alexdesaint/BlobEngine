#include <BlobEngine/Geometrie.hpp>

namespace Blob {
	bool Rectangle::overlap(const Rectangle &r) {

		float xdiff = size.x / 2;
		float ydiff = size.y / 2;
		float rxdiff = r.size.x / 2;
		float rydiff = r.size.y / 2;

		return ((position.x - xdiff <= r.position.x + rxdiff) && (position.x - xdiff >= r.position.x - rxdiff) &&
				(position.y - ydiff <= r.position.y + rydiff) && (position.y - ydiff >= r.position.y - rydiff))
			   ||
			   ((position.x + xdiff <= r.position.x + rxdiff) && (position.x + xdiff >= r.position.x - rxdiff) &&
				(position.y - ydiff <= r.position.y + rydiff) && (position.y - ydiff >= r.position.y - rydiff))
			   ||
			   ((position.x - xdiff <= r.position.x + rxdiff) && (position.x - xdiff >= r.position.x - rxdiff) &&
				(position.y + ydiff <= r.position.y + rydiff) && (position.y + ydiff >= r.position.y - rydiff))
			   ||
			   ((position.x + xdiff <= r.position.x + rxdiff) && (position.x + xdiff >= r.position.x - rxdiff) &&
				(position.y + ydiff <= r.position.y + rydiff) && (position.y + ydiff >= r.position.y - rydiff));
	}
}