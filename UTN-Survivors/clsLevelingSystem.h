
#pragma once
class LevelingSystem
{
public:
    LevelingSystem();

    void resetLeveling();

    void obtainExp(int expGain);

    void checkLevelUp();

    int getLevel();

    int getCurrentExperience();

    int getExpNeeded();
    

private:

    int currentLevel;
    int currentExperience;
    //int expUntilNextLevel;

    

};
