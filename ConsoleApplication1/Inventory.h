#pragma once
#include "Item.h"
#include <string>
//#include "Player.h"

class Inventory
{
protected:
	Item item;
	std::string InventoryUIString;
	std::string InventoryWeaponEquipped;
	std::string InventoryArmorEquipped;
	std::string InventoryPlayerClass;
	int InventoryPlayerLvl;
	int InventoryPlayerEXP;
	int InventoryPlayerHP;
	int InventoryPlayerMaxHP;
	int InventoryPlayerPower;
	int InventoryPlayerDefence;
	int InventoryPlayerCritChance;
	int InventoryPlayerCurrency;
	int InventoryCurrentDifficulty;

	std::string InventoryConsumables[10];
	int ConsumableIndex;

	bool InventoryPlayerIsUsingItem;
	int InventoryPlayerItemUseChoice;

	std::string InventoryItemList[23];
	std::string InventoryItemDescriptionList[23];
	std::string InventoryItemTypeList[23];
	std::string InventoryWeaponList[7];
	int InventoryWeaponPowerList[7];
	int InventoryArmorHPList[7];

	std::string ItemDropRarity;
	std::string DroppedItem;
	std::string DroppedItemType;

	std::string InventoryConsumablesItemList[12];
	int InventoryConsumablesItemEffectList[12];

public:
	Inventory();

	// setter
	void SetInventoryWeaponEquipped(std::string name);
	void SetInventoryArmorEquipped(std::string name);
	void SetInventoryPlayerClass(std::string classname);
	void SetInventoryPlayerLvl(int lvl);
	void SetInventoryPlayerEXP(int exp);
	void SetInventoryPlayerHP(int hp);
	void SetInventoryPlayerMaxHP(int maxhp);
	void SetInventoryPlayerPower(int power);
	void SetInventoryPlayerDefence(int defence);
	void SetInventoryPlayerCritChance(int critchance);
	void SetInventoryPlayerCurrency(int gold);
	void SetInventoryCurrentDifficulty(int floor);
	void SetInventoryConsumables(std::string consumable, int index);
	void SetConsumableIndex(int index);
	void SetInventoryItemListIndex(std::string name, int index);
	void SetInventoryItemDescriptionListIndex(std::string name, int index);
	void SetInventoryItemTypeListIndex(std::string name, int index);
	void SetInventoryWeaponListIndex(std::string name, int index);
	void SetInventoryWeaponPowerList();
	void SetInventoryArmorHPList();
	void SetInventoryConsumablesItemList();
	void SetInventoryConsumablesItemEffectList();

	// getter
	std::string GetInventoryWeaponEquipped();
	std::string GetInventoryArmorEquipped();
	int GetInventoryPlayerHP();
	int GetInventoryPlayerMaxHP();
	int GetInventoryPlayerPower();
	int GetInventoryPlayerDefence();
	int GetInventoryPlayerCritChance();
	Item& GetItem();

	std::string GetInventoryConsumablesIndex(int index);
	int GetConsumableIndex();

	// methods
	std::string DrawInventoryUI();
	void PromptPlayerUseItem();
	void ItemEffectCheck();
	void UpdateConsumablesInventory();
	void ObtainItemDrop();








};