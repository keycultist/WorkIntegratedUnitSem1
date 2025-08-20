#include "Shop.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>

Shop::Shop() {
	ShopUIString = "";
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
		ShopWarriorWeaponList[i];
		ShopMageWeaponList[i];
		ShopHunterWeaponList[i];
	}
}




void Shop::SetShopItemSlot() {
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



		switch (ShopFloor) {
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

		ShopSlotItemName[i] = ShopItemList[ShopSlotIndex];
		ShopSlotItemDescription[i] = ShopItemDescriptionList[ShopSlotIndex];
		ShopSlotItemCost[i] = ShopItemCostList[ShopSlotIndex];
		ShopSlotItemType[i] = ShopItemTypeList[ShopSlotIndex];
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

void Shop::SetPlayerIsShopping() {
	PlayerIsShopping = true;
}

bool Shop::GetPlayerIsShopping() {
	return PlayerIsShopping;
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






void Shop::SetShopWarriorWeaponListIndex(std::string name, int index) {
	ShopWarriorWeaponList[index] = name;
}



void Shop::SetShopMageWeaponListIndex(std::string name, int index) {
	ShopMageWeaponList[index] = name;
}




void Shop::SetShopHunterWeaponListIndex(std::string name, int index) {
	ShopHunterWeaponList[index] = name;
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
	ShopArmorHPList[1] = 40;
	ShopArmorHPList[2] = 70;
	ShopArmorHPList[3] = 150;
	ShopArmorHPList[4] = 250;
}












std::string Shop::DrawShopUI() {

	// debug show ALL item name, desc, cost

	//
	// for (int i = 0; i < 23; i++) {
	//
	//std::cout << ShopItemList[i] << std::endl;
	//
	//std::cout << ShopItemDescriptionList[i] << std::endl;
	//
	//std::cout << ShopItemCostList[i] << std::endl;
	//
	//std::cout << std::endl;
	//



	// sets random 3 items
	//std::cout << "shop floor: " << ShopFloor << std::endl;
	std::cout << "\n\n\n\n\n" << std::endl;
	for (int i = 0; i < 3; i++) {
		if (ItemIsInStock[i]) {
			std::cout << "Shop Item " << i + 1 << ": " << ShopSlotItemName[i] << std::endl;
			std::cout << ShopSlotItemDescription[i] << std::endl;
			std::cout << "Type: " << ShopSlotItemType[i] << std::endl;
			std::cout << "Cost: " << ShopSlotItemCost[i] << " Gold\n" << std::endl;
		}

		else {
			std::cout << "Shop Item " << i + 1 << ": " << "OUT OF STOCK\n" << std::endl;
		}
	}

	return "0";
}













void Shop::EquipBoughtWeapon(int slot) {
	// check which weapon
	for (int i = 1; i < 7; i++) {
		//std::cout << "shop slot item name : " << ShopSlotItemName[slot] << std::endl;
		//std::cout << "warrior weapon name : " << ShopWarriorWeaponList[i] << std::endl;

		if (ShopSlotItemName[slot] == ShopWarriorWeaponList[i]) {
			ShopPlayerNewPower = ShopWeaponPowerList[i];
		}

		std::cout << "player new power: " << ShopPlayerNewPower << std::endl;
	}
}


void Shop::EquipBoughtArmor(int slot) {
	// check which armor
	for (int i = 0; i < 5; i++) {
		//std::cout << "shop slot item name: " << ShopSlotItemName[slot] << std::endl;
		//std::cout << "armor name: " << ShopItemList[5 * i + 1] << std::endl;

		if (ShopSlotItemName[slot] == ShopItemList[5 * i + 1]) {
			ShopPlayerNewHP = ShopArmorHPList[i];
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

				for (int k = 0; k < 3; k++) {
					std::cout << "bought consumables: " << ShopBoughtConsumablesList[k] << std::endl;
				}

			}

		}
	}
}













int Shop::PromptPlayerShopInteraction() {

	std::cout << "Current Funds: " << ShopPlayerCurrency << "\n" << std::endl;
	std::cout << "(1) Buy Item 1" << std::endl;
	std::cout << "(2) Buy Item 2" << std::endl;
	std::cout << "(3) Buy Item 3" << std::endl;
	std::cout << "(4) Exit Shop" << std::endl;

	std::cin >> PlayerShopChoice;

	switch (PlayerShopChoice) {
	case 1:
		if (ShopPlayerCurrency >= ShopSlotItemCost[0] && ItemIsInStock[0]) {
			std::cout << ShopSlotItemName[0] << " Purchased!\n" << std::endl;

			ShopPlayerCurrency -= ShopSlotItemCost[0];
			ItemIsInStock[0] = false;


			// equip

			//std::cout << "shop slot weapon type: " << ShopSlotItemType[0] << std::endl;
			if (ShopSlotItemType[0] == "Weapon") {
				EquipBoughtWeapon(0);
			}

			if (ShopSlotItemType[0] == "Armor") {
				EquipBoughtArmor(0);
			}


			if (ShopSlotItemType[0] == "Consumable") {
				BoughtConsumables(0);
			}





		}

		else {
			if (ItemIsInStock[0] == false) {
				std::cout << "Item Is Not In Stock\n" << std::endl;
			}
			else {
				std::cout << "Insufficient Funds\n" << std::endl;
			}
		}

		break;




	case 2:
		if (ShopPlayerCurrency >= ShopSlotItemCost[1] && ItemIsInStock[1]) {
			std::cout << ShopSlotItemName[1] << " Purchased!\n" << std::endl;

			ShopPlayerCurrency -= ShopSlotItemCost[1];
			ItemIsInStock[1] = false;



			// equip

			//std::cout << "shop slot weapon type: " << ShopSlotItemType[0] << std::endl;
			if (ShopSlotItemType[1] == "Weapon") {
				EquipBoughtWeapon(1);
			}

			if (ShopSlotItemType[1] == "Armor") {
				EquipBoughtArmor(1);
			}


			if (ShopSlotItemType[1] == "Consumable") {
				BoughtConsumables(1);
			}





		}

		else {
			if (ItemIsInStock[1] == false) {
				std::cout << "Item Is Not In Stock\n" << std::endl;
			}
			else {
				std::cout << "Insufficient Funds\n" << std::endl;
			}
		}

		break;




	case 3:
		if (ShopPlayerCurrency >= ShopSlotItemCost[2] && ItemIsInStock[2]) {
			std::cout << ShopSlotItemName[2] << " Purchased!\n" << std::endl;

			ShopPlayerCurrency -= ShopSlotItemCost[2];
			ItemIsInStock[2] = false;



			// equip

			//std::cout << "shop slot weapon type: " << ShopSlotItemType[0] << std::endl;
			if (ShopSlotItemType[2] == "Weapon") {
				EquipBoughtWeapon(2);
			}

			if (ShopSlotItemType[2] == "Armor") {
				EquipBoughtArmor(2);
			}


			if (ShopSlotItemType[2] == "Consumable") {
				BoughtConsumables(2);
			}





		}

		else {
			if (ItemIsInStock[2] == false) {
				std::cout << "Item Is Not In Stock\n" << std::endl;
			}
			else {
				std::cout << "Insufficient Funds\n" << std::endl;
			}
		}

		break;




	case 4:
		PlayerIsShopping = false;

		break;

	default:
		std::cout << "Invalid Option\n" << std::endl;

	}


	return 0;
}