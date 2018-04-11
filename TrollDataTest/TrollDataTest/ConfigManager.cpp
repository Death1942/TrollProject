#include "ConfigManager.h"
#include <sstream>
#include <iostream>
using namespace std;

ConfigManager::ConfigManager()
{
	//Loads all the config values
	istringstream file("test.config");
	string line;

	while (getline(file, line))
	{
		istringstream lineValue(line);

		string key;

		if (getline(lineValue, key, '='))
		{
			string value;
			if (getline(lineValue, value))
			{
				//new value is key, value
				//need to match the key with one in code somehow
			}
		}
	}


}

#pragma region Getters

int ConfigManager::GetTotalTrollStats()
{
	return _totalTrollStats;
}

int ConfigManager::GetMinTrollStatValue()
{
	return _minTrollStatValue;
}

#pragma endregion
