#pragma once
#include <iostream>
#include <string>
#include "Player.h"
class Combat
{
public:
	void InitCombat(Player& MC, Enemy& target, std::string MoveName);
	bool Update(bool& InCombat, Player& MC, Enemy& target, std::string MoveName);

	static void PlayerAttack(Player& MC, Enemy& target, std::string MoveName);
	static void EnemyAttack(Player& MC, Enemy& target, std::string MoveName);
};

