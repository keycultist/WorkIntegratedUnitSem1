#include "Player.h"
#include "Moveset.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <stdlib.h>
#include <time.h> 

void Player::SetPlayerClass(std::string Class) {
    SetPlayerClass(Class);
}

void Player::SetPlayerMaxHP(int MaxHP)
{
    SetPlayerMaxHP(MaxHP);
}

void Player::SetPlayerHP(int HP) {
    SetPlayerHP(HP);
}

void Player::SetPlayerPower(int Power) {
    SetPlayerPower(Power);
    SetPlayermagicPower(Power);
}

void Player::SetPlayermagicPower(int Power)
{
    SetPlayermagicPower(Power);
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
    SetPlayerCurrency(Currency);
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
    return GetPlayerClass();
}

int Player::GetPlayerMaxHP(void) const
{
    return GetPlayerMaxHP();
}

int Player::GetPlayerHP(void) const {
    return GetPlayerHP();
}

int Player::GetPlayerPower(void) const {
    return GetPlayerPower();
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
    return GetPlayerCurrency();
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

Player::Player() : Entity("Warrior", 100, 100, 5, 0, 0), PlayerClass("Warrior"), PlayerMaxHP(100), PlayerHP(100), PlayerPower(5), PlayerCritChance(5), PlayerPosX(0), PlayerPosY(0), PlayerLvl(1), PlayerXP(0), PlayerEquippedWeapon("None"), PlayerEquippedArmor("None"), PlayerCurrency(0), PlayerKarma(50), CurrentDifficulty(1)
{
}

Player::Player(std::string PlayerClass, int PlayerMaxHP, int PlayerHP, int PlayerPower, int PlayerCritChance, int PlayerPosX, int PlayerPosY, int PlayerLvl, int PlayerXP, std::string PlayerEquippedWeapon, std::string PlayerEquippedArmor, int PlayerCurrency, int PlayerKarma, int CurrentDifficulty)
    : Entity(PlayerClass, PlayerMaxHP, PlayerHP, PlayerPower, PlayerPower, PlayerCurrency), PlayerCritChance(PlayerCritChance), PlayerPosX(PlayerPosX), PlayerPosY(PlayerPosY), PlayerLvl(PlayerLvl), PlayerXP(PlayerXP), PlayerEquippedWeapon(PlayerEquippedWeapon), PlayerEquippedArmor(PlayerEquippedArmor), PlayerKarma(PlayerKarma), CurrentDifficulty(CurrentDifficulty)
{
}

Player::~Player()
{
}

void Player::InitPlayer()
{
    int ChosenClass;
    bool ConfirmClass = false;
    while (!ConfirmClass) {
        ConfirmClass = false;
        std::cout << "What Class are You? (Warrior by default)" << std::endl;
        std::cout << "(1) Warrior" << std::endl;
        std::cout << "(2) Mage" << std::endl;
        std::cout << "(3) Hunter" << std::endl;
        std::cout << "(4) Assassin" << std::endl;
        std::cout << "(5) Summoner" << std::endl;
        std::cout << "(6) Ritualist" << std::endl;
        std::cout << "(7) Berserker" << std::endl;
        std::cin >> ChosenClass;
        switch (ChosenClass) {
        case 1:
            SetPlayerClass("Warrior");
            SetPlayerMaxHP(100);
            SetPlayerHP(100);
            SetPlayerPower(4);
            SetPlayerCritChance(5);
            break;
        case 2:
            SetPlayerClass("Mage");
            SetPlayerMaxHP(70);
            SetPlayerHP(70);
            SetPlayerPower(7);
            SetPlayerCritChance(5);
            break;
        case 3:
            SetPlayerClass("Hunter");
            SetPlayerMaxHP(40);
            SetPlayerHP(40);
            SetPlayerPower(10);
            SetPlayerCritChance(5);
            break;
        case 4:
            SetPlayerClass("Assassin");
            SetPlayerMaxHP(50);
            SetPlayerHP(50);
            SetPlayerPower(5);
            SetPlayerCritChance(10);
            break;
        case 5:
            SetPlayerClass("Summoner");
            SetPlayerMaxHP(70);
            SetPlayerHP(70);
            SetPlayerPower(0);
            SetPlayerCritChance(5);
            break;
        case 6:
            SetPlayerClass("Ritualist");
            SetPlayerMaxHP(250);
            SetPlayerHP(250);
            SetPlayerPower(10);
            SetPlayerCritChance(5);
            break;
        case 7:
            SetPlayerClass("Berserker");
            SetPlayerMaxHP(120);
            SetPlayerHP(120);
            SetPlayerPower(10);
            SetPlayerCritChance(15);
            break;
        case 11037:
            SetPlayerClass("Conduit");
            SetPlayerMaxHP(200);
            SetPlayerHP(200);
            SetPlayerPower(10);
            SetPlayerCritChance(50);
            break;
        default:
            SetPlayerClass("Warrior");
            SetPlayerMaxHP(100);
            SetPlayerHP(100);
            SetPlayerPower(4);
            SetPlayerCritChance(5);
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
        ShowPlayerStats();
        ShowPlayerMoves();
        std::cout << std::endl;
        std::cout << "Are you sure? Y/N" << std::endl;
        int chP = _getch();
        if (chP == 'y') {
            ConfirmClass = true;
        }
        else {
            ConfirmClass = false;
        }
        system("cls");
    }
}

void Player::ShowPlayerStats() const
{
    std::cout << std::endl;
    std::cout << "Current Stats:" << std::endl;
    std::cout << "Class: " << GetPlayerClass() << std::endl;
    std::cout << "HP: " << GetPlayerHP() << "/" << GetPlayerMaxHP() << std::endl;
    std::cout << "Power: " << GetPlayerPower() << std::endl;
    std::cout << "Crit Chance: " << GetPlayerCritChance() << "%" << std::endl;
    std::cout << "Level: " << GetPlayerLvl() << std::endl;
    if (GetPlayerClass() == "Berserker") {
        std::cout << "EXP: " << "Berserker cannot gain EXP, EXP gain is converted to Power" << std::endl;
    }
    else {
        std::cout << "EXP: " << GetPlayerXP() << std::endl;
    }
    std::cout << "Currency: " << GetPlayerCurrency() << std::endl;
    std::cout << "Karma: " << GetPlayerKarma() << std::endl;
}

void Player::ShowPlayerMoves() const
{
    std::cout << std::endl;
    std::cout << "Current Moves:" << std::endl;
    std::cout << "Note: Dark moves cost 15% of your Max HP, Heal moves heal by the amount of Strength shown." << std::endl;
    if (GetPlayerClass() == "Ritualist") {
        std::cout << "Note: Ritual Type moves cost MaxHP to use. (Amt indicated by strength)" << std::endl;
    }
    std::cout << "(1) [" << moveset.GetMove(0).MoveName << "] Strength: " << moveset.GetMove(0).MoveStrength << " Hit(s): " << moveset.GetMove(0).Hits << " Type: " << moveset.GetMove(0).MoveType << std::endl;
    std::cout << "(2) [" << moveset.GetMove(1).MoveName << "] Strength: " << moveset.GetMove(1).MoveStrength << " Hit(s): " << moveset.GetMove(1).Hits << " Type: " << moveset.GetMove(1).MoveType << std::endl;
    std::cout << "(3) [" << moveset.GetMove(2).MoveName << "] Strength: " << moveset.GetMove(2).MoveStrength << " Hit(s): " << moveset.GetMove(2).Hits << " Type: " << moveset.GetMove(2).MoveType << std::endl;
    std::cout << "(4) [" << moveset.GetMove(3).MoveName << "] Strength: " << moveset.GetMove(3).MoveStrength << " Hit(s): " << moveset.GetMove(3).Hits << " Type: " << moveset.GetMove(3).MoveType << std::endl;
}

void Player::LevelUpCheck()
{
    int baseXP = 10;

    if (GetPlayerLvl() < 10 && GetPlayerClass() != "Conduit") {
        while (GetPlayerXP() >= baseXP && GetPlayerLvl() < 11)
        {
            SetPlayerXP(GetPlayerXP() - baseXP);
            SetPlayerLvl(GetPlayerLvl() + 1);
            LevelUp();

            std::cout << std::endl;
            std::cout << "Level up! You are now level " << GetPlayerLvl() << "!" << std::endl;

            baseXP += 18;
        }
    }
    else if (GetPlayerLvl() < 11 && GetPlayerClass() == "Conduit") {
        while (GetPlayerXP() >= baseXP && GetPlayerLvl() < 11)
        {
            SetPlayerXP(GetPlayerXP() - baseXP);
            SetPlayerLvl(GetPlayerLvl() + 1);

            std::cout << std::endl;
            std::cout << "Level up! You are now level " << GetPlayerLvl() << "!" << std::endl;
            LevelUp();

            if (GetPlayerLvl() < 10) {
                baseXP += 18;
            }
            else {
                baseXP += 100;
            }
        }
    }
}

void Player::LevelUp()
{
    int replaceindex;
    //Phys-biased
    if (GetPlayerClass() == "Warrior") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 15);
        SetPlayerHP(GetPlayerHP() + 15);
        SetPlayerPower(GetPlayerPower() + 3);
        if (GetPlayerLvl() == 2) {
            std::cout << "You learnt Double Slash, 3 Strength, 2 Hit, Physical." << std::endl;
            moveset.SetMove(Moveset::Move("Double Slash", 3, 2, "Physical"));
        }
        else if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You learnt Holy Thrust, 5 Strength, 1 Hit, Physical." << std::endl;
                moveset.SetMove(Moveset::Move("Holy Thrust", 5, 1, "Physical"));
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You learnt Swiss Strike, 4 Strength, 3 Hit, Physical." << std::endl;
                moveset.SetMove(Moveset::Move("Swiss Strike", 4, 3, "Physical"));
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You learnt Dark Blades, 2 Strength, 3 Hit, Magical." << std::endl;
                moveset.SetMove(Moveset::Move("Dark Blades", 2, 3, "Magical"));
            }
        }
        else if (GetPlayerLvl() == 5) {
            std::cout << "You are trying to learn Triple Slash, 4 Strength, 3 Hits, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Triple Slash", 4, 3, "Physical"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Hallowed Ground, 20 Healing, 1 Hit, Heal." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Hallowed Ground", 20, 1, "Heal"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Full Gray Moon, 4 Strength, 6 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Full Gray Moon", 4, 6, "Physical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Blood Sacrifice, 5 Strength, 5 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Blood Sacrifice", 5, 5, "Dark"), replaceindex - 1);
                }
            }
        }
        else if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Quadruple Slash, 5 Strength, 4 Hits, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Quadruple Slash", 5, 4, "Physical"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn God's Will, 15 Strength, 2 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("God's Will", 15, 2, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Like Stone, Forever Unchanging, 20 Strength, 2 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Like Stone, Forever Unchanging", 20, 2, "Physical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Acheron, 5 Strength, 10 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Acheron", 5, 10, "Dark"), replaceindex - 1);
                }
            }
        }
        else {
            int chP = _getch();
        }
        system("cls");
    }
    //Mag-biased
    else if (GetPlayerClass() == "Mage") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 11);
        SetPlayerHP(GetPlayerHP() + 11);
        SetPlayerPower(GetPlayerPower() + 4);
        if (GetPlayerLvl() == 2) {
            std::cout << "You learnt Fireball, 6 Strength, 1 Hit, Magical." << std::endl;
            moveset.SetMove(Moveset::Move("Fireball", 6, 1, "Magical"));
        }
        else if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You learnt Light Ray, 1 Strength, 8 Hit, Magical." << std::endl;
                moveset.SetMove(Moveset::Move("Light Ray", 1, 8, "Magical"));
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You learnt Tri-Elemental, 4 Strength, 4 Hit, Magical." << std::endl;
                moveset.SetMove(Moveset::Move("Tri-Elemental", 4, 4, "Magical"));
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You learnt Hellfire, 2 Strength, 5 Hit, Magical." << std::endl;
                moveset.SetMove(Moveset::Move("Hellfire", 2, 5, "Magical"));
            }
        }
        else if (GetPlayerLvl() == 5) {
            std::cout << "You are trying to learn Aura Farm, 15 Healing, 1 Hit, Heal." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Aura Farm", 15, 1, "Heal"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Dignified End, 15 Strength, 1 Hit, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Dignified End", 15, 1, "Physical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Axisal, 10 Strength, 2 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Axisal", 10, 2, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Red Red Room, 3 Strength, 7 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Red Red Room", 3, 7, "Dark"), replaceindex - 1);
                }
            }
        }
        else if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Rolling Waves, 4 Strength, 5 Hits, Magical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Rolling Waves", 4, 5, "Magical"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Purging Light, 30 Strength, 1 Hit, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Purging Light", 30, 1, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Gold-Silver Horizon, 6 Strength, 6 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Gold-Silver Horizon", 6, 6, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Paimonial Wrath, 1 Strength, 30 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Paimonial Wrath", 1, 30, "Dark"), replaceindex - 1);
                }
            }
        }
        else {
            int chP = _getch();
        }
        system("cls");
    }
    //Glass cannon-ish
    else if (GetPlayerClass() == "Hunter") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 8);
        SetPlayerHP(GetPlayerHP() + 8);
        SetPlayerPower(GetPlayerPower() + 5);
        if (GetPlayerLvl() == 2) {
            std::cout << "You learnt Triple Shot, 2 Strength, 3 Hit, Physical." << std::endl;
            moveset.SetMove(Moveset::Move("Triple Shot", 2, 3, "Physical"));
        }
        else if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You learnt True Strike, 15 Strength, 1 Hit, Magical." << std::endl;
                moveset.SetMove(Moveset::Move("True Strike", 15, 1, "Magical"));
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You learnt Thread Thin, 4 Strength, 5 Hit, Physical." << std::endl;
                moveset.SetMove(Moveset::Move("Thread Thin", 4, 5, "Physical"));
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You learnt Underhanded Tactics, 3 Strength, 8 Hit, Physical." << std::endl;
                moveset.SetMove(Moveset::Move("Underhanded Tactics", 3, 8, "Physical"));
            }
        }
        else if (GetPlayerLvl() == 5) {
            std::cout << "You are trying to learn Shadow Strike, 16 Strength, 1 Hit, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Shadow Strike", 16, 1, "Physical"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Windrider, 3 Strength, 6 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Windrider", 3, 6, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Pendulum, 14 Strength, 2 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Pendulum", 14, 2, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Ehe, 1 Strength, 13 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Ehe", 1, 13, "Dark"), replaceindex - 1);
                }
            }
        }
        else if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Checkmate, 20 Strength, 1 Hit, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Checkmate", 20, 1, "Physical"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Magarula, 40 Strength, 1 Hit, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Magarula", 40, 1, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Infinity, 1 Strength, 50 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Infinity", 1, 50, "Dark"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Styx's Call, 5 Strength, 10 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Styx's Call", 5, 10, "Magical"), replaceindex - 1);
                }
            }
        }
        else {
            int chP = _getch();
        }
        system("cls");
    }
    //Crit Bias
    else if (GetPlayerClass() == "Assassin") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 9);
        SetPlayerHP(GetPlayerHP() + 9);
        SetPlayerPower(GetPlayerPower() + 4);
        SetPlayerCritChance(GetPlayerCritChance() + 3);
        if (GetPlayerLvl() == 2) {
            std::cout << "You learnt Firestrike, 5 Strength, 1 Hit, Magical." << std::endl;
            moveset.SetMove(Moveset::Move("Firestrike", 5, 1, "Magical"));
        }
        else if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You learnt Divine Sacrifice, 16 Strength, 1 Hit, Dark." << std::endl;
                moveset.SetMove(Moveset::Move("Divine Sacrifice", 16, 1, "Dark"));
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You learnt Multi-Faced, 4 Strength, 5 Hit, Physical." << std::endl;
                moveset.SetMove(Moveset::Move("Multi-Faced", 4, 5, "Physical"));
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You learnt Under Me, 0 Strength, 1 Hit, Control." << std::endl;
                moveset.SetMove(Moveset::Move("Under Me", 0, 1, "Control"));
            }
        }
        else if (GetPlayerLvl() == 5) {
            std::cout << "You are trying to learn Quick Refractory, 13 Strength, 1 Hit, Heal." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Quick Refractory", 13, 1, "Heal"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Blinding Daggers, 3 Strength, 5 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Blinding Daggers", 3, 5, "Physical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Puppeteer, 0 Strength, 2 Hits, Control." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Puppeteer", 0, 2, "Control"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Blood for the Blood God, 9 Strength, 2 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Blood for the Blood God", 9, 2, "Dark"), replaceindex - 1);
                }
            }
        }
        else if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Phantom Party, 6 Strength, 4 Hit, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Phantom Party", 6, 4, "Physical"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Inspiring Control, 0 Strength, 3 Hit, Control." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Inspiring Control", 0, 3, "Control"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn In the Dark, for the Light, 15 Strength, 4 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("In the Dark, for the Light", 15, 4, "Dark"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Death by a Thousand Cuts, 2 Strength, 15 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Death by a Thousand Cuts", 2, 15, "Physical"), replaceindex - 1);
                }
            }
        }
        else {
            int chP = _getch();
        }
        system("cls");
    }
    //y=mx+c Graph
    else if (GetPlayerClass() == "Summoner") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 10);
        SetPlayerHP(GetPlayerHP() + 10);
        if (GetPlayerLvl() == 2) {
            std::cout << "You learnt Summon: Rat, 2 Strength, 1 Hit, Summon." << std::endl;
            moveset.SetMove(Moveset::Move("Summon: Rat", 2, 1, "Summon"));
        }
        else if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You learnt Summon: Deer, 4 Strength, 1 Hit, Summon." << std::endl;
                moveset.SetMove(Moveset::Move("Summon: Deer", 4, 1, "Summon"));
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You learnt Summon: Owl, 5 Strength, 1 Hit, Summon." << std::endl;
                moveset.SetMove(Moveset::Move("Summon: Owl", 5, 1, "Summon"));
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You learnt Summon: Crows, 2 Strength, 2 Hit, Summon." << std::endl;
                moveset.SetMove(Moveset::Move("Summon: Crows", 2, 2, "Summon"));
            }
        }
        else if (GetPlayerLvl() == 5) {
            std::cout << "You learnt Forestry Knowledge, 10 Strength, 1 Hit, Heal." << std::endl;
            moveset.SetMove(Moveset::Move("Forestry Knowledge", 10, 1, "Heal"));
        }
        else if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Protect Command, 0 Strength, 3 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Protect Command", 0, 3, "Physical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Loyal Command, 2 Strength, 2 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Loyal Command", 2, 2, "Physical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Attack Command, 5 Strength, 4 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Attack Command", 5, 4, "Dark"), replaceindex - 1);
                }
            }
        }
        else if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Summon: Bear, 10 Strength, 1 Hit, Summon." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Summon: Bear", 10, 1, "Summon"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Summon: Pheonix, 30 Strength, 1 Hit, Heal." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Summon: Pheonix", 30, 1, "Heal"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Summon: Dragon, 20 Strength, 1 Hits, Summon." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Summon: Dragon", 20, 1, "Summon"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Summon: Demon, 40 Strength, 1 Hits, Dark." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Summon: Demon", 40, 1, "Dark"), replaceindex - 1);
                }
            }
        }
        else {
            int chP = _getch();
        }
        system("cls");
    }
    //Self-Harmer
    else if (GetPlayerClass() == "Ritualist") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 25);
        SetPlayerHP(GetPlayerHP() + 25);
        if (GetPlayerLvl() == 2) {
            std::cout << "You learnt Blood Moon Rites, 20 Strength, 2 Hit, Ritual." << std::endl;
            moveset.SetMove(Moveset::Move("Blood Moon Rites", 20, 2, "Ritual"));
        }
        else if (GetPlayerLvl() == 4) {
            std::cout << "You learnt Meta-Aura, 0 Strength, 1 Hit, Control." << std::endl;
            moveset.SetMove(Moveset::Move("Meta-Aura", 0, 1, "Control"));
        }
        else if (GetPlayerLvl() == 7) {
            std::cout << "You learnt Ancient Awakening, 20 Strength, 2 Hit, Ritual." << std::endl;
            moveset.SetMove(Moveset::Move("Ancient Awakening", 20, 2, "Ritual"));
        }
        else if (GetPlayerLvl() == 10) {
            std::cout << "You are trying to learn Ritual of The Last Morning, 40 Strength, 3 Hits, Ritual." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Ritual of The Last Morning", 40, 3, "Ritual"), replaceindex - 1);
            }
        }
        else {
            int chP = _getch();
        }
        system("cls");
    }

    //Simplay OP
    else if (GetPlayerClass() == "Conduit") {
        SetPlayerMaxHP(GetPlayerMaxHP() + 20);
        SetPlayerHP(GetPlayerHP() + 20);
        SetPlayerPower(GetPlayerPower() + 10);
        SetPlayerCritChance(GetPlayerCritChance() + 2);
        if (GetPlayerLvl() == 2) {
            std::cout << "You learnt Psychokinesis, 20 Strength, 1 Hit, Magical." << std::endl;
            moveset.SetMove(Moveset::Move("Psychokinesis", 20, 1, "Magical"));
        }
        else if (GetPlayerLvl() == 4) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You learnt All-Out Attack, 10 Strength, 4 Hit, Physical." << std::endl;
                moveset.SetMove(Moveset::Move("All-Out Attack", 10, 4, "Physical"));
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You learnt Ragnarok, 15 Strength, 4 Hit, Magical." << std::endl;
                moveset.SetMove(Moveset::Move("Ragnarok", 15, 4, "Magical"));
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You learnt God's Hand, 50 Strength, 1 Hit, Dark." << std::endl;
                moveset.SetMove(Moveset::Move("God's Hand", 50, 1, "Dark"));
            }
        }
        else if (GetPlayerLvl() == 5) {
            std::cout << "You are trying to learn Sode no Shirayuki, 12 Strength, 4 Hit, Magical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Sode no Shirayuki", 12, 4, "Magical"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 7) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Rasengan, 50 Strength, 1 Hits, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Rasengan", 50, 1, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Serious Punch, 75 Strength, 1 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Serious Punch", 75, 1, "Physical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Masamune, 17 Strength, 3 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Masamune", 17, 3, "Physical"), replaceindex - 1);
                }
            }
        }
        else if (GetPlayerLvl() == 8) {
            std::cout << "You are trying to learn Summon: Panzer, 20 Strength, 1 Hit, Summon." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Summon: Panzer", 20, 1, "Summon"), replaceindex - 1);
            }
        }
        else if (GetPlayerLvl() == 10) {
            if (GetPlayerKarma() > 50) {
                std::cout << "You are trying to learn Kamehameha, 300 Strength, 1 Hit, Magical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Kamehameha", 300, 1, "Magical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() == 50) {
                std::cout << "You are trying to learn Unlimited Blade Works, 3 Strength, 150 Hits, Physical." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Unlimited Blade Works", 3, 150, "Physical"), replaceindex - 1);
                }
            }
            else if (GetPlayerKarma() < 50) {
                std::cout << "You are trying to learn Spirit Whisper, 0 Strength, 7 Hits, Control." << std::endl;
                ListMovesToReplace();
                std::cin >> replaceindex;
                if (replaceindex != 5) {
                    moveset.ReplaceMove(Moveset::Move("Spirit Whisper", 0, 7, "Control"), replaceindex - 1);
                }
            }
        }
        else if (GetPlayerLvl() == 11) {
            std::cout << "You are trying to learn Atomic Oblivion – The Unstoppable Apex, I stand alone. I devour worlds. None shall rival my might, 1 Strength, 1000 Hit, Physical." << std::endl;
            ListMovesToReplace();
            std::cin >> replaceindex;
            if (replaceindex != 5) {
                moveset.ReplaceMove(Moveset::Move("Atomic Oblivion – The Unstoppable Apex, I stand alone. I devour worlds. None shall rival my might", 1, 1000, "Physical"), replaceindex - 1);
            }
        }
        else {
            int chP = _getch();
        }
        system("cls");
    }
}

void Player::ListMovesToReplace()
{
    std::cout << "Replace which move?" << std::endl;
    std::cout << "Current Moves" << std::endl;
    std::cout << "(1) [" << GetMoveset().GetMove(0).MoveName << "] Strength: " << GetMoveset().GetMove(0).MoveStrength << " Hit(s): " << GetMoveset().GetMove(0).Hits << " Type: " << GetMoveset().GetMove(0).MoveType << std::endl;
    std::cout << "(2) [" << GetMoveset().GetMove(1).MoveName << "] Strength: " << GetMoveset().GetMove(1).MoveStrength << " Hit(s): " << GetMoveset().GetMove(1).Hits << " Type: " << GetMoveset().GetMove(1).MoveType << std::endl;
    std::cout << "(3) [" << GetMoveset().GetMove(2).MoveName << "] Strength: " << GetMoveset().GetMove(2).MoveStrength << " Hit(s): " << GetMoveset().GetMove(2).Hits << " Type: " << GetMoveset().GetMove(2).MoveType << std::endl;
    std::cout << "(4) [" << GetMoveset().GetMove(3).MoveName << "] Strength: " << GetMoveset().GetMove(3).MoveStrength << " Hit(s): " << GetMoveset().GetMove(3).Hits << " Type: " << GetMoveset().GetMove(3).MoveType << std::endl;
    std::cout << "(5) Don't learn this move" << std::endl;
    std::cout << std::endl;
}