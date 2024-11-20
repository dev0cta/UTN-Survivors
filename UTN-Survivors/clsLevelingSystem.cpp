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
    else if(currentLevel <= 10)
    {
        if (currentExperience >= 150)
        {
            currentLevel++;
            currentExperience = 0;
        }
    }
    else if (currentLevel <= 15)
    {
        if (currentExperience >= 200)
        {
            currentLevel++;
            currentExperience = 0;
        }
    }
    else if (currentLevel <= 19)
    {
        if (currentExperience >= 250)
        {
            currentLevel++;
            currentExperience = 0;
        }
    }
    else
    {
        currentExperience = 0;
    }
    
    
}

int LevelingSystem::getLevel()
{
    return currentLevel;
}

int LevelingSystem::getCurrentExperience()
{
    return currentExperience;
}

int LevelingSystem::getExpNeeded()
{
    if (currentLevel <= 5) {

        return 100;
    }
    else if (currentLevel <= 10)
    {
        return 150;
    }
    else if (currentLevel <= 15)
    {
        return 200;
    }
    else if (currentLevel <=20)
    {
        return 250;
    }
}
