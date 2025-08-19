#include "Player.h"
#include "Moveset.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

void Player::SetPlayerClass(std::string Class) {
    PlayerClass = Class;
}

void Player::SetPlayerHP(int HP) {
    PlayerHP = HP;
}

void Player::SetPlayerPower(int Power) {
    PlayerPower = Power;
}

void Player::SetPlayerCritChance(int CritChance)
{
    PlayerCritChance = CritChance;
}

void Player::SetPlayerPosX(int X) {
    PlayerPosX = X;
}

void Player::SetPlayerPosY(int Y) {
    PlayerPosY = Y;
}

void Player::SetPlayerLvl(int Lvl) {
    PlayerLvl = Lvl;
}

void Player::SetPlayerXP(int XP) {
    PlayerXP = XP;
}

void Player::SetPlayerEquippedWeapon(std::string Weapon) {
    PlayerEquippedWeapon = Weapon;
}

void Player::SetPlayerEquippedArmor(std::string Armor) {
    PlayerEquippedArmor = Armor;
}

void Player::SetPlayerCurrency(int Currency) {
    PlayerCurrency = Currency;
}

void Player::SetPlayerKarma(int Karma)
{
    PlayerKarma = Karma;
}



std::string Player::GetPlayerClass(void) const {
    return PlayerClass;
}

int Player::GetPlayerHP(void) const {
    return PlayerHP;
}

int Player::GetPlayerPower(void) const {
    return PlayerPower;
}

int Player::GetPlayerCritChance(void) const
{
    return PlayerCritChance;
}

int Player::GetPlayerPosX(void) const {
    return PlayerPosX;
}

int Player::GetPlayerPosY(void) const {
    return PlayerPosY;
}

int Player::GetPlayerLvl(void) const {
    return PlayerLvl;
}

int Player::GetPlayerXP(void) const {
    return PlayerXP;
}

std::string Player::GetPlayerEquippedWeapon(void) const {
    return PlayerEquippedWeapon;
}

std::string Player::GetPlayerEquippedArmor(void) const {
    return PlayerEquippedArmor;
}

int Player::GetPlayerCurrency(void) const {
    return PlayerCurrency;
}

int Player::GetPlayerKarma(void) const
{
    return PlayerKarma;
}

Moveset& Player::GetMoveset()
{
    return moveset;
}

Player::Player()
{
}

Player::Player(std::string PlayerClass, int PlayerHP, int PlayerPower, int PlayerCritChance, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerCurrency, int PlayerKarma)
{
}

Player::~Player()
{
}

void Player::InitPlayer()
{
    int ChosenClass;
    std::cout << "What Class are You? (Warrior by default)" << std::endl;
    std::cout << "[1] Warrior" << std::endl;
    std::cout << "[2] Mage" << std::endl;
    std::cout << "[3] Hunter" << std::endl;
    std::cin >> ChosenClass;
    switch (ChosenClass) {
    case 1:
        SetPlayerClass("Warrior");
        SetPlayerHP(100);
        SetPlayerPower(4);
        break;
    case 2:
        SetPlayerClass("Mage");
        SetPlayerHP(70);
        SetPlayerPower(7);
        break;
    case 3:
        SetPlayerClass("Hunter");
        SetPlayerHP(40);
        SetPlayerPower(10);
        break;
    default:
        SetPlayerClass("Warrior");
        SetPlayerHP(100);
        SetPlayerPower(4);
        break;
    }
    SetPlayerPosX(0);
    SetPlayerPosY(0);
    SetPlayerLvl(1);
    SetPlayerXP(0);
    SetPlayerEquippedWeapon("None");
    SetPlayerEquippedArmor("None");
    SetPlayerCurrency(0);
    SetPlayerKarma(0);
    moveset.PlayerInit(GetPlayerClass());
    std::cout << "You are a " << GetPlayerClass() << ". With " << GetPlayerHP() << " HP and " << GetPlayerPower() << " Power." << std::endl;
}

void Player::ShowPlayerStats() const
{
    std::cout << "Class: " << GetPlayerClass() << std::endl;
    std::cout << "HP: " << GetPlayerHP() << std::endl;
    std::cout << "Power: " << GetPlayerPower() << std::endl;
    std::cout << "Level: " << GetPlayerLvl() << std::endl;
    std::cout << "EXP: " << GetPlayerXP() << std::endl;
    std::cout << "Currency: " << GetPlayerCurrency() << std::endl;
    std::cout << "Karma: " << GetPlayerKarma() << std::endl;
}

void Player::LevelUpCheck()
{
    int baseXP = 10;

    while (GetPlayerXP() >= baseXP)
    {
        SetPlayerXP(GetPlayerXP() - baseXP);
        SetPlayerLvl(GetPlayerLvl() + 1);

        std::cout << "Level up! You are now level " << GetPlayerLvl() << "!\n";

        baseXP += 10;
    }
}

void Player::LevelUp()
{
    if (GetPlayerClass() == "Warrior") {
        SetPlayerHP(GetPlayerHP() + 10);
        SetPlayerPower(GetPlayerPower() + 3);
    }
    else if (GetPlayerClass() == "Mage") {
        SetPlayerHP(GetPlayerHP() + 6);
        SetPlayerPower(GetPlayerPower() + 4);
    }
    else if (GetPlayerClass() == "Hunter") {
        SetPlayerHP(GetPlayerHP() + 3);
        SetPlayerPower(GetPlayerPower() + 5);
    }
}
