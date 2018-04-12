#pragma once
#include <stdlib.h>

class BaseCharacter
{
public:
	BaseCharacter();
	BaseCharacter(int strength, int dexterity, int armour, int health, bool isRanged);
	void ChangeHealth(int valueToChangeBy);
	int GetHealth();
	int GetStrength();
	int GetDexterity();
	int GetArmour();
	int GetMinStatValue();
	bool IsRanged();
	virtual void SetUpCharacter();
private:
	int _health;

	int _strength;
	int _dexterity;
	int _armour;
	int _minStatValue;

	bool _rangedAttack;
protected:
	void SetHealth(int health);
	void SetDexterity(int dexterity);
	void SetArmour(int armour);
	void SetRanged(bool ranged);
	void SetStrength(int strength);
	void SetMinStatValue(int statValue);
};