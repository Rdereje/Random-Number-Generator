#include "RNG.h"
#include <stdlib.h> 
#include <time.h> 

RNG::RNG(int l, int u):lowerBound{l}, upperBound{u}
{	
}
int RNG::NewNumber()
{
	int diff = upperBound - lowerBound + 1;
	
	srand(time(NULL));	
	int num = rand()%diff + lowerBound;
	if(!language)
		std::cout<<num<<std::endl;
	return 0;
}
bool RNG::Remaining()
{
	return true;
}
void RNG::Lang(bool which)
{
	language = which;
}