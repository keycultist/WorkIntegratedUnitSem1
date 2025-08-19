#ifndef DIVINE_INTERVENTION_H
#define DIVINE_INTERVENTION_H

#include "entity.h"
#include <random>
#include <map>       //<map> is basically a container that stores key words (gods) and value pairs. Keys MUST be unique. Values can have the same key and has to be tied to the key.
#include <string>    
#include <vector>

enum class God {     //enum = enumerated type, which means the set of datas are numbered and ordered (basically a list)
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
	std::map<God, std::string> godNames; //map that stores the names of the gods into god names
    std::map<God, std::vector<std::string>> godDialogues;      
	std::random_device rd;        //random_device is used to seed the random number generator that is non-determistic.   
	std::mt19937 gen;            //should be a random number generator

	struct GodProbability {            //struct is a type of user defined data structure that groups keys & values together. In this case, it groups the god and its probability.
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