#pragma once
#include <map>
using namespace std;


class ConfigManager {
public:
	~ConfigManager();
	ConfigManager();
	int GetTotalTrollStats();
	int GetMinTrollStatValue();
	int GetTrollHealth();

	int GetTotalKnightStats();
	int GetMinKnightStatValue();
	int GetKnightHealth();

	int GetTotalArcherStats();
	int GetMinArcherStatValue();
	int GetArcherHealth();
private:
	int _totalTrollStats;
	int _minTrollStatValue;
	map<string, string> _configData;
};