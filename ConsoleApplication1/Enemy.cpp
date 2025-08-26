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
	EnemyClass = Class;
}

void Enemy::SetEnemyHP(int HP) {
	EnemyHP = HP;
}

void Enemy::SetEnemyMaxHP(int MaxHP) {
	EnemyMaxHP = MaxHP;
}

void Enemy::SetEnemyPower(int Power) {
	EnemyPower = Power;
}

void Enemy::SetEnemyCritChance(int CritChance) {
	EnemyCritChance = CritChance;
}

void Enemy::SetEnemyPos(int X, int Y) {
	EnemyPosX, EnemyPosY = X, Y;
}

void Enemy::SetEnemyLvl(int Lvl) {
	EnemyLvl = Lvl;
}

void Enemy::SetEnemyXP(int XP) {
	EnemyXP = XP;
}

void Enemy::SetEnemyEquippedArmor(std::string Armor) {
	EnemyEquippedArmor = Armor;
}

void Enemy::SetEnemyEquippedWeapon(std::string Weapon) {
	EnemyEquippedWeapon = Weapon;
}

std::string Enemy::GetEnemyClass(void) const {
	return EnemyClass;
}

int Enemy::GetEnemyHP(void) const {
	return EnemyHP;
}

int Enemy::GetEnemyMaxHP(void) const {
	return EnemyMaxHP;
}

int Enemy::GetEnemyPower(void) const {
	return EnemyPower;
}

int Enemy::GetEnemyCritChance(void) const {
	return EnemyCritChance;
}

int Enemy::GetEnemyPosX(void) const {
	return EnemyPosX;
}

int Enemy::GetEnemyPosY(void) const {
	return EnemyPosY;
}

int Enemy::GetEnemyLvl(void) const {
	return EnemyLvl;
}

int Enemy::GetEnemyXP(void) const {
	return EnemyXP;
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

Enemy::Enemy()
{
}

Enemy::Enemy(std::string EnemyClass, int EnemyHP, int EnemyPower, int EnemyPosX, int EnemyPosY, int EnemyLvl, std::string EnemyEquippedWeapon, std::string EnemyEquippedArmor)
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
}

void Enemy::ShowEnemyStats(Enemy& MC) {
	// Return Enemy Stats Here with STD::COUT!!!! (tedious)
}

std::string Enemy::DecisionMatrix(int PlayerHP, bool PlayerBuffed)
{
	// Standard Enemy Decision Matrix, here we go.

	if (usedMoves.size() >= 3) {
		usedMoves.erase(usedMoves.begin());
	}

	if (EnemyHP <= 0) {
		return "DEAD";
	}
	else {
		if (EnemyClass != "OneWingedAngel" and EnemyClass != "JovialChaos") {
			if (EnemyHP <= 0) {
				return "DEAD";
			}

			else if (Buffed == false) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Buff") {
						std::string moveName = moveset.GetMove(i).MoveName;

						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							return moveName;
						}
					}
				}
			}

			// thank you, next. (ariana grande!!!!) if no buff is available, check if player is buffed.
			if (PlayerBuffed == true) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Debuff") {
						std::string moveName = moveset.GetMove(i).MoveName;
						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							return moveName;
						}
					}
				}
			}

			// if all else fails, launch an attack. or smth like that
			for (int i = 0; i < moveset.size(); i++) {
				if (moveset.GetMove(i).MoveType == "Physical" ||
					moveset.GetMove(i).MoveType == "Abyssal" ||
					moveset.GetMove(i).MoveType == "Magical") {
					return moveset.GetMove(i).MoveName;
				}
			}

		}
		else {
			// SPECIAL TRUE BOSS DECISION MATRIX WHAT THE WHAT!?!?
			if (EnemyHP <= 0) {
				if (Phase == true) {
					for (int i = 0; i < moveset.size(); i++) {
						if (moveset.GetMove(i).MoveType == "DeathMove") {
							return moveset.GetMove(i).MoveName;
						}
					}

					EnemyHP = 0;
					Phase = false;
				}
				return "DEAD";
			}

			else if (Buffed == false) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Buff") {
						std::string moveName = moveset.GetMove(i).MoveName;

						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							return moveName;
						}
					}
				}
			}

			// thank you, next. (ariana grande!!!!) if no buff is available, check if player is buffed.
			if (PlayerBuffed == true) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "Counter") {
						std::string moveName = moveset.GetMove(i).MoveName;
						if (std::find(usedMoves.begin(), usedMoves.end(), moveName) == usedMoves.end()) {
							return moveName;
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
							return moveName;
						}
					}
				}
			}

			if (EnemyHP <= EnemyMaxHP / 2) {
				if (Phase == false) {
					Phase = true;

					for (int i = 0; i < moveset.size(); i++) {
						if (moveset.GetMove(i).MoveType == "BossMove") {
							return moveset.GetMove(i).MoveName;
						}
					}
				}
			}

			if (EnemyHP <= EnemyMaxHP / 99) {
				for (int i = 0; i < moveset.size(); i++) {
					if (moveset.GetMove(i).MoveType == "DeathMove") {
						EnemyHP = 0;
						Phase = false;
						return moveset.GetMove(i).MoveName;
					}
				}
			}

			// if all else fails, launch an attack. or smth like that
			for (int i = 0; i < moveset.size(); i++) {
				if (moveset.GetMove(i).MoveType == "Physical" ||
					moveset.GetMove(i).MoveType == "Abyssal" ||
					moveset.GetMove(i).MoveType == "Magical") {
					return moveset.GetMove(i).MoveName;
				}
			}



		}
	}
}