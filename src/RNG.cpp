#include "RNG.h"
#include <stdlib.h> 
#include <time.h> 
using std::vector;
RNG::RNG(int l, int u):lowerBound{l}, upperBound{u}
{
		done = false;
		diff = u-l+1;
		
		while(l <= u)
		{
			numList.push_back(l);
			l++;
		}
}
int RNG::newNumber()
{
	
	srand(time(NULL));	
	int index = rand()%diff;
	
	if(!language)
	{
		std::cout<<numList.at(index)<<std::endl;
	}
	numList.erase(numList.begin()+index);
	diff--;
	return 0;
}

void RNG::Lang(bool which)
{
	language = which;
}
bool RNG::getDone()
{
	return diff==0;
}