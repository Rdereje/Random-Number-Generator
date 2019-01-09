#include <iostream>
#include <vector>
class RNG

{
	public:
		RNG(int l, int u);
		int newNumber();
		void Lang(bool which);
		bool getDone();
		void newBounds(int l, int u);
		void restart();
	private:
		int lowerBound;
		int upperBound;
		bool language;
		bool done;
		int diff;
		std::vector<int> numList;
	
};