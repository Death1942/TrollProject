// TrollDataTest.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <time.h>

#include "ConfigManager.h"
#include "SimulationManager.h"
using namespace std;


int main()
{	
	ConfigManager configManager;
	SimulationManager manager(configManager);

	srand(time(NULL));	

	while (manager.SimulationRunning)
	{
		//Code is running, do not exit
	}

    return 0;
}

