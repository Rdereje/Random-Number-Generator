#include "RNG_English.h"

RNG_English::RNG_English(int l, int u):lowerBound{l}, upperBound{2}
{	
}
int RNG_English::NewNumber()
{
	return 0;
}
bool RNG_English::Remaining()
{
	return true;
}
void RNG_English::Lang(bool which)
{
	language = which;
}