
#pragma once
class LevelingSystem
{
public:
    LevelingSystem();

    void resetLeveling();

    void obtainExp(int expGain);

    void checkLevelUp();

    int getLevel();

private:

    int currentLevel;
    int currentExperience;
    //int expUntilNextLevel;

    

};
