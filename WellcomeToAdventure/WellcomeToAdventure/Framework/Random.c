#include "Random.h"
#include "commonh.h"


bool Random_Init()
{
	srand(time(NULL));
	return true;
}

int32 Random_GetNumberFromRange(int32 minInclusive, int32 maxInclusive)
{
	if (minInclusive < INT32_MIN)
	{
		minInclusive = INT32_MIN;
	}
	if (maxInclusive > INT32_MAX)
	{
		maxInclusive = INT32_MAX;
	}
	int32 randomNum = (rand() % (maxInclusive - minInclusive)) + minInclusive;
	return randomNum;
}

float Random_GetFNumberFromRange(float minInclusive, float maxInclusive)
{
	float randomNum = (((maxInclusive - minInclusive) * ((float)rand() / RAND_MAX)) + minInclusive);
	return randomNum;
}