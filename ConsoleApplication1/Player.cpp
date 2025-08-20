#include "Player.h"
#include "Moveset.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 

void Player::SetPlayerClass(std::string Class) {
    PlayerClass = Class;
}

void Player::SetPlayerMaxHP(int MaxHP)
{
    PlayerMaxHP = MaxHP;
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

void Player::SetCurrentDifficulty(int Difficulty)
{
    CurrentDifficulty = Difficulty;
}



std::string Player::GetPlayerClass(void) const {
    return PlayerClass;
}

int Player::GetPlayerMaxHP(void) const
{
    return PlayerMaxHP;
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

int Player::GetCurrentDifficulty(void) const
{
    return CurrentDifficulty;
}

Moveset& Player::GetMoveset()
{
    return moveset;
}

Player::Player() : PlayerClass("Warrior"), PlayerMaxHP(100), PlayerHP(100), PlayerPower(5), PlayerCritChance(5), PlayerPosX(0), PlayerPosY(0), PlayerLvl(1), PlayerXP(0), PlayerEquippedWeapon("None"), PlayerEquippedArmor("None"), PlayerCurrency(0), PlayerKarma(50), CurrentDifficulty(1)
{
}

Player::Player(std::string PlayerClass, int PlayerMaxHP, int PlayerHP, int PlayerPower, int PlayerCritChance, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerCurrency, int PlayerKarma, int CurrentDifficulty) : PlayerClass(PlayerClass), PlayerMaxHP(PlayerMaxHP), PlayerHP(PlayerHP), PlayerPower(PlayerPower), PlayerCritChance(PlayerCritChance), PlayerPosX(PlayerPosX), PlayerPosY(PlayerPosY), PlayerLvl(PlayerLvl), PlayerXP(PlayerXP), PlayerEquippedWeapon(PlayerEquippedWeapon), PlayerEquippedArmor(PlayerEquippedArmor), PlayerCurrency(PlayerCurrency), PlayerKarma(PlayerKarma), CurrentDifficulty(CurrentDifficulty)
{
}

Player::~Player()
{
}

void Player::InitPlayer()
{
    int ChosenClass;
    std::cout << "What Class are You? (Warrior by default)" << std::endl;
    std::cout << "(1) Warrior" << std::endl;
    std::cout << "(2) Mage" << std::endl;
    std::cout << "(3) Hunter" << std::endl;
    std::cin >> ChosenClass;
    switch (ChosenClass) {
    case 1:
        SetPlayerClass("Warrior");
        SetPlayerMaxHP(100);
        SetPlayerHP(100);
        SetPlayerPower(4);
        break;
    case 2:
        SetPlayerClass("Mage");
        SetPlayerMaxHP(70);
        SetPlayerHP(70);
        SetPlayerPower(7);
        break;
    case 3:
        SetPlayerClass("Hunter");
        SetPlayerMaxHP(40);
        SetPlayerHP(40);
        SetPlayerPower(10);
        break;
    default:
        SetPlayerClass("Warrior");
        SetPlayerMaxHP(100);
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
    SetPlayerKarma(50);
    SetCurrentDifficulty(1);
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
        LevelUp();

        std::cout << "Level up! You are now level " << GetPlayerLvl() << "!" << std::endl;

        baseXP += 18;
    }
}

void Player::LevelUp()
{
    int replaceindex;
    if (GetPlayerClass() == "Warrior") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 15);
        SetPlayerHP(GetPlayerHP() + 15);
        SetPlayerPower(GetPlayerPower() + 3);
        if (GetPlayerLvl() == 2) {
            moveset.SetMove(Moveset::Move("Double Slash",3,2,"Physical"));
        }
        if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                moveset.SetMove(Moveset::Move("Holy Thrust", 5, 1, "Physical"));
            }
            else if (GetPlayerKarma() == 50) {
                moveset.SetMove(Moveset::Move("Swiss Strike", 4, 3, "Physical"));
            }
            else if (GetPlayerKarma() < 50) {
                moveset.SetMove(Moveset::Move("Dark Blades", 2, 3, "Magical"));
            }
        }
        if (GetPlayerLvl() == 5) {
            std::cout << "You are trying to learn Triple Slash, 4 Strength, 3 Hits, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Triple Slash", 4, 3, "Physical"), replaceindex);
            }
        }
        if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Hallowed Ground, 20 Healing, 1 Hit, Heal." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Hallowed Ground", -20, 1, "Heal"), replaceindex);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Full Gray Moon, 4 Strength, 6 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Full Gray Moon", 4, 6, "Physical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Blood Sacrifice, 5 Strength, 5 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Blood Sacrifice", 5, 5, "Dark"), replaceindex);
                }
            }
        }
        if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Quadruple Slash, 5 Strength, 4 Hits, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Quadruple Slash", 5, 4, "Physical"), replaceindex);
            }
        }
        if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn God's Will, 15 Strength, 2 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("God's Will", 15, 2, "Magical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Like Stone, Forever Unchanging, 20 Strength, 2 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Like Stone, Forever Unchanging", 20, 2, "Physical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Acheron, 5 Strength, 10 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Acheron", 5, 10, "Dark"), replaceindex);
                }
            }
        }
    }
    else if (GetPlayerClass() == "Mage") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 11);
        SetPlayerHP(GetPlayerHP() + 11);
        SetPlayerPower(GetPlayerPower() + 4);
        if (GetPlayerLvl() == 2) {
            moveset.SetMove(Moveset::Move("Fireball", 6, 1, "Magical"));
        }
        if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                moveset.SetMove(Moveset::Move("Light Ray", 1, 8, "Magical"));
            }
            else if (GetPlayerKarma() == 50) {
                moveset.SetMove(Moveset::Move("Tri-Elemental", 4, 4, "Magical"));
            }
            else if (GetPlayerKarma() < 50) {
                moveset.SetMove(Moveset::Move("Hellfire", 2, 5, "Magical"));
            }
        }
        if (GetPlayerLvl() == 5) {
            std::cout << "You are trying to learn Aura Farm, 15 Healing, 1 Hit, Heal." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Aura Farm", -15, 1, "Heal"), replaceindex);
            }
        }
        if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Dignified End, 15 Strength, 1 Hit, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Dignified End", 15, 1, "Physical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Axisal, 10 Strength, 2 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Axisal", 10, 2, "Magical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Red Red Room, 3 Strength, 7 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Red Red Room", 3, 7, "Dark"), replaceindex);
                }
            }
        }
        if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Rolling Waves, 4 Strength, 5 Hits, Magical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Rolling Waves", 4, 5, "Magical"), replaceindex);
            }
        }
        if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Purging Light, 30 Strength, 1 Hit, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Purging Light", 30, 1, "Magical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Gold-Silver Horizon, 6 Strength, 6 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Gold-Silver Horizon", 6, 6, "Magical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Paimonial Wrath, 1 Strength, 30 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Paimonial Wrath", 1, 30, "Dark"), replaceindex);
                }
            }
        }
    }
    else if (GetPlayerClass() == "Hunter") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 8);
        SetPlayerHP(GetPlayerHP() + 8);
        SetPlayerPower(GetPlayerPower() + 5);
        if (GetPlayerLvl() == 2) {
            moveset.SetMove(Moveset::Move("Triple Shot", 2, 3, "Physical"));
        }
        if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                moveset.SetMove(Moveset::Move("True Strike", 15, 1, "Magical"));
            }
            else if (GetPlayerKarma() == 50) {
                moveset.SetMove(Moveset::Move("Thread Thin", 4, 5, "Physical"));
            }
            else if (GetPlayerKarma() < 50) {
                moveset.SetMove(Moveset::Move("Underhanded Tactics", 3, 8, "Physical"));
            }
        }
        if (GetPlayerLvl() == 5) {
            std::cout << "You are trying to learn Shadow Strike, 16 Strength, 1 Hit, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Shadow Strike", 16, 1, "Physical"), replaceindex);
            }
        }
        if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Windrider, 3 Strength, 6 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Windrider", 3, 6, "Magical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Pendulum, 14 Strength, 2 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Pendulum", 14, 2, "Magical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Ehe, 1 Strength, 13 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Ehe", 1, 13, "Dark"), replaceindex);
                }
            }
        }
        if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Checkmate, 20 Strength, 1 Hit, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Checkmate", 20, 1, "Physical"), replaceindex);
            }
        }
        if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Magarula, 40 Strength, 1 Hit, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Magarula", 40, 1, "Magical"), replaceindex);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Infinity, 1 Strength, 50 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Infinity", 1, 50, "Dark"), replaceindex);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Styx's Call, 5 Strength, 10 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Styx's Call", 5, 10, "Magical"), replaceindex);
                }
            }
        }
    }
}

void Player::ListMovesToReplace()
{
    std::cout << "Replace which move?" << std::endl;
    std::cout << "Current Moves" << std::endl;
    std::cout << "(1) " << GetMoveset().GetMove(0).MoveName << std::endl;
    std::cout << "(2) " << GetMoveset().GetMove(1).MoveName << std::endl;
    std::cout << "(3) " << GetMoveset().GetMove(2).MoveName << std::endl;
    std::cout << "(4) " << GetMoveset().GetMove(3).MoveName << std::endl;
    std::cout << "(5) Don't learn this move" << std::endl;
}
