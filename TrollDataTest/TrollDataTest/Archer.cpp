#include "Archer.h"
#include "RandomHelper.h"

Archer::Archer()
{
}

Archer::Archer(int strength, int dexterity, int armour, int health, bool isRanged)
{
}

void Archer::SetUpCharacter(ConfigManager & currentManager)
{
	//Values to set up default stats for a troll
	int totalStats = currentManager.GetTotalArcherStats();
	SetMinStatValue(currentManager.GetMinArcherStatValue());

	int MinRangeValue = GetMinStatValue();
	//Only account for 2 min values because we are already calculating the 3rd
	int MaxRangeValue = totalStats - (2 * GetMinStatValue());

	int dexRandom  = RandomHelper::GetRandom(MaxRangeValue, MinRangeValue);

	//Can't use random helper below as we have custom logic for two min values
	int armRandom = rand() % ((MaxRangeValue - dexRandom) + 1) + MinRangeValue;

	totalStats -= (armRandom + dexRandom);

	SetArmour(armRandom);
	SetDexterity(dexRandom);
	SetStrength(totalStats);

	SetHealth(currentManager.GetArcherHealth());

	SetRanged(true);

	this->Type = CharacterType::c_Archer;
}
