// TrollDataTest.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "Troll.h"
#include "Knight.h"
#include "ConfigManager.h"
using namespace std;


int main()
{
	int numberOfTrolls = 0;
	ConfigManager configManager;

	cout << "Enter number of trolls to generate" << endl;
	cin >> numberOfTrolls;

	srand(time(NULL));

	vector<Troll> trolls;
	int randomValue = 0;

	for (int i = 0; i < numberOfTrolls; ++i)
	{
		Troll newTroll;
		newTroll.SetUpCharacter(configManager);

		trolls.push_back(newTroll);
	}

	cout << "Press enter to print trolls" << endl;
	cout << endl;
	cout << endl;

	for (int y = 0; y < trolls.size(); ++y)
	{
		cout << "Troll " << y << endl;
		cout << "Health " << trolls[y].GetHealth() << endl;
		cout << "Armour " << trolls[y].GetArmour() << endl;
		cout << "Str " << trolls[y].GetStrength() << endl;
		cout << "Dex " << trolls[y].GetDexterity() << endl;
		cout << "HealRatio " << trolls[y].GetHealRatio() << endl;
		cout << "IsRanged " << trolls[y].IsRanged() << endl;
		cout << endl;
	}

	int test;
	cin >> test;

	//Knight testKnight();

    return 0;
}

