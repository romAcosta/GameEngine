#pragma once
#include <cmath>


namespace Math {

	constexpr float Pi     = 3.14159265359f;

	constexpr float Pi2    = 3.14159265359f * 2;

	constexpr float HalfPi = 3.14159265359f / 2;

	constexpr float RadToDeg(float radians) {return radians * (180.0f / Pi);}
	constexpr float DegToRad(float degrees) {return degrees * ( Pi/180.0f);}

	inline float Sin(float radians) {
		return std::sinf(radians);
	}

	inline float Cos(float radians) {
		return std::cosf(radians);
	}

	inline float Sqrt(float value)
	{
		return std::sqrtf(value);
	}

	inline float Atan2(float y, float x)
	{
		return std::atan2f(y, x);
	}

	/// <summary>
	/// Returns the maximum value of a and b.
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a">value</param>
	/// <param name="b">value</param>
	/// <returns>The maximum value of a and b</returns>
	template<typename T>
	T Max(T a, T b) { return (a > b) ? a : b; }

	template<typename T>
	T Min(T a, T b) { return (a < b) ? a: b; }
	
	template<typename T>
	T Abs(T value) { return (value < 0) ? -value: value; }


	template<typename T>
	inline T Clamp(T v, T min, T max)
	{
		if (v < min) return min;
		if (v > max) return max;

		return v;
	}

	inline int Wrap(int value, int max) {
		return value % max + ((value < 0) ? max : 0);
	}

	inline float Wrap(float value, float max) {
		return std::fmodf(value, max) + ((value < 0.0f) ? max : 0.0f);
	}
	
}