#include <iostream>
#include <vector>
#include <string>
#include <time.h> 
#include "RNG.h"
using std::cout;
using std::cin;
using std::endl;
int choice;
int lower;
int upper;

//method to enforce that users enter the correct char values
char rightTrueChar(char check)
{
	//loop will end when user enters correct true and false values
	while(check != 'Y' && check != 'y' && check != 'n' && check != 'N')
	{
		cout<<"You entered the wrong letter please try again."<<endl;
		cout<<"Contune Y or N?"<<endl;
		cin>>check;
	}
	return check;
}
//makes sure option 1 or 2 are picked for intengers
int rightInt(int check)
{
	while(check != 1 && check != 2)
	{
		cout<<"You've entered the wrong number :("<<endl;
		cout<<"Please enter 1 or 2 :)"<<endl;
		cin>>check;
	}
	return check;
}
void start()
{	
	cout<<"1) random number genertor with english numbers"<<endl;
	cout<<"2) random numer genertor spelled in the fidel"<<endl;
	cout << "Please enter 1 or 2: "<<endl;
	cin>>choice;
	
	choice = rightInt(choice);
	
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
	return;
}
void Generate(bool next, RNG* RNG)
{
	char go;
	char again;
	bool end = false;
	
	if(choice == 1)
		RNG->Lang(false);
	else
		RNG->Lang(true);
	
	
	while(next)
	{
		RNG->newNumber();
		cout<<"Do you wish to continue Y or N?"<<endl;
		cin>>go;
		go = rightTrueChar(go);
		if(go == 'N' || go == 'n')
		{
			next = false;
		}
		if(!RNG->getDone())
		{
			cout<<"There are no more numbers."<<endl;
			cout<<"Software is now closing"<<endl;
			next = false;
		}
	}
	RNG->restart();
	cout<<"Random number generation has ended would you like to go again Y or N"<<endl;
	cin>>again;
	again = rightTrueChar(again);
	if(again == 'N' || again == 'n')
		end = true;
	if(!end)
	{
		start();
		RNG->newBounds(lower, upper);
		Generate(true, RNG);
	}
}
int main(int argc, char* argv[])
{
	
	char go;
	
	start();
	
	RNG RNG(lower,upper);
	
	Generate(true, &RNG);
	
	
	return 0;
}
