#pragma once
#include <string>
#include "Player.h"
#include "Item.h"
#include "Inventory.h"

class Shop {
protected:
	//std::ostringstream ShopUIString;
	std::string ShopItemList[23];
	std::string ShopItemDescriptionList[23];
	int ShopItemCostList[23];
	std::string ShopItemTypeList[23];
	int ShopSlotIndex;
	std::string ShopSlotItemName[3];
	std::string ShopSlotItemDescription[3];
	int ShopSlotItemCost[3];
	std::string ShopSlotItemType[3];
	int PlayerShopChoice;
	bool ItemIsInStock[3];
	bool PlayerIsShopping;

	int ShopPlayerCurrency;
	std::string ShopPlayerClass;
	int ShopPlayerBaseHP;
	int ShopPlayerNewHP;
	int ShopPlayerNewPower;

	int ShopFloor;

	std::string ShopWeaponList[7];
	int ShopWeaponPowerList[7];
	int ShopArmorHPList[5];
	int ShopArmorDefList[5];
	std::string ShopBoughtConsumablesList[3];

	std::string ShopPlayerEquippedWeapon;
	std::string ShopPlayerEquippedArmor;

	std::string InventoryConsumableList[10];

	std::string descline[4];
public:
	Shop();

	// setter
	void SetPlayerCurrency(int c);
	void SetShopItemListIndex(std::string items, int index);
	void SetShopItemDescriptionListIndex(std::string descriptions, int index);
	void SetShopItemCostListIndex(int costs, int index);
	void SetShopItemTypeListIndex(std::string types, int index);
	void SetShopItemSlot(Player& MC, Item& items);
	void SetShopPlayerClass(const std::string& c);
	void SetShopFloor(int floor);
	void SetPlayerIsShopping(bool a);
	void SetShopPlayerBaseHP(int hp);
	void SetShopPlayerNewHP(int hp);
	void SetShopPlayerNewPower(int power);
	void SetShopWeaponListIndex(std::string name, int index);
	void SetShopWeaponPowerList();
	void SetShopArmorHPList();
	void SetShopArmorDefList();
	void SetConsumablesListIndex(std::string name, int index);
	void SetInventoryConsumableListIndex(std::string name, int index);

	// getter
	int GetPlayerCurrency();
	std::string GetShopPlayerClass();
	bool GetPlayerIsShopping();
	int GetShopPlayerNewHP();
	int GetShopPlayerNewPower();
	std::string GetShopPlayerEquippedWeapon();
	std::string GetShopPlayerEquippedArmor();
	int GetShopFloor();
	std::string GetConsumablesListIndex(int index);

	// methods
	std::string DrawShopUI(Player& MC, Item& items, Inventory& inv);
	int PromptPlayerShopInteraction(Player& MC, Item& items, Inventory& inv);
	void EquipBoughtWeapon(Player& MC, Item& items, int slot);
	void EquipBoughtArmor(Player& MC, Item& items, int slot);
	void BoughtConsumables(Item& items, int slot);
	void SplitDescriptionString(std::string description);
};

