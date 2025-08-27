#define ENEMY_H

#pragma once

#include "Moveset.h"
#include "entity.h"
#include "Position.h"

class Enemy : public Entity
{
private:
	/*std::string EnemyClass;
	int EnemyMaxHP;
	int EnemyHP;
	int EnemyPower;
	int EnemyCritChance;
	int EnemyCurrency;
	int EnemyPosX, EnemyPosY;
	int EnemyLvl;
	int EnemyXP;*/
	bool Phase;
	bool Buffed;
	std::string EnemyEquippedWeapon;
	std::string EnemyEquippedArmor;
	std::vector<std::string> usedMoves;

	Moveset moveset;
protected:


public:
	void SetEnemyClass(std::string Class);
	void SetEnemyHP(int HP);
	void SetEnemyMaxHP(int MaxHP);
	void SetEnemyPower(int Power);
	void SetEnemyCritChance(int CritChance);
	void SetEnemyCurrency(int Currency);
	void SetEnemyPos(int X, int Y);
	void SetEnemyLvl(int Lvl);
	void SetEnemyXP(int XP);
	void SetEnemyEquippedWeapon(std::string Weapon);
	void SetEnemyEquippedArmor(std::string Armor);

	std::string GetEnemyClass(void) const;
	int GetEnemyHP(void) const;
	int GetEnemyMaxHP(void) const;
	int GetEnemyPower(void) const;
	int GetEnemyCritChance(void) const;
	int GetEnemyCurrency(void) const;
	int GetEnemyPosX(void) const;
	int GetEnemyPosY(void) const;
	int GetEnemyLvl(void) const;
	int GetEnemyXP(void) const;
	std::string GetEnemyEquippedWeapon(void) const;
	std::string GetEnemyEquippedArmor(void) const;
	Moveset& GetMoveSet();

	Enemy();
	Enemy(std::string EnemyClass, int EnemyMaxHP, int EnemyHP, int EnemyPower, int EnemyCritChance, int EnemyCurrency, int EnemyPosX, int EnemyPosY, int EnemyLvl, int EnemyXP, std::string EnemyEquippedWeapon, std::string EnemyEquippedArmor);
	~Enemy();

	void InitEnemy();
	static void ShowEnemyStats(Enemy& EC);

	std::string DecisionMatrix(int PlayerHP, bool PlayerBuffed);
};