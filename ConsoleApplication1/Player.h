#pragma once
#include <string>
#include "Moveset.h"
#include "Inventory.h"
#include "entity.h"
#include "Position.h"
class Player : public Entity
{
private:
	/*std::string PlayerClass;
	int PlayerMaxHP;
	int PlayerHP;
	int PlayerPower;
	int PlayerCritChance;
	int PlayerCurrency;
	int PlayerPosX, PlayerPosY;
	int PlayerLvl;
	int PlayerXP;*/
	//Commented out bc of Entity class integration
	std::string PlayerEquippedWeapon;
	std::string PlayerEquippedArmor;
	int PlayerWeaponPower;
	int PlayerArmorHP;
	int PlayerArmorDefence;
	int PlayerDefence;
	int PlayerKarma;
	int CurrentDifficulty;

	Moveset moveset;
	Inventory inventory;

protected:

public:
	void SetPlayerClass(std::string Class);
	void SetPlayerMaxHP(int MaxHP);
	void SetPlayerHP(int HP);
	void SetPlayerPower(int Power);
	void SetPlayerCritChance(int CritChance);
	void SetPlayerPos(int X, int Y);
	void SetPlayerLvl(int Lvl);
	void SetPlayerXP(int XP);
	void SetPlayerEquippedWeapon(std::string Weapon);
	void SetPlayerEquippedArmor(std::string Armor);
	void SetPlayerCurrency(int Currency);
	void SetPlayerWeaponPower(int WPower);
	void SetPlayerArmorHP(int AHP);
	void SetPlayerArmorDefence(int ADefence);
	void SetPlayerDefence(int Defence);
	void SetPlayerKarma(int Karma);
	void SetCurrentDifficulty(int Difficulty);

	std::string GetPlayerClass(void) const;
	int GetPlayerMaxHP(void) const;
	int GetPlayerHP(void) const;
	int GetPlayerPower(void) const;
	int GetPlayerCritChance(void) const;
	int GetPlayerPosX(void) const;
	int GetPlayerPosY(void) const;
	int GetPlayerLvl(void) const;
	int GetPlayerXP(void) const;
	std::string GetPlayerEquippedWeapon(void) const;
	std::string GetPlayerEquippedArmor(void) const;
	int GetPlayerCurrency(void) const;
	int GetPlayerWeaponPower(void) const;
	int GetPlayerArmorHP(void) const;
	int GetPlayerArmorDefence(void) const;
	int GetPlayerDefence(void) const;
	int GetPlayerKarma(void) const;
	int GetCurrentDifficulty(void) const;
	Moveset& GetMoveSet();
	Inventory& GetInventory();

	Player();
	Player(std::string PlayerClass, int PlayerMaxHP, int PlayerHP, int PlayerPower, int PlayerCritChance, int PlayerCurrency, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerKarma, int CurrentDifficulty);
	~Player();

	void InitPlayer();
	void ShowPlayerStats() const;
	void ShowPlayerMoves() const;
	void LevelUpCheck();
	void LevelUp();
	void ListMovesToReplace();

	void UpdateInventoryPlayerStats();
	void UpdatePlayerStatsInventory();
	void AddPlayerEquipmentStats();

	virtual void move();
	/*virtual void checkEnemy(Player& MC, Enemy& target);
	virtual void checkEvent(Entity* ptr[6]);*/
};


