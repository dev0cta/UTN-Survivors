#include "clsGameplayData.h"

GameplayData::GameplayData()
{
}

std::vector<Slime>& GameplayData::getSlimes()
{
    return spawnedSlimes;
}

void GameplayData::spawnSlime(Slime slimeTemplate, sf::Vector2f playerPos)
{
    Slime e(slimeTemplate);

    int type = rand() % 3;
    e.getBody().setPosition(playerPos);


    e.setType(type);

    spawnedSlimes.push_back(e);


}

int GameplayData::howManySlimes()
{
    return spawnedSlimes.size();
}
