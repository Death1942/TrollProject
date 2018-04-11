#include "stdafx.h"
#include "BaseCharacter.h"

BaseCharacter::BaseCharacter()
{
}

BaseCharacter::BaseCharacter(int strength, int dexterity, int armour, int health, bool isRanged)
{
	_health = health;
	_strength = strength;
	_dexterity - dexterity;
	_armour = armour;
	_rangedAttack = isRanged;
}


void BaseCharacter::ChangeHealth(int valueToChangeBy)
{
	int currentHealth = _health;

	//Lower bounds check
	if (currentHealth - valueToChangeBy < 0)
	{
		_health = 0;
	}
	else
	{
		_health += valueToChangeBy;
	}
}

#pragma region getters and setters
int BaseCharacter::GetHealth()
{
	return _health;
}

int BaseCharacter::GetStrength()
{
	return _strength;
}

int BaseCharacter::GetDexterity()
{
	return _dexterity;
}

int BaseCharacter::GetArmour()
{
	return _armour;
}

bool BaseCharacter::IsRanged()
{
	return _rangedAttack;
}

int BaseCharacter::GetMinStatValue()
{
	return _minStatValue;
}

void BaseCharacter::SetHealth(int health)
{
	_health = health;
}

void BaseCharacter::SetDexterity(int dexterity)
{
	_dexterity = dexterity;
}

void BaseCharacter::SetArmour(int armour)
{
	_armour = armour;
}

void BaseCharacter::SetRanged(bool ranged)
{
	_rangedAttack = ranged;
}

void BaseCharacter::SetStrength(int strength)
{
	_strength = strength;
}

void BaseCharacter::SetMinStatValue(int statValue)
{
	_minStatValue = statValue;
}

#pragma endregion
