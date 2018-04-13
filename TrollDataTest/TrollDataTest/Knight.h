#pragma once
#include "BaseCharacter.h"
#include "ConfigManager.h"

class Knight : public BaseCharacter
{
public:	
	Knight();
	Knight(int strength, int dexterity, int armour, int health, bool isRanged);
	void SetUpCharacter(ConfigManager &currentManager);
private:	
protected:
};
