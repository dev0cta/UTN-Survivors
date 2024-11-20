#include "clsGameplayData.h"
#include <iostream>

GameplayData::GameplayData()
{

    bossSpawned = false;
    bossBeaten = false;

    gameTime = 0.0f;

    enemyLevel = 0;
    spawnCd = 0.25f;

    tornadoCd = 2.0f;
    areaCd = 2.5f;
    areaCd = 2.5f;
    tornadoDmgCd = 0.5f;
    areaDmgCd = 0.5f;
    ballDmgCd = 0.5f;

    dmgTakenCd = 0.25f;

    ///STATISTICS
    timeSurvived = 0.0f;

    dmgTaken = 0;
    dmgDealt = 0;

    slimesDefeated = 0;
    elementalSlimesDefeated = 0;
    spartansDefeated = 0;
    reapersDefeated = 0;
    timesLeveledUp = 0;
    gameBeatedCounter = 0;



}

void GameplayData::ResetGameData(sf::RectangleShape& characterBody)
{
    characterBody.setPosition(sf::Vector2f(250.0f, 250.0f));
    levelingSystem.resetLeveling();


    bossBeaten = false;
    bossSpawned = false;

    enemyLevel = 0;
    gameTime = 0;

    getSlimes().clear();
    getElemSlimes().clear();
    getSpartans().clear();
    getReapers().clear();
    getDirubin().clear();

    areaAttacksSpawned.clear();
    tornadosSpawned.clear();
    spawnedBalls.clear();

    resetStatistics();




}

void GameplayData::randomSpawn(sf::Vector2f playerPos, float deltaTime, Slime slimeTemplate, ElementalSlime elemSlimeTemplate, Spartan spartanTemplate, Reaper reaperTemplate, Dirubin dirubinTemplate)
{

    gameTime += deltaTime*10;
    int minutesPassed = int(gameTime / 60);
    
    spawnCd -= deltaTime;

    std::cout << "gameTime: " << gameTime << std::endl;
    

    if (spawnCd <= 0.0f) {


        int randomSpawn = (rand() % 100) + 1;

        switch (minutesPassed)
        {
        case 0:                                         //25% elemSlime 75% slime

            spawnSlime(slimeTemplate, playerPos, minutesPassed);

            break;
        case 1:                                         //50% slime 50% elemental slime
            if (randomSpawn <= 50) {
                spawnSlime(slimeTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnElementalSlime(elemSlimeTemplate, playerPos, minutesPassed);
            }

            break;
        case 2:                                         //75% elemental slime 25% slime
            if (randomSpawn <= 75) {
                spawnElementalSlime(elemSlimeTemplate, playerPos,  minutesPassed);
            }
            else
            {
                spawnSlime(slimeTemplate, playerPos,  minutesPassed);
            }

        case 3:                                         //80% elemental slime 20% spartan
            if (randomSpawn <= 80) {
                spawnElementalSlime(elemSlimeTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnSpartan(spartanTemplate, playerPos, minutesPassed);
            }
            break;
        case 4:                                         //40% elemental slime 60% spartan
            if (randomSpawn <= 40) {
                spawnElementalSlime(elemSlimeTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnSpartan(spartanTemplate, playerPos, minutesPassed);
            }
            break;
        case 5:                                         //20% elemental slime 70% spartan 10% reaper
            if (randomSpawn <= 20) {
                spawnElementalSlime(elemSlimeTemplate, playerPos, minutesPassed);
            }
            else if (randomSpawn <= 90)
            {
                spawnSpartan(spartanTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnReaper(reaperTemplate, playerPos, minutesPassed);
            }
            break;
        case 6:                                         //15% elemental slime 70% spartan 15% reaper
            if (randomSpawn <= 15) {
                spawnElementalSlime(elemSlimeTemplate, playerPos, minutesPassed);
            }
            else if (randomSpawn <= 90)
            {
                spawnSpartan(spartanTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnReaper(reaperTemplate, playerPos, minutesPassed);
            }
            break;
        case 7:                                         //15% elemental slime 45% spartan 40% reaper
            if (randomSpawn <= 15) {
                spawnElementalSlime(elemSlimeTemplate, playerPos, minutesPassed);
            }
            else if (randomSpawn <= 60)
            {
                spawnSpartan(spartanTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnReaper(reaperTemplate, playerPos, minutesPassed);
            }
            break;
        case 8:                                         //40% spartan 60% reaper
            if (randomSpawn <= 40)
            {
                spawnSpartan(spartanTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnReaper(reaperTemplate, playerPos, minutesPassed);
            }
            break;
        case 9:                                         //50% spartan 50% reaper
            if (randomSpawn <= 50)
            {
                spawnSpartan(spartanTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnReaper(reaperTemplate, playerPos, minutesPassed);
            }
            break;
        case 10:

            if (!bossSpawned) {
                bossSpawned = true;
                spawnDirubin(dirubinTemplate, playerPos);
            }

            if (randomSpawn <= 75)
            {
                spawnSpartan(spartanTemplate, playerPos, minutesPassed);
            }
            else
            {
                spawnReaper(reaperTemplate, playerPos, minutesPassed);
            }
            break;
        default:
            //no spawn, termina el juego si se mato al boss

            break;
        }
        spawnCd = 0.4f;
    }

}

bool GameplayData::isGameBeaten()
{
    timesLeveledUp = levelingSystem.getLevel() - 1;

    if (bossBeaten) {
        gameBeatedCounter = 1;
        return true;
    }
    else {
        return false;
    }
}


void GameplayData::UpdateEveryEnemy(float deltaTime, sf::Vector2f playerPos)
{

    ///statistics
    timeSurvived += deltaTime;

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

    for (auto& enemy : getDirubin())
    {
        enemy.Update(deltaTime, playerPos);
    }

}

void GameplayData::checkPlayerCollision(CircleCollider playerCollider, Player& player, float deltaTime)
{
    dmgTakenCd -= deltaTime;

    bool canTakeDmg = false;
    if (dmgTakenCd <= 0) {
        canTakeDmg = true;
    }

    for (auto& enemy : getSlimes())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f) && canTakeDmg) {
            CheckDamageEnemy(player, enemy.getDmg());
            dmgTakenCd = 0.5f;
            ///statistics
            dmgTaken += enemy.getDmg();
        }

    }
    for (auto& enemy : getElemSlimes())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f) && canTakeDmg) {
            CheckDamageEnemy(player, enemy.getDmg());
            dmgTakenCd = 0.5f;
            ///statistics
            dmgTaken += enemy.getDmg();
        }
    }
    for (auto& enemy : getSpartans())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f) && canTakeDmg) {
            CheckDamageEnemy(player, enemy.getDmg());
            dmgTakenCd = 0.5f;
            ///statistics
            dmgTaken += enemy.getDmg();
        }
    }
    for (auto& enemy : getReapers())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f) && canTakeDmg) {
            CheckDamageEnemy(player, enemy.getDmg());
            dmgTakenCd = 0.5f;
            ///statistics
            dmgTaken += enemy.getDmg();
        }
    }
    for (auto& enemy : getReapers())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f) && canTakeDmg) {
            CheckDamageEnemy(player, enemy.getDmg());
            dmgTakenCd = 0.5f;
            ///statistics
            dmgTaken += enemy.getDmg();
        }
    }
    
    for (auto& enemy : getDirubin())
    {
        if (enemy.GetCollider().checkSolidCollision(playerCollider, 0.5f) && canTakeDmg) {
            CheckDamageEnemy(player, enemy.getDmg());
            dmgTakenCd = 0.5f;
            ///statistics
            dmgTaken += enemy.getDmg();
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
            levelingSystem.obtainExp(15);
            ///statistics
            slimesDefeated++;
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
            levelingSystem.obtainExp(15);
            ///statistics
            elementalSlimesDefeated++;
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
            levelingSystem.obtainExp(15);
            ///statistics
            spartansDefeated++;
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
            levelingSystem.obtainExp(15);
            ///statistics
            reapersDefeated++;
        }
        else
        {
            i++;
        }

    }
    
    for (int i = 0; i < spawnedDirubin.size();)
    {
        if (spawnedDirubin[i].getHealth() <= 0)
        {
            spawnedDirubin.erase(spawnedDirubin.begin() + i);
            levelingSystem.obtainExp(15);
            bossBeaten = true;

            
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
    for (auto& enemy : getDirubin())
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
    for (auto& enemy : getDirubin())
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

void GameplayData::UpdateEverySkill(sf::Vector2f playerpos, float deltaTime)
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
    for (auto& skill : spawnedBalls)
    {
        skill.update(playerpos, deltaTime);
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
    for (auto& skill : spawnedBalls)
    {
        skill.draw(window);
    }
}



void GameplayData::checkDmgCollision(float deltaTime, int playerDmg)
{
    tornadoDmgCd -= deltaTime;
    areaDmgCd -= deltaTime;
    ballDmgCd -= deltaTime;

    if (tornadoDmgCd <= 0) {
        for (auto& skill : tornadosSpawned)
        {
            for (auto& enemy : getSlimes())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.75 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.75 * playerDmg);
                }

            }
            for (auto& enemy : getElemSlimes())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.75 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.75 * playerDmg);
                }

            }
            for (auto& enemy : getSpartans())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.75 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.75 * playerDmg);
                }

            }
            for (auto& enemy : getReapers())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.75 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.75 * playerDmg);
                }

            }
            for (auto& enemy : getDirubin())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.75 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.75 * playerDmg);
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
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.25 * playerDmg);
                }

            }
            for (auto& enemy : getElemSlimes())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.25 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.25 * playerDmg);
                }

            }
            for (auto& enemy : getSpartans())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.25 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.25 * playerDmg);
                }

            }
            for (auto& enemy : getReapers())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.25 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.25 * playerDmg);
                }

            }
            for (auto& enemy : getDirubin())
            {
                if (skill.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(skill.getDmg() + int(0.25 * playerDmg));
                    ///statistics
                    dmgDealt += skill.getDmg() + int(0.25 * playerDmg);
                }

            }
        }
        areaDmgCd = 0.5f;
    }

    if (ballDmgCd <= 0) {
        for (auto& ball : spawnedBalls) {
            for (auto& enemy : getSlimes()) {
                if (ball.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(ball.getDmg() + 0.4 * playerDmg);
                    ///statistics
                    dmgDealt += ball.getDmg() + 0.4 * playerDmg;
                }
            }
            for (auto& enemy : getElemSlimes()) {
                if (ball.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(ball.getDmg() + 0.4*playerDmg);
                    ///statistics
                    dmgDealt += ball.getDmg() + 0.4 * playerDmg;
                }
            }
            for (auto& enemy : getSpartans()) {
                if (ball.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(ball.getDmg() + 0.4 * playerDmg);
                    ///statistics
                    dmgDealt += ball.getDmg() + 0.4 * playerDmg;
                }
            }
            for (auto& enemy : getReapers()) {
                if (ball.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(ball.getDmg() + 0.4 * playerDmg);
                    ///statistics
                    dmgDealt += ball.getDmg() * 0.4 + playerDmg;
                }
            }
            for (auto& enemy : getDirubin())
            {
                if (ball.getCollider().checkCollision(enemy.GetCollider())) {
                    enemy.takeDmg(ball.getDmg() + 0.4 * playerDmg);
                    ///statistics
                    dmgDealt += ball.getDmg() + 0.4 * playerDmg;
                }

            }
        }
        ballDmgCd = 0.75f; // Resetear el tiempo de cooldown para la bola
    }
}

void GameplayData::createBall(MagicBall magicBallTemplate, sf::Vector2f playerpos)
{
    //std::cout << "Magic ball cd: " << ballDmgCd << std::endl;

    MagicBall e(magicBallTemplate);

    MagicBall newBall(magicBallTemplate);

    addMagicBall(newBall);

}

void GameplayData::addMagicBall(const MagicBall& newBall) {
    if (spawnedBalls.size() < 1) { // Limitar a un m�ximo de 1 bolas, cuandoa gregue mas veo el tema del angulo
        spawnedBalls.push_back(newBall);
    }
    else {
        // std::cout << "Ya alcanzaste el m�ximo de bolas m�gicas (3)." << std::endl;
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

int GameplayData::getCurrentExp()
{
    return levelingSystem.getCurrentExperience();
}

int GameplayData::getExpNeeded()
{
    return levelingSystem.getExpNeeded();
}






std::vector<Slime>& GameplayData::getSlimes()
{

    return spawnedSlimes;

}

void GameplayData::spawnSlime(Slime slimeTemplate, sf::Vector2f playerPos, int minutesPassed)
{

   // if (spawnedSlimes.size() < 10) {

        Slime e(slimeTemplate);

        int type = rand() % 3;

        int degree = rand() % 360;

        float rad = degree * (3.14 / 180);

        float distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));

        e.setLevel(minutesPassed);
        e.setType(type);

        spawnedSlimes.push_back(e);
   // }

}



std::vector<ElementalSlime>& GameplayData::getElemSlimes()
{
    return spawnedElemSlimes;
}

void GameplayData::spawnElementalSlime(ElementalSlime elemSlimeTemplate, sf::Vector2f playerPos, int minutesPassed)
{
    //if (spawnedElemSlimes.size() < 10) {

        ElementalSlime e(elemSlimeTemplate);

        int type = rand() % 3;

        int degree = rand() % 360;

        float rad = degree * (3.14 / 180);

        float distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));

        e.setLevel(minutesPassed);
        e.setType(type);

        spawnedElemSlimes.push_back(e);
   // }


}


std::vector<Spartan>& GameplayData::getSpartans()
{
    return spawnedSpartans;
}

void GameplayData::spawnSpartan(Spartan spartanTemplate, sf::Vector2f playerPos, int minutesPassed)
{
   // if (spawnedSpartans.size() < 10) {

        Spartan e(spartanTemplate);



        int degree = rand() % 360;

        int rad = degree * (3.14 / 180);

        float distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));

        e.setLevel(minutesPassed);
        spawnedSpartans.push_back(e);
   // }
}



std::vector<Reaper>& GameplayData::getReapers()
{
    return spawnedReapers;
}

void GameplayData::spawnReaper(Reaper reaperTemplate, sf::Vector2f playerPos, int minutesPassed)
{
   // if (spawnedReapers.size() < 10) {

        Reaper e(reaperTemplate);

        int degree = rand() % 360;

        float rad = degree * (3.14 / 180);

        float distance = 250.0f;

        e.getBody().setPosition(playerPos + sf::Vector2f(float(cos(rad)) * distance, float(sin(rad)) * distance));
        e.setLevel(minutesPassed);
        spawnedReapers.push_back(e);
   // }
}

std::vector<Dirubin>& GameplayData::getDirubin()
{
    return spawnedDirubin;
}

void GameplayData::spawnDirubin(Dirubin dirubinTemplate, sf::Vector2f playerPos)
{

    Dirubin e(dirubinTemplate);


    float distance = 250.0f;

    e.getBody().setPosition(playerPos + sf::Vector2f(0.0f, 1 * distance));

    spawnedDirubin.push_back(e);
}


///-------------------------------------------- MINI FUNCIONES ---------------------------------------


void GameplayData::loadTimesLeveledUp()
{
    timesLeveledUp = levelingSystem.getLevel();

}

Statistics GameplayData::getGameStatistics()
{

    Statistics obj(timeSurvived, dmgTaken, dmgDealt, slimesDefeated,
        elementalSlimesDefeated, spartansDefeated, reapersDefeated, timesLeveledUp, gameBeatedCounter);

    return obj;
}

void GameplayData::saveSomeData()
{
    timesLeveledUp = levelingSystem.getLevel();
}

void GameplayData::resetStatistics()
{
    timeSurvived = 0.0f;
    dmgTaken = 0;
    dmgDealt = 0;
    slimesDefeated = 0;
    elementalSlimesDefeated = 0;
    spartansDefeated = 0;
    reapersDefeated = 0;
    timesLeveledUp = 0;
    gameBeatedCounter = 0;

}

float GameplayData::getDistance(sf::Vector2f pos1, sf::Vector2f pos2)
{
    float Xdistance = abs(pos1.x - pos2.x);
    float Ydistance = abs(pos1.y - pos2.y);

    float distance = sqrt((Xdistance * Xdistance) + (Ydistance * Ydistance));
    
    return distance;
}
