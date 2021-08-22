#include <cmath>

namespace SDL {

	struct Vector {
		float x;
		float y;
		
		static float Length(const Vector& p1, const Vector& p2) {
			return std::sqrtf((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
		} 
		
		Vector(float x, float y) :
			x(x), y(y) {}
	};
}