#include "clsGameplayData.h"
#include <iostream>

GameplayData::GameplayData()
{

    sf::Clock gameClock;

    enemyLevel = 0;

    tornadoCd = 2.0f;
    areaCd = 2.5f;
    tornadoDmgCd = 0.5f;
    areaDmgCd = 0.5f;

    for (int i = 0; i < 3; i++)
    {
        skillLevels[i] = 0;
    }
}

void GameplayData::ResetGameData(sf::RectangleShape& characterBody)
{
    characterBody.setPosition(sf::Vector2f(250.0f, 250.0f));
    levelingSystem.resetLeveling();

    enemyLevel = 0;
    gameTime = 0;

    getSlimes().clear();
    getElemSlimes().clear();
    getSpartans().clear();
    getReapers().clear();


    for (int i = 0; i < 3; i++)
    {
        skillLevels[i] = 0;
    }
}

void GameplayData::randomSpawn(sf::Vector2f playerPos, float deltaTime, Slime slimeTemplate, ElementalSlime elemSlimeTemplate, Spartan spartanTemplate, Reaper reaperTemplate)
{
    gameTime += deltaTime;
    int minutesPassed = int(deltaTime / 60);
    
    

    int randomSpawn = (rand() % 100) + 1;

    switch (minutesPassed)
    {
    case 0:                                         //25% elemSlime 75% slime

            spawnSlime(slimeTemplate, playerPos);
       
        break;
    case 1:                                         //50% slime 50% elemental slime
        if (randomSpawn <= 50) {
            spawnSlime(slimeTemplate, playerPos);
        }
        else
        {
            spawnElementalSlime(elemSlimeTemplate, playerPos);
        }

        break;
    case 2:                                         //75% elemental slime 25% slime
        if (randomSpawn <= 75) {
            spawnElementalSlime(elemSlimeTemplate, playerPos);
        }
        else
        {
            spawnSlime(slimeTemplate, playerPos);
        }
        
    case 3:                                         //80% elemental slime 20% spartan
        if (randomSpawn <= 80) {
            spawnElementalSlime(elemSlimeTemplate, playerPos);
        }
        else
        {
            spawnSpartan(spartanTemplate, playerPos);
        }
        break;
    case 4:                                         //40% elemental slime 60% spartan
        if (randomSpawn <= 40) {
            spawnElementalSlime(elemSlimeTemplate, playerPos);
        }
        else
        {
            spawnSpartan(spartanTemplate, playerPos);
        }
        break;
    case 5:                                         //20% elemental slime 70% spartan 10% reaper
        if (randomSpawn <= 20) {
            spawnElementalSlime(elemSlimeTemplate, playerPos);
        }
        else if(randomSpawn <= 90)
        {
            spawnSpartan(spartanTemplate, playerPos);
        }
        else
        {
            spawnReaper(reaperTemplate, playerPos);
        }
        break;
    case 6:                                         //15% elemental slime 70% spartan 15% reaper
        if (randomSpawn <= 15) {
            spawnElementalSlime(elemSlimeTemplate, playerPos);
        }
        else if (randomSpawn <= 90)
        {
            spawnSpartan(spartanTemplate, playerPos);
        }
        else
        {
            spawnReaper(reaperTemplate, playerPos);
        }
        break;
    case 7:                                         //15% elemental slime 45% spartan 40% reaper
        if (randomSpawn <= 15) {
            spawnElementalSlime(elemSlimeTemplate, playerPos);
        }
        else if (randomSpawn <= 60)
        {
            spawnSpartan(spartanTemplate, playerPos);
        }
        else
        {
            spawnReaper(reaperTemplate, playerPos);
        }
        break;
    case 8:                                         //40% spartan 60% reaper
        if (randomSpawn <= 40)
        {
            spawnSpartan(spartanTemplate, playerPos);
        }
        else
        {
            spawnReaper(reaperTemplate, playerPos);
        }
        break;
    case 9:                                         //50% spartan 50% reaper
        if (randomSpawn <= 50)
        {
            spawnSpartan(spartanTemplate, playerPos);
        }
        else
        {
            spawnReaper(reaperTemplate, playerPos);
        }
        break;
    case 10:
        if (randomSpawn <= 75)
        {
            spawnSpartan(spartanTemplate, playerPos);
        }
        else
        {
            spawnReaper(reaperTemplate, playerPos);
        }
        break;
    default:
        //no spawn termina el juego
        break;
    }

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

void GameplayData::checkPlayerCollision(CircleCollider playerCollider, Player& player)
{

    for (auto& enemy : getSlimes())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f)) {
            CheckDamageEnemy(player, enemy.getDmg());
        }

    }
    for (auto& enemy : getElemSlimes())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f)) {
            CheckDamageEnemy(player, enemy.getDmg());
        }
    }
    for (auto& enemy : getSpartans())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f)) {
            CheckDamageEnemy(player, enemy.getDmg());
        }
    }
    for (auto& enemy : getReapers())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f)) {
            CheckDamageEnemy(player, enemy.getDmg());
        }
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
            levelingSystem.obtainExp(10);
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
            levelingSystem.obtainExp(10);
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
            levelingSystem.obtainExp(10);
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
            levelingSystem.obtainExp(10);
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

void GameplayData::CheckDamageEnemy(Player& player, int dmgTaken)
{

    player.takeDmg(dmgTaken);
}

void GameplayData::createTornado(BulletAttack bulletTemplate, sf::Vector2f playerPos)
{
    //std::cout << "TORNADO CD: " << tornadoCd<<std::endl;
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

        float rad = float(degree * (3.14 / 180));

        float distance = 100.0f;
        
        e.setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));
        

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
                    enemy.takeDmg(skill.getDmg() + int(0.25 * playerDmg));
                }

            }
            for (auto& enemy : getElemSlimes())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.25 * playerDmg));
                }

            }
            for (auto& enemy : getSpartans())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.25 * playerDmg));
                }

            }
            for (auto& enemy : getReapers())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.25 * playerDmg));
                }

            }
        }
        areaDmgCd = 0.5f;
    }

}

int GameplayData::getLevel()
{
    return levelingSystem.getLevel();
}

void GameplayData::checkLevelUp()
{
    levelingSystem.checkLevelUp();
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

        float rad = degree * (3.14 / 180);

        float distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));


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

        float rad = degree * (3.14 / 180);

        float distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));


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

        float distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));


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

        float rad = degree * (3.14 / 180);

        float distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));

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
