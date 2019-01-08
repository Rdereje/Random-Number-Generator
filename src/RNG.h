#include <iostream>
#include <vector>
class RNG
struct lastDig
{
	int digit;
	std::vector<int>numList;
}
{
	public:
		RNG(int l, int u);
		int newNumber();
		bool Repeat(int check);
		void Lang(bool which);
		bool getDone();
	private:
		int lowerBound;
		int upperBound;
		bool language;
		bool done;
		int diff;
		int count;
	
};