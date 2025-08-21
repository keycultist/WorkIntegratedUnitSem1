#pragma once
#include <string>
#include "Moveset.h"
#include "entity.h"
class Player : public Entity
{
private:
	std::string PlayerClass;
	int PlayerMaxHP;
	int PlayerHP;
	int PlayerPower;
	int PlayerCritChance;
	int PlayerPosX, PlayerPosY;
	int PlayerLvl;
	int PlayerXP;
	std::string PlayerEquippedWeapon;
	std::string PlayerEquippedArmor;
	int PlayerCurrency;
	int PlayerKarma;
	int CurrentDifficulty;

	Moveset moveset;

protected:

public:
	void SetPlayerClass(std::string Class);
	void SetPlayerMaxHP(int MaxHP);
	void SetPlayerHP(int HP);
	void SetPlayerPower(int Power);
	void SetPlayermagicPower(int Power);
	void SetPlayerCritChance(int CritChance);
	void SetPlayerPosX(int X);
	void SetPlayerPosY(int Y);
	void SetPlayerLvl(int Lvl);
	void SetPlayerXP(int XP);
	void SetPlayerEquippedWeapon(std::string Weapon);
	void SetPlayerEquippedArmor(std::string Armor);
	void SetPlayerCurrency(int Currency);
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
	int GetPlayerKarma(void) const;
	int GetCurrentDifficulty(void) const;
	Moveset& GetMoveset();

	Player();
	Player(std::string PlayerClass, int PlayerMaxHP, int PlayerHP, int PlayerPower, int PlayerCritChance, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerCurrency, int PlayerKarma, int CurrentDifficulty);
	~Player();

	void InitPlayer();
	void ShowPlayerStats() const;
	void ShowPlayerMoves() const;
	void LevelUpCheck();
	void LevelUp();
	void ListMovesToReplace();
};


