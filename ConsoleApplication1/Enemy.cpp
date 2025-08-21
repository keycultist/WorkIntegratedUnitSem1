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
	SetEnemyEquippedWeapon("None");
	SetEnemyEquippedArmor("None");
}

void Enemy::ShowEnemyStats(Enemy& MC) {
	// Return Enemy Stats Here with STD::COUT!!!! (tedious)
}

std::string Enemy::DecisionMatrix()
{
	// HP Check
	// Based off HP / Enemy Power, decides what to do
	// If HP < 20% and SpecialClass, use specialClass Move.
	// if SpecialClass Move requires conditionals, check if conditions are met.
	// If not, then heal or enter phase change if they have one.
	// If HP < 50% and not specialClass, use Heal Move if available.
	// If heal already used, dont use heal again for N turns.
	// If player is low hp, focus on attacking.
	// If player is high hp, focus on debuffing or buffing.
	
	// For Special Bosses, use a different Decision Matrix.
	// 
}