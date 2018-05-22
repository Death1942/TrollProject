#include "SimulationManager.h"
#include "RandomHelper.h"
#include <iostream>
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <time.h>
#include <thread>
using namespace std;

SimulationManager::SimulationManager()
{
}

SimulationManager::SimulationManager(ConfigManager & currentManager)
{
	_configManager = &currentManager;
}

SimulationManager::~SimulationManager()
{
	_knights.clear();
	_trolls.clear();
	_archers.clear();
}

void SimulationManager::SetUpSimulation()
{
	SimulationRunning = true;
	cout << "Enter number of trolls to generate per generation" << endl;
	cin >> _numberOfTrollsPerGeneration;

	int targetRounds = 0;
	cout << "Enter the number of generations to simulate for" << endl;
	cin >> _numberOfGenerations;

	int choiceToRun = 0;
	bool madeChoice = false;

	do
	{
		ClearScreen();
		cout << "Enter 1 to start simulation or 2 to quit" << endl;
		cin >> choiceToRun;

		if (choiceToRun == 1)
		{
			madeChoice = true;
			StartSimulation();
		}
		else if (choiceToRun == 2)
		{
			madeChoice = true;
			SimulationRunning = false;
		}
	} while (!madeChoice);
}

void SimulationManager::StartSimulation()
{
	//todo Add threads for this at some point
	for (int i = 0; i < _numberOfGenerations; ++i)
	{
		RunGeneration();
	}
}

void SimulationManager::ClearScreen()
{
	COORD newPos;
	newPos.X = 0;
	newPos.Y = 0;

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(console, ' ', screen.dwSize.X * screen.dwSize.Y, newPos, &written);
	FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, screen.dwSize.X * screen.dwSize.Y, newPos, &written);
	SetConsoleCursorPosition(console, newPos);
}

void SimulationManager::SaveSimulationRun()
{
	ofstream fileToSave;
	time_t now = time(0);
	struct tm tstruct;
	tstruct = *localtime(&now);

	fileToSave.open("/Simulations/SimulationRun #" + tstruct.tm_mon + tstruct.tm_mday + tstruct.tm_hour + tstruct.tm_sec);

	fileToSave << "Number of trolls per generation " << _numberOfTrollsPerGeneration << endl;
	fileToSave << "Number of generations " << _numberOfGenerations << endl;

	for (int i = 0; i < _trolls.size(); ++i)
	{
		fileToSave << "Troll " << i << endl;
		fileToSave << "Knights killed: " << _trolls[i].GetStats().KnightKillCount << endl;
		fileToSave << "Archers killed: " << _trolls[i].GetStats().ArcherKilLCount << endl;
		fileToSave << "Rounds survived: " << _trolls[i].GetStats().RoundsSurvived << endl;
		fileToSave << "Troll stats: " << "Str " << _trolls[i].GetStrength() << "   Dex " << _trolls[i].GetDexterity() << "   Arm " << _trolls[i].GetArmour()
			<< "  HealRatio " << _trolls[i].GetHealRatio() << "   remaingHealth " << _trolls[i].GetHealth();
		fileToSave << endl;
		fileToSave << endl;
	}

	fileToSave.close();
}

void SimulationManager::RunGeneration()
{
	//Generate trolls
	for (int i = 0; i < _numberOfTrollsPerGeneration; ++i)
	{
		Troll newTroll;
		newTroll.SetUpCharacter(*_configManager);
		_trolls.push_back(newTroll);
	}

	//Generate Knights

	//Generate Archers

	//Run 10 combats for each troll
	for (int i = 0; i < 10; ++i)
	{
		for each (Troll troll in _trolls)
		{
			thread newThread(&SimulationManager::RunCombat, &troll);
		}
	}

	//Finish generation
}

void SimulationManager::RunCombat(Troll* trollToUse)
{
	vector<BaseCharacter> combatants;

	//Generate new knights and archers for each combat
	for (int i = 0; i < 2; ++i)
	{
		Knight newKnight;
		newKnight.SetUpCharacter(*_configManager);
		combatants.push_back(newKnight);

		Archer newArcher;
		newArcher.SetUpCharacter(*_configManager);

		combatants.push_back(newArcher);
	}

	SimulationManager::CombatRound(trollToUse, &combatants);
}

void SimulationManager::CombatRound(Troll* trollToUse, vector<BaseCharacter>* combatants)
{
	float trollArmourRatio = trollToUse->GetArmour() / 100;

	//Each character gets to swing at the troll
	for each (BaseCharacter character in *combatants)
	{
		int strength = character.GetStrength();
		int finalDamageValue = (int)(strength - (strength * trollArmourRatio));

		trollToUse->ChangeHealth(finalDamageValue);
	}

	//Troll picks a target
	BaseCharacter targetCharacter;
	vector<BaseCharacter> rangedCharacters;
	vector<BaseCharacter> meleeCharacters;

	for each(BaseCharacter character in *combatants)
	{
		//Only count alive characters
		if (character.GetHealth() > 0)
		{
			if (character.IsRanged())
			{
				rangedCharacters.push_back(character);
			}
			else
			{
				meleeCharacters.push_back(character);
			}
		}
	}

	//Ranged can hit any character at any time
	if (trollToUse->IsRanged())
	{
		int randomIndex = RandomHelper::GetRandom(combatants->size(), 0);
		targetCharacter = combatants->at(randomIndex);
	}
	else
	{
		//Melee trolls have to kill knights first
		if (meleeCharacters.size() > 0)
		{
			int randomIndex = RandomHelper::GetRandom(meleeCharacters.size(), 0);
			targetCharacter = combatants->at(randomIndex);
		}
		else
		{
			int randomIndex = RandomHelper::GetRandom(rangedCharacters.size(), 0);
			targetCharacter = combatants->at(randomIndex);
		}
	}

	
	//Swings and does damage
	float armourDampener = targetCharacter.GetArmour() / 100 * 0.5f;
	targetCharacter.ChangeHealth((int) trollToUse->GetStrength() * armourDampener);

	//If we kill the target, update the counts
	if (targetCharacter.GetHealth() <= 0)
	{
		switch (targetCharacter.Type)
		{
			case CharacterType::c_Archer:
			{
				trollToUse->UpdateArcherKillCount(1);
				break;
			}
			case CharacterType::c_Knight:
			{
				trollToUse->UpdateKnightKillCount(1);
				break;
			}
		}
	}

	if (trollToUse->GetHealth() > 0)
	{
		trollToUse->UpdateRoundsSurvived(1);

		if (trollToUse->GetHealRatio() <= trollToUse->GetHealth() / 100)
		{
			trollToUse->ChangeHealth(20);
		}
	}
}
