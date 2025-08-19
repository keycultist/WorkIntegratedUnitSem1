#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "Enemy.h"
class Combat
{
public:
	void InitCombat(Player& MC, Enemy& target);
	bool Update(bool& InCombat, Player& MC, Enemy& target);

	static void PlayerAttack(Player& MC, Enemy& target, int ChosenMove);
	static void EnemyAttack(Player& MC, Enemy& target, int ChosenMove, bool Defend);
};

