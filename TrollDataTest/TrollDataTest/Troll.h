#pragma once
#include "BaseCharacter.h"
#include "ConfigManager.h"

class Troll :public BaseCharacter
{
public:
	Troll();
	Troll(int strength, int dexterity, int armour, int health, float healthRatio, bool isRanged);
	float GetHealRatio();
	void SetUpCharacter(ConfigManager &currentManager);
private:
	float _targetHealRatio;
};
