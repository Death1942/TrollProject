#include "Knight.h"
#include "RandomHelper.h"

Knight::Knight()
{
}

Knight::Knight(int strength, int dexterity, int armour, int health, bool isRanged)
{
}

void Knight::SetUpCharacter(ConfigManager &currentManager)
{
	//Values to set up default stats for a troll
	int totalStats = currentManager.GetTotalKnightStats();
	SetMinStatValue(currentManager.GetMinKnightStatValue());

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

	SetHealth(currentManager.GetKnightHealth());

	SetRanged(false);
}
