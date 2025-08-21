#include "entity.h"
#include "Player.h"
#include <iostream>

//Entity::Entity()
//{
//}
//
//Entity::Entity(std::string Cl, int MH, int H, int P, int mP, int C)
//    : Class(Cl), MaxHP(MH), HP(H), Power(P), magicPower(mP), Currency(C)
//{
//}
//
//Entity::~Entity()
//{
//}
//
//void Entity::SetClass(std::string Class)
//{
//    this->Class = Class;
//}
//
//void Entity::SetMaxHP(int MaxHP)
//{
//    this->MaxHP = MaxHP;
//}
//
//void Entity::SetHP(int HP)
//{
//    this->HP = HP;
//}
//
//void Entity::SetPower(int Power)
//{
//    this->Power = Power;
//}
//
//void Entity::SetmagicPower(int magicPower)
//{
//    this->magicPower = magicPower;
//}
//
//void Entity::SetCurrency(int Currency)
//{
//    this->Currency = Currency;
//}
//
//std::string Entity::GetClass(void) const
//{
//    return Class;
//}
// 
//int Entity::GetMaxHP(void) const
//{
//    return MaxHP;
//}
//
//int Entity::GetHP(void) const
//{
//    return HP;
//}
//
//int Entity::GetPower(void) const
//{
//    return Power;
//}
//
//int Entity::GetmagicPower(void) const
//{
//    return magicPower;
//}
//
//int Entity::GetCurrency(void) const
//{
//    return Currency;
//}

void Entity::applyBuff(const std::string& stat, int value) {
    if (stat == "HP") {
        PlayerHP += value;
        if (PlayerHP > PlayerMaxHP) PlayerHP = PlayerMaxHP;
        if (PlayerHP < 0) PlayerHP = 0;
        std::cout << PlayerClass << "'s HP changed by " << value << ". Current HP: " << PlayerHP << "/" << PlayerMaxHP << std::endl;
    }
    else if (stat == "Power") {
        PlayerPower += value;
        if (PlayerPower < 0) PlayerPower = 0;
        std::cout << PlayerClass << "'s Power changed by " << value << ". Current Power: " << PlayerPower << std::endl;
    }
    else if (stat == "MAGIC") {
        PlayerPower += value;
        if (PlayerPower < 0) PlayerPower = 0;
        std::cout << PlayerClass << "'s MAGIC Power changed by " << value << ". Current MAGIC Power: " << PlayerPower << std::endl;
    }
    else if (stat == "Currency") {
        PlayerCurrency += value;
        if (PlayerCurrency < 0) PlayerCurrency = 0;
        std::cout << PlayerClass << "'s Currency changed by " << value << ". Current Currency: " << PlayerCurrency << std::endl;
    }
}

void Entity::applyKarmaEffect(int value, float multiplierChange) {
    PlayerKarma += value;
    if (PlayerKarma > 100) PlayerKarma = 100;
    if (PlayerKarma < 0) PlayerKarma = 0;

    PlayerKarma += multiplierChange;
    if (PlayerKarma < 0.1f) PlayerKarma = 0.1f;

    std::cout << PlayerClass << "'s karma changed by " << value
        << " (Now: " << PlayerKarma << "/100)\n";
    std::cout << "Karma multiplier changed by " << multiplierChange
        << " (Now: " << PlayerKarma << "x)\n";
}

void Entity::heal(int amount) {
    if (amount <= 0) return;

    int oldHp = PlayerHP;
    PlayerHP += amount;
    if (PlayerHP > PlayerMaxHP) PlayerHP = PlayerMaxHP;

    int actualHeal = PlayerHP - oldHp;
    std::cout << PlayerClass << " is healed for " << actualHeal << " HP! ";
    std::cout << "Current HP: " << PlayerHP << "/" << PlayerMaxHP << std::endl;
}

bool Entity::isAlive() const {
    return PlayerHP > 0; 
}

void Entity::attack(Entity& target) {
    int damage = PlayerPower;
    std::cout << PlayerClass << " attacks " << target.PlayerClass << " for " << damage << " damage!" << std::endl;
    target.PlayerHP -= damage;
    if (target.PlayerHP < 0) target.PlayerHP = 0;
}

void Entity::magicAttack(Entity& target) {
    int damage = PlayerPower;
    std::cout << PlayerClass << " casts a spell on " << target.PlayerClass << " for " << damage << " magic damage!" << std::endl;
    target.PlayerHP -= damage;
    if (target.PlayerHP < 0) target.PlayerHP = 0;
}
void Entity::increaseMaxHP(int amount) {
    if (amount <= 0) {
        return;
    }

    int oldMaxHp = PlayerMaxHP;
    PlayerMaxHP += amount;

    std::cout << PlayerClass << "'s maximum HP increased by " << amount << "! ";
    std::cout << "HP: " << PlayerHP << "/" << PlayerMaxHP << " (+" << amount << ")\n";
}
void Entity::modifyCritChance(float amount) {
    PlayerCritChance += amount;
    // Clamp crit chance between 0% and 100%
    if (PlayerCritChance < 0.0f) PlayerCritChance = 0.0f;
    if (PlayerCritChance > 1.0f) PlayerCritChance = 1.0f; {
    
    std::cout << PlayerClass << "'s crit chance changed by " << (amount * 100) << "%";
    std::cout << " (Now: " << (PlayerCritChance * 100) << "%)\n";
}