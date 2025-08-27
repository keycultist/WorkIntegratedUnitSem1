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
	bool turnEnd = false;
	int ChosenMove = 0;
	bool Defend = false;
	int RunChance = rand() % 10;
	while (!turnEnd) {
		std::cout << "You are fighting a: " << target.GetEnemyClass() << std::endl;
		std::cout << target.GetEnemyHP() << "HP" << std::endl;
		std::cout << "What will you do?" << std::endl;
		std::cout << "(1) Attack" << std::endl;
		std::cout << "(2) Defend" << std::endl;
		std::cout << "(3) Item" << std::endl;
		std::cout << "(4) Run" << std::endl;
		MC.ShowPlayerStats();
		ChosenMove = 0;
		Defend = false;
		RunChance = rand() % 10;
		const char* HORSEAscii = R"(
		                                                                                                              
                      @%                                                                                      
                      #@%*                                                    :-                              
                        %##+                                               ...--:                             
                         #%#++---                                        .:==++..                             
                         %%@@%##*+++=         :...    .  ..::.        .::=+*+*=..                             
                          %@@@@@%%%%#+-::..... . .....::...     ....:-*****##%+..                             
                          %@@@@@@@@@@#*=-+*#-::::=-.:::-++--...:+*-+#%#%##%%##+.                              
                            %@@@@@@@@@%%@@#=-+:::---:-.=-+--::.:#%%%%%%%###%%*:.                              
                             #@@@@@@@@@@@*=:++---==---==-++--:--.#@%%%%@%#%%+:.                               
                              #@@@@@@@@%#+--+#:-====-=-=*=++:-:=:-*%%%%%%##+:                                 
                               *@@@@@@%#*==+##=:==*==*===-=*=--==:=#%%%%#*=..                                 
                                *@@@@@%#+===#*=--++==*-+=-=*+----::-+###*-.                                   
                                -*@%%@%#*+==#*===+*+++-==:=**--=-.:-=+++-..                                   
                                -:+%%%%%#++=#+=++=++++-+*==#+--=-.:-===:..:                                   
                               =-:=#%%##**+=**+*++=++==+#=-*++---.:-=+-...                                    
                               -:=##%#####**#***++=+====*+-*#+--:.:==++=..                                    
                               :-+%***#*######%#++======+*-+##+--.-==-==-:                                    
                              ==-+*###%%%%%#%#*%#+=-=====#+*##%+==++=----:.                                   
                              ===+*#%@%%%%%%%%##%#+=+=+-=#+##*#*+-*###+=-:.                                   
                              ==+%@@@@@@@@@%%%%%%%#++*+--*+*##*#%+%%%##+=::                                   
                              -=*%@@@@@@@@%%%%#%%%##**==-++*##%##*%@@%%%##+                                   
                              -=%@@@@@@@@@%%@%#%%%*%##+-=++*#%##%*%%@@@%%*+                                   
                             =-+%%%@@@@@@@%%@%#%%#%%%#*=++***###%#%@%%@@@#=                                   
                             ==+###@@@@@@@@%%%%%%%##%##*=***####%#%%#%@%*:                                    
                             --+#%%@@@@@@@%%%@%%%%%%%#%#-+*#####%##%#**=::                                    
                             ==+#%#%@@@@@@%%%@%%%%%%%%#%=*%###*#%##**#*-::                                    
                             ==+#%#%%@@@@@%%%@%%%%%%%###+##**#####****+:::                                    
                            +--+*%%%@@@@@%%%%@%%%%%%%#######*####*****=.::                                    
                            =--+*%%%@@%@@%%%%@%%%%%%%######*#*##**++*+=..:                                    
                            =--=*%%%@@%@@%%%%%%%%%########******+*+**+-....                                   
                            =--=*%%%@@@@@%%#%%%%#####*####******+++**+-..:-                                   
                            -=--*%%%%@@@@%%###########********+++*+**+-. ..                                   
                            ====*%%%%@@@@%########**********++===+*#*+=. ..                                   
                           =-+==##%%%@@@@%%#*###*#**#*****+++=-==+*##+-..::                                   
                           =-+--%#%%@%@@%%%#**####*****##***+=:=++*#*+=...:                                   
                          --==++*#%%@@%%%%%#*#####*###*******+=-+++**+-::::                                   
                         =--=+=+##%%@@%%%%%#######*##**##**+===-++++++-:-.:                                   
                         +=-=-+###%@%@%%%%%#**=#**##******+==:.-=++++=:.:::                                   
                        =----*+*%#%@@@%%%%#*-=+++**###***++=-:..===**+.:....:                                 
                      ++-:=--***%#%@@@@%###*==++**##*****++=-:..-=+**=-::::..:.:                              
                     =-=+==--=*#%%%%@@@%%%#+==+**#*####*#*++=:..--+*+::-:::::...::                            
                   --+*+*+*=-=##%%%%%@@@%%*+=+***#*###******+=:.=+*+-:::--::=-..:.:-                          
                 ++++*+#**++-=*#%@@%%@@@%#++*%######%##*****#**=-++-:.::=-...:---::::                         
               +*+*#*#*##*=-::+#%@@@@@@@%**%%@@%%###%#######%%%#+=+-::-:-*=....===-:..:                       
             +==*#%%#%%@*++-::=#%@@@@@@@%*%@@@@@%%#%%%#%%%%%%#%@@+::.:---+++...-=+==-:.:                      
            **##%%%@%%%@%*+=::=*%@@@@@@@@%@@@@@@@@%%%%%%%%%@@%#@@#--..:-=-=*:...-+++=--.-                     
           #%@@%%@@@@%%#*=--:--+#@@@@@@@#%@@@@@%@@@@@%%%@@@@@%%%@#=-:.::--=++:...-++===:.:                    
          #%@@%%%@@@%%#++-==---+*@@@@@@@%%@@@@@%@@@@@%%%@@@@@%%%%#+-:::-==+===:...:-++=-::-                   
          %@@@@@@@@@#*===+*==--=+%@@@@@@@#%%@@@@@@@@@%%@@@@@@*###*==::==-==+==-.....-++=:::=                  
         #%@@@@@@@@#+=+--=+---==+%@@@@@@@%#@@%%@@@@@@@@@@@@@%****+==-:==++*+=++-.:....---::-                  
         %@@@@@@@%*+++++++*#*--++%@@@@@@@@#%@@@@@@@@@@@@@@@@%%#+=++=:::=****+=++=::..:::--::-                 
         %@@@@@%***+++++++**++:+*#@@@@@@@@%#%@@@%@@@@@@@@@%%#*+=+*+=-:-===*#=--=--::::..::::-                 
        %@@@@@%*+*+++=+##+*#++--**%@@@@@@@%#@%%%%@%@@@@%%%%#+==+++++-.:+=++*#++====:.:::..:--=                
        %@@@@%*++*+*#+#**###**+-=*%@@@@@@@@%%@@@%###%%%%##**#*++++++=:--++###*+=+=--:--:....:-                
        %%@%#*###*+=#####%%#*#+--*%@@@@@@@@@@@@@@@@@@@@@@%%#**#***++=--*+**###===+-==-::-=-..:=               
        %@%#@%*#%%##+=######%#+==*#@@@@@@@@@@@@@@@@%%#%%@%#%%###+**==-:+*#**##*++==+++---=++:::=              
        %#%%**##%%%%=+####%%%%%==+#%@@@@@@@@@@@@@@@@@@@@@@%%%###***==--=**#####*+++===-:+==+-:.:-             
       %@##%###%@@##%#%%##@%%@@++*#%@@@@@@@@@@@@@@@@@@@@@@@%%####*+-=-==++**####*++===--+=+=-::-:=            
      ####%%*%#@%%#%@#%%##@@@@#+**#%@@@@@@@@@@@@@@@@@@@@@@@@%#*##**====+++*#####*+=:==---====-=-.:=           
      %@#%%%@%@%%@@@#%@%#%@@@@**#*#%@@@@@@@@@@@@@@@@@@@@@@@%%%###**+=====+#*#%###+==:+=-:-=++=------          
     ##%%%#@@@@%%@@%%%#%@@@@@%#%%##%@@@@@@@@@@@@@@@@@@@@@@@%#####*#*++-=++++*##**#*==-=-=--+==+=----=         
     %@%%#%%@@%@@@@##%%@@@@@@%@%%##@@@@@@@@@@@@@@@@@@@@@@@@%%%##%#*#+++++++**#####*+==-:--=++====--=-         
		)";
		turnEnd = false;

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
			chP = _getch();
			turnEnd = true;
			break;
		case '2':
			std::cout << "Prepaired to Defend" << std::endl;
			Defend = true;
			chP = _getch();
			turnEnd = true;
			break;
		case '3':
			MC.UpdateInventoryPlayerStats();
			std::cout << MC.GetInventory().DrawInventoryUI() << std::endl;
			std::cout << "Use an item? Y/N" << std::endl;
			chP = _getch();
			if (chP == 'y') {
				MC.GetInventory().PromptPlayerUseItem();
				MC.UpdatePlayerStatsInventory();
				turnEnd = true;
			}
			else {
				turnEnd = false;
			}
			break;
		case '4':
			if (RunChance >= 8) {
				std::cout << "Successfuly Ran Away" << std::endl;
				return true;
			}
			else if (RunChance >= 4 && RunChance < 8) {
				std::cout << "Ran Away but Damaged" << std::endl;
				MC.SetPlayerHP(MC.GetPlayerHP() * 0.95);
				return true;
			}
			else {
				std::cout << "Failed to Run" << std::endl;
				return false;
				turnEnd = true;
			}
			chP = _getch();
			break;
		case 'h':
			std::cout << HORSEAscii << "\n";
			turnEnd = true;
			break;
		default:
			turnEnd = false;
			break;
		}
		system("cls");
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
		int EnemyMoveChoice = target.DecisionMatrix(MC.GetPlayerHP(), MC.GetPlayerPower() > 0);
		Combat::EnemyAttack(MC, target, EnemyMoveChoice, Defend);
		chP = _getch();
		system("cls");
		return false;
	}
	if (MC.GetPlayerHP() <= 0) { //Player death check
		std::cout << "Player Defeated! You Lose!" << std::endl;
		system("cls");
		return true;
	}
}

void Combat::PlayerAttack(Player& MC, Enemy& target, int ChosenMove)
{
	int Critting = rand() % 100 + 1;
	bool Critted = false;
	if (MC.GetMoveSet().GetMove(ChosenMove).MoveType == "Heal") {
		MC.SetPlayerHP(MC.GetPlayerHP() + (MC.GetMoveSet().GetMove(ChosenMove).MoveStrength));
		std::cout << "Healed " << MC.GetMoveSet().GetMove(ChosenMove).MoveStrength << " HP." << std::endl;
		if (MC.GetPlayerHP() > MC.GetPlayerMaxHP()) {
			MC.SetPlayerHP(MC.GetPlayerMaxHP());
		}
		std::cout << "Current HP: " << MC.GetPlayerHP() << "/" << MC.GetPlayerMaxHP() << std::endl;
	}
	//Heal Type, based on move strength
	else {
		if (MC.GetMoveSet().GetMove(ChosenMove).MoveType == "Dark") {
			std::cout << "Dark Move Used! -15%HP" << std::endl;
			MC.SetPlayerHP(MC.GetPlayerHP() - (MC.GetPlayerMaxHP() * 0.15));
		}
		//Dark Type, -15% maxHP

		for (int i = 0; i < MC.GetMoveSet().GetMove(ChosenMove).Hits; i++) {
			std::cout << std::endl;
			if (MC.GetMoveSet().GetMove(ChosenMove).MoveType == "Summon") {
				std::cout << MC.GetPlayerClass() << " used " << MC.GetMoveSet().GetMove(ChosenMove).MoveName << std::endl;
				MC.SetPlayerPower(MC.GetPlayerPower() + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength);
				std::cout << "Gained " << MC.GetMoveSet().GetMove(ChosenMove).MoveStrength << " Power" << std::endl;
				target.SetEnemyHP(target.GetEnemyHP() - MC.GetPlayerPower());
				std::cout << "Dealt: " << (MC.GetPlayerPower()) << " damage." << std::endl;
			}
			// Summon Type, adds move power to total power
			else if (MC.GetMoveSet().GetMove(ChosenMove).MoveType == "Ritual") {
				std::cout << MC.GetPlayerClass() << " used " << MC.GetMoveSet().GetMove(ChosenMove).MoveName << std::endl;
				MC.SetPlayerMaxHP(MC.GetPlayerMaxHP() - MC.GetMoveSet().GetMove(ChosenMove).MoveStrength);
				if (MC.GetPlayerHP() > MC.GetPlayerMaxHP()) {
					MC.SetPlayerHP(MC.GetPlayerMaxHP());
				}
				std::cout << "Consumed " << MC.GetMoveSet().GetMove(ChosenMove).MoveStrength << " Max HP" << std::endl;
				target.SetEnemyHP(target.GetEnemyHP() - MC.GetMoveSet().GetMove(ChosenMove).MoveStrength);
				std::cout << "Dealt: " << (MC.GetPlayerPower()) << " damage." << std::endl;
			}
			//Ritual Type, consumes MaxHP to use
			if (MC.GetMoveSet().GetMove(ChosenMove).MoveType == "Control") {
				std::cout << MC.GetPlayerClass() << " used " << MC.GetMoveSet().GetMove(ChosenMove).MoveName << std::endl;
				int controltypechosen = rand() % 4;
				std::cout << MC.GetPlayerClass() << " controlled the enemy into using " << target.GetMoveSet().GetMove(controltypechosen).MoveName << std::endl;
				//Can possibly add enemy move type differenciation
				for (int i = 0; i < target.GetMoveSet().GetMove(controltypechosen).Hits; i++) {
					target.SetEnemyHP(target.GetEnemyHP() - MC.GetPlayerPower());
					std::cout << "Dealt: " << (target.GetMoveSet().GetMove(controltypechosen).MoveStrength) << " damage." << std::endl;
				}
			}
			// Control Type, uses rand()%4 enemy's move
			else {
				Critting = rand() % 100 + 1;
				if (Critting <= MC.GetPlayerCritChance()) {
					Critted = true;
				}
				else {
					Critted = false;
				}
				std::cout << MC.GetPlayerClass() << " used " << MC.GetMoveSet().GetMove(ChosenMove).MoveName << std::endl;
				if (MC.GetMoveSet().GetMove(ChosenMove).MoveType == "Physical" || MC.GetMoveSet().GetMove(ChosenMove).MoveType == "Dark") {
					if (Critted) {
						target.SetEnemyHP(target.GetEnemyHP() - (MC.GetPlayerPower() + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength) * 2);
						std::cout << "Critical Hit! Dealt: " << (MC.GetPlayerPower() + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength) * 2 << " damage." << std::endl;
					}
					else {
						target.SetEnemyHP(target.GetEnemyHP() - (MC.GetPlayerPower() + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength));
						std::cout << "Dealt: " << (MC.GetPlayerPower() + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength) << " damage." << std::endl;
					}
				}
				//Physical/Dark, scales power
				else if (MC.GetMoveSet().GetMove(ChosenMove).MoveType == "Magical") {
					if (Critted) {
						target.SetEnemyHP(target.GetEnemyHP() - ((MC.GetPlayerMaxHP() / 10) + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength) * 2);
						std::cout << "Critical Hit! Dealt: " << ((MC.GetPlayerMaxHP() / 10) + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength) * 2 << " damage." << std::endl;
					}
					else {
						target.SetEnemyHP(target.GetEnemyHP() - ((MC.GetPlayerMaxHP() / 10) + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength));
						std::cout << "Dealt: " << ((MC.GetPlayerMaxHP() / 10) + MC.GetMoveSet().GetMove(ChosenMove).MoveStrength) << " damage." << std::endl;
					}
				}
				//Magical, scales MaxHP
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
		int DamageTaken = 0;
		std::cout << std::endl;
		Critting = rand() % 100 + 1;
		if (Critting <= target.GetEnemyCritChance()) {
			Critted = true;
		}
		else {
			Critted = false;
		}

		if (target.GetMoveSet().GetMove(ChosenMove).MoveType == "Physical" || target.GetMoveSet().GetMove(ChosenMove).MoveType == "BossMove" || target.GetMoveSet().GetMove(ChosenMove).MoveType == "DeathMove") {
			if (Critted) {
				DamageTaken += ((target.GetEnemyPower() + target.GetMoveSet().GetMove(ChosenMove).MoveStrength) * 2);
			}
			else {
				DamageTaken += ((target.GetEnemyPower() + target.GetMoveSet().GetMove(ChosenMove).MoveStrength));
			}
		}
		//Physical/BossMove/DeathMove, scales power
		else if (target.GetMoveSet().GetMove(ChosenMove).MoveType == "Magical") {
			if (Critted) {
				DamageTaken += (((target.GetEnemyMaxHP() / 10) + target.GetMoveSet().GetMove(ChosenMove).MoveStrength) * 2);
			}
			else {
				DamageTaken += (((target.GetEnemyMaxHP() / 10) + target.GetMoveSet().GetMove(ChosenMove).MoveStrength));

			}
		}
		//Magical, scales MaxHP
		else if (target.GetMoveSet().GetMove(ChosenMove).MoveType == "Abyssal") {
			if (Critted) {
				DamageTaken += (((target.GetEnemyMaxHP() / 8) + target.GetMoveSet().GetMove(ChosenMove).MoveStrength) * 2);
			}
			else {
				DamageTaken += (((target.GetEnemyMaxHP() / 8) + target.GetMoveSet().GetMove(ChosenMove).MoveStrength));

			}
		}
		//Abyssal, scales MaxHP but better
		else if (target.GetMoveSet().GetMove(ChosenMove).MoveType == "Buff") {
			target.SetEnemyMaxHP(target.GetEnemyMaxHP() + target.GetMoveSet().GetMove(ChosenMove).MoveStrength);
			target.SetEnemyHP(target.GetEnemyHP() + target.GetMoveSet().GetMove(ChosenMove).MoveStrength);
		}
		//Buff, like Summon, adds move str to a stat

		//...


		std::cout << target.GetEnemyClass() << " used " << target.GetMoveSet().GetMove(ChosenMove).MoveName << std::endl;
		if (Defend) {
			DamageTaken = (DamageTaken * 100) / (MC.GetPlayerDefence() + 100);
			if (DamageTaken <= 1) {
				DamageTaken = 1;
			}
			MC.SetPlayerHP(MC.GetPlayerHP() - DamageTaken / 2);
		}
		else if (!Defend) {
			DamageTaken = (DamageTaken * 100) / (MC.GetPlayerDefence() + 100);
			if (DamageTaken <= 1) {
				DamageTaken = 1;
			}
			MC.SetPlayerHP(MC.GetPlayerHP() - DamageTaken);
		}
		if (target.GetMoveSet().GetMove(ChosenMove).MoveType != "Buff") {
			std::cout << MC.GetPlayerClass() << " has " << MC.GetPlayerHP() << " HP left." << std::endl;
		}
		else if (target.GetMoveSet().GetMove(ChosenMove).MoveType == "Buff") {
			std::cout << target.GetEnemyClass() << " gained " << target.GetMoveSet().GetMove(ChosenMove).MoveStrength << " HP." << std::endl;
		}
	}
}

