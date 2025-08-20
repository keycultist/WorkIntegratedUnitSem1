#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>

class Entity {
public:
    std::string name;
    int hp;
    int maxHp;
    int atk;
    int magicAtk;
    int gold;
    int karma;
    float karmaMultiplier;

    Entity(std::string n, int h, int a, int ma, int g);
    void applyBuff(const std::string& stat, int value);
    void applyKarmaEffect(int value, float multiplierChange);
    void heal(int amount); 
    void increaseMaxHP(int amount);
    bool isAlive() const;
    void attack(Entity& target);
    void magicAttack(Entity& target);
};

#endif