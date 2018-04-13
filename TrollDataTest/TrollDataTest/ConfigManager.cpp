#include "ConfigManager.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "ConfigHelper.h"

ConfigManager::~ConfigManager()
{
	_configData.clear();
}

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

//Troll
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

//Knight
int ConfigManager::GetTotalKnightStats()
{
	return stoi(_configData[ConfigHelper::TotalKnightStats]);
}

int ConfigManager::GetMinKnightStatValue()
{
	return stoi(_configData[ConfigHelper::MinKnightStatValue]);
}

int ConfigManager::GetKnightHealth()
{
	return stoi(_configData[ConfigHelper::KnightHealth]);
}

//Archer
int ConfigManager::GetTotalArcherStats()
{
	return stoi(_configData[ConfigHelper::TotalArcherStats]);
}

int ConfigManager::GetMinArcherStatValue()
{
	return stoi(_configData[ConfigHelper::MinArcherStatValue]);
}

int ConfigManager::GetArcherHealth()
{
	return stoi(_configData[ConfigHelper::ArcherHealth]);
}
#pragma endregion
