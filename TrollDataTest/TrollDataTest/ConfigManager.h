#pragma once

class ConfigManager {
public:
	ConfigManager();
	int GetTotalTrollStats();
	int GetMinTrollStatValue();
private:
	int _totalTrollStats;
	int _minTrollStatValue;
};