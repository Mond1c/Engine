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
	
	inline Vector operator+(const Vector& v1, const Vector& v2) {
		return {v1.x + v2.x, v1.y + v2.y};
	}
	
	inline Vector operator-(const Vector& v1, const Vector& v2) {
		return {v1.x - v2.x, v1.y - v2.y};
	}
	
	inline Vector& operator+=(Vector& v1, const Vector& v2) {
		v1.x += v2.x; v1.y += v2.y;
		return v1;
	}
	
	inline Vector& operator-=(Vector& v1, const Vector& v2) {
		v1.x -= v2.x; v1.y -= v2.y;
		return v1;
	}

    inline Vector operator*(const Vector& v1, float factor) {
        return {v1.x * factor, v1.y * factor};
    }

    inline Vector& operator*=(Vector& v1, float factor) {
        v1.x *= factor; v1.y *= factor;
        return v1;
    }

    inline Vector operator/(const Vector& v1, float factor) {
        return {v1.x / factor, v1.y / factor};
    }

    inline Vector& operator/=(Vector& v1, float factor) {
        v1.x /= factor; v1.y /= factor;
        return v1;
    }
}
