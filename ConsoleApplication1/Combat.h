#pragma once
#include <iostream>
#include "Player.h"
#include "Enemy.h"

class Combat
{
private:
	static int tracker;

public:
	int GetTracker(void);

	static void InitCombat(Player& MC, Enemy& target);
	static void InitTutorialCombat(Player& MC, Enemy& target);
	static bool UpdateTutorial(bool& InCombat, Player& MC, Enemy& target);
	static bool Update(bool& InCombat, Player& MC, Enemy& target);

	static int ChoseAction(Player& MC, Enemy& target, int stage);
	static void PlayerAttack(Player& MC, Enemy& target, int ChosenMove);
	static void EnemyAttack(Player& MC, Enemy& target, int ChosenMove, bool Defend);
	static void PlaySoundOPA(Player& MC, int ChosenMove);

	static void DrawCombatUI(Player& MC, Enemy& target, std::string scene, int controltypechosen);
};

