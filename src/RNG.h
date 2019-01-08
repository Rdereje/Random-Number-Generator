#include <iostream>
class RNG
{
	public:
		RNG(int l, int u);
		int NewNumber();
		bool Remaining();
		void Lang(bool which);
	private:
		int lowerBound;
		int upperBound;
		bool language;
	
};