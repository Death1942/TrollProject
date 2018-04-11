#include "stdafx.h"
#include "Troll.h"
#include <fstream>

Troll::Troll()
{

}

Troll::Troll(int strength, int dexterity, int armour, int health, float healthRatio, bool isRanged):BaseCharacter(strength, dexterity, armour, health, isRanged)
{
	_targetHealRatio = healthRatio;
}

float Troll::GetHealRatio()
{
	return _targetHealRatio;
}

void Troll::SetUpTroll()
{
	//Values to set up default stats for a troll
	int totalStats = 100;

	SetMinStatValue(20);

	int armRandom = GetMinStatValue() + rand() % ((totalStats - 3 * GetMinStatValue()) + 1 - GetMinStatValue());
	int dexRandom = GetMinStatValue() + rand() % (totalStats - armRandom) + 1 - GetMinStatValue();

	totalStats -= armRandom + dexRandom;

	SetArmour(armRandom);
	SetDexterity(dexRandom);
	SetStrength(totalStats);

	SetHealth(100);

	SetRanged((rand() % 2) + 1);
	_targetHealRatio = ((float)rand() / RAND_MAX);
}
