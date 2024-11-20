#include "clsStatistics.h"


Statistics::Statistics()
{

	this->timeSurvived = 0.0f;
	this->dmgTaken = 0;
	this->dmgDealt = 0;
	this->slimesDefeated = 0;
	this->elementalSlimesDefeated = 0;
	this->spartansDefeated = 0;
	this->reapersDefeated = 0;
	this->timesLeveledUp = 0;
	this->gameBeatedCounter = 0;
}

Statistics::Statistics(float timeSurvived, int dmgTaken, int dmgDealt, int slimesDefeated, int elementalSlimesDefeated,
	int spartansDefeated, int reapersDefeated, int timesLeveledUp, int gameBeatedCounter)
{
	this->timeSurvived = timeSurvived;
	this->dmgTaken = dmgTaken;
	this->dmgDealt = dmgDealt;
	this->slimesDefeated = slimesDefeated;
	this->elementalSlimesDefeated = elementalSlimesDefeated;
	this->spartansDefeated = spartansDefeated;
	this->reapersDefeated = reapersDefeated;
	this->timesLeveledUp = timesLeveledUp;
	this->gameBeatedCounter = gameBeatedCounter;

}

Statistics Statistics::operator+=(Statistics& other)
{
	this->timeSurvived += other.getTimeSurvived();
	this->dmgTaken += other.getDmgTaken();
	this->dmgDealt += other.getDmgDealt();
	this->slimesDefeated += other.getSlimesDefeated();
	this->elementalSlimesDefeated += other.getElementalSlimesDefeated();
	this->spartansDefeated += other.getSpartansDefeated();
	this->reapersDefeated += other.getReapersDefeated();
	this->timesLeveledUp += other.getTimesLeveledUp();
	this->gameBeatedCounter += other.getGameBeatedCounter();


	return *this;
}

void Statistics::coutStatistics(Statistics statistics)
{
	std::cout << "timeSurvived:      " << timeSurvived            << std::endl;
	std::cout << "dmgTaken:          " << dmgTaken                << std::endl;
	std::cout << "dmgDealt:          " << dmgDealt                << std::endl;
	std::cout << "slimesDefeated:    " << slimesDefeated          << std::endl;
	std::cout << "elemSlimesDefeated:" << elementalSlimesDefeated << std::endl;
	std::cout << "spartansDefeated:  " << spartansDefeated        << std::endl;
	std::cout << "timesGameBeated:   " << gameBeatedCounter       << std::endl;
	std::cout << "reapersDefeated:   " << reapersDefeated         << std::endl;
	std::cout << "timedLevelUp:      " << gameBeatedCounter       << std::endl;
}
