#include "RandomHelper.h"
#include <random>

int RandomHelper::GetRandom(int max, int min)
{
	return rand() % ((max - min) + 1) + min;
}

float RandomHelper::GetRandom(float max, float min) 
{
	return min + float((max * rand()) / (RAND_MAX + 1.0));
}