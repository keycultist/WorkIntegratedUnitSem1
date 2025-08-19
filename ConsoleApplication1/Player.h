#pragma once
#include <string>
class Player
{
private:
	std::string PlayerClass;
	int PlayerHP;
	int PlayerPower;
	int PlayerPosX, PlayerPosY;
	int PlayerLvl;
	int PlayerXP;
	std::string PlayerEquippedWeapon;
	std::string PlayerEquippedArmor;
	int PlayerCurrency;
	int PlayerKarma;

	//Moveset PlayerMoveset;

protected:

public:
	void SetPlayerClass(std::string Class);
	void SetPlayerHP(int HP);
	void SetPlayerPower(int Power);
	void SetPlayerPosX(int X);
	void SetPlayerPosY(int Y);
	void SetPlayerLvl(int Lvl);
	void SetPlayerXP(int XP);
	void SetPlayerEquippedWeapon(std::string Weapon);
	void SetPlayerEquippedArmor(std::string Armor);
	void SetPlayerCurrency(int Currency);
	void SetPlayerKarma(int Karma);
	//void SetPlayerMoveset(const Moveset& m);

	std::string GetPlayerClass(void) const;
	int GetPlayerHP(void) const;
	int GetPlayerPower(void) const;
	int GetPlayerPosX(void) const;
	int GetPlayerPosY(void) const;
	int GetPlayerLvl(void) const;
	int GetPlayerXP(void) const;
	std::string GetPlayerEquippedWeapon(void) const;
	std::string GetPlayerEquippedArmor(void) const;
	int GetPlayerCurrency(void) const;
	int GetPlayerKarma(void) const;
	//Moveset GetPlayerMoveset() const;

	Player();
	Player(std::string PlayerClass, int PlayerHP, int PlayerPower, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerCurrency, int PlayerKarma);
	~Player();

	static void InitPlayer(Player &MC);
	static void ShowPlayerStats(Player &MC);
};


