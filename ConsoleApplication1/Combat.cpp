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

	bool InCombat = true; //starts combat loop
	while (InCombat) {
		InCombat = !Update(InCombat, MC, target);
	}
}

bool Combat::Update(bool& InCombat, Player& MC, Enemy& target)
{
	std::cout << "You are fighting a: " << target.GetEnemyClass() << std::endl;
	std::cout << target.GetEnemyHP() << "HP" << std::endl;
	std::cout << "What will you do?" << std::endl;
	std::cout << "(1) Attack" << std::endl;
	std::cout << "(2) Defend" << std::endl;
	std::cout << "(3) Item" << std::endl;
	std::cout << "(4) Run" << std::endl;
	MC.ShowPlayerStats();
	int ChosenMove = 0;
	bool Defend = false;
	int RunChance = rand() % 3;
	int chP = _getch();
	system("cls");
	switch (chP) { //select action
	case '1':
		//Include Player Moveset
		MC.ShowPlayerMoves();
		chP = _getch();
		system("cls");
		switch (chP) {
		case '1':
			ChosenMove = 1;
			break;
		case '2':
			ChosenMove = 2;
			break;
		case '3':
			ChosenMove = 3;
			break;
		case '4':
			ChosenMove = 4;
			break;
		default:
			break;
		}
		Combat::PlayerAttack(MC, target, ChosenMove - 1);
		break;
	case '2':
		std::cout << "Prepaired to Defend" << std::endl;
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
			MC.SetPlayerHP(MC.GetPlayerHP() * 0.95);
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
	if (target.GetEnemyHP() <= 0) { //Enemy death check
		std::cout << "Enemy Defeated! Gained XP!" << std::endl;
		if (MC.GetPlayerClass() == "Berserker") {
			MC.SetPlayerPower(MC.GetPlayerPower() + target.GetEnemyXP());
			std::cout << "Gained XP converted to Power! You have: " << MC.GetPlayerPower() << " Power" << std::endl;
		}
		else {
			MC.SetPlayerXP(MC.GetPlayerXP() + target.GetEnemyXP());
		}
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
		chP = _getch();
		system("cls");
		return false;
	}
}

void Combat::PlayerAttack(Player& MC, Enemy& target, int ChosenMove)
{
	int Critting = rand() % 100 + 1;
	bool Critted = false;
	if (MC.GetMoveset().GetMove(ChosenMove).MoveType == "Heal") {
		MC.SetPlayerHP(MC.GetPlayerHP() + (MC.GetMoveset().GetMove(ChosenMove).MoveStrength));
		std::cout << "Healed " << MC.GetMoveset().GetMove(ChosenMove).MoveStrength << " HP." << std::endl;
		std::cout << "Current HP: " << MC.GetPlayerHP() << "/" << MC.GetPlayerMaxHP() << std::endl;
	} //Heal Type, based on move strength
	else {
		if (MC.GetMoveset().GetMove(ChosenMove).MoveType == "Dark") {
			std::cout << "Dark Move Used! -15%HP" << std::endl;
			MC.SetPlayerHP(MC.GetPlayerHP() - (MC.GetPlayerMaxHP() * 0.15));
		} //Dark Type, -15% maxHP

		for (int i = 0; i < MC.GetMoveset().GetMove(ChosenMove).Hits; i++) {
			std::cout << std::endl;
			if (MC.GetMoveset().GetMove(ChosenMove).MoveType == "Summon") {
				std::cout << MC.GetPlayerClass() << " used " << MC.GetMoveset().GetMove(ChosenMove).MoveName << std::endl;
				MC.SetPlayerPower(MC.GetPlayerPower() + MC.GetMoveset().GetMove(ChosenMove).MoveStrength);
				std::cout << "Gained " << MC.GetMoveset().GetMove(ChosenMove).MoveStrength << " Power" << std::endl;
				target.SetEnemyHP(target.GetEnemyHP() - MC.GetPlayerPower());
				std::cout << "Dealt: " << (MC.GetPlayerPower()) << " damage." << std::endl;
			} // Summon Type, adds move power to total power
			else if (MC.GetMoveset().GetMove(ChosenMove).MoveType == "Ritual") {
				std::cout << MC.GetPlayerClass() << " used " << MC.GetMoveset().GetMove(ChosenMove).MoveName << std::endl;
				MC.SetPlayerMaxHP(MC.GetPlayerMaxHP() - MC.GetMoveset().GetMove(ChosenMove).MoveStrength);
				if (MC.GetPlayerHP() > MC.GetPlayerMaxHP()) {
					MC.SetPlayerHP(MC.GetPlayerMaxHP());
				}
				std::cout << "Consumed " << MC.GetMoveset().GetMove(ChosenMove).MoveStrength << " Max HP" << std::endl;
				target.SetEnemyHP(target.GetEnemyHP() - MC.GetMoveset().GetMove(ChosenMove).MoveStrength);
				std::cout << "Dealt: " << (MC.GetPlayerPower()) << " damage." << std::endl;
			} //Ritual Type, consumes MaxHP to use
			else {
				Critting = rand() % 100 + 1;
				if (Critting <= MC.GetPlayerCritChance()) {
					Critted = true;
				}
				else {
					Critted = false;
				}
				std::cout << MC.GetPlayerClass() << " used " << MC.GetMoveset().GetMove(ChosenMove).MoveName << std::endl;
				if (MC.GetMoveset().GetMove(ChosenMove).MoveType == "Physical") {
					if (Critted) {
						target.SetEnemyHP(target.GetEnemyHP() - (MC.GetPlayerPower() + MC.GetMoveset().GetMove(ChosenMove).MoveStrength) * 2);
						std::cout << "Critical Hit! Dealt: " << (MC.GetPlayerPower() + MC.GetMoveset().GetMove(ChosenMove).MoveStrength) * 2 << " damage." << std::endl;
					}
					else {
						target.SetEnemyHP(target.GetEnemyHP() - (MC.GetPlayerPower() + MC.GetMoveset().GetMove(ChosenMove).MoveStrength));
						std::cout << "Dealt: " << (MC.GetPlayerPower() + MC.GetMoveset().GetMove(ChosenMove).MoveStrength) << " damage." << std::endl;
					}
				} //Physical, scales power
				else if (MC.GetMoveset().GetMove(ChosenMove).MoveType == "Magical") {
					if (Critted) {
						target.SetEnemyHP(target.GetEnemyHP() - ((MC.GetPlayerMaxHP() / 10) + MC.GetMoveset().GetMove(ChosenMove).MoveStrength) * 2);
						std::cout << "Critical Hit! Dealt: " << ((MC.GetPlayerMaxHP() / 10) + MC.GetMoveset().GetMove(ChosenMove).MoveStrength) * 2 << " damage." << std::endl;
					}
					else {
						target.SetEnemyHP(target.GetEnemyHP() - ((MC.GetPlayerMaxHP() / 10) + MC.GetMoveset().GetMove(ChosenMove).MoveStrength));
						std::cout << "Dealt: " << ((MC.GetPlayerMaxHP() / 10) + MC.GetMoveset().GetMove(ChosenMove).MoveStrength) << " damage." << std::endl;
					}
				} //Magical, scales MaxHP
			}
			std::cout << target.GetEnemyClass() << " has " << target.GetEnemyHP() << " HP left." << std::endl;
			if (target.GetEnemyHP() <= 0) {
				break;
			}
		}
	}
}

void Combat::EnemyAttack(Player& MC, Enemy& target, int ChosenMove, bool Defend)
{
	//WIP
	int Critting = rand() % 100 + 1;
	bool Critted = false;
	for (int i = 0; i < target.GetMoveSet().GetMove(ChosenMove).Hits; i++) {
		std::cout << std::endl;
		Critting = rand() % 100 + 1;
		if (Critting <= MC.GetPlayerCritChance()) {
			Critted = true;
		}
		else {
			Critted = false;
		}
		std::cout << target.GetEnemyClass() << " used " << target.GetMoveSet().GetMove(ChosenMove).MoveName << std::endl;
		if (!Defend) {
			MC.SetPlayerHP(MC.GetPlayerHP() - target.GetEnemyPower());
		}
		else if (Defend) {
			MC.SetPlayerHP(MC.GetPlayerHP() - (target.GetEnemyPower() * 0.40));
		}
		std::cout << MC.GetPlayerClass() << " has " << MC.GetPlayerHP() << " HP left." << std::endl;
	}
}
