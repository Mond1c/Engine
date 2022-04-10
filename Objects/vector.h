#include <cmath>

namespace engine {
    template<typename T>
	struct Vector2 {
		T x;
		T y;

		static float Length(const Vector2& p1, const Vector2& p2) {
			return std::sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
		} 
		
		Vector2(T x, T y) :
			x(x), y(y) {}
	};

    typedef Vector2<float> Vector2f;
    typedef Vector2<int> Vector2i;

    template<typename T>
	inline Vector2<T> operator+(const Vector2<T>& v1, const Vector2<T>& v2) {
		return {v1.x + v2.x, v1.y + v2.y};
	}

    template<typename T>
	inline Vector2<T> operator-(const Vector2<T>& v1, const Vector2<T>& v2) {
		return {v1.x - v2.x, v1.y - v2.y};
	}

    template<typename T>
	inline Vector2<T>& operator+=(Vector2<T>& v1, const Vector2<T>& v2) {
		v1.x += v2.x; v1.y += v2.y;
		return v1;
	}

    template<typename T>
	inline Vector2<T>& operator-=(Vector2<T>& v1, const Vector2<T>& v2) {
		v1.x -= v2.x; v1.y -= v2.y;
		return v1;
	}

    template<typename T>
    inline Vector2<T> operator*(const Vector2<T>& v1, T factor) {
        return {v1.x * factor, v1.y * factor};
    }

    template<typename T>
    inline Vector2<T>& operator*=(Vector2<T>& v1, T factor) {
        v1.x *= factor; v1.y *= factor;
        return v1;
    }

    template<typename T>
    inline Vector2<T> operator/(const Vector2<T>& v1, T factor) {
        return {v1.x / factor, v1.y / factor};
    }

    template<typename T>
    inline Vector2<T>& operator/=(Vector2<T>& v1, T factor) {
        v1.x /= factor; v1.y /= factor;
        return v1;
    }
}
