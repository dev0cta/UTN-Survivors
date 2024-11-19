#include "clsLevelingSystem.h"

LevelingSystem::LevelingSystem()
{
    
    currentLevel = 1;
    currentExperience = 0;

    
}

void LevelingSystem::resetLeveling()
{
    currentLevel = 1;
    currentExperience = 0;
}

void LevelingSystem::obtainExp(int expGain)
{

    currentExperience += expGain;
    checkLevelUp();
  
}

void LevelingSystem::checkLevelUp()
{
    
    if (currentLevel <= 5) {
        if (currentExperience >= 100)
        {
            currentLevel++;
            currentExperience = 0;
        }
    }
    else if(currentLevel > 5)
    {
        if (currentExperience >= 150);
        {
            currentLevel++;
            currentExperience = 0;
        }
    }
    
}

int LevelingSystem::getLevel()
{
    return currentLevel;
}
