#include "Player.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

void Player::setPlayerClass(std::string Class) {
    PlayerClass = Class; 
}

void Player::setPlayerHP(int HP) { 
    PlayerHP = HP; 
}

void Player::setPlayerPower(int Power) { 
    PlayerPower = Power; 
}

void Player::setPlayerPosX(int X) {
    PlayerPosX = X; 
}

void Player::setPlayerPosY(int Y) {
    PlayerPosY = Y; 
}

void Player::setPlayerLvl(int Lvl) {
    PlayerLvl = Lvl; 
}

void Player::setPlayerXP(int XP) {
    PlayerXP = XP; 
}

void Player::setPlayerEquippedWeapon(std::string Weapon) {
    PlayerEquippedWeapon = Weapon; 
}

void Player::setPlayerEquippedArmor(std::string Armor) {
    PlayerEquippedArmor = Armor; 
}

void Player::setPlayerCurrency(int Currency) {
    PlayerCurrency = Currency; 
}

void Player::setPlayerKarma(int Karma)
{
    PlayerKarma = Karma;
}



std::string Player::getPlayerClass(void) const {
    return PlayerClass; 
}

int Player::getPlayerHP(void) const {
    return PlayerHP; 
}

int Player::getPlayerPower(void) const {
    return PlayerPower; 
}

int Player::getPlayerPosX(void) const {
    return PlayerPosX; 
}

int Player::getPlayerPosY(void) const {
    return PlayerPosY; 
}

int Player::getPlayerLvl(void) const {
    return PlayerLvl; 
}

int Player::getPlayerXP(void) const {
    return PlayerXP; 
}

std::string Player::getPlayerEquippedWeapon(void) const {
    return PlayerEquippedWeapon; 
}

std::string Player::getPlayerEquippedArmor(void) const {
    return PlayerEquippedArmor; 
}

int Player::getPlayerCurrency(void) const {
    return PlayerCurrency; 
}

int Player::getPlayerKarma(void) const
{
    return PlayerKarma;
}

Player::Player()
{
}

Player::Player(std::string PlayerClass, int PlayerHP, int PlayerPower, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerCurrency, int PlayerKarma)
{
    PlayerClass = "";
    PlayerHP = 0;
    PlayerPower = 0;
    PlayerPosX = 0;
    PlayerPosY = 0;
    PlayerLvl = 0;
    PlayerXP = 0;
    PlayerEquippedWeapon = "";
    PlayerEquippedArmor = "";
    PlayerCurrency = 0;
    PlayerKarma = 0;
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
        MC.setPlayerClass("Warrior");
        MC.setPlayerHP(100);
        MC.setPlayerPower(4);
        break;
    case 2:
        MC.setPlayerClass("Mage");
        MC.setPlayerHP(70);
        MC.setPlayerPower(7);
        break;
    case 3:
        MC.setPlayerClass("Hunter");
        MC.setPlayerHP(40);
        MC.setPlayerPower(10);
        break;
    default:
        MC.setPlayerClass("Warrior");
        MC.setPlayerHP(100);
        MC.setPlayerPower(4);
        break;
    }
    MC.setPlayerPosX(0);
    MC.setPlayerPosY(0);
    MC.setPlayerLvl(1);
    MC.setPlayerXP(0);
    MC.setPlayerEquippedWeapon("None");
    MC.setPlayerEquippedArmor("None");
    MC.setPlayerCurrency(0);
    MC.setPlayerKarma(0);
    std::cout << "You are a " << MC.getPlayerClass() << ". With " << MC.getPlayerHP() << " HP and " << MC.getPlayerPower() << " Power." << std::endl;
}

void Player::ShowPlayerStats(Player &MC)
{
    std::cout << "Class: " << MC.getPlayerClass() << std::endl;
    std::cout << "HP: " << MC.getPlayerHP() << std::endl;
    std::cout << "Power: " << MC.getPlayerPower() << std::endl;
    std::cout << "Level: " << MC.getPlayerLvl() << std::endl;
    std::cout << "EXP: " << MC.getPlayerXP() << std::endl;
    std::cout << "Currency: " << MC.getPlayerCurrency() << std::endl;
    std::cout << "Karma: " << MC.getPlayerKarma() << std::endl;
}
