#include "entity.h"
#include "Player.h"
#include <iostream>

Entity::Entity()
{
}

Entity::Entity(std::string Cl, int MH, int H, int P, int mP, int C)
    : Class(Cl), MaxHP(MH), HP(H), Power(P), magicPower(mP), Currency(C)
{
}

Entity::~Entity()
{
}

void Entity::SetClass(std::string Class)
{
    this->Class = Class;
}

void Entity::SetMaxHP(int MaxHP)
{
    this->MaxHP = MaxHP;
}

void Entity::SetHP(int HP)
{
    this->HP = HP;
}

void Entity::SetPower(int Power)
{
    this->Power = Power;
}

void Entity::SetmagicPower(int magicPower)
{
    this->magicPower = magicPower;
}

void Entity::SetCurrency(int Currency)
{
    this->Currency = Currency;
}

std::string Entity::GetClass(void) const
{
    return Class;
}

int Entity::GetMaxHP(void) const
{
    return MaxHP;
}

int Entity::GetHP(void) const
{
    return HP;
}

int Entity::GetPower(void) const
{
    return Power;
}

int Entity::GetmagicPower(void) const
{
    return magicPower;
}

int Entity::GetCurrency(void) const
{
    return Currency;
}

void Entity::applyBuff(const std::string& stat, int value) {
    if (stat == "HP") {
        HP += value;
        if (HP > MaxHP) HP = MaxHP;
        if (HP < 0) HP = 0;
        std::cout << Class << "'s HP changed by " << value << ". Current HP: " << HP << "/" << MaxHP << std::endl;
    }
    else if (stat == "Power") {
        Power += value;
        if (Power < 0) Power = 0;
        std::cout << Class << "'s Power changed by " << value << ". Current Power: " << Power << std::endl;
    }
    else if (stat == "MAGIC") {
        magicPower += value;
        if (magicPower < 0) magicPower = 0;
        std::cout << Class << "'s MAGIC Power changed by " << value << ". Current MAGIC Power: " << magicPower << std::endl;
    }
    else if (stat == "Currency") {
        Currency += value;
        if (Currency < 0) Currency = 0;
        std::cout << Class << "'s Currency changed by " << value << ". Current Currency: " << Currency << std::endl;
    }
}

void Entity::applyKarmaEffect(int value, float multiplierChange) {
    Karma += value;
    if (Karma > 100) Karma = 100;
    if (Karma < 0) Karma = 0;

    karmaMultiplier += multiplierChange;
    if (karmaMultiplier < 0.1f) karmaMultiplier = 0.1f;

    std::cout << Class << "'s karma changed by " << value
        << " (Now: " << Karma << "/100)\n";
    std::cout << "Karma multiplier changed by " << multiplierChange
        << " (Now: " << karmaMultiplier << "x)\n";
}

void Entity::heal(int amount) {
    if (amount <= 0) return;

    int oldHp = HP;
    HP += amount;
    if (HP > MaxHP) HP = MaxHP;

    int actualHeal = HP - oldHp;
    std::cout << Class << " is healed for " << actualHeal << " HP! ";
    std::cout << "Current HP: " << HP << "/" << MaxHP << std::endl;
}

bool Entity::isAlive() const {
    return HP > 0;
}

void Entity::attack(Entity& target) {
    int damage = Power;
    std::cout << Class << " attacks " << target.Class << " for " << damage << " damage!" << std::endl;
    target.HP -= damage;
    if (target.HP < 0) target.HP = 0;
}

void Entity::magicAttack(Entity& target) {
    int damage = magicPower;
    std::cout << Class << " casts a spell on " << target.Class << " for " << damage << " magic damage!" << std::endl;
    target.HP -= damage;
    if (target.HP < 0) target.HP = 0;
}
void Entity::increaseMaxHP(int amount) {
    if (amount <= 0) {
        return;
    }

    int oldMaxHp = MaxHP;
    MaxHP += amount;

    std::cout << Class << "'s maximum HP increased by " << amount << "! ";
    std::cout << "HP: " << HP << "/" << MaxHP << " (+" << amount << ")\n";
}
