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
	void setPlayerClass(std::string Class);
	void setPlayerHP(int HP);
	void setPlayerPower(int Power);
	void setPlayerPos(int X, int Y);
	//void setPlayerPosY(int Y);
	void setPlayerLvl(int Lvl);
	void setPlayerXP(int XP);
	void setPlayerEquippedWeapon(std::string Weapon);
	void setPlayerEquippedArmor(std::string Armor);
	void setPlayerCurrency(int Currency);
	void setPlayerKarma(int Karma);
	//void setPlayerMoveset(const Moveset& m);

	std::string getPlayerClass(void) const;
	int getPlayerHP(void) const;
	int getPlayerPower(void) const;
	int getPlayerPos(void) const;
	//int getPlayerPosY(void) const;
	int getPlayerLvl(void) const;
	int getPlayerXP(void) const;
	std::string getPlayerEquippedWeapon(void) const;
	std::string getPlayerEquippedArmor(void) const;
	int getPlayerCurrency(void) const;
	int getPlayerKarma(void) const;
	//Moveset getPlayerMoveset() const;

	Player();
	Player(std::string PlayerClass, int PlayerHP, int PlayerPower, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerCurrency, int PlayerKarma);
	~Player();

	static void InitPlayer(Player &MC);
	static void ShowPlayerStats(Player &MC);
};


