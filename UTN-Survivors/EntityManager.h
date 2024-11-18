#pragma once
#include <iostream>
#include <vector>
class EntityManager
{
public:
	EntityManager();
	bool CreateEnemy();
	void Update();
private:
	int TotalEnemies[50] = {0};

};

