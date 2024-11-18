#include "clsGameplayData.h"

GameplayData::GameplayData()
{
}

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

void GameplayData::checkPlayerCollision(CircleCollider playerCollider)
{

    for (auto& enemy : getSlimes())
    {
        enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f);;
    }
    for (auto& enemy : getElemSlimes())
    {
        enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f);;
    }
    for (auto& enemy : getSpartans())
    {
        enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f);;
    }
    for (auto& enemy : getReapers())
    {
        enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f);;
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

std::vector<Slime>& GameplayData::getSlimes()
{
    return spawnedSlimes;
}

void GameplayData::spawnSlime(Slime slimeTemplate, sf::Vector2f playerPos)
{

   // if (spawnedSlimes.size() < 10) {

        Slime e(slimeTemplate);

        int type = rand() % 3;

        int degree = rand() % 360;

        int rad = degree * (3.14 / 180);

        int distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(cos(rad) * distance, sin(rad) * distance));


        e.setType(type);

        spawnedSlimes.push_back(e);
   // }

}

int GameplayData::howManySlimes()
{
    return spawnedSlimes.size();
}




std::vector<ElementalSlime>& GameplayData::getElemSlimes()
{
    return spawnedElemSlimes;
}

void GameplayData::spawnElementalSlime(ElementalSlime elemSlimeTemplate, sf::Vector2f playerPos)
{
    //if (spawnedElemSlimes.size() < 10) {

        ElementalSlime e(elemSlimeTemplate);

        int type = rand() % 3;

        int degree = rand() % 360;

        int rad = degree * (3.14 / 180);

        int distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(cos(rad) * distance, sin(rad) * distance));


        e.setType(type);

        spawnedElemSlimes.push_back(e);
   // }


}

int GameplayData::howManyElemSlimes()
{
    return 0;
}




std::vector<Spartan>& GameplayData::getSpartans()
{
    return spawnedSpartans;
}

void GameplayData::spawnSpartan(Spartan spartanTemplate, sf::Vector2f playerPos)
{
   // if (spawnedSpartans.size() < 10) {

        Spartan e(spartanTemplate);



        int degree = rand() % 360;

        int rad = degree * (3.14 / 180);

        int distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(cos(rad) * distance, sin(rad) * distance));


        spawnedSpartans.push_back(e);
   // }
}


int GameplayData::howManySpartans()
{
    return spawnedSpartans.size();
}



std::vector<Reaper>& GameplayData::getReapers()
{
    return spawnedReapers;
}

void GameplayData::spawnReaper(Reaper reaperTemplate, sf::Vector2f playerPos)
{
   // if (spawnedReapers.size() < 10) {

        Reaper e(reaperTemplate);

        int degree = rand() % 360;

        int rad = degree * (3.14 / 180);

        int distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(cos(rad) * distance, sin(rad) * distance));

        spawnedReapers.push_back(e);
   // }
}

int GameplayData::howManyReapers()
{
    return spawnedReapers.size();
}
