#include <iostream>
class RNG_English
{
	public:
		RNG_English(int l, int u);
		int NewNumber();
		bool Remaining();
		void Lang(bool which);
	private:
		int lowerBound;
		int upperBound;
		bool language;
	
};