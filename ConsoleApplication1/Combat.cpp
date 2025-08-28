#include "Combat.h"
#include "divine_intervention.h"
#include "Sound.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h> 
int Combat::tracker = 0;

int Combat::GetTracker(void)
{
	return tracker;
}

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

void Combat::InitTutorialCombat(Player& MC, Enemy& target) //WIP
{
	int chP = _getch();
	system("cls");
	srand(time(NULL));

	bool InCombat = true; //starts combat loop
	while (InCombat) {
		InCombat = !UpdateTutorial(InCombat, MC, target);
	}
}

bool Combat::UpdateTutorial(bool& InCombat, Player& MC, Enemy& target) //WIP
{
	DivineIntervention DivInter;
	bool turnEnd = false;
	int ChosenMove = 0;
	bool Defend = false;
	int RunChance = rand() % 10;
	int DivInt = 0;
	while (!turnEnd) {
		DivInt = rand() % 100 + 1;
		if (DivInt <= 30) {
			DivInter.applyEffect(DivInter.getRandomGod(), MC, target);
		}
		ChosenMove = 0;
		Defend = false;
		RunChance = rand() % 10;
		turnEnd = false;
		int chP;
		switch (ChoseAction(MC, target, 1)) { //select action
		case 1:
			system("cls");
			switch (ChoseAction(MC, target, 2)) {
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
				ChosenMove = 1;
				break;
			}
			Combat::PlayerAttack(MC, target, ChosenMove - 1);
			chP = _getch();
			turnEnd = true;
			break;
		case 2:
			std::cout << "Prepared to Defend" << std::endl;
			Defend = true;
			chP = _getch();
			turnEnd = true;
			break;
		case 3:
			MC.UpdateInventoryPlayerStats();
			std::cout << MC.GetInventory().DrawInventoryUI() << std::endl;
			std::cout << "Use an item? Y/N" << std::endl;
			chP = _getch();
			if (chP == 'y' || chP == 'Y') {
				MC.GetInventory().PromptPlayerUseItem();
				MC.UpdatePlayerStatsInventory();
				turnEnd = true;
			}
			else {
				turnEnd = false;
			}
			break;
		case 4:
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
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
		Combat::EnemyAttack(MC, target, EnemyMoveChoice, Defend);
		chP = _getch();
		system("cls");
	}
	if (MC.GetPlayerHP() <= 0) { //Player death check
		std::cout << "Player Defeated! You Lose!" << std::endl;
		system("cls");
		return true;
	}
	else {
		return false;
	}
}

bool Combat::Update(bool& InCombat, Player& MC, Enemy& target)
{
	DivineIntervention DivInter;
	bool turnEnd = false;
	int ChosenMove = 0;
	bool Defend = false;
	int RunChance = rand() % 10;
	int DivInt = 0;
	while (!turnEnd) {
		DivInt = rand() % 100 + 1;
		if (DivInt <= 30) {
			DivInter.applyEffect(DivInter.getRandomGod(), MC, target);
		}
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
                               :-+%***#*######%#++======+*-+##+--.-==-==-:           Neigh                     
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
		int chP;
		switch (ChoseAction(MC, target, 1)) { //select action
		case 1:
			//Include Player Moveset
			//MC.ShowPlayerMoves();
			system("cls");
			switch (ChoseAction(MC, target, 2)) {
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
				ChosenMove = 1;
				break;
			}
			Combat::PlayerAttack(MC, target, ChosenMove - 1);
			chP = _getch();
			turnEnd = true;
			break;
		case 2:
			std::cout << "Prepared to Defend" << std::endl;
			Defend = true;
			chP = _getch();
			turnEnd = true;
			break;
		case 3:
			MC.UpdateInventoryPlayerStats();
			std::cout << MC.GetInventory().DrawInventoryUI() << std::endl;
			std::cout << "Use an item? Y/N" << std::endl;
			chP = _getch();
			if (chP == 'y' || chP == 'Y') {
				MC.GetInventory().PromptPlayerUseItem();
				MC.UpdatePlayerStatsInventory();
				turnEnd = true;
			}
			else {
				turnEnd = false;
			}
			break;
		case 4:
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
		case 65:
			std::cout << HORSEAscii << "\n";
			MC.SetPlayerXP(MC.GetPlayerXP() + 1000);
			target.SetEnemyHP(0);
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
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
		Combat::EnemyAttack(MC, target, EnemyMoveChoice, Defend);
		chP = _getch();
		system("cls");
	}
	if (MC.GetPlayerHP() <= 0) { //Player death check
		std::cout << "Player Defeated! You Lose!" << std::endl;
		system("cls");
		return true;
	}
	else {
		return false;
	}
}

int Combat::ChoseAction(Player& MC, Enemy& target, int stage)
{
	bool ChosingAction = true;
	tracker = 0;
	int chP;
		if (stage == 1) {
			std::string c[4] = {
				"(1) Attack ",
				"(2) Defend ",
				"(3) Item   ",
				"(4) Run    ",
			};
			c[0] += "<--";
			tracker = 0;
			while (ChosingAction) {
				/*std::cout << "You are fighting a: " << target.GetEnemyClass() << std::endl;
				std::cout << target.GetEnemyHP() << "HP" << std::endl;
				std::cout << "What will you do?" << std::endl;
				std::cout << c[0] << std::endl;
				std::cout << c[1] << std::endl;
				std::cout << c[2] << std::endl;
				std::cout << c[3] << std::endl;*/
				DrawCombatUI(MC, target, "Action");
				chP = _getch();
				//std::cout << (int)chP << std::endl;
				system("cls");
				switch (chP) {
				case 'w':
				case 'W':
					c[tracker].erase(11);
					if (tracker == 0) {
						tracker = 3;
					}
					else {
						tracker -= 1;
					}
					c[tracker] += "<--";
					break;
				case 's':
				case 'S':
					c[tracker].erase(11);
					if (tracker == 3) {
						tracker = 0;
					}
					else {
						tracker += 1;
					}
					c[tracker] += "<--";
					break;
				case 13:
					ChosingAction = false;
					return tracker + 1;
				case 'h':
					ChosingAction = false;
					return 65;
				default:
					break;
				}
			}
		}

		if (stage == 2) {
			std::string c[4] = {
				'[' + MC.GetMoveSet().GetMove(0).MoveName + "] Strength: (" + std::to_string(MC.GetMoveSet().GetMove(0).MoveStrength) + ") Hits: (" + std::to_string(MC.GetMoveSet().GetMove(0).Hits) + ") Type: " + MC.GetMoveSet().GetMove(0).MoveType,
				'[' + MC.GetMoveSet().GetMove(1).MoveName + "] Strength: (" + std::to_string(MC.GetMoveSet().GetMove(1).MoveStrength) + ") Hits: (" + std::to_string(MC.GetMoveSet().GetMove(1).Hits) + ") Type: " + MC.GetMoveSet().GetMove(1).MoveType,
				'[' + MC.GetMoveSet().GetMove(2).MoveName + "] Strength: (" + std::to_string(MC.GetMoveSet().GetMove(2).MoveStrength) + ") Hits: (" + std::to_string(MC.GetMoveSet().GetMove(2).Hits) + ") Type: " + MC.GetMoveSet().GetMove(2).MoveType,
				'[' + MC.GetMoveSet().GetMove(3).MoveName + "] Strength: (" + std::to_string(MC.GetMoveSet().GetMove(3).MoveStrength) + ") Hits: (" + std::to_string(MC.GetMoveSet().GetMove(3).Hits) + ") Type: " + MC.GetMoveSet().GetMove(3).MoveType,
			};
			c[0] += " <--";
			tracker = 0;
			while (ChosingAction) {
				/*std::cout << "Choose your move" << std::endl;
				std::cout << target.GetEnemyHP() << "HP" << std::endl;
				std::cout << "What will you do?" << std::endl;
				std::cout << c[0] << std::endl;
				std::cout << c[1] << std::endl;
				std::cout << c[2] << std::endl;
				std::cout << c[3] << std::endl;*/
				DrawCombatUI(MC, target, "Moveset");
				chP = _getch();
				//std::cout << (int)chP << std::endl;
				system("cls");
				switch (chP) {
				case 'w':
				case 'W':
					c[tracker].erase(c[tracker].find(" <--"));
					if (tracker == 0) {
						tracker = 3;
					}
					else {
						tracker -= 1;
					}
					c[tracker] += " <--";
					break;
				case 's':
				case 'S':
					c[tracker].erase(c[tracker].find(" <--"));
					if (tracker == 3) {
						tracker = 0;
					}
					else {
						tracker += 1;
					}
					c[tracker] += " <--";
					break;
				case 13:
					ChosingAction = false;
					return tracker + 1;
				default:
					break;
				}
			}
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
					Sound::PlaySoundEffect("SwordSound");
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

			if (target.GetMoveSet().GetMove(ChosenMove).MoveType == "BossMove") {
				std::cout << "An overwhelming sense of dread washes over you." << std::endl;
			}

			if (target.GetMoveSet().GetMove(ChosenMove).MoveType == "DeathMove") {
				std::cout << "You feel nothing but malice." << std::endl;
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

















































void Combat::DrawCombatUI(Player& MC, Enemy& target, std::string scene) {
	std::string CombatPlayerUIString[18];

	if (MC.GetCurrentDifficulty() + 1 == 1 || MC.GetCurrentDifficulty() + 1 == 2) {
		std::string PlayerSpriteLines[18] = {
			"                            ..:.                  ",
			"                         .+@@%%@@.                ",
			"                        =@#.   :@*                ",
			"                       .@*     .@%                ",
			"                       .@*    .*@-                ",
			"                    .:=+=@%-:#@%.                 ",
			"                   .@@@@@%#*+:.                   ",
			"                   -@@@@@@@@@@@@@=                ",
			"                   %@@@@@@@@@@@@@@.               ",
			"                  -@=@@@@@@@@@@@@#.               ",
			"                 :@+ .@@@@@@@@@@@.                ",
			"                .@%.@@:.*@@%%**@@:                ",
			"                *@. %@@@@@@@@@@@@-                ",
			"               =@-  #@@@@@@@@@@:@=                ",
			"                    .*@@@@@@@* .@+                ",
			"                    .@% ..  %% .@#                ",
			"                    #%      *@: .:                ",
			"                   +@-      .@+                   ",
		};

		for (int i = 0; i < 18; i++) {
			CombatPlayerUIString[i] = PlayerSpriteLines[i];
		}

	}

	else if (MC.GetCurrentDifficulty() + 1 == 3 || MC.GetCurrentDifficulty() + 1 == 4) {

		std::string PlayerSpriteLines[18] = {
			"                            :-=-.                 ",
			"                          .+#***%@+.              ",
			"                        .+#+-----*@:              ",
			"                        =#=:----:+@=              ",
			"                        =#-:::---*%.              ",
			"                     ...:*#=---=#*.               ",
			"                   .+%%@@#*####+:                 ",
			"                   -*###%@@@@*+=--.               ",
			"                  :=*###@@@@@@@####-.             ",
			"                 :-+*##@@@@@@@@####*:             ",
			"                .:=*=+@@@@@@@@@###*-:             ",
			"               .:=#+--:%@@@@@@@%+#=::             ",
			"              .:-#+-*@*-:+%#****##+::.            ",
			"              .-**-:#@@@@@@@@@@@##*-:.            ",
			"             .:+#-:.*@@@@@@@@@@@*+#-:.            ",
			"             ::--:. .+@@@@@@@@@:.=*-::.           ",
			"              .::.   %@==++-=#@..=*=::.           ",
			"                    -@=      +@:.-*-::.           ",
		};

		for (int i = 0; i < 18; i++) {
			CombatPlayerUIString[i] = PlayerSpriteLines[i];
		}
	}



	else if (MC.GetCurrentDifficulty() + 1 == 5 || MC.GetCurrentDifficulty() + 1 == 6) {

		std::string PlayerSpriteLines[18] = {
			"                                                  ",
			"                                                  ",
			"                        :*##@@*                   ",
			"                      -**=--:=#=                  ",
			"                     -*=::--:.#%.                 ",
			"                     -+::::::-*+                  ",
			"                     :+=::::-+=                   ",
			"                 :#***-====+=.                    ",
			"                .++==+++++--:::                   ",
			"               .:+====++====--=-.                 ",
			"              .:====+++=====----:                 ",
			"              :-=::+++======---:.                 ",
			"             .-+-:: -+======-:-...                ",
			"            .:+=:-*+-..::..-=--:..                ",
			"           .:++::=***++++++++==:..                ",
			"          .:-+-:.:#******+++=:=-::.               ",
			"          .::::   :##******- .==::.               ",
			"            .    .*#.    .*+ .=+::.               ",
		};

		for (int i = 0; i < 18; i++) {
			CombatPlayerUIString[i] = PlayerSpriteLines[i];
		}
	}



	else {
		std::string PlayerSpriteLines[18] = {
			"                                                  ",
			"                              -+*=.               ",
			"                           :++=--+#=              ",
			"                          =+-:::::+*.             ",
			"                       ..-+:::::::+*.             ",
			"                   .....:-=------==-..            ",
			"                      .:=:-=----==:.              ",
			"                  ...-=======-----:-:::::.......  ",
			"                 ...:==============-----::.....   ",
			"                   .:=--========--=-:.......      ",
			"            .....:--==-=========----:..........   ",
			"           ...:...:==--==========--:::...         ",
			"               ..:-=---:-=====--::-::.            ",
			"    .. ...:::...:-=-:=+==::::..----:.. .          ",
			"    ...   ::-::::==::=+++========--:..            ",
			"       ....::::-===---++++++++++-:--..            ",
			"         .....::::-::::+*++++++-.:--:.            ",
			"                .    .*+     .+= .==::.           ",
		};

		for (int i = 0; i < 18; i++) {
			CombatPlayerUIString[i] = PlayerSpriteLines[i];
		}
	}

	std::string EnemySpriteLines[20] = {
		"           .::::.        #+                            ",
		"                :#####%##%*+=   :+             *.      ",
		"     =-          *###%%#%%#%#####+*.    =      #:      ",
		"      =+  =      :--#%+#%=*#*###########:      #:      ",
		"       -+. +: :  % #% -%  %: ###################:      ",
		"     .+ :+- =+=+#*#%%#%%#%%%%#########*##====@@#****   ",
		"      :+  +=.%+*%-%# #%#%%%%############%@@%+%-#=      ",
		"       :+: +%::%=##.%%**%#%%%########%@@@#@@##*#=      ",
		"      +++##%%#%%%%%%%%%%%%%%%%%%%%@@@@%@@%#%+#-=*      ",
		"       +- *%-#%#%%%%%%%%%%%%@@@@@@@@@@@@@@#%.#= #      ",
		"        +*%%%%%%%%%%#%%%%@@%%%@@%@@@%@@@%=@@+#=        ",
		"     :=+#%%%%%%%%%%%%@@@@@@@@@@@@%@@@%:%@@@#=##        ",
		"       -#***#%%%%%@@@@@@@@@@@@@@@@%#@@@@#-#@#.*%:   %@.",
		"    #%%%%%#####*****%*%=%%##@@@@@@@@@@:+@%*%@@* @@@+   ",
		"       *:#%%@@@@@@@@@@@@@#@@@%@@@@###@@+%@@@=#@@-      ",
		"          -####%%@@@@@@@@@@@@@@@@@@@@@@@@= @@-         ",
		"        =+=+#########%%%%@@@@@@@@@@@@@@ #@+            ",
		"             +: =+===+.#@%#*#@%#%%%%%%%*##===          ",
		"              +:     =++++=#%%%####***                 ",
		"                          .=+=.      .::---:           ",
	};
















	std::string movedesc[4][2];

	// setting moveset names
	std::string PlayerMovesetName[4];
	for (int i = 0; i < 4; i++) {
		PlayerMovesetName[i] = MC.GetMoveSet().GetMove(i).MoveName;
	}

	// split names
	for (int i = 0; i < 4; i++) {

		// if length > 71 char
		if (PlayerMovesetName[i].length()/*MC.moveset.GetMove(0).length()*/ >= 71) {
			if (PlayerMovesetName[i][71] == ' ') {
				// moves all element from index 71 forward, replacing the ' ' at index 71
				for (int j = 71; j < PlayerMovesetName[i].length(); j++) {
					PlayerMovesetName[i][j] = PlayerMovesetName[i][j + 1];
				}
				// adds an empty ' ' at the end to keep string length constant
				PlayerMovesetName[i][PlayerMovesetName[i].length() - 1] = ' ';
			}

			for (int j = 0; j < 71; j++) {
				movedesc[i][0] += PlayerMovesetName[i][j];
			}

			for (int j = 71; j < PlayerMovesetName[i].length(); j++) {
				movedesc[i][1] += PlayerMovesetName[i][j];
			}
		}

		// if length <= 71
		else {
			for (int j = 0; j < PlayerMovesetName[i].length(); j++) {
				movedesc[i][0] += PlayerMovesetName[i][j];
			}
		}
	}



















	std::string CombatUIString;

	//
	CombatUIString += "+------------------------------------------------------------------------------------------------------------+\n";
	CombatUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	CombatUIString += "|``````````````````````````````````````````````````````````````````~.______________________________________.~|\n";
	CombatUIString += "|``````````````````````````````````````````````````````````````````:|                                      |:|\n";



	// enemy name
	CombatUIString += "|``````````````````````````````````````````````````````````````````:| ";
	CombatUIString += target.GetEnemyClass();
	// 36 spaces for enemy name
	for (int i = 0; i < 36 - target.GetEnemyClass().length(); i++) {
		CombatUIString += " ";
	}
	CombatUIString += " |:|\n";



	//
	CombatUIString += "|``````````````````````````````````````````````````````````````````:|                                      |:|\n";



	// enemy hp
	CombatUIString += "|``````````````````````````````````````````````````````````````````:| ";
	CombatUIString += std::to_string(target.GetHP()) + "/" + std::to_string(target.GetMaxHP()) + " HP";
	// 36 spaces for HP/MAXHP HP
	for (int i = 0; i < 36 - std::to_string(target.GetHP()).length() - 1 - std::to_string(target.GetMaxHP()).length() - 3; i++) {
		CombatUIString += " ";
	}
	CombatUIString += " |:|\n";



	// enemy hp bar
	CombatUIString += "|``````````````````````````````````````````````````````````````````:| |";
	// 34 characters for hp bar
	// calculate percentage of maxhp
	int EnemyHPPercentBar = (static_cast<float>(target.GetHP()) / static_cast<float>(target.GetMaxHP())) * 34.f;

	// fill bar sections if full to %
	for (int i = 0; i < EnemyHPPercentBar; i++) {
		CombatUIString += "%";
	}

	// fill bar section if its partially filled to +
	if (EnemyHPPercentBar < (static_cast<float>(target.GetHP()) / static_cast<float>(target.GetMaxHP())) * 34.f) { // if theres a bar with partial hp
		CombatUIString += "+";
	}

	// fill rest of bar with empty -
	for (int i = 0; i < 34 - EnemyHPPercentBar - 1; i++) {
		CombatUIString += "-";
	}

	//
	CombatUIString += "| |:|\n";



	//
	CombatUIString += "|``````````````````````````````````````````````````````````````````:|                                      |:|\n";
	CombatUIString += "|``````````````````````````````````````````````````````````````````~*======================================*~|\n";
	CombatUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	CombatUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	CombatUIString += "|`                                                  `                                                       `|\n";
	CombatUIString += "|`                                                  `                                                       `|\n";



	// player and enemy sprites

	for (int i = 0; i < 20; i++) {
		CombatUIString += "|`";

		// player
		if (i >= 2) {
			CombatUIString += CombatPlayerUIString[i - 2] + "`";
		}

		else {
			CombatUIString += "                                                  `";
		}

		// enemy // and border
		CombatUIString += EnemySpriteLines[i] + "`|\n";
	}



	//
	CombatUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	CombatUIString += "|`~.___________________.~````````````````````````````````````````````````````````````````````````````````````|\n";
	CombatUIString += "|`:|                   |:````````````````````````````````````````````````````````````````````````````````````|\n";


	// player class, lvl
	CombatUIString += "|`:| ";
	CombatUIString += MC.GetPlayerClass();

	// 11 spaces for class
	for (int i = 0; i < 11 - MC.GetPlayerClass().length(); i++) {
		CombatUIString += " ";
	}

	CombatUIString += "Lvl ";
	CombatUIString += std::to_string(MC.GetPlayerLvl());

	// 2 spaces for lvl
	for (int i = 0; i < 2 - std::to_string(MC.GetPlayerLvl()).length(); i++) {
		CombatUIString += " ";
	}

	CombatUIString += " |:````````````````````````````````````````````````````````````````````````````````````|\n";



	//
	CombatUIString += "|`:|                   |:````````````````````````````````````````````````````````````````````````````````````|\n";


	// player hp
	CombatUIString += "|`:| ";
	CombatUIString += std::to_string(MC.GetPlayerHP()) + "/" + std::to_string(MC.GetPlayerMaxHP()) + " HP";
	// 17 spaces for hp/maxhp
	for (int i = 0; i < 17 - std::to_string(MC.GetPlayerHP()).length() - 1 - std::to_string(MC.GetPlayerMaxHP()).length() - 3; i++) {
		CombatUIString += " ";
	}

	CombatUIString += " |:````````````````````````````````````````````````````````````````````````````````````|\n";



	// hp bar
	CombatUIString += "|`:| |";
	// calculate percentage based of 15 characters yaya
	int PlayerHPPercentBar = (static_cast<float>(MC.GetPlayerHP()) / static_cast<float>(MC.GetPlayerMaxHP())) * 15.f;

	// fill bar sections if full to %
	for (int i = 0; i < PlayerHPPercentBar; i++) {
		CombatUIString += "%";
	}

	// fill bar section if its partially filled to +
	if (PlayerHPPercentBar < (static_cast<float>(MC.GetPlayerHP()) / static_cast<float>(MC.GetPlayerMaxHP())) * 15.f) { // if theres a bar with partial hp
		CombatUIString += "+";
	}

	// fill rest of bar with empty -
	for (int i = 0; i < 15 - PlayerHPPercentBar - 1; i++) {
		CombatUIString += "-";
	}

	//
	CombatUIString += "| |:````````````````````````````````````````````````````````````````````````````````````|\n";



	//
	CombatUIString += "|`:|                   |:````````````````````````````````````````````````````````````````````````````````````|\n";
	CombatUIString += "|`~*===================*~*================================================================================*~`|\n";

	if (scene == "Action") {
		// attack, enemy flavor text
		CombatUIString += "|`:| Attack ";
		if (tracker == 0) {
			CombatUIString += "<--";
		}
		else {
			CombatUIString += "   ";
		}
		CombatUIString += "        |:| Foe ";
		CombatUIString += target.GetEnemyClass();
		CombatUIString += " stands before you.";
		for (int i = 0; i < 56 - target.GetEnemyClass().length(); i++) {
			CombatUIString += " ";
		}
		CombatUIString += "|:`|\n";



		//

		CombatUIString += "|`:|                   |:|                                                                                |:`|\n";
		CombatUIString += "|`:| Defend ";
		if (tracker == 1) {
			CombatUIString += "<--";
		}
		else {
			CombatUIString += "   ";
		}
		CombatUIString += "        |:|                                                                                |:`|\n";


		CombatUIString += "|`:|                   |:|                                                                                |:`|\n";
		CombatUIString += "|`:| Inventory ";
		if (tracker == 2) {
			CombatUIString += "<--";
		}
		else {
			CombatUIString += "   ";
		}
		CombatUIString += "     |:|                                                                                |:`|\n";



		CombatUIString += "|`:|                   |:|                                                                                |:`|\n";
		CombatUIString += "|`:| Run ";
		if (tracker == 3) {
			CombatUIString += "<--";
		}
		else {
			CombatUIString += "   ";
		}
		CombatUIString += "           |:|                                                                                |:`|\n";


		CombatUIString += "|`:|                   |:|                                                                                |:`|\n";

	}

	else if (scene == "Moveset") { // if choosing moveset
		// moveset 1, desc line 1
		CombatUIString += "|`:|                   |:| 1) ";
		CombatUIString += movedesc[0][0];
		// 71 char for movedesc 1 line 1
		for (int i = 0; i < 71 - movedesc[0][0].length(); i++) {
			CombatUIString += " ";
		}
		CombatUIString += " ";

		// selection arrow
		if (tracker == 0) {
			CombatUIString += "<--";
		}
		else {
			CombatUIString += "   ";
		}

		//
		CombatUIString += " |:`|\n";



		// moveset type, desc line 2
		CombatUIString += "|`:| Type: ";


		CombatUIString += MC.GetMoveSet().GetMove(tracker).MoveType;
		for (int i = 0; i < 11 - MC.GetMoveSet().GetMove(tracker).MoveType.length() ; i++) {
			CombatUIString += " ";
		}
		CombatUIString += " |:|    ";

		// 71 space for line 2
		CombatUIString += movedesc[0][1];
		for (int i = 0; i < 71 - movedesc[0][1].length(); i++) {
			CombatUIString += " ";
		}

		//
		CombatUIString += "     |:`|\n";



		// moveset 2, desc line 1
		CombatUIString += "|`:|                   |:| 2) ";
		CombatUIString += movedesc[1][0];
		// 71 char for movedesc 2 line 1
		for (int i = 0; i < 71 - movedesc[1][0].length(); i++) {
			CombatUIString += " ";
		}
		CombatUIString += " ";

		// selection arrow
		if (tracker == 1) {
			CombatUIString += "<--";
		}
		else {
			CombatUIString += "   ";
		}

		//
		CombatUIString += " |:`|\n";



		// moveset type, desc line 2
		CombatUIString += "|`:| Strength: ";

		CombatUIString += MC.GetMoveSet().GetMove(tracker).MoveStrength;
		for (int i = 0; i < 7 - std::to_string(MC.GetMoveSet().GetMove(tracker).MoveStrength).length(); i++) {
			CombatUIString += " ";
		}
		CombatUIString += " |:|    ";

		// 71 space for line 2
		CombatUIString += movedesc[1][1];
		for (int i = 0; i < 71 - movedesc[1][1].length(); i++) {
			CombatUIString += " ";
		}

		//
		CombatUIString += "     |:`|\n";



		// moveset 3, desc line 1
		CombatUIString += "|`:|                   |:| 3) ";
		CombatUIString += movedesc[2][0];
		// 71 char for movedesc 2 line 1
		for (int i = 0; i < 71 - movedesc[2][0].length(); i++) {
			CombatUIString += " ";
		}
		CombatUIString += " ";

		// selection arrow
		if (tracker == 2) {
			CombatUIString += "<--";
		}
		else {
			CombatUIString += "   ";
		}

		//
		CombatUIString += " |:`|\n";



		// moveset hits, desc line 2
		CombatUIString += "|`:| Hits: ";

		CombatUIString += MC.GetMoveSet().GetMove(tracker).Hits;
		for (int i = 0; i < 11 - std::to_string(MC.GetMoveSet().GetMove(tracker).Hits).length(); i++) {
			CombatUIString += " ";
		}
		CombatUIString += " |:|    ";

		// 71 space for line 2
		CombatUIString += movedesc[2][1];
		for (int i = 0; i < 71 - movedesc[2][1].length(); i++) {
			CombatUIString += " ";
		}

		//
		CombatUIString += "     |:`|\n";



		// moveset 4, desc line 1
		CombatUIString += "|`:|                   |:| 4) ";
		CombatUIString += movedesc[3][0];
		// 71 char for movedesc 4 line 1
		for (int i = 0; i < 71 - movedesc[3][0].length(); i++) {
			CombatUIString += " ";
		}
		CombatUIString += " ";

		// selection arrow
		if (tracker == 3) {
			CombatUIString += "<--";
		}
		else {
			CombatUIString += "   ";
		}

		//
		CombatUIString += " |:`|\n";



		// moveset 4, desc line 2
		CombatUIString += "|`:|                   |:|    ";
		CombatUIString += movedesc[3][1];
		// 71 spaces for movedesc line 2
		for (int i = 0; i < 71 - movedesc[3][1].length(); i++) {
			CombatUIString += " ";
		}
		CombatUIString += "     |:`|\n";
	}





	//
	CombatUIString += "|`~*===================*~*================================================================================*~`|\n";
	CombatUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	CombatUIString += "+============================================================================================================+\n";
















	std::cout << CombatUIString;
}