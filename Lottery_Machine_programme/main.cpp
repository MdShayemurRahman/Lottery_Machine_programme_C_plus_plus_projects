#include <iostream>
#include<ctime> //for time function
#include<algorithm> //sort
#include<string>  //used string
#include<iomanip> // for using setw
#include "ownlibrary.h" //my own library
using namespace std;

int main()
{
	int UserDef[7], MachineDef[7];
	int input = 1;
	welcome_message(); // display welcome message

	while (input != 0)
	{
		cout << endl << setw(38) << "How do you want to play?\n" << endl;  // to keep nice straight columns I used setw() .
		cout << setw(48) << "Option 1: Taking input (by your hand). \n " << endl;
		cout << setw(50) << "Option 2: Machine define input (randomly).\n" << endl;
		cout << setw(41) << "Option 0: To Exit The Programme.\n " << endl;
		cout << setw(22) << "Your Option :  ";
		cin >> input;

		switch (input)
		{
		case 1: userDefined(UserDef);
			break;
		case 2: machineDefined(MachineDef);
			break;

		case 0: end_message(); // to display end message
			break;
		default:
			cout << endl << setw(59) << "Invalid choose Option! Please choose correct Option" << endl << endl;
			break;
		}
	}

	return 0;
}


