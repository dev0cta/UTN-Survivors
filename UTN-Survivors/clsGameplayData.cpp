#include "clsGameplayData.h"
#include <iostream>

GameplayData::GameplayData()
{
    tornadoCd = 2.0f;
    areaCd = 2.5f;
    tornadoDmgCd = 0.5f;
    areaDmgCd = 0.5f;
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

void GameplayData::dyingEnemies()
{

    for (int i = 0; i < spawnedSlimes.size();)
    {
        if (spawnedSlimes[i].getHealth() <= 0)
        {
            spawnedSlimes.erase(spawnedSlimes.begin() + i);
        }
        else
        {
            i++;
        }

    }
    for (int i = 0; i < spawnedElemSlimes.size();)
    {
        if (spawnedElemSlimes[i].getHealth() <= 0)
        {
            spawnedElemSlimes.erase(spawnedElemSlimes.begin() + i);
        }
        else
        {
            i++;
        }

    }
    for (int i = 0; i < spawnedSpartans.size();)
    {
        if (spawnedSpartans[i].getHealth() <= 0)
        {
            spawnedSpartans.erase(spawnedSpartans.begin() + i);
        }
        else
        {
            i++;
        }

    }
    for (int i = 0; i < spawnedReapers.size();)
    {
        if (spawnedReapers[i].getHealth() <= 0)
        {
            spawnedReapers.erase(spawnedReapers.begin() + i);
        }
        else
        {
            i++;
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

float GameplayData::getNearestEnemyAngle(sf::Vector2f playerPos)
{
    sf::Vector2f nearestPoint(playerPos);
    float minDistance = 100.0f;

    for (auto& enemy : getSlimes())
    {
        if (getDistance(enemy.getBody().getPosition(), playerPos) < minDistance) {
            nearestPoint = enemy.getBody().getPosition();
            minDistance = getDistance(enemy.getBody().getPosition(), playerPos);
        }
    }
    for (auto& enemy : getElemSlimes())
    {
        if (getDistance(enemy.getBody().getPosition(), playerPos) < minDistance) {
            nearestPoint = enemy.getBody().getPosition();
            minDistance = getDistance(enemy.getBody().getPosition(), playerPos);
        }
    }
    for (auto& enemy : getSpartans())
    {
        if (getDistance(enemy.getBody().getPosition(), playerPos) < minDistance) {
            nearestPoint = enemy.getBody().getPosition();
            minDistance = getDistance(enemy.getBody().getPosition(), playerPos);
        }
    }
    for (auto& enemy : getReapers())
    {
        if (getDistance(enemy.getBody().getPosition(), playerPos) < minDistance) {
            nearestPoint = enemy.getBody().getPosition();
            minDistance = getDistance(enemy.getBody().getPosition(), playerPos);
        }
    }


    if (minDistance == 25.47f)
        return -1.0f;

    float angle = atan2(nearestPoint.y - playerPos.y, nearestPoint.x - playerPos.x);

    return angle;
}

void GameplayData::createTornado(BulletAttack bulletTemplate, sf::Vector2f playerPos)
{
    std::cout << "TORNADO CD: " << tornadoCd<<std::endl;
    if (tornadoCd <= 0.0f) {
        BulletAttack e(bulletTemplate);
        e.setPosition(playerPos);
        e.setAngle(getNearestEnemyAngle(playerPos));


        tornadosSpawned.push_back(e);
        tornadoCd = 2.0f;
    }

}

void GameplayData::createAreaAttack(AreaAttack areaTemplate, sf::Vector2f playerPos)
{
    if (areaCd <= 0.0f) {
        AreaAttack e(areaTemplate);
        
        int degree = rand() % 360;

        int rad = degree * (3.14 / 180);

        int distance = 100.0f;
        
        e.setPosition(playerPos + sf::Vector2f(cos(rad) * distance, sin(rad) * distance));
        

        areaAttacksSpawned.push_back(e);
        areaCd = 2.5f;
    }
}

void GameplayData::UpdateEverySkill(float deltaTime)
{
    tornadoCd -= deltaTime;
    areaCd -= deltaTime;



    ///BORRAR A LOS EXPIRADOS

    for (int i = 0; i < tornadosSpawned.size();)
    {
        //std::cout << "tornado time alive" << tornadosSpawned[i].getTimeAlive() << std::endl;
        if (tornadosSpawned[i].getTimeAlive() >= 2.0f)
        {
            tornadosSpawned.erase(tornadosSpawned.begin() + i);
        }
        else
        {
            i++;
        }

    }
    
    for (int i = 0; i < areaAttacksSpawned.size();)
    {
        //std::cout << "tornado time alive" << tornadosSpawned[i].getTimeAlive() << std::endl;
        if (areaAttacksSpawned[i].getTimeAlive() >= 2.0f)
        {
            areaAttacksSpawned.erase(areaAttacksSpawned.begin() + i);
        }
        else
        {
            i++;
        }

    }


    ///UPDATEAR TODO
    for (auto& skill : tornadosSpawned)
    {
        skill.Update(deltaTime);
    }

    for (auto& skill : areaAttacksSpawned)
    {
        skill.Update(deltaTime);
    }

}

void GameplayData::DrawEverySkill(sf::RenderWindow& window)
{

    for (auto& skill : tornadosSpawned)
    {
        skill.Draw(window);
    }
    for (auto& skill : areaAttacksSpawned)
    {
        skill.Draw(window);
    }

}



void GameplayData::checkDmgCollision(float deltaTime, int playerDmg)
{
    tornadoDmgCd -= deltaTime;
    areaDmgCd -= deltaTime;


    if (tornadoDmgCd <= 0) {
        for (auto& skill : tornadosSpawned)
        {
            for (auto& enemy : getSlimes())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + playerDmg);
                }

            }
            for (auto& enemy : getElemSlimes())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + playerDmg);
                }

            }
            for (auto& enemy : getSpartans())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + playerDmg);
                }

            }
            for (auto& enemy : getReapers())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + playerDmg);
                }

            }
        }
        tornadoDmgCd = 0.5f;
    }

    if (areaDmgCd <= 0) {

        for (auto& skill : areaAttacksSpawned)
        {
            for (auto& enemy : getSlimes())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + 0.25 * playerDmg);
                }

            }
            for (auto& enemy : getElemSlimes())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + 0.25 * playerDmg);
                }

            }
            for (auto& enemy : getSpartans())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + 0.25 * playerDmg);
                }

            }
            for (auto& enemy : getReapers())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + 0.25 * playerDmg);
                }

            }
        }
        areaDmgCd = 0.5f;
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

///-------------------------------------------- MINI FUNCIONES ---------------------------------------


float GameplayData::getDistance(sf::Vector2f pos1, sf::Vector2f pos2)
{
    float Xdistance = abs(pos1.x - pos2.x);
    float Ydistance = abs(pos1.y - pos2.y);

    float distance = sqrt((Xdistance * Xdistance) + (Ydistance * Ydistance));
    
    return distance;
}
