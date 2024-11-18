#include "clsGameplayData.h"
#include <cmath>
#include <SFML/Graphics.hpp>
GameplayData::GameplayData()
{
}

std::vector<Slime>& GameplayData::getSlimes()
{
    return spawnedSlimes;
}

void GameplayData::spawnSlime(Slime slimeTemplate, sf::Vector2f playerPos)
{
    if (spawnedSlimes.size() < 10) {
        Slime e(slimeTemplate);
        
        int type = rand() % 3;

        int degree = rand() % 360;

        int rad = degree * (3.14 / 180);

        int distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(cos(rad) * distance, sin(rad) * distance));

        e.setType(type);

        spawnedSlimes.push_back(e);

        
    }

}

int GameplayData::howManySlimes()
{
    return spawnedSlimes.size();
}
