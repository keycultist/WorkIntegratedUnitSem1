#ifndef ENTITY_H
#define ENTITY_H

#include "Position.h"
#include <string>
#include <iostream>


class Entity {
private:
    std::string Class;
    int MaxHP;
    int HP;
    int Power;
    int CritChance;
    //int PosX, PosY;
    int Lvl;
    int XP;

    std::string EquippedWeapon;
    std::string EquippedArmor;
    int Currency;
    int Karma;
    int CurrentDifficulty;

    Position entityPosObj;

    //Moveset moveset;
public:
    void SetClass(std::string Class);
    void SetMaxHP(int MaxHP);
    void SetHP(int HP);
    void SetPower(int Power);
    void SetCritChance(int CritChance);
    void SetCurrency(int Currency);
    void SetPos(int PosX, int PosY);
    void SetLvl(int Lvl);
    void SetXP(int XP);

    std::string GetClass(void) const;
    int GetMaxHP(void) const;
    int GetHP(void) const;
    int GetPower(void) const;
    int GetCritChance(void) const;
    int GetCurrency(void) const;
    int GetPosX(void) const;
    int GetPosY(void) const;
    int GetLvl(void) const;
    int GetXP(void) const;

    Entity();
    Entity(std::string Cl, int MH, int H, int P, int CC, int C, int PX, int PY, int L, int XP);
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