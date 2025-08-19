#include "Player.h"
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

//void Player::SetPlayerMoveset(const Moveset& m)
//{
//    PlayerMoveset = m;
//}



std::string Player::GetPlayerClass(void) const {
    return PlayerClass; 
}

int Player::GetPlayerHP(void) const {
    return PlayerHP; 
}

int Player::GetPlayerPower(void) const {
    return PlayerPower; 
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

//Moveset Player::GetPlayerMoveset() const
//{
//    return PlayerMoveset();
//}

Player::Player()
{
}

Player::Player(std::string PlayerClass, int PlayerHP, int PlayerPower, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerCurrency, int PlayerKarma)
{
}

Player::~Player()
{
}

void Player::InitPlayer(Player &MC)
{
    //MC = new Player();
    int ChosenClass;
    std::cout << "What Class are You? (Warrior by default)" << std::endl;
    std::cout << "[1] Warrior" << std::endl;
    std::cout << "[2] Mage" << std::endl;
    std::cout << "[3] Hunter" << std::endl;
    std::cin >> ChosenClass;
    switch (ChosenClass) {
    case 1:
        MC.SetPlayerClass("Warrior");
        MC.SetPlayerHP(100);
        MC.SetPlayerPower(4);
        //MC.SetPlayerMoveset({});
        break;
    case 2:
        MC.SetPlayerClass("Mage");
        MC.SetPlayerHP(70);
        MC.SetPlayerPower(7);
        //MC.setPlayerMoveset({});
        break;
    case 3:
        MC.SetPlayerClass("Hunter");
        MC.SetPlayerHP(40);
        MC.SetPlayerPower(10);
        //MC.setPlayerMoveset({});
        break;
    default:
        MC.SetPlayerClass("Warrior");
        MC.SetPlayerHP(100);
        MC.SetPlayerPower(4);
        //MC.setPlayerMoveset({});
        break;
    }
    MC.SetPlayerPosX(0);
    MC.SetPlayerPosY(0);
    MC.SetPlayerLvl(1);
    MC.SetPlayerXP(0);
    MC.SetPlayerEquippedWeapon("None");
    MC.SetPlayerEquippedArmor("None");
    MC.SetPlayerCurrency(0);
    MC.SetPlayerKarma(0);
    std::cout << "You are a " << MC.GetPlayerClass() << ". With " << MC.GetPlayerHP() << " HP and " << MC.GetPlayerPower() << " Power." << std::endl;
}

void Player::ShowPlayerStats(Player &MC)
{
    std::cout << "Class: " << MC.GetPlayerClass() << std::endl;
    std::cout << "HP: " << MC.GetPlayerHP() << std::endl;
    std::cout << "Power: " << MC.GetPlayerPower() << std::endl;
    std::cout << "Level: " << MC.GetPlayerLvl() << std::endl;
    std::cout << "EXP: " << MC.GetPlayerXP() << std::endl;
    std::cout << "Currency: " << MC.GetPlayerCurrency() << std::endl;
    std::cout << "Karma: " << MC.GetPlayerKarma() << std::endl;
    //std::cout << "Moveset: " << MC.GetPlayerMoveset() << std::endl;
}
