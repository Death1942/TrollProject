#include "ConfigManager.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "ConfigHelper.h"
//using namespace std;

ConfigManager::ConfigManager()
{
	ifstream fileToRead("test.config");
	//Loads all the config values
	string line;

	if (fileToRead.is_open())
	{
		while (getline(fileToRead, line))
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
					_configData.insert(pair<string, string>(key, value));
				}
			}
		}		
	}

	fileToRead.close();

	string testKey = _configData[ConfigHelper::TotalTrollStats];
}

#pragma region Getters

int ConfigManager::GetTotalTrollStats()
{
	return stoi(_configData[ConfigHelper::TotalTrollStats]);
}

int ConfigManager::GetMinTrollStatValue()
{	
	return stoi(_configData[ConfigHelper::MinTrollStatValue]);
}

int ConfigManager::GetTrollHealth()
{
	return stoi(_configData[ConfigHelper::TrollHealth]);
}
#pragma endregion
