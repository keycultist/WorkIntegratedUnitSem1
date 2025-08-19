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

void Enemy::SetEnemyPower(int Power) {
	EnemyPower = Power;
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

int Enemy::GetEnemyPower(void) const {
	return EnemyPower;
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

void Enemy::ShowEnemyStats(Enemy& MC) {
	// Return Enemy Stats Here with STD::COUT!!!! (tedious)
}