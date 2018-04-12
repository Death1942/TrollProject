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

void Troll::SetUpCharacter(ConfigManager &currentManager)
{
	//Values to set up default stats for a troll
	int totalStats = currentManager.GetTotalTrollStats();

	SetMinStatValue(currentManager.GetMinTrollStatValue());

	int armRandom = GetMinStatValue() + rand() / (RAND_MAX / ((totalStats - (3 * GetMinStatValue()) - GetMinStatValue()) + 1));
	int dexRandom = GetMinStatValue() + rand() / (RAND_MAX / ((totalStats - (3 * GetMinStatValue()) - armRandom) - GetMinStatValue()) + 1);

	totalStats -= (armRandom + dexRandom);

	SetArmour(armRandom);
	SetDexterity(dexRandom);
	SetStrength(totalStats);

	SetHealth(currentManager.GetTrollHealth());

	SetRanged((rand() % 2) + 1);
	_targetHealRatio = ((float)rand() / RAND_MAX);
}
