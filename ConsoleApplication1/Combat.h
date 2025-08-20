#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"

class Combat
{
public:
	static void InitCombat(Player& MC, Enemy& target);
	static bool Update(bool& InCombat, Player& MC, Enemy& target);

	static void PlayerAttack(Player& MC, Enemy& target, int ChosenMove);
	static void EnemyAttack(Player& MC, Enemy& target, int ChosenMove, bool Defend);
};

