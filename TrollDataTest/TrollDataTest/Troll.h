#pragma once
#include "BaseCharacter.h"
#include "ConfigManager.h"

struct TrollStats {
	int KnightKillCount;
	int ArcherKilLCount;
	int RoundsSurvived;
};

class Troll :public BaseCharacter
{
public:
	Troll();
	Troll(int strength, int dexterity, int armour, int health, float healthRatio, bool isRanged);
	float GetHealRatio();
	void SetUpCharacter(ConfigManager &currentManager);

	TrollStats GetStats();
	void UpdateKnightKillCount(int addValue);
	void UpdateArcherKillCount(int addValue);
	void UpdateRoundsSurvived(int addValue);
private:
	float _targetHealRatio;
	TrollStats _currentStats;
};


