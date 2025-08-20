#pragma once
#include <string>

class Shop {
protected:
	std::string ShopUIString;
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
	int ShopPlayerNewHP;
	int ShopPlayerNewPower;

	int ShopFloor;

	std::string ShopWarriorWeaponList[7];
	std::string ShopMageWeaponList[7];
	std::string ShopHunterWeaponList[7];
	int ShopWeaponPowerList[7];
	int ShopArmorHPList[5];
	std::string ShopBoughtConsumablesList[3];

public:
	Shop();

	// setter
	void SetPlayerCurrency(int c);
	void SetShopItemListIndex(std::string items, int index);
	void SetShopItemDescriptionListIndex(std::string descriptions, int index);
	void SetShopItemCostListIndex(int costs, int index);
	void SetShopItemTypeListIndex(std::string types, int index);
	void SetShopItemSlot();
	void SetShopPlayerClass(const std::string& c);
	void SetShopFloor(int floor);
	void SetPlayerIsShopping();
	void SetShopPlayerNewHP(int hp);
	void SetShopPlayerNewPower(int power);
	void SetShopWarriorWeaponListIndex(std::string name, int index);
	void SetShopMageWeaponListIndex(std::string name, int index);
	void SetShopHunterWeaponListIndex(std::string name, int index);
	void SetShopWeaponPowerList();
	void SetShopArmorHPList();

	// getter
	int GetPlayerCurrency();
	std::string GetShopPlayerClass();
	bool GetPlayerIsShopping();
	int GetShopPlayerNewHP();
	int GetShopPlayerNewPower();

	// methods
	std::string DrawShopUI();
	int PromptPlayerShopInteraction();
	void EquipBoughtWeapon(int slot);
	void EquipBoughtArmor(int slot);
	void BoughtConsumables(int slot);
};

