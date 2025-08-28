#pragma once
#include <string>
#include "Player.h"
#include "Item.h"
#include "Inventory.h"

class Shop {
protected:
	//std::ostringstream ShopUIString;
	int ShopSlotIndex;
	std::string ShopSlotItemName[3];
	std::string ShopSlotItemDescription[3];
	int ShopSlotItemCost[3];
	std::string ShopSlotItemType[3];
	int PlayerShopChoice;
	bool ItemIsInStock[3];
	bool PlayerIsShopping;

	std::string ShopBoughtConsumablesList[3];

	std::string descline[4];
public:
	Shop();

	// setter
	void SetShopItemSlot(Player& MC, Item& items);
	void SetPlayerIsShopping(bool a);

	// getter
	bool GetPlayerIsShopping();

	// methods
	std::string DrawShopUI(Player& MC, Item& items, Inventory& inv);
	int PromptPlayerShopInteraction(Player& MC, Item& items, Inventory& inv);
	void EquipBoughtWeapon(Player& MC, Item& items, int slot);
	void EquipBoughtArmor(Player& MC, Item& items, int slot);
	void SplitDescriptionString(std::string description);
	void BoughtConsumables(Item& items, int slot);
};

