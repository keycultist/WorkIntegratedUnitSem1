#include "Inventory.h"
#include <iostream>
#include <string>

Inventory::Inventory() {
	InventoryUIString = "";
	for (int i = 0; i < 10; i++) {
		InventoryConsumables[i] = "-";
	}
	ConsumableIndex = 0;

	InventoryPlayerIsUsingItem = false;
}







void Inventory::SetInventoryWeaponEquipped(std::string name) {
	InventoryWeaponEquipped = name;
}

void Inventory::SetInventoryArmorEquipped(std::string name) {
	InventoryArmorEquipped = name;
}

void Inventory::SetInventoryPlayerClass(std::string classname) {
	InventoryPlayerClass = classname;
}

void Inventory::SetInventoryPlayerLvl(int lvl) {
	InventoryPlayerLvl = lvl;
}

void Inventory::SetInventoryPlayerEXP(int exp) {
	InventoryPlayerEXP = exp;
}

void Inventory::SetInventoryPlayerHP(int hp) {
	InventoryPlayerHP = hp;
}

void Inventory::SetInventoryPlayerMaxHP(int maxhp) {
	InventoryPlayerMaxHP = maxhp;
}

void Inventory::SetInventoryPlayerPower(int power) {
	InventoryPlayerPower = power;
}

void Inventory::SetInventoryPlayerDefence(int defence) {
	InventoryPlayerDefence = defence;
}

void Inventory::SetInventoryPlayerCritChance(int critchance) {
	InventoryPlayerCritChance = critchance;
}

void Inventory::SetInventoryPlayerCurrency(int gold) {
	InventoryPlayerCurrency = gold;
}

void Inventory::SetInventoryCurrentDifficulty(int floor) {
	InventoryCurrentDifficulty = floor;
}

void Inventory::SetInventoryConsumables(std::string consumable, int index) {
	InventoryConsumables[index] = consumable;
}

std::string Inventory::GetInventoryConsumablesIndex(int index) {
	return InventoryConsumables[index];
}

void Inventory::SetConsumableIndex(int index) {
	ConsumableIndex = index;
}

int Inventory::GetConsumableIndex() {
	return ConsumableIndex;
}

void Inventory::SetInventoryItemListIndex(std::string name, int index) {
	InventoryItemList[index] = name;
}

void Inventory::SetInventoryItemDescriptionListIndex(std::string name, int index) {
	InventoryItemDescriptionList[index] = name;
}

void Inventory::SetInventoryItemTypeListIndex(std::string name, int index) {
	InventoryItemTypeList[index] = name;
}

void Inventory::SetInventoryWeaponListIndex(std::string name, int index) {
	InventoryWeaponList[index] = name;
}

void Inventory::SetInventoryWeaponPowerList() {
	InventoryWeaponPowerList[0] = 1;
	InventoryWeaponPowerList[1] = 2;
	InventoryWeaponPowerList[2] = 4;
	InventoryWeaponPowerList[3] = 7;
	InventoryWeaponPowerList[4] = 13;
	InventoryWeaponPowerList[5] = 20;
	InventoryWeaponPowerList[6] = 35;
}

void Inventory::SetInventoryArmorHPList() {
	InventoryArmorHPList[0] = 25;
	InventoryArmorHPList[1] = 40;
	InventoryArmorHPList[2] = 70;
	InventoryArmorHPList[3] = 150;
	InventoryArmorHPList[4] = 250;
}

void Inventory::SetInventoryConsumablesItemList() {
	for (int i = 0; i < 4; i++) { // 4 rarities
		for (int j = 0; j < 3; j++) { // 3 potion types per rarity
			InventoryConsumablesItemList[(3 * i) + j] = InventoryItemList[(5 * i) + (j + 2)];
		}
	}
}

void Inventory::SetInventoryConsumablesItemEffectList() {
	// healing
	// strength
	// dexterity

	InventoryConsumablesItemEffectList[0] = 15;
	InventoryConsumablesItemEffectList[1] = 2;
	InventoryConsumablesItemEffectList[2] = 10;

	InventoryConsumablesItemEffectList[3] = 30;
	InventoryConsumablesItemEffectList[4] = 4;
	InventoryConsumablesItemEffectList[5] = 20;

	InventoryConsumablesItemEffectList[6] = 50;
	InventoryConsumablesItemEffectList[7] = 6;
	InventoryConsumablesItemEffectList[8] = 35;

	InventoryConsumablesItemEffectList[9] = 130;
	InventoryConsumablesItemEffectList[10] = 10;
	InventoryConsumablesItemEffectList[11] = 50;
}














































std::string Inventory::DrawInventroyUI() {
	int SpaceAmount;

	//for (int i = 0; i < 10; i++) {
	//	InventoryConsumables[i] = "ouiyftdr";
	//}


	// for consumables list

	std::string ConsumableUISection[10];

	for (int i = 0; i < 10; i++) {
		ConsumableUISection[i] = "";

		// 44 spaces for consumable index + name
		// spaceamount = 44 - itemname length - item index length - 2 (for ". ")

		if (InventoryConsumables[i] != "-") {
			SpaceAmount = 44 - InventoryConsumables[i].length() - std::to_string(i + 1).length() - 2;

			ConsumableUISection[i] += std::to_string(i + 1) + ". " + InventoryConsumables[i];

			for (int j = 0; j < SpaceAmount; j++) {
				ConsumableUISection[i] += " ";
			}
		}

		else {
			for (int j = 0; j < 44; j++) {
				ConsumableUISection[i] += " ";
			}
		}


	}








	InventoryUIString = "";

	InventoryUIString += "+============================================================================================================+\n";
	InventoryUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	InventoryUIString += "|```````````````````=*^=--__````````````````__.....--=**=--.....__````````````````__--=^*=```````````````````|\n";
	InventoryUIString += "|````````````````````*````**^^==--____--==^^**''``          ``''**^^==--____--==^^**````*````````````````````|\n";
	InventoryUIString += "|`````````````````````*=-_          *             Inventory:             *           _-=*````````````````````|\n";
	InventoryUIString += "|`````````````````````````````**^^^^*=----____                  ____----=*^^^^**`````````````````````````````|\n";
	InventoryUIString += "|`````````````````````````````````````````````**^^==--__--==^^**`````````````````````````````````````````````|\n";
	InventoryUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	InventoryUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	InventoryUIString += "|```````~.___________________________________.~``````````````````````````````````````````````````````````````|\n";
	InventoryUIString += "|```````:|                                   |:```~.______________________________________________.~`````````|\n";



	// line with CLASS NAME + XP VALUE
	// 29 spaces for lvl, class, space, (xp/reqxp XP)
	// space = 29 - lvl length - 1 space, classname length - xp length - required xp length - 6 (for "(/ XP)")
	std::string PlayerLvl = std::to_string(InventoryPlayerLvl);
	std::string RequiredEXP = std::to_string(18 * (InventoryPlayerLvl - 1) + 10);
	std::string PlayerEXP = std::to_string(InventoryPlayerEXP);

	SpaceAmount = 29 - PlayerLvl.length() - 1 - InventoryPlayerClass.length() - PlayerEXP.length() - RequiredEXP.length() - 6;

	InventoryUIString += "|```````:| Lvl ";
	InventoryUIString += PlayerLvl + " " + InventoryPlayerClass;
	for (int i = 0; i < SpaceAmount; i++) {
		InventoryUIString += " ";
	}
	InventoryUIString += "(" + PlayerEXP + "/" + RequiredEXP + " XP)";
	InventoryUIString += " |:```:|                                              |:`````````|\n";



	// line with EQUIPPED WEAPON NAME
	// 37 spaces for weapon name
	// space = 37 - weaponname length
	SpaceAmount = 37 - InventoryWeaponEquipped.length();

	InventoryUIString += "|```````:|                                   |:```:| Weapon: ";
	InventoryUIString += InventoryWeaponEquipped;
	for (int i = 0; i < SpaceAmount; i++) {
		InventoryUIString += " ";
	}
	InventoryUIString += "|:`````````|\n";



	// line with HP. MAXHP
	// 29 spaces for HP, MAXHP
	// space = 29 - HP.length - MAXHP.length - 1 (for "/")
	std::string PlayerHP = std::to_string(InventoryPlayerHP);
	std::string PlayerMaxHP = std::to_string(InventoryPlayerMaxHP);
	SpaceAmount = 29 - PlayerHP.length() - PlayerMaxHP.length() - 1;

	InventoryUIString += "|```````:| HP: ";
	InventoryUIString += PlayerHP + "/" + PlayerMaxHP;
	for (int i = 0; i < SpaceAmount; i++) {
		InventoryUIString += " ";
	}
	InventoryUIString += " |:```:|                                              |:`````````|\n";



	// line with HP BAR (filled) and ARMORNAME
	// hp:
	// 31 spaces, 100% = 31 "%", 0% = 26 "-"
	// HP/MAXHP to find %, 31 * % / 100 OR if not in terms f %, 31 * percentage
	// round to nearest number, that amount of %s
	// remaining is -s
	// armor:
	// 38 spaces for armor name
	// space = 38 - armorname length
	int PlayerHPPercentBar = (static_cast<float>(InventoryPlayerHP) / static_cast<float>(InventoryPlayerMaxHP)) * 31.f;
	SpaceAmount = 38 - InventoryArmorEquipped.length();

	InventoryUIString += "|```````:| [";
	for (int i = 0; i < PlayerHPPercentBar; i++) {
		InventoryUIString += "%";
	}
	for (int i = 0; i < 31 - PlayerHPPercentBar; i++) {
		InventoryUIString += "-";
	}
	InventoryUIString += "] |:```:| Armor: " + InventoryArmorEquipped;
	for (int i = 0; i < SpaceAmount; i++) {
		InventoryUIString += " ";
	}
	InventoryUIString += "|:`````````|\n";

	// 

	InventoryUIString += "|```````:|                                   |:```:|                                              |:`````````|\n";
	InventoryUIString += "|```````~.===================================.~```~.==============================================.~`````````|\n";
	InventoryUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	InventoryUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	InventoryUIString += "|```````~.______________________________.~```````~.______________________________________________.~``````````|\n";
	InventoryUIString += "|```````:|                              |:```````:|                                              |:``````````|\n";
	InventoryUIString += "|```````:|            Stats:            |:```````:|                 Consumables:                 |:``````````|\n";
	InventoryUIString += "|```````:|                              |:```````:|                                              |:``````````|\n";



	// line with POWER and CONSUMABLE ITEM 1
	// 22 spaces for power
	SpaceAmount = 22 - std::to_string(InventoryPlayerPower).length();

	InventoryUIString += "|```````:| Power: " + std::to_string(InventoryPlayerPower);
	for (int i = 0; i < SpaceAmount; i++) {
		InventoryUIString += " ";
	}

	// + consumable section
	InventoryUIString += "|:```````:|  " + ConsumableUISection[0] + "|:``````````|\n";



	// line with DEFENCE and ITEM 2
	// 20 space for defence
	SpaceAmount = 20 - std::to_string(InventoryPlayerDefence).length();

	InventoryUIString += "|```````:| Defence: " + std::to_string(InventoryPlayerDefence);
	for (int i = 0; i < SpaceAmount; i++) {
		InventoryUIString += " ";
	}

	// + item 2
	InventoryUIString += "|:```````:|  " + ConsumableUISection[1] + "|:``````````|\n";



	// line with crit% and item 3
	// 15 space for crit
	// spaceamount = 15 - critchance length - 1 (for "%")
	SpaceAmount = 15 - std::to_string(InventoryPlayerCritChance).length() - 1;

	InventoryUIString += "|```````:| Crit. Chance: " + std::to_string(InventoryPlayerCritChance) + "%";
	for (int i = 0; i < SpaceAmount; i++) {
		InventoryUIString += " ";
	}

	// + item 3
	InventoryUIString += "|:```````:|  " + ConsumableUISection[2] + "|:``````````|\n";



	// line with item 4

	InventoryUIString += "|```````:|                              |:```````:|  " + ConsumableUISection[3] + "|:``````````|\n";



	// line with gold and item 5
	// 23 spaces for gold
	// space amount = 23 - currency length - 2 (for " G")
	SpaceAmount = 23 - std::to_string(InventoryPlayerCurrency).length() - 2;

	InventoryUIString += "|```````:| Gold: " + std::to_string(InventoryPlayerCurrency) + " G";
	for (int i = 0; i < SpaceAmount; i++) {
		InventoryUIString += " ";
	}

	// item 5
	InventoryUIString += "|:```````:|  " + ConsumableUISection[4] + "|:``````````|\n";




	// line with floor and item 6
	// 22 spaces for floor
	// space amount = 22 - 1 (for floor length, always single digit) - 1 (for "F")

	InventoryUIString += "|```````:| Floor: F" + std::to_string(InventoryCurrentDifficulty);
	for (int i = 0; i < 20; i++) {
		InventoryUIString += " ";
	}

	// item 6;
	InventoryUIString += "|:```````:|  " + ConsumableUISection[5] + "|:``````````|\n";



	// lines with item 7, 8, 9, 10

	InventoryUIString += "|```````:|                              |:```````:|  " + ConsumableUISection[6] + "|:``````````|\n";
	InventoryUIString += "|```````:|                              |:```````:|  " + ConsumableUISection[7] + "|:``````````|\n";
	InventoryUIString += "|```````:|                              |:```````:|  " + ConsumableUISection[8] + "|:``````````|\n";
	InventoryUIString += "|```````~.==============================.~```````:|  " + ConsumableUISection[9] + "|:``````````|\n";



	//
	InventoryUIString += "|````````````````````````````````````````````````:|                                              |:``````````|\n";
	InventoryUIString += "|````````````````````````````````````````````````~.==============================================.~``````````|\n";
	InventoryUIString += "|````````````````````````````````````````````````````````````````````````````````````````````````````````````|\n";
	InventoryUIString += "+============================================================================================================+\n";







	return InventoryUIString;

}





















void Inventory::ItemEffectCheck() {

	for (int i = 0; i < 12; i++) {
		// finds which item it is
		//std::cout << "inventoryconsumablesitemlist: " << InventoryConsumablesItemList[i] << std::endl;

		if (InventoryConsumables[InventoryPlayerItemUseChoice - 1] == InventoryConsumablesItemList[i]) {

			// checks which potion type it is
			// healing
			if (i % 3 == 0) {
				InventoryPlayerHP += InventoryConsumablesItemEffectList[i];

				// overhealed edge case
				if (InventoryPlayerHP >= InventoryPlayerMaxHP) {
					InventoryPlayerHP = InventoryPlayerMaxHP;
				}

				//std::cout << "healed for " << InventoryConsumablesItemEffectList[i] << std::endl;
			}

			// strength
			if (i % 3 == 1) {
				InventoryPlayerPower += InventoryConsumablesItemEffectList[i];

				//std::cout << "strength increased " << InventoryConsumablesItemEffectList[i] << std::endl;
			}

			// dexterity
			if (i % 3 == 2) {
				InventoryPlayerCritChance += InventoryConsumablesItemEffectList[i];

				//std::cout << "dexterity increased " << InventoryConsumablesItemEffectList[i] << std::endl;
			}
		}
	}
}









void Inventory::UpdateConsumablesInventory() {
	int tempindex = 0;
	std::string temparraystore[10];
	for (int i = 0; i < 10; i++) {
		temparraystore[i] = "-";
	}

	for (int i = 0; i < 10; i++) {
		if (InventoryConsumables[i] != "-") {
			temparraystore[tempindex] = InventoryConsumables[i];
			tempindex++;
		}
	}

	for (int i = 0; i < 10; i++) {
		InventoryConsumables[i] = temparraystore[i];
	}

	//std::cout << "update debug" << std::endl;
	//for (int i = 0; i < 21; i++) {
	//	std::cout << InventoryConsumables[i] << std::endl;
	//}
}












void Inventory::PromptPlayerUseItem() {
	InventoryPlayerIsUsingItem = true;

	while (InventoryPlayerIsUsingItem) {
		std::cout << "Use Inventory Slot: (Input item slot number to use | '0' to exit)" << std::endl;

		std::cin >> InventoryPlayerItemUseChoice;

		if (InventoryPlayerItemUseChoice == 0) {
			InventoryPlayerIsUsingItem = false;
			break;
		}

		else if (InventoryConsumables[InventoryPlayerItemUseChoice - 1] == "-") {
			std::cout << "Invalid Option" << std::endl;
			break;
		}

		else {
			ItemEffectCheck();
			InventoryPlayerIsUsingItem = false;

			std::cout << "item used; " << InventoryConsumables[InventoryPlayerItemUseChoice - 1] << std::endl;

			InventoryConsumables[InventoryPlayerItemUseChoice - 1] = "-";



			// find a way to remove and move list elements
		}

	}
}






























void Inventory::ObtainItemDrop() {
	int rng = rand() % 100;

	switch (InventoryCurrentDifficulty) {
	case 1:
		if (rng < 80) {
			ItemDropRarity = "Common";
		}
		if (rng >= 80) {
			ItemDropRarity = "Uncommon";
		}

		break;

	case 2:
		if (rng < 20) {
			ItemDropRarity = "Common";
		}
		if (rng >= 20 && rng < 20 + 70) {
			ItemDropRarity = "Uncommon";
		}
		if (rng >= 20 + 70 && rng < 20 + 70 + 10) {
			ItemDropRarity = "Rare";
		}

		break;

	case 3:
		if (rng < 50) {
			ItemDropRarity = "Uncommon";
		}
		if (rng >= 50 && rng < 50 + 45) {
			ItemDropRarity = "Rare";
		}
		if (rng >= 50 + 45 && rng < 50 + 45 + 5) {
			ItemDropRarity = "Epic";
		}

		break;

	case 4:
		if (rng < 15) {
			ItemDropRarity = "Uncommon";
		}
		if (rng >= 15 && rng < 15 + 65) {
			ItemDropRarity = "Rare";
		}
		if (rng >= 15 + 65 && rng < 15 + 65 + 20) {
			ItemDropRarity = "Epic";
		}

		break;

	case 5:
		if (rng < 55) {
			ItemDropRarity = "Rare";
		}
		if (rng >= 55 && rng < 55 + 40) {
			ItemDropRarity = "Epic";
		}
		if (rng >= 55 + 40 && rng < 55 + 40 + 5) {
			ItemDropRarity = "Legendary";
		}

		break;

	case 6:
		if (rng < 20) {
			ItemDropRarity = "Rare";
		}
		if (rng >= 20 && rng < 20 + 65) {
			ItemDropRarity = "Epic";
		}
		if (rng >= 20 + 65 && rng < 20 + 65 + 15) {
			ItemDropRarity = "Legendary";
		}

		break;

	}

	int templistindex = 0;

	if (ItemDropRarity == "Common") {
		templistindex = rand() % 5;
	}
	if (ItemDropRarity == "Uncommon") {
		templistindex = rand() % 5 + 5;
	}
	if (ItemDropRarity == "Rare") {
		templistindex = rand() % 5 + 10;
	}
	if (ItemDropRarity == "Epic") {
		templistindex = rand() % 5 + 15;
	}
	if (ItemDropRarity == "Legendary") {
		templistindex = rand() % 2 + 20;
	}

	DroppedItem = InventoryItemList[templistindex];
	DroppedItemType = InventoryItemTypeList[templistindex];

	// check if consumable has space
	bool PlayerHasInventorySpace = false;
	for (int i = 0; i < 10; i++) {
		if (InventoryConsumables[i] == "-") {
			PlayerHasInventorySpace = true;
			break;
		}
	}

	if (InventoryItemTypeList[templistindex] == "Consumable" && PlayerHasInventorySpace == false) {
		// if item is consumable & player has no inv space
		std::cout << "debug dropped accessory but no space" << std::endl;
	}

	else {
		std::cout << ItemDropRarity << " Rarity Item Dropped!" << std::endl;
		std::cout << InventoryItemList[templistindex] << std::endl;







		if (DroppedItemType == "Weapon" || DroppedItemType == "Armor") {
			std::cout << "Equip " << DroppedItem << "? (Input: Y/N)" << std::endl;
			std::cout << InventoryItemDescriptionList[templistindex];

			char tempplayerchoice;
			std::cin >> tempplayerchoice;

			if (tempplayerchoice == 'Y' || tempplayerchoice == 'y') {

				if (DroppedItemType == "Weapon") {
					for (int i = 1; i < 7; i++) {
						//std::cout << "kjigyrtd\n\n\n" << DroppedItem << "\n" << InventoryWeaponList[i] << std::endl;
						if (DroppedItem == InventoryWeaponList[i]) {
							InventoryPlayerPower = InventoryWeaponPowerList[i];
							InventoryWeaponEquipped = InventoryWeaponList[i];
						}


					}

					//std::cout << "player new power: " << InventoryPlayerPower << std::endl;

				}



				if (DroppedItemType == "Armor") {
					for (int i = 0; i < 5; i++) {
						//std::cout << "kjigyrtd\n\n\n" << DroppedItem << "\n" << InventoryItemList[5 * i + 1] << std::endl;
						if (DroppedItem == InventoryItemList[5 * i + 1]) {
							InventoryPlayerHP = InventoryArmorHPList[i];
							InventoryArmorEquipped = InventoryItemList[5 * i + 1];
						}


					}

					//std::cout << "player new hp: " << InventoryPlayerHP << std::endl;

				}

			}

			else {
				std::cout << DroppedItem << " Trashed" << std::endl;
			}
		}



		if (DroppedItemType == "Consumable") {
			// already checked for inventory space above
			for (int i = 0; i < 10; i++) {
				if (InventoryConsumables[i] == "-") {
					InventoryConsumables[i] = DroppedItem;
					break;
				}
			}
		}



















	}







}