#include "entity.h"
//#include ".h"
#include <iostream>
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

void Entity::SetCritChance(int CritChance)
{
    this->CritChance = CritChance;
}

void Entity::SetCurrency(int Currency)
{
    this->Currency = Currency;
}

void Entity::SetPos(int PosX, int PosY)
{
    entityPosObj.SetX(PosX);
    entityPosObj.SetY(PosY);
}

void Entity::SetLvl(int Lvl)
{
    this->Lvl = Lvl;
}

void Entity::SetXP(int XP)
{
    this->XP = XP;
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

int Entity::GetCritChance(void) const
{
    return CritChance;
}

int Entity::GetCurrency(void) const
{
    return Currency;
}

int Entity::GetPosX(void) const
{
    return entityPosObj.GetX();
}

int Entity::GetPosY(void) const
{
    return entityPosObj.GetY();
}

int Entity::GetLvl(void) const
{
    return Lvl;
}

int Entity::GetXP(void) const
{
    return XP;
}

Entity::Entity() : Class("None"), MaxHP(100), HP(100), Power(0), CritChance(0), Currency(0), entityPosObj(0, 0), Lvl(1), XP(0)
{
}

Entity::Entity(std::string Cl, int MH, int H, int P, int CC, int C, int PX, int PY, int L, int XP) : 
    Class(Cl), MaxHP(MH), HP(H), Power(P), CritChance(CC), Currency(C), entityPosObj(PX, PY), Lvl(L), XP(XP)
{
}

Entity::~Entity()
{
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
        Power += value;
        if (Power < 0) Power = 0;
        std::cout << Class << "'s MAGIC Power changed by " << value << ". Current MAGIC Power: " << Power << std::endl;
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

    Karma += multiplierChange;
    if (Karma < 0.1f) Karma = 0.1f;

    std::cout << Class << "'s karma changed by " << value
        << " (Now: " << Karma << "/100)\n";
    std::cout << "Karma multiplier changed by " << multiplierChange
        << " (Now: " << Karma << "x)\n";
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

//void Entity::attack(Entity& target) {
//    int damage = Power;
//    std::cout << Class << " attacks " << target.Class << " for " << damage << " damage!" << std::endl;
//    target.HP -= damage;
//    if (target.HP < 0) target.HP = 0;
//}
//
//void Entity::magicAttack(Entity& target) {
//    int damage = Power;
//    std::cout << Class << " casts a spell on " << target.Class << " for " << damage << " magic damage!" << std::endl;
//    target.HP -= damage;
//    if (target.HP < 0) target.HP = 0;
//}
void Entity::increaseMaxHP(int amount) {
    if (amount <= 0) {
        return;
    }

    int oldMaxHp = MaxHP;
    MaxHP += amount;

    std::cout << Class << "'s maximum HP increased by " << amount << "! ";
    std::cout << "HP: " << HP << "/" << MaxHP << " (+" << amount << ")\n";
}
void Entity::modifyCritChance(int amount) {
    SetCritChance(GetCritChance() + amount);
    // Clamp crit chance between 0% and 100%
    if (GetCritChance() < 0.0f) CritChance = 0.0f;
    if (GetCritChance() > 1.0f) CritChance = 1.0f; {

        std::cout << Class << "'s crit chance changed by " << (amount * 100) << "%";
        std::cout << " (Now: " << (CritChance * 100) << "%)\n";
    }
}
