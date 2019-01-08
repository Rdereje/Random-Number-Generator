#include "RNG.h"
#include <stdlib.h> 
#include <time.h> 
using std::vector;
RNG::RNG(int l, int u):lowerBound{l}, upperBound{u}
{
		done = false;
		diff = u-l+1;
		numList.resize(diff);
		count = 0;
}
int RNG::newNumber()
{
	srand(time(NULL));	
	int num = rand()%diff + lowerBound;
	
	while(Repeat(num-lowerBound))
	{
		srand(time(NULL));	
		num = rand()%diff + lowerBound;
	}
	
	if(!language)
		std::cout<<num<<std::endl;
	
	count++;
	return 0;
}
bool RNG::Repeat(int check)
{
	if(numList.at(check) == true)
		return true;
	else
	{
		numList.at(check) = true;
		return false;
	}
}
void RNG::Lang(bool which)
{
	language = which;
}
bool RNG::getDone()
{
	return count==diff;
}