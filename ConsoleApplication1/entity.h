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
    int karma;               // New karma variable (range 0-100)
    float karmaMultiplier;   // New karma multiplier

    Entity(std::string n, int h, int a, int ma, int g);
    void applyBuff(const std::string& stat, int value);
    void applyKarmaEffect(int value, float multiplierChange); // New method for karma
    bool isAlive() const;
    void attack(Entity& target);
    void magicAttack(Entity& target);
};

#endif // ENTITY_H