#pragma once
#include "MathUtils.h"
#include <cmath>


struct Vector2 {
	float x;
	float y;


	Vector2() = default;
	Vector2(float x, float y) { 
		this->x = x; 
		this->y = y;
	}
	Vector2(int x, int y) {
		this->x = (float) x;
		this->y = (float) y;
	}

	

	Vector2 operator + (Vector2 v) {
		return Vector2{ x + v.x, y + v.y };
	}
	Vector2 operator - (Vector2 v) {
		return Vector2{ x - v.x, y - v.y };
	}

	
	Vector2 operator * (Vector2 v) {
		return Vector2{ x * v.x, y * v.y };
	}

	Vector2 operator + (float s) const {
		return Vector2{ x + s, y + s};
	}
	Vector2 operator - (float s) const {
		return Vector2{ x - s, y - s };
	}
	Vector2 operator * (float s) const {
		return Vector2{ x * s, y * s };
	}
	Vector2 operator / (float s) const {
		return Vector2{ x / s, y / s };
	}

	Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
	Vector2& operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; }
	Vector2& operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; }
	Vector2& operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; }

	Vector2& operator += (float s) { x += s; y += s; return *this; }
	Vector2& operator -= (float s) { x -= s; y -= s; return *this; }
	Vector2& operator *= (float s) { x *= s; y *= s; return *this; }
	Vector2& operator /= (float s) { x /= s; y /= s; return *this; }

	float Angle() { return Math::Atan2(x, y); }
	float LengthSqr() const { return (x * x) + (y * y); }
	float Length() const { return std::sqrt((x * x) + (y * y)); }


	

	Vector2 Rotate(float radians) const;

	Vector2 Normalized() const { return *this / Length(); }


};

inline Vector2 Vector2::Rotate(float radians) const
{
	float x_ = x * std::cos(radians) - y * std::sin(radians);
	float y_ = x * std::sin(radians) + y * std::cos(radians);

	return { x_,y_ };
};

inline Vector2 OnUnitCircle(float angle) {
	
	return Vector2{ Math::Cos(Math::DegToRad(angle)),Math::Sin(Math::DegToRad(angle)) };
}