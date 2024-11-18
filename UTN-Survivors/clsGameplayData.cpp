#include "clsGameplayData.h"
#include <cmath>
#include <SFML/Graphics.hpp>
GameplayData::GameplayData()
{
}

<<<<<<< Updated upstream
=======
void GameplayData::UpdateEveryEnemy(float deltaTime, sf::Vector2f playerPos)
{

    for (auto& enemy : getSlimes())
    {
        enemy.Update(deltaTime, playerPos);
    }
    for (auto& enemy : getElemSlimes())
    {
        enemy.Update(deltaTime, playerPos);
    }
    for (auto& enemy : getSpartans())
    {
        enemy.Update(deltaTime, playerPos);
    }
    for (auto& enemy : getReapers())
    {
        enemy.Update(deltaTime, playerPos);
    }

}

void GameplayData::checkPlayerSolidCollision(CircleCollider playerCollider)
{

    for (auto& enemy : getSlimes())
    {
        enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f);
    }
    for (auto& enemy : getElemSlimes())
    {
        enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f);
    }
    for (auto& enemy : getSpartans())
    {
        enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f);
    }
    for (auto& enemy : getReapers())
    {
        enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f);   
    }

}

void GameplayData::CheckEverySolidCollision()
{
    for (auto& enemy : getSlimes())
    {
        for (auto& otherEnemy : getSlimes())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getElemSlimes())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getSpartans())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getReapers())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }

    }
    for (auto& enemy : getElemSlimes())
    {
        for (auto& otherEnemy : getSlimes())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getElemSlimes())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getSpartans())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getReapers())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }

    }
    for (auto& enemy : getSpartans())
    {
        for (auto& otherEnemy : getSlimes())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getElemSlimes())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getSpartans())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getReapers())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }

    }
    for (auto& enemy : getReapers())
    {
        for (auto& otherEnemy : getSlimes())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getElemSlimes())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getSpartans())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }
        for (auto& otherEnemy : getReapers())
        {
            enemy.GetCollider().checkSolidCollision(otherEnemy.GetCollider(), 1.0f);
        }

    }
}

void GameplayData::DrawEveryEnemy(sf::RenderWindow& window)
{

    for (auto& enemy : getSlimes())
    {
        enemy.Draw(window);
    }
    for (auto& enemy : getElemSlimes())
    {
        enemy.Draw(window);
    }
    for (auto& enemy : getSpartans())
    {
        enemy.Draw(window);
    }
    for (auto& enemy : getReapers())
    {
        enemy.Draw(window);
    }

}

>>>>>>> Stashed changes
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
