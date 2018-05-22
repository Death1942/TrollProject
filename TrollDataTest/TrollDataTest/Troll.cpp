#include "Troll.h"
#include <fstream>
#include "RandomHelper.h"

Troll::Troll()
{

}

Troll::Troll(int strength, int dexterity, int armour, int health, float healthRatio, bool isRanged)
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

	int MinRangeValue = GetMinStatValue();
	//Only account for 2 min values because we are already calculating the 3rd
	int MaxRangeValue = totalStats - (2 * GetMinStatValue());

	int armRandom = RandomHelper::GetRandom(MaxRangeValue, MinRangeValue);

	//Can't use random helper below as we have custom logic for two min values
	int dexRandom = rand() % ((MaxRangeValue - armRandom) + 1) + MinRangeValue;

	totalStats -= (armRandom + dexRandom);

	SetArmour(armRandom);
	SetDexterity(dexRandom);
	SetStrength(totalStats);

	SetHealth(currentManager.GetTrollHealth());

	int ranged = RandomHelper::GetRandom(2, 1);

	SetRanged(ranged == 1);
	_targetHealRatio = ((float)rand() / RAND_MAX);
	this->Type = CharacterType::c_Troll;
}

TrollStats Troll::GetStats()
{
	return _currentStats;
}

void Troll::UpdateKnightKillCount(int addValue)
{
	_currentStats.KnightKillCount += addValue;
}

void Troll::UpdateArcherKillCount(int addValue)
{
	_currentStats.ArcherKilLCount += addValue;
}

void Troll::UpdateRoundsSurvived(int addValue)
{
	_currentStats.RoundsSurvived += addValue;
}
