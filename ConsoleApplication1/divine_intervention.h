#ifndef DIVINE_INTERVENTION_H
#define DIVINE_INTERVENTION_H

#include "entity.h"
#include <random>
#include <map>
#include <string>

enum class God {
    NONE,
    SAGACITY,  // Affects magic attack
    AURORA,    // Affects physical attack
    CHRYSES,   // Affects gold
    FERONIA,   // Affects HP (can be positive or negative)
    KERES,     // Always reduces HP
    PREYSEYE   // Affects karma
};

class DivineIntervention {
private:
    std::map<God, std::string> godNames; //idk what this does
	std::random_device rd;  // Random number generator
    std::mt19937 gen; //huh?????

    struct GodProbability {
        God god;
        int probability;
    };

    const std::vector<GodProbability> godProbabilities = {
        {God::SAGACITY, 15},
        {God::AURORA, 15},
        {God::CHRYSES, 20},
        {God::FERONIA, 20},  // Reduced from 25 to make room
        {God::KERES, 20},    // Reduced from 25 to make room
        {God::PREYSEYE, 10}  // New god with 10% weight
    };

public:
    DivineIntervention();
    God getRandomGod() const;
    void applyEffect(God god, Entity& player, Entity& enemy) const;
};

#endif // DIVINE_INTERVENTION_H