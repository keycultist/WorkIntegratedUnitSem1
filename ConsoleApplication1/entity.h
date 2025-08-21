#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Entity {
private:
    std::string Class;
    int HP;
    int MaxHP;
    int Power;
    int magicPower;
    int Currency;
    int Karma;               // New karma variable (range 0-100)
    float karmaMultiplier;  // New karma multiplier
public:
    void SetClass(std::string Class);
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
    int GetCurrency(void) const;

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
};

#endif