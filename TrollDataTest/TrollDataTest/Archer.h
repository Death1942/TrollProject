#pragma once
#include "BaseCharacter.h"
#include "ConfigManager.h"

class Archer : public BaseCharacter
{
public:
	Archer();
	Archer(int strength, int dexterity, int armour, int health, bool isRanged);
	void SetUpCharacter(ConfigManager &currentManager);
};
