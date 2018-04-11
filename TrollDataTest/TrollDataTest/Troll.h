#pragma once
#include "stdafx.h"
#include "BaseCharacter.h"

class Troll :public BaseCharacter
{
public:
	Troll();
	Troll(int strength, int dexterity, int armour, int health, float healthRatio, bool isRanged);
	float GetHealRatio();
	void SetUpTroll();
private:
	float _targetHealRatio;
};
