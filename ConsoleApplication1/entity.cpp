#include "entity.h"

Entity::Entity(std::string n, int h, int a, int ma, int g)
    : name(n), hp(h), maxHp(h), atk(a), magicAtk(ma), gold(g) {
}

void Entity::applyBuff(const std::string& stat, int value) {
    if (stat == "HP") {
        hp += value;
        if (hp > maxHp) hp = maxHp;
        if (hp < 0) hp = 0;
        std::cout << name << "'s HP changed by " << value << ". Current HP: " << hp << "/" << maxHp << std::endl;
    }
    else if (stat == "ATK") {
        atk += value;
        if (atk < 0) atk = 0;
        std::cout << name << "'s ATK changed by " << value << ". Current ATK: " << atk << std::endl;
    }
    else if (stat == "MAGIC") {
        magicAtk += value;
        if (magicAtk < 0) magicAtk = 0;
        std::cout << name << "'s MAGIC ATK changed by " << value << ". Current MAGIC ATK: " << magicAtk << std::endl;
    }
    else if (stat == "GOLD") {
        gold += value;
        if (gold < 0) gold = 0;
        std::cout << name << "'s GOLD changed by " << value << ". Current GOLD: " << gold << std::endl;
    }
}

bool Entity::isAlive() const {
    return hp > 0;
}

void Entity::attack(Entity& target) {
    int damage = atk;
    std::cout << name << " attacks " << target.name << " for " << damage << " damage!" << std::endl;
    target.hp -= damage;
    if (target.hp < 0) target.hp = 0;
}

void Entity::magicAttack(Entity& target) {
    int damage = magicAtk;
    std::cout << name << " casts a spell on " << target.name << " for " << damage << " magic damage!" << std::endl;
    target.hp -= damage;
    if (target.hp < 0) target.hp = 0;
}