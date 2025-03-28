#include "Structures/Vector.h"

#include <cmath>

float FVector::GetLength() const
{
	return std::powf(std::powf(x, 2.0f) + std::powf(y, 2.0f) + std::powf(z, 2.0f), 0.5f);
}
