#include "Shop.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

Shop::Shop() {
	//ShopUIString = "";
	ShopSlotIndex = 0;
	for (int i = 0; i < 3; i++) {
		ShopSlotItemName[i] = "";
		ShopSlotItemDescription[i] = "";
		ShopSlotItemCost[i] = 0;
		ShopBoughtConsumablesList[i] = "-";
	}

	for (int i = 0; i < 22; i++) {
		ShopItemList[i];
		ShopItemDescriptionList[i];
		ShopItemCostList[i];
		ShopItemTypeList[i];
	}

	ShopPlayerCurrency = 0;
	ShopPlayerClass = "";

	for (int i = 0; i < 7; i++) {
		ShopWeaponList[i];
	}

	ShopPlayerEquippedWeapon = "Splintered Wood Sword";
	ShopPlayerEquippedArmor = "Ragged Clothing";
}




void Shop::SetShopItemSlot(Player& MC, Item& items) {
	for (int i = 0; i < 3; i++) {
		int rng = rand() % 1000; // 0.1% each number

		/*
		itemlist
		index 0-4 = common
		index 5-9 = uncommon
		index 10-14 = rare
		index 15-19 = epic
		index 20-21 = legendary
		index 22 = secret

		ShopSlotIndex = rand() % 5; // range 0 - 4 common
		ShopSlotIndex = rand() % 5 + 5; // range 5 - 9 uncommon
		ShopSlotIndex = rand() % 5 + 10; // range 10 - 14 rare
		ShopSlotIndex = rand() % 5 + 15; // range 15 - 19 epic
		ShopSlotIndex = rand() % 2 + 20; // range 20 - 21 legendary
		ShopSlotIndex = 22; // range 22 secret
		*/



		switch (MC.GetCurrentDifficulty() + 1) {
		case 1: // floor 1 [81.9% common / 15% uncommon / 3% rare / 0.1% secret]

			// common
			if (rng < 819) {
				ShopSlotIndex = rand() % 5; // range 0 - 4 common
			}

			// uncommon
			if (rng >= 819 && rng < 819 + 150) {
				ShopSlotIndex = rand() % 5 + 5; // range 5 - 9 uncommon
			}

			// rare
			if (rng >= 819 + 150 && rng < 819 + 150 + 30) {
				ShopSlotIndex = rand() % 5 + 10; // range 10 - 14 rare
			}

			// secret
			if (rng >= 999) {
				ShopSlotIndex = 22; // range 22 secret
			}

			break;

		case 2: // floor 2 [58.8% common / 30% uncommon / 10% rare / 1% epic / 0.2% secret]

			// common
			if (rng < 588) {
				ShopSlotIndex = rand() % 5; // range 0 - 4 common
			}

			// uncommon
			if (rng >= 588 && rng < 588 + 300) {
				ShopSlotIndex = rand() % 5 + 5; // range 5 - 9 uncommon
			}

			// rare
			if (rng >= 588 + 300 && rng < 588 + 300 + 100) {
				ShopSlotIndex = rand() % 5 + 10; // range 10 - 14 rare
			}

			// epic
			if (rng >= 588 + 300 + 100 && rng < 588 + 300 + 100 + 10) {
				ShopSlotIndex = rand() % 5 + 15; // range 15 - 19 epic
			}

			// secret
			if (rng >= 998) {
				ShopSlotIndex = 22; // range 22
			}

			break;

		case 3: // floor 3 [19.7% common / 55% uncommon / 20% rare / 5% epic / 0.3% secret]

			// common
			if (rng < 197) {
				ShopSlotIndex = rand() % 5; // range 0 - 4 common
			}

			// uncommon
			if (rng >= 197 && rng < 197 + 550) {
				ShopSlotIndex = rand() % 5 + 5; // range 5 - 9 uncommon
			}

			// rare
			if (rng >= 197 + 550 && rng < 197 + 550 + 200) {
				ShopSlotIndex = rand() % 5 + 10; // range 10 - 14 rare
			}

			// epic
			if (rng >= 197 + 550 + 200 && rng < 197 + 550 + 200 + 50) {
				ShopSlotIndex = rand() % 5 + 15; // range 15 - 19 epic
			}

			// secret
			if (rng >= 997) {
				ShopSlotIndex = 22; // range 22
			}

			break;

		case 4: // floor 4 [40.6% uncommon / 45% rare / 12% epic / 2% legendary / 0.4% secret]

			// uncommon
			if (rng < 406) {
				ShopSlotIndex = rand() % 5 + 5; // range 5 - 9 uncommon
			}

			// rare
			if (rng >= 406 && rng < 406 + 450) {
				ShopSlotIndex = rand() % 5 + 10; // range 10 - 14 rare
			}

			// epic
			if (rng >= 406 + 450 && rng < 406 + 450 + 120) {
				ShopSlotIndex = rand() % 5 + 15; // range 15 - 19 epic
			}

			// legendary
			if (rng >= 406 + 450 + 120 && rng < 406 + 450 + 120 + 20) {
				ShopSlotIndex = rand() % 2 + 20; // range 20 - 21 legendary
			}

			// secret
			if (rng >= 996) {
				ShopSlotIndex = 22; // range 22
			}

			break;

		case 5: // floor 5 [13.5% uncommon / 57% rare / 23% epic / 6% legendary / 0.5% secret]

			// uncommon
			if (rng < 135) {
				ShopSlotIndex = rand() % 5 + 5; // range 5 - 9 uncommon
			}

			// rare
			if (rng >= 135 && rng < 135 + 570) {
				ShopSlotIndex = rand() % 5 + 10; // range 10 - 14 rare
			}

			// epic
			if (rng >= 135 + 570 && rng < 135 + 570 + 230) {
				ShopSlotIndex = rand() % 5 + 15; // range 15 - 19 epic
			}

			// legendary
			if (rng >= 135 + 570 + 230 && rng < 135 + 570 + 230 + 60) {
				ShopSlotIndex = rand() % 2 + 20; // range 20 - 21 legendary
			}

			// secret
			if (rng >= 995) {
				ShopSlotIndex = 22; // range 22
			}

			break;

		case 6: // floor 6 [46.3% rare / 42% epic / 11% legendary / 0.7% secret]

			// rare
			if (rng < 463) {
				ShopSlotIndex = rand() % 5 + 10; // range 10 - 14 rare
			}

			// epic
			if (rng >= 463 && rng < 463 + 420) {
				ShopSlotIndex = rand() % 5 + 15; // range 15 - 19 epic
			}

			// legendary
			if (rng >= 463 + 420 && rng < 463 + 420 + 110) {
				ShopSlotIndex = rand() % 2 + 20; // range 20 - 21 legendary
			}

			// secret
			if (rng >= 993) {
				ShopSlotIndex = 22; // range 22
			}

			break;

		case 7: // floor 7 [17% rare / 55% epic / 27% legendary / 1% secret]

			// rare
			if (rng < 170) {
				ShopSlotIndex = rand() % 5 + 10; // range 10 - 14 rare
			}

			// epic
			if (rng >= 170 && rng < 170 + 550) {
				ShopSlotIndex = rand() % 5 + 15; // range 15 - 19 epic
			}

			// legendary
			if (rng >= 170 + 550 && rng < 170 + 550 + 270) {
				ShopSlotIndex = rand() % 2 + 20; // range 20 - 21 legendary
			}

			// secret
			if (rng >= 990) {
				ShopSlotIndex = 22; // range 22
			}

			break;

		}

		ShopSlotItemName[i] = items.GetItemListIndex(ShopSlotIndex);
		ShopSlotItemDescription[i] = items.GetItemDescriptionListIndex(ShopSlotIndex);
		ShopSlotItemCost[i] = items.GetItemCostListIndex(ShopSlotIndex);
		ShopSlotItemType[i] = items.GetItemTypeListIndex(ShopSlotIndex);
		ItemIsInStock[i] = true;
	}
}





void Shop::SetShopPlayerClass(const std::string& c) {
	ShopPlayerClass = c;
}

std::string Shop::GetShopPlayerClass() {
	return ShopPlayerClass;
}

void Shop::SetPlayerCurrency(int c) {
	ShopPlayerCurrency = c;
}

int Shop::GetPlayerCurrency() {
	return ShopPlayerCurrency;
}






void Shop::SetShopItemListIndex(std::string items, int index) {
	ShopItemList[index] = items;
}

void Shop::SetShopItemDescriptionListIndex(std::string descriptions, int index) {
	ShopItemDescriptionList[index] = descriptions;
}

void Shop::SetShopItemCostListIndex(int costs, int index) {
	ShopItemCostList[index] = costs;
}

void Shop::SetShopItemTypeListIndex(std::string types, int index) {
	ShopItemTypeList[index] = types;
}

void Shop::SetShopFloor(int floor) {
	ShopFloor = floor;
}

void Shop::SetPlayerIsShopping(bool a) {
	PlayerIsShopping = a;
}

bool Shop::GetPlayerIsShopping() {
	return PlayerIsShopping;
}




void Shop::SetShopPlayerBaseHP(int hp) {
	ShopPlayerBaseHP = hp;
}

void Shop::SetShopPlayerNewHP(int hp) {
	ShopPlayerNewHP = hp;
}

void Shop::SetShopPlayerNewPower(int power) {
	ShopPlayerNewPower = power;
}

int Shop::GetShopPlayerNewHP() {
	return ShopPlayerNewHP;
}

int Shop::GetShopPlayerNewPower() {
	return ShopPlayerNewPower;
}






void Shop::SetShopWeaponListIndex(std::string name, int index) {
	ShopWeaponList[index] = name;
}




void Shop::SetShopWeaponPowerList() {
	ShopWeaponPowerList[0] = 1;
	ShopWeaponPowerList[1] = 2;
	ShopWeaponPowerList[2] = 4;
	ShopWeaponPowerList[3] = 7;
	ShopWeaponPowerList[4] = 13;
	ShopWeaponPowerList[5] = 20;
	ShopWeaponPowerList[6] = 35;
}

void Shop::SetShopArmorHPList() {
	ShopArmorHPList[0] = 25;
	ShopArmorHPList[1] = 50;
	ShopArmorHPList[2] = 90;
	ShopArmorHPList[3] = 175;
	ShopArmorHPList[4] = 250;
}

void Shop::SetShopArmorDefList() {
	ShopArmorDefList[0] = 5;
	ShopArmorDefList[1] = 12;
	ShopArmorDefList[2] = 22;
	ShopArmorDefList[3] = 35;
	ShopArmorDefList[4] = 50;
}





std::string Shop::GetShopPlayerEquippedWeapon() {
	return ShopPlayerEquippedWeapon;
}



std::string Shop::GetShopPlayerEquippedArmor() {
	return ShopPlayerEquippedArmor;
}



int Shop::GetShopFloor() {
	return ShopFloor;
}



void Shop::SetConsumablesListIndex(std::string name, int index) {
	ShopBoughtConsumablesList[index] = name;
}


std::string Shop::GetConsumablesListIndex(int index) {
	return ShopBoughtConsumablesList[index];
}




void Shop::SetInventoryConsumableListIndex(std::string name, int index) {
	InventoryConsumableList[index] = name;

}























































void Shop::SplitDescriptionString(std::string description) {
	// seperate string into strings of 50 char

	if (description.length() > 240) {
		std::cout << description.length() << "YFTYGUIHOHUVYCTXRYVUBIVYCT" << std::endl;
	}

	for (int i = 1; i < 3; i++) {
		if (description.length() >= 60 * i) {
			if (description[60 * i] == ' ') {
				// moves all element from index 60 forward, replacing the ' ' at index 60
				for (int j = 60 * i; j < description.length(); j++) {
					description[j] = description[j + 1];
				}
				// adds an empty ' ' at the end to keep string length constant
				description[description.length() - 1] = ' ';
			}
		}
	}


	for (int i = 0; i < 4; i++) {
		descline[i] = "";
	}

	int maxcharlines = description.length() / 60;

	// for lines with 60/60 characters
	for (int i = 0; i < maxcharlines; i++) {
		for (int j = 0; j < 60; j++) {
			descline[i] += description[60 * i + j];
		}
	}

	// for last line with <60 characters
	for (int i = 60 * maxcharlines; i < description.length(); i++) {
		descline[maxcharlines] += description[i];
	}
}










std::string Shop::DrawShopUI(Player& MC, Item& items, Inventory& inv) {
	std::ostringstream ShopUIString;

	ShopUIString.str("");
	ShopUIString.clear();

	ShopUIString << "+====================================================================================###====###==============+\n";
	ShopUIString << "|````````````````````````````````````````````````````````````````````````````````````|#||``||#|``````````````|\n";
	ShopUIString << "|`````+_______________________________________________________________+``````````````|#||``||#|``````````````|\n";
	ShopUIString << "|`````|                                                               |````````__-=+*{##****##}*+=-__````````|\n";

	// item 1
	// 44 spaces for item 1 name
	ShopUIString << "|`````| Item 1: ";
	if (ItemIsInStock[0]) {
		ShopUIString << ShopSlotItemName[0];
		for (int i = 0; i < 54 - ShopSlotItemName[0].length(); i++) {
			ShopUIString << " ";
		}
	}
	else {
		ShopUIString << "-OUT OF STOCK-";
		for (int i = 0; i < 40; i++) {
			ShopUIString << " ";
		}
	}

	ShopUIString << "|`````__*                      *__`````|\n";



	//
	ShopUIString << "|`````|                                                               |````#            SHOP            #````|\n";

	// Item 1 description + floor number
	if (ItemIsInStock[0]) {
		SplitDescriptionString(ShopSlotItemDescription[0]);

		//for (int i = 0; i < 4; i++) {
		//	std::cout << "descline[" << i << "] = " << descline[i] << "\n";
		//}
	}
	else {
		for (int i = 0; i < 4; i++) {
			descline[i] = "";
		}

		if (ShopSlotItemType[0] == "Weapon") {
			if (MC.GetPlayerClass() == "Warrior" || MC.GetPlayerClass() == "Hunter" || MC.GetPlayerClass() == "Assassin" || MC.GetPlayerClass() == "Berserker") {
				descline[0] = "A fine weapon choice. May it fell great foes under your wield.";
			}
			else {
				descline[0] = "A wise choice. May the Elder Sages guide your arcanism.";
			}
		}



		if (ShopSlotItemType[0] == "Armor") {
			descline[0] = "Take good care of the armor, and it'll take care of you.";
		}



		if (ShopSlotItemType[0] == "Consumable") {
			descline[0] = "Careful with that one, you don't want the flask exploding,";
			descline[1] = "do you?";
		}


	}
	// description line 1
	ShopUIString << "|`````| " << descline[0];
	for (int i = 0; i < 60 - descline[0].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |```|_             F" << std::to_string(ShopFloor) + "             _|```|\n";

	// description line 2
	ShopUIString << "|`````| " << descline[1];
	for (int i = 0; i < 60 - descline[1].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |````#=-____                ____-=#````|\n";

	// description line 3
	ShopUIString << "|`````| " << descline[2];
	for (int i = 0; i < 60 - descline[2].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |```````````^*#===----===#*^```````````|\n";

	// description line 4
	ShopUIString << "|`````| " << descline[3];
	for (int i = 0; i < 60 - descline[3].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |````````````````````````````_`````````|\n";



	// cost
	ShopUIString << "|`````|                                                     ";
	ShopUIString << "Cost: " << std::to_string(ShopSlotItemCost[0]) << "G";
	for (int i = 0; i < 3 - std::to_string(ShopSlotItemCost[0]).length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "|```````````````````````````///````````|\n";



	// 
	ShopUIString << "|`````+===============================================================+```````````````````````````|#|````````|\n";
	ShopUIString << "|`````````````````````````````````````````````````````````````````````````````````````````````````|#|````````|\n";
	ShopUIString << "|`````+_______________________________________________________________+``````````````_````````````|#|````````|\n";
	ShopUIString << "|`````|                                                               |`````````````+#+````````___/#\\___`````|\n";



	// item 2 + cost
	// 44 spaces for item 2 name
	ShopUIString << "|`````| Item 2: ";
	if (ItemIsInStock[1]) {
		ShopUIString << ShopSlotItemName[1];
		for (int i = 0; i < 54 - ShopSlotItemName[1].length(); i++) {
			ShopUIString << " ";
		}
	}
	else {
		ShopUIString << "-OUT OF STOCK-";
		for (int i = 0; i < 40; i++) {
			ShopUIString << " ";
		}
	}

	ShopUIString << "|```````##````| |```````<=+#_ _+#=>````|\n";



	//
	ShopUIString << "|`````|                                                               |```````||```/   \\```````` \\;_;/ ``````|\n";



	// item 2 description
	if (ItemIsInStock[1]) {
		SplitDescriptionString(ShopSlotItemDescription[1]);
		//for (int i = 0; i < 4; i++) {
		//	std::cout << "descline[" << i << "] = " << descline[i] << "\n";
		//}
	}
	else {
		for (int i = 0; i < 4; i++) {
			descline[i] = "";
		}

		if (ShopSlotItemType[1] == "Weapon") {
			if (MC.GetPlayerClass() == "Warrior" || MC.GetPlayerClass() == "Hunter" || MC.GetPlayerClass() == "Assassin" || MC.GetPlayerClass() == "Berserker") {
				descline[0] = "A fine weapon choice. May it fell great foes under your wield.";
			}
			else {
				descline[0] = "A wise choice. May the Elder Sages guide your arcanism.";
			}
		}



		if (ShopSlotItemType[1] == "Armor") {
			descline[0] = "Take good care of the armor, and it'll take care of you.";
		}



		if (ShopSlotItemType[1] == "Consumable") {
			descline[0] = "Careful with that one, you don't want the flask exploding,";
			descline[1] = "do you?";
		}




	}
	// description line 1
	ShopUIString << "|`````| " << descline[0];
	for (int i = 0; i < 60 - descline[0].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |``````/  \\`{     }`````=+|%%%%%|+=````|\n";

	// description line 2
	ShopUIString << "|`````| " << descline[1];
	for (int i = 0; i < 60 - descline[1].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |``````\\__/``\\___/``````````| |````````|\n";

	// description line 3
	ShopUIString << "|`````| " << descline[2];
	for (int i = 0; i < 60 - descline[2].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |`````==============````````| |````````|\n";

	// description line 4
	ShopUIString << "|`````| " << descline[3];
	for (int i = 0; i < 60 - descline[3].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |````/_____________/````````| |````````|\n";



	// cost
	ShopUIString << "|`````|                                                     ";
	ShopUIString << "Cost: " << std::to_string(ShopSlotItemCost[1]) << "G";
	for (int i = 0; i < 3 - std::to_string(ShopSlotItemCost[1]).length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "|```````````````````````````| |````````|\n";



	//
	ShopUIString << "|`````+===============================================================+```````````````````````````| |````````|\n";
	ShopUIString << "|`````````````````````````````````````````````````````````````````````````````````````````````````| |````````|\n";
	ShopUIString << "|`````+_______________________________________________________________+```````````````````````````| |````````|\n";
	ShopUIString << "|`````|                                                               |```````````````````````````\\ /````````|\n";



	//std::cout << "wallwlwlalwalwlal" << std::endl;

	// item 3 + cost
	ShopUIString << "|`````| Item 3: ";
	if (ItemIsInStock[2]) {
		ShopUIString << ShopSlotItemName[2];
		for (int i = 0; i < 54 - ShopSlotItemName[2].length(); i++) {
			ShopUIString << " ";
		}
	}
	else {
		ShopUIString << "-OUT OF STOCK-";
		for (int i = 0; i < 40; i++) {
			ShopUIString << " ";
		}
	}


	ShopUIString << "|````````````````````````````v`````````|\n";



	//
	ShopUIString << "|`````|                                                               |``````````````````````````````````````|\n";



	//std::cout << "walllllll the second" << std::endl;

	// item 3 description
	if (ItemIsInStock[2]) {
		SplitDescriptionString(ShopSlotItemDescription[2]);
		//for (int i = 0; i < 4; i++) {
		//	std::cout << "descline[" << i << "] = " << descline[i] << "\n";
		//}
	}
	else {
		for (int i = 0; i < 4; i++) {
			descline[i] = "";
		}

		if (ShopSlotItemType[2] == "Weapon") {
			if (MC.GetPlayerClass() == "Warrior" || MC.GetPlayerClass() == "Hunter" || MC.GetPlayerClass() == "Assassin" || MC.GetPlayerClass() == "Berserker") {
				descline[0] = "A fine weapon choice. May it fell great foes under your wield.";
			}
			else {
				descline[0] = "A wise choice. May the Elder Sages guide your arcanism.";
			}
		}



		if (ShopSlotItemType[2] == "Armor") {
			descline[0] = "Take good care of the armor, and it'll take care of you.";
		}

		//std::cout << "3rd wall" << std::endl;

		if (ShopSlotItemType[2] == "Consumable") {
			descline[0] = "Careful with that one, you don't want the flask exploding,";
			descline[1] = "do you?";
		}

		//std::cout << "4th wall" << std::endl;


	}
	// description line 1
	ShopUIString << "|`````| " << descline[0];
	//std::cout << descline[0] << descline[0].length() << std::endl;
	for (int i = 0; i < 60 - descline[0].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |```````#===========================#``|\n";

	// description line 2
	ShopUIString << "|`````| " << descline[1];
	for (int i = 0; i < 60 - descline[1].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |``````/                           /|``|\n";


	// description line 3
	ShopUIString << "|`````| " << descline[2];
	for (int i = 0; i < 60 - descline[2].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |`````/                           / |``|\n";


	// description line 4
	ShopUIString << "|`````| " << descline[3];
	for (int i = 0; i < 60 - descline[3].length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "  |````#===========================#  |``|\n";

	//std::cout << "5th wall" << std::endl;

	//
	ShopUIString << "|`````|                                                     ";
	ShopUIString << "Cost: " << std::to_string(ShopSlotItemCost[2]) << "G";
	for (int i = 0; i < 3 - std::to_string(ShopSlotItemCost[2]).length(); i++) {
		ShopUIString << " ";
	}
	ShopUIString << "|````|                           |  |``|\n";
	ShopUIString << "|`````+===============================================================+````|                           |  |``|\n";
	ShopUIString << "|``````````````````````````````````````````````````````````````````````````|                           |  |``|\n";
	ShopUIString << "+==========================================================================#===========================#==#==+\n";






	return ShopUIString.str();
}













void Shop::EquipBoughtWeapon(int slot) {
	// check which weapon
	for (int i = 1; i < 7; i++) {
		//std::cout << "shop slot item name : " << ShopSlotItemName[slot] << std::endl;
		//std::cout << "warrior weapon name : " << ShopWarriorWeaponList[i] << std::endl;

		if (ShopSlotItemName[slot] == ShopWeaponList[i]) {
			ShopPlayerNewPower = ShopWeaponPowerList[i];
			ShopPlayerEquippedWeapon = ShopWeaponList[i];
		}

	}


	std::cout << "player new power: " << ShopPlayerNewPower << std::endl;

}


void Shop::EquipBoughtArmor(int slot) {
	// check which armor
	for (int i = 0; i < 5; i++) {
		//std::cout << "shop slot item name: " << ShopSlotItemName[slot] << std::endl;
		//std::cout << "armor name: " << ShopItemList[5 * i + 1] << std::endl;

		if (ShopSlotItemName[slot] == ShopItemList[5 * i + 1]) {
			ShopPlayerNewHP = ShopPlayerBaseHP + ShopArmorHPList[i];
			ShopPlayerEquippedArmor = ShopItemList[5 * i + 1];
		}

		std::cout << "player new hp: " << ShopPlayerNewHP << std::endl;
	}
}


void Shop::BoughtConsumables(int slot) {
	// check which consumable
	for (int i = 0; i < 4; i++) { // 4 rarities of consumables
		for (int j = 0; j < 3; j++) { // 3 types of consumables
			//std::cout << "shop slot item name: " << ShopSlotItemName[slot] << std::endl;
			//std::cout << "consumable name: " << ShopItemList[(5 * i) + (j + 2)] << std::endl;

			if (ShopSlotItemName[slot] == ShopItemList[(5 * i) + (j + 2)]) {

				for (int k = 0; k < 3; k++) {
					if (ShopBoughtConsumablesList[k] == "-") {
						ShopBoughtConsumablesList[k] = ShopSlotItemName[slot];
						break;
					}
				}

				//for (int k = 0; k < 3; k++) {
				//	std::cout << "bought consumables: " << ShopBoughtConsumablesList[k] << std::endl;
				//}

			}

		}
	}
}













int Shop::PromptPlayerShopInteraction() {

	std::cout << "Current Funds: " << ShopPlayerCurrency << "\n" << std::endl;
	std::cout << "(1) Buy Item 1\n(2) Buy Item 2\n(3) Buy Item 3\n(4) Exit Shop\n" << std::endl;
	std::cin >> PlayerShopChoice;
	// consumable inv space check
	bool PlayerHasInventorySpace = false;

	for (int i = 0; i < 10; i++) {
		if (InventoryConsumableList[i] == "-") {
			PlayerHasInventorySpace = true;
		}
	}



	if (std::cin.fail() || PlayerShopChoice < 1 || PlayerShopChoice > 4) {
		std::cout << "Invalid Input\n" << std::endl;
		std::cin.clear();
		std::cin.ignore();
	}

	// if leave shop
	else if (PlayerShopChoice == 4) {
		PlayerIsShopping = false;
	}

	else if (ShopSlotItemType[PlayerShopChoice - 1] == "Consumable" && PlayerHasInventorySpace == false) {
		std::cout << "Insufficient Inventory Space" << std::endl;
	}



	// if purchasable, check for purchase
	else if (ShopPlayerCurrency >= ShopSlotItemCost[PlayerShopChoice - 1] && ItemIsInStock[PlayerShopChoice - 1]) {
		std::cout << ShopSlotItemName[PlayerShopChoice - 1] << " Purchased!\n" << std::endl;

		ShopPlayerCurrency -= ShopSlotItemCost[PlayerShopChoice - 1];
		ItemIsInStock[PlayerShopChoice - 1] = false;


		// equip

		//std::cout << "shop slot weapon type: " << ShopSlotItemType[0] << std::endl;
		if (ShopSlotItemType[PlayerShopChoice - 1] == "Weapon") {
			EquipBoughtWeapon(PlayerShopChoice - 1);
		}

		if (ShopSlotItemType[PlayerShopChoice - 1] == "Armor") {
			EquipBoughtArmor(PlayerShopChoice - 1);
		}


		if (ShopSlotItemType[PlayerShopChoice - 1] == "Consumable") {
			BoughtConsumables(PlayerShopChoice - 1);
		}

	}



	// if out of stock
	else if (ItemIsInStock[PlayerShopChoice - 1] == false) {
		std::cout << "Item Is Not In Stock\n" << std::endl;
	}

	// if not enough money
	else if (ShopPlayerCurrency < ShopSlotItemCost[PlayerShopChoice - 1]) {
		std::cout << "Insufficient Funds\n" << std::endl;
	}






	return 0;
}