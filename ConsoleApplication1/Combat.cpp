#include "Combat.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h> 

void Combat::InitCombat(Player& MC, Enemy& target, std::string MoveName)
{
	std::cout << "Enemy Encountered! (Press any button to continue)" << std::endl;
	int chP = _getch();
	system("cls");
	srand(time(NULL));

	bool InCombat = true;
	while (InCombat) {
		Update(InCombat, MC, target, Movename);
	}
}

bool Combat::Update(bool& InCombat, Player& MC, Enemy& target, std::string MoveName)
{
	std::cout << "What will you do?" << std::endl;
	std::cout << "(1) Attack" << std::endl;
	std::cout << "(2) Defend" << std::endl;
	std::cout << "(3) Item" << std::endl;
	std::cout << "(4) Run" << std::endl;
	bool Defend = false;
	int chP = _getch();
	system("cls");
	switch (chP) {
	case 1:
		//Include Player Moveset
		std::cout << "Choose a Move" << std::endl;
		std::cout << "(1) " << std::endl;
		std::cout << "(2) " << std::endl;
		std::cout << "(3) " << std::endl;
		std::cout << "(4) " << std::endl;
		Combat::PlayerAttack(MC, target, Movename);
		break;
	case 2:
		Defend = true;
		break;
	case 3:
		//Input inventory system
		break;
	case 4:
		int RunChance = rand() % 3;
		if (RunChance == 2) {
			std::cout << "Successfuly Ran Away" << std::endl;
			return true;
		}
		else if (RunChance == 1) {
			std::cout << "Ran Away but Damaged" << std::endl;
			MC.setPlayerHP(MC.getPlayerHP() - 5);
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
	if (target.getEnemyHP() <= 0) {
		std::cout << "Enemy Defeated! Gained XP!" << std::endl;
		MC.setPlayerXP(MC.getPlayerXP() + target.getEnemyXP());
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
		Combat::EnemyAttack(MC, target, Movename);
		return false;
	}
}

void Combat::PlayerAttack(Player& MC, Enemy& target, std::string MoveName)
{
	std::cout << MC.getPlayerClass() << " used " << MoveName << std::endl;
	target.setEnemyHP(target.getEnemyHP() - MC.getPlayerPower());
	std::cout << target.getEnemyClass() << " has " << target.getEnemyHP() << " HP left." << std::endl;
}

void Combat::EnemyAttack(Player& MC, Enemy& target, std::string MoveName)
{
	std::cout << target.getEnemyClass() << " used " << MoveName << std::endl;
	MC.setPlayerHP(MC.getPlayerHP() - target.getEnemyPower());
	std::cout << MC.getPlayerClass() << " has " << MC.getPlayerHP() << " HP left." << std::endl;
}
