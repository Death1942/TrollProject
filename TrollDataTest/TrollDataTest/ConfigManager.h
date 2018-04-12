#pragma once
#include <map>
using namespace std;


class ConfigManager {
public:
	ConfigManager();
	int GetTotalTrollStats();
	int GetMinTrollStatValue();
	int GetTrollHealth();
private:
	int _totalTrollStats;
	int _minTrollStatValue;
	map<string, string> _configData;
};