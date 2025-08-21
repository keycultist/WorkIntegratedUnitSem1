#ifndef ENTITY_H
#define ENTITY_H

#include "Player.h"
#include <string>
#include <iostream>


class Entity {
private:
    std::string PlayerClass;
    int PlayerMaxHP;
    int PlayerHP;
    int PlayerPower;
    int PlayerCritChance;
    int PlayerPosX, PlayerPosY;
    int PlayerLvl;
    int PlayerXP;
    std::string PlayerEquippedWeapon;
    std::string PlayerEquippedArmor;
    int PlayerCurrency;
    int PlayerKarma;
    int CurrentDifficulty;

    Moveset moveset;
public:
   /* void SetClass(std::string Class);
    void SetMaxHP(int MaxHP);
    void SetHP(int HP);
    void SetPower(int Power);
    void SetmagicPower(int magicPower);
    void SetCurrency(int Currency);

    std::string GetClass(void) const;
    int GetMaxHP(void) const;
    int GetHP(void) const;
    int GetPower(void) const;
    int GetmagicPower(void) const;
    int GetCurrency(void) const;*/

    Entity();
    Entity(std::string Cl, int MH, int H, int P, int mP, int C);
    ~Entity();

    void applyBuff(const std::string& stat, int value); 
    void applyKarmaEffect(int value, float multiplierChange);
    void heal(int amount);
    void increaseMaxHP(int amount);
    bool isAlive() const;
    void attack(Entity& target);
    void magicAttack(Entity& target);
    void modifyCritChance(float amount);
};

#endif