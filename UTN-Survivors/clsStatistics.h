#pragma once

#include <iostream>

class Statistics
{

public:
	Statistics();

	Statistics(float timeSurvived, int dmgTaken, int dmgDealt, int slimesDefeated, int elementalSlimesDefeated,
		int spartansDefeated, int reapersDefeated, int timesLeveledUp, int gameBeatedCounter);

	Statistics operator+=(Statistics& other);

	void coutStatistics(Statistics statistics);


	float getTimeSurvived()		  	 { return timeSurvived; }
	int getDmgTaken()				 { return dmgTaken; }
	int getDmgDealt()				 { return dmgDealt; }

	int getSlimesDefeated()			 { return slimesDefeated; }
	int getElementalSlimesDefeated() { return elementalSlimesDefeated; }
	int getSpartansDefeated()		 { return spartansDefeated; }
	int getReapersDefeated()		 { return reapersDefeated; }
	int getTimesLeveledUp()			 { return timesLeveledUp; }
	int getGameBeatedCounter()		 { return gameBeatedCounter; }


private:
	float timeSurvived;

	int dmgTaken;
	int dmgDealt;

	int slimesDefeated;
	int elementalSlimesDefeated;
	int spartansDefeated;
	int reapersDefeated;
	int timesLeveledUp;
	int gameBeatedCounter;
};

