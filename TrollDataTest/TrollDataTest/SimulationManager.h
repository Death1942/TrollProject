#pragma once
#include "ConfigManager.h"
#include "Knight.h"
#include "Archer.h"
#include "Troll.h"
#include <vector>

class SimulationManager 
{
public:
	SimulationManager();
	SimulationManager(ConfigManager &currentManager);	
	~SimulationManager();
	void SetUpSimulation();
	void StartSimulation();
	bool SimulationRunning;
private:
	vector<Archer> _archers;
	vector<Troll> _trolls;
	vector<Knight> _knights;
	ConfigManager* _configManager;
	void ClearScreen();
	void SaveSimulationRun();
	void RunGeneration();
	void RunCombat(Troll* trollToUse);
	void CombatRound(Troll* trollToUse, vector<BaseCharacter>* combatants);

	int _numberOfGenerations;
	int _numberOfTrollsPerGeneration;

};
