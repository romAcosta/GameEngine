#pragma once
#include <cstdlib>
#include "Random.h"

struct Color {
	int r, g, b, a = 0;

	Color() = default;
	void randomize();


};