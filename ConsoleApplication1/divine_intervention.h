#ifndef DIVINE_INTERVENTION_H
#define DIVINE_INTERVENTION_H

#include "entity.h"
#include <random>
#include <map>
#include <string>
#include <vector>

enum class God {
    NONE,
    SAGACITY,
    AURORA,
    CHRYSES,
    FERONIA,
    KERES,
    PREYSEYE
};

class DivineIntervention {
private:
    std::map<God, std::string> godNames;
    std::map<God, std::vector<std::string>> godDialogues;
    std::random_device rd;
    std::mt19937 gen;

    struct GodProbability {
        God god;
        int probability;
    };

    const std::vector<GodProbability> godProbabilities = {
        {God::SAGACITY, 15},
        {God::AURORA, 15},
        {God::CHRYSES, 20},
        {God::FERONIA, 20},
        {God::KERES, 20},
        {God::PREYSEYE, 10}
    };

    std::string getRandomDialogue(God god) const;

public:
    DivineIntervention();
    God getRandomGod() const;
    void applyEffect(God god, Entity& player, Entity& enemy) const;
};

#endif // DIVINE_INTERVENTION_H