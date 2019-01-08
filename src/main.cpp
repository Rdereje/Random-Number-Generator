#include <iostream>
#include <vector>
#include <string>
#include "RNG_English.h"
int main(int argc, char* argv[])
{
	using std::cout;
	using std::cin;
	using std::endl;
	int choice;
	int lower;
	int upper;
	char go;
	bool next = true;
	
	cout<<"1) random number genertor with english numbers"<<endl;
	cout<<"2) random numer genertor spelled in the fidel"<<endl;
	cout << "Please enter 1 or 2: "<<endl;
	cin>>choice;
	
	while(choice != 1 && choice != 2)
	{
		cout<<"You've entered the wrong number :("<<endl;
		cout<<"Please enter 1 or 2 :)"<<endl;
		cin>>choice;
	}
	
	cout<<"Please enter lower limit"<<endl;
	cin>>lower;
	cout<<"Please enter upper limit"<<endl;
	cin>>upper;
	
	while(lower>upper)
	{
		cout<<"The lower limit must be less than the upper limit."<<endl;
		cout<<"Please enter a new lower limit"<<endl;
		cin>>lower;
		cout<<"Please enter a new upper limit"<<endl;
		cin>>upper;
	}
	
	RNG_English RNG(lower,upper);
	if(choice == 1)
		RNG.Lang(false);
	else
		RNG.Lang(true);
	while(RNG.Remaining() && next)
	{
		RNG.NewNumber();
		cout<<"Do you wish to continue Y or N?"<<endl;
		cin>>go;
		while(go != 'Y' && go != 'y' && go != 'n' && go != 'N')
		{
			cout<<"You entered the wrong letter please try again."<<endl;
			cout<<"Contune Y or N?"<<endl;
			cin>>go;
		}
		if(go == 'N' || go == 'n')
		{
			next = false;
		}
	}
	return 0;
}