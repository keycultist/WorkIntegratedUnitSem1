#pragma once
#include <string>

class Item
{
protected:
	std::string ItemList[23];
	std::string ItemDescriptionList[23];
	int ItemCostList[23];
	std::string ItemTypeList[23];
	std::string ItemPlayerClass;

	std::string WeaponList[7];
	std::string WarriorWeaponList[7];
	std::string MageWeaponList[7];
	std::string HunterWeaponList[7];
	std::string AssassinWeaponList[7];
	std::string BerserkerWeaponList[7];
	std::string SummonerWeaponList[7];
	std::string RitualistWeaponList[7];


public:
	Item();

	// setter
	void SetItemPlayerClass(std::string c);
	void SetItemList();
	void SetItemDescriptionList();
	void SetItemCostList();
	void SetItemTypeList();
	void SetWeaponList();

	// getter
	std::string GetItemPlayerClass();
	std::string GetItemListIndex(int index);
	std::string GetItemDescriptionListIndex(int index);
	int GetItemCostListIndex(int index);
	std::string GetItemTypeListIndex(int index);
	std::string GetWeaponListIndex(int index);
	std::string GetWarriorWeaponListIndex(int index);
	std::string GetMageWeaponListIndex(int index);
	std::string GetHunterWeaponListIndex(int index);
	std::string GetAssassinWeaponListIndex(int index);
	std::string GetBerserkerWeaponListIndex(int index);
	std::string GetSummonerWeaponListIndex(int index);
	std::string GetRitualistWeaponListIndex(int index);
};

