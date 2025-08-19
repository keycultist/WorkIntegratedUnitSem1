#include "Combat.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h> 

void Combat::InitCombat(Player& MC, Enemy& target)
{
	std::cout << "Enemy Encountered! (Press any button to continue)" << std::endl;
	int chP = _getch();
	system("cls");
	srand(time(NULL));

	bool InCombat = true;
	while (InCombat) {
		Update(InCombat, MC, target);
	}
}

bool Combat::Update(bool& InCombat, Player& MC, Enemy& target)
{
	std::cout << "What will you do?" << std::endl;
	std::cout << "(1) Attack" << std::endl;
	std::cout << "(2) Defend" << std::endl;
	std::cout << "(3) Item" << std::endl;
	std::cout << "(4) Run" << std::endl;
	int ChosenMove;
	bool Critted = false;
	int Critting = rand() % 100 + 1;
	bool Defend = false;
	int RunChance = rand() % 3;
	int chP = _getch();
	system("cls");
	switch (chP) {
	case '1':
		//Include Player Moveset
		std::cout << "Choose a Move" << std::endl;
		std::cout << "Note: Dark moves cost 15% of your HP" << std::endl;
		std::cout << "(1) " << MC.GetMoveset().GetMove(0).MoveName << " Strength: " << MC.GetMoveset().GetMove(0).MoveStrength << " Hit(s): " << MC.GetMoveset().GetMove(0).Hits << " Type: " << MC.GetMoveset().GetMove(0).MoveType << std::endl;
		std::cout << "(2) " << MC.GetMoveset().GetMove(1).MoveName << " Strength: " << MC.GetMoveset().GetMove(1).MoveStrength << " Hit(s): " << MC.GetMoveset().GetMove(1).Hits << " Type: " << MC.GetMoveset().GetMove(1).MoveType << std::endl;
		std::cout << "(3) " << MC.GetMoveset().GetMove(2).MoveName << " Strength: " << MC.GetMoveset().GetMove(2).MoveStrength << " Hit(s): " << MC.GetMoveset().GetMove(2).Hits << " Type: " << MC.GetMoveset().GetMove(2).MoveType << std::endl;
		std::cout << "(4) " << MC.GetMoveset().GetMove(3).MoveName << " Strength: " << MC.GetMoveset().GetMove(3).MoveStrength << " Hit(s): " << MC.GetMoveset().GetMove(3).Hits << " Type: " << MC.GetMoveset().GetMove(3).MoveType << std::endl;
		std::cin >> ChosenMove;
		if (Critting <= MC.GetPlayerCritChance()) {
			Critted = true;
		}
		Combat::PlayerAttack(MC, target, ChosenMove, Critted);
		break;
	case '2':
		Defend = true;
		break;
	case '3':
		//Input inventory system
		break;
	case '4':
		if (RunChance == 2) {
			std::cout << "Successfuly Ran Away" << std::endl;
			return true;
		}
		else if (RunChance == 1) {
			std::cout << "Ran Away but Damaged" << std::endl;
			MC.SetPlayerHP(MC.GetPlayerHP() - 5);
			return true;
		}
		else {
			std::cout << "Failed to Run" << std::endl;
			return false;
		}
		break;
	default:
		break;
	}
	if (target.GetEnemyHP() <= 0) {
		std::cout << "Enemy Defeated! Gained XP!" << std::endl;
		MC.SetPlayerXP(MC.GetPlayerXP() + target.GetEnemyXP());
		MC.LevelUpCheck();
		int chP = _getch();
		system("cls");
		return true;
	}
	else {
		std::cout << "Enemy's turn" << std::endl;
		int chP = _getch();
		system("cls");
		int EnemyMoveChoice = rand() % 4 + 1;
		// Include Enemy Moveset
		switch (EnemyMoveChoice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}
		Combat::EnemyAttack(MC, target, EnemyMoveChoice, Defend);
		return false;
	}
}

void Combat::PlayerAttack(Player& MC, Enemy& target, int ChosenMove, bool Critted)
{
	if (MC.GetMoveset().GetMove(ChosenMove).MoveType == "Dark") {
		std::cout << "Dark Move Used! -15%HP" << std::endl;
		MC.SetPlayerHP(MC.GetPlayerHP() * 0.85);
	}
	for (int i = 0; i < MC.GetMoveset().GetMove(ChosenMove).Hits; i++) {
		std::cout << MC.GetPlayerClass() << " used " << MC.GetMoveset().GetMove(ChosenMove).MoveName << std::endl;
		if (Critted) {
			target.SetEnemyHP(target.GetEnemyHP() - (MC.GetPlayerPower() + MC.GetMoveset().GetMove(ChosenMove).MoveStrength) * 2);
			std::cout << "Critical Hit!" << std::endl;
		}
		else {
			target.SetEnemyHP(target.GetEnemyHP() - (MC.GetPlayerPower() + MC.GetMoveset().GetMove(ChosenMove).MoveStrength));
		}
		std::cout << target.GetEnemyClass() << " has " << target.GetEnemyHP() << " HP left." << std::endl;
	}
}

void Combat::EnemyAttack(Player& MC, Enemy& target, int ChosenMove, bool Defend)
{
	std::cout << target.GetEnemyClass() << " used " << MoveName << std::endl;
	if (!Defend) {
		MC.SetPlayerHP(MC.GetPlayerHP() - target.GetEnemyPower());
	}
	else if (Defend) {
		MC.SetPlayerHP(MC.GetPlayerHP() - (target.GetEnemyPower() * 0.40));
	}
	std::cout << MC.GetPlayerClass() << " has " << MC.GetPlayerHP() << " HP left." << std::endl;
}
