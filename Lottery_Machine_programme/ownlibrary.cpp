#include <iostream>
#include<ctime>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;

void welcome_message()
{
	cout << endl << setw(50) << "Welcome to the Virtual Lottery Machine" << endl << endl;
	cout << setw(52) << "===========================================" << endl << endl;

}

void userDefined(int(&UserDef)[7])
{
	srand(time(0)); //sets random number algorithm

	int lotNum[7];
	int BonusNum[3];
	int temp;
	int choosenNum[7];
	int match1 = 0, match2 = 0;

	cout << endl << setw(52) << "Please, choose 7 numbers (1 - 39) inclusive: " << '\n' << endl;

	for (int i = 0; i < 7; i++)
	{
		do
		{
			cout << setw(23) << "Your input no # " << i + 1 << ":  ";
			cin >> choosenNum[i];
			temp = true;
			for (int j = 0; j < i; j++)
			{
				///Avoid Duplicates..
				if (choosenNum[j] == choosenNum[i])
				{                                       // Check for existing numbers..
				    cout << endl;
					cout << setw(72) << "It's a Rule that you can't input the same number multiple times.\n";
					cout << setw(50) << "====< Please input unique numbers >====\n" << endl;
					temp = false;
				}
			}
		} while (!temp);

		while (choosenNum[i] < 1 || choosenNum[i] > 39)
		{
			cout << endl << setw(49) << "Error! choose numbers (1 - 39) inclusive:\n" << endl;
			cout << setw(23) << "Your input no # " << i + 1 << ":  ";
			cin >> choosenNum[i];
		}
	}


	///sorting the choosen numbers..
	int q = sizeof(choosenNum) / sizeof(choosenNum[0]);
	sort(choosenNum, choosenNum + q, greater<int>());

	for (int i = 0; i < 7; i++) // to get lottery numbers..
	{
		do
		{   // Check Random..
			lotNum[i] = rand() % 39 + 1;
			temp = true;
			for (int j = 0; j < i; j++)
			{
				///Avoid Duplicates..
				if (lotNum[j] == lotNum[i])
				{ // Check for existing numbers..
					temp = false;
				}
			}
		} while (!temp);
	}

	///sorting the lottery numbers..
	int n = sizeof(lotNum) / sizeof(lotNum[0]);
	sort(lotNum, lotNum + n, greater<int>());

	// print lottery number and your in-putted number

	cout << "\n\tLottery\t\tYour(In-putted)";
	cout << "\n\tNumbers\t\tNumbers\n";
	cout << setw(42) << "====================================\n";

	for (int i = 0; i < 7; i++)
	{
		if (lotNum[i] == choosenNum[i])
		{
			cout << "\n\t" << lotNum[i] << "\t\t" << choosenNum[i] << "\n";
		}
		else {
			cout << "\n\t" << lotNum[i] << "\t\t" << choosenNum[i] << "\n";
		}
	}

	for (int i = 0; i < 3; i++) // to get bonus numbers..
	{
		do
		{   // Check Random..
			BonusNum[i] = rand() % 39 + 1;
			temp = true;
			for (int j = 0; j < i; j++)
			{
				///Avoid Duplicates..
				if (BonusNum[j] == BonusNum[i])
				{ // Check for existing numbers..
					temp = false;
				}
			}
		} while (!temp);
	}

	///sorting the Bonus numbers..
	int m = sizeof(BonusNum) / sizeof(BonusNum[0]);
	sort(BonusNum, BonusNum + m, greater<int>());
	cout << endl << endl;

	cout << setw(28) << "Bonus number's are :";

	for (int i = 0; i < 3; i++)
	{
		cout << setw(4) << BonusNum[i];
	}
	//match between lottery number and in-putted numbers
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (lotNum[i] == choosenNum[j])
			{
				match1 += 1;
			}
		}
	}

	//match between bonus and inputted num
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (BonusNum[i] == choosenNum[j])
			{
				match2 += 1;
			}
		}
	}

	cout << endl << endl << endl;;
	cout << setw(15) << "You got " << match1 << " Regular number Correct!\n" << endl;
	cout << setw(15) << "You got " << match2 << " Bonus number Correct!\n" << endl;
	cout << setw(20) << "So You got ( " << match1 << "+ " << match2 << " ) numbers Correct!" << endl;
	cout << endl;
	// for every matching regular number user will won 300 dollars and for every matching bonus number user will won 30 dollar
	cout << setw(30) << "Total Amount You Won = " << ((match1 * 300)) + (match2 * 30) << " dollars!\n\n" << endl;
}



void machineDefined(int(&MachineDef)[7])
{
	srand(time(0));

	int lotNum[7];
	int BonusNum[3];
	int temp;
	int newlot[7];
	int match1 = 0, match2 = 0;

	for (int i = 0; i < 7; i++) // get numbers..
	{
		do
		{   // Check Random..
			newlot[i] = rand() % 39 + 1;
			temp = true;
			for (int j = 0; j < i; j++)
			{
				///Avoid Duplicates..
				if (newlot[j] == newlot[i])
				{ // Check for existing numbers..
					temp = false;
				}
			}
		} while (!temp);
	}

	///sorting the new lottery numbers..
	int p = sizeof(newlot) / sizeof(newlot[0]);
	sort(newlot, newlot + p, greater<int>());



	for (int i = 0; i < 7; i++) // get numbers..
	{
		do
		{   // Check Random..
			lotNum[i] = rand() % 39 + 1;
			temp = true;
			for (int j = 0; j < i; j++)
			{
				///Avoid Duplicates..
				if (lotNum[j] == lotNum[i])
				{ // Check for existing numbers..
					temp = false;
				}
			}
		} while (!temp);
	}

	///sorting the lottery numbers..
	int n = sizeof(lotNum) / sizeof(lotNum[0]);
	sort(lotNum, lotNum + n, greater<int>());

	/// Lottery Winners are..


	cout << "\n\tLottery\t\tYour(Machine)";
	cout << "\n\tNumbers\t\tNumbers\n";
	cout << setw(42) << "====================================\n";

	for (int i = 0; i < 7; i++)
	{
		if (lotNum[i] == newlot[i])
		{
			cout << "\n\t" << lotNum[i] << "\t\t" << newlot[i] << "\n";
		}
		else {
			cout << "\n\t" << lotNum[i] << "\t\t" << newlot[i] << "\n";
		}

	}

	for (int i = 0; i < 3; i++) // to get numbers..
	{
		do
		{   // Check Random..
			BonusNum[i] = rand() % 39 + 1;
			temp = true;
			for (int j = 0; j < i; j++)
			{
				///Avoid Duplicates..
				if (BonusNum[j] == BonusNum[i])
				{ // Check for existing numbers..
					temp = false;
				}
			}
		} while (!temp);
	}

	///sorting the Bonus numbers..
	int m = sizeof(BonusNum) / sizeof(BonusNum[0]);
	sort(BonusNum, BonusNum + m, greater<int>());
	cout << endl << endl;

	cout << setw(28) << "Bonus number's are :";
	for (int i = 0; i < 3; i++)
	{
		cout << setw(4) << BonusNum[i];

	}

	//match between lottery number and machine's user number
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (lotNum[i] == newlot[j])
			{
				match1 += 1;
			}
		}
	}
	//match between bonus and machine's user number
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (BonusNum[i] == newlot[j])
			{
				match2 += 1;
			}
		}
	}

	cout << endl << endl << endl;
	cout << setw(16) << "You got " << match1 << " Regular number Correct!\n" << endl;
	cout << setw(16) << "You got " << match2 << " Bonus number Correct!\n" << endl;
	cout << setw(22) << "So, You got ( " << match1 << " + " << match2 << " ) numbers Correct!" << endl;
	cout << endl;
	// for every matching regular number user will won 300 dollars and for every matching bonus number user will won 30 dollar
	cout << setw(31) << "Total Amount You Won = " << ((match1 * 300)) + (match2 * 30) << " dollars!\n\n" << endl;
}
void end_message()
{
	cout << endl << setw(42) << "Thanks for Playing Virtual Lottery!" << endl << endl;
}

