// Inclusions

#include "Enemy.h"
#include "Moveset.h"
#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <vector>
#include <algorithm>
#include <conio.h> 
#include <windows.h>
#include <chrono>

// Define namespace
using namespace std;

// Functions, Classes
void Enemy::SetEnemyClass(std::string Class) {
	SetClass(Class);
}

void Enemy::SetEnemyHP(int HP) {
	SetHP(HP);
}

void Enemy::SetEnemyMaxHP(int MaxHP) {
	SetMaxHP(MaxHP);
}

void Enemy::SetEnemyPower(int Power) {
	SetPower(Power);
}

void Enemy::SetEnemyCritChance(int CritChance) {
	SetCritChance(CritChance);
}

void Enemy::SetEnemyCurrency(int Currency)
{
	SetCurrency(Currency);
}

void Enemy::SetEnemyPos(int X, int Y) {
	SetPos(X, Y);
}

void Enemy::SetEnemyLvl(int Lvl) {
	SetLvl(Lvl);
}

void Enemy::SetEnemyXP(int XP) {
	SetXP(XP);
}

void Enemy::SetEnemyEquippedArmor(std::string Armor) {
	EnemyEquippedArmor = Armor;
}

void Enemy::SetEnemyEquippedWeapon(std::string Weapon) {
	EnemyEquippedWeapon = Weapon;
}

std::string Enemy::GetEnemyClass(void) const {
	return GetClass();
}

int Enemy::GetEnemyHP(void) const {
	return GetHP();
}

int Enemy::GetEnemyMaxHP(void) const {
	return GetMaxHP();
}

int Enemy::GetEnemyPower(void) const {
	return GetPower();
}

int Enemy::GetEnemyCritChance(void) const {
	return GetCritChance();
}

int Enemy::GetEnemyCurrency(void) const
{
	return GetCurrency();
}

int Enemy::GetEnemyPosX(void) const {
	return GetPosX();
}

int Enemy::GetEnemyPosY(void) const {
	return GetPosY();
}

int Enemy::GetEnemyLvl(void) const {
	return GetLvl();
}

int Enemy::GetEnemyXP(void) const {
	return GetXP();
}

std::string Enemy::GetEnemyEquippedWeapon(void) const {
	return EnemyEquippedWeapon;
}

std::string Enemy::GetEnemyEquippedArmor(void) const {
	return EnemyEquippedArmor;
}

Moveset& Enemy::GetMoveSet() {
	return moveset;
}

Enemy::Enemy() : Entity("Grunt", 100, 100, 5, 5, 0, 0, 0, 1, 0), EnemyEquippedWeapon("None"), EnemyEquippedArmor("None")
{
}

Enemy::Enemy(std::string EnemyClass, int EnemyMaxHP, int EnemyHP, int EnemyPower, int EnemyCritChance, int EnemyCurrency, int EnemyPosX, int EnemyPosY, int EnemyLvl, int EnemyXP, std::string EnemyEquippedWeapon, std::string EnemyEquippedArmor)
	: Entity(EnemyClass, EnemyMaxHP, EnemyHP, EnemyPower, EnemyCritChance, EnemyCurrency, EnemyPosX, EnemyPosY, EnemyLvl, EnemyXP), EnemyEquippedWeapon(EnemyEquippedWeapon), EnemyEquippedArmor(EnemyEquippedArmor)
{
}

Enemy::~Enemy()
{
}

void Enemy::InitEnemy()
{
	SetEnemyClass("Grunt");
	SetEnemyMaxHP(20);
	SetEnemyHP(20);
	SetEnemyPower(1);
	SetEnemyCritChance(5);
	SetEnemyPos(0, 0);;
	SetEnemyLvl(1);
	SetEnemyXP(0);
	Phase = false;
	SetEnemyEquippedWeapon("None");
	SetEnemyEquippedArmor("None");
	moveset.EnemyInit(GetEnemyClass());
}

void Enemy::ShowEnemyStats(Enemy& MC) {
	// Return Enemy Stats Here with STD::COUT!!!! (tedious)
}

int Enemy::DecisionMatrix(int EnemyHP, bool EnemyBuffed)
{
	// Standard Enemy Decision Matrix, here we go.

	if (usedMoves.size() >= 3) {
		usedMoves.erase(usedMoves.begin());
	}

	if (EnemyHP <= 0) {
		return 0;
	}
	else {
		if (GetEnemyClass() != "OneWingedAngel" and GetEnemyClass() != "JovialChaos") {
			if (EnemyHP <= 0) {
				return 0;
			}

			else if (Buffed == false) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Buff") {
						std::string moveName = moveset.GetMove(i).MoveName;

						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							return i;
						}
					}
				}
			}

			// thank you, next. (ariana grande!!!!) if no buff is available, check if Enemy is buffed.
			if (EnemyBuffed == true) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Debuff") {
						std::string moveName = moveset.GetMove(i).MoveName;
						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							return i;
						}
					}
				}
			}

			// if all else fails, launch an attack. or smth like that
			for (int i = 0; i < moveset.size(); i++) {
				if (moveset.GetMove(i).MoveType == "Physical" ||
					moveset.GetMove(i).MoveType == "Abyssal" ||
					moveset.GetMove(i).MoveType == "Magical") {
					return i;
				}
			}

		}
		else {
			// SPECIAL TRUE BOSS DECISION MATRIX WHAT THE WHAT!?!?
			if (EnemyHP <= 0) {
				if (Phase == true) {
					for (int i = 0; i < moveset.size(); i++) {
						if (moveset.GetMove(i).MoveType == "DeathMove") {
							return i;
						}
					}

					EnemyHP = 0;
					Phase = false;
				}
				return 0;
			}

			else if (Buffed == false) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Buff") {
						std::string moveName = moveset.GetMove(i).MoveName;

						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							break;
						}
						else {
							return i;
						}
					}
				}
			}

			// thank you, next. (ariana grande!!!!) if no buff is available, check if Enemy is buffed.
			if (EnemyBuffed == true) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Counter") {
						std::string moveName = moveset.GetMove(i).MoveName;
						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							return i;
						}
					}
				}
			}

			if (Buffed == true) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Physical" ||
						moveset.GetMove(i).MoveType == "Abyssal" ||
						moveset.GetMove(i).MoveType == "Magical") {
						std::string moveName = moveset.GetMove(i).MoveName;
						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							return i;
						}
					}
				}
			}

			if (EnemyHP <= GetEnemyMaxHP() / 2) {
				if (Phase == false) {
					Phase = true;

					for (int i = 0; i < moveset.size(); i++) {
						if (moveset.GetMove(i).MoveType == "BossMove") {
							return i;
						}
					}
				}
			}

			if (EnemyHP <= GetEnemyMaxHP() / 99) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "DeathMove") {
						EnemyHP = 0;
						Phase = false;
						return i;
					}
				}
			}

			// if all else fails, launch an attack. or smth like that
			for (int i = 0; i < moveset.size(); i++) {
				if (moveset.GetMove(i).MoveType == "Physical" ||
					moveset.GetMove(i).MoveType == "Abyssal" ||
					moveset.GetMove(i).MoveType == "Magical") {
					return i;
				}
			}



		}
	}
}