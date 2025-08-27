#ifndef DIVINE_INTERVENTION_H  
#define DIVINE_INTERVENTION_H

#include "entity.h"
#include "Player.h"
#include <map>
#include <string>    
#include <vector>
#include <cstdlib>  // Added for rand() and srand()
#include <ctime>    // Added for time()

enum class God {
    NONE,
    SAGACITY,
    AURORA,
    CHRYSES,
    FERONIA,
    KERES,
    PREYSEYE,
    SANCTORUM,
    BOON,
    /* MAGNAR*/
};

class DivineIntervention {
private:
    std::map<God, std::string> godNames;
    std::map<God, std::vector<std::string>> godDialogues;

    // Helper functions for random number generation
    int randomInt(int min, int max) const;
    float randomFloat(float min, float max) const;
    bool randomBool(float probability = 0.5f) const;

    struct GodProbability {
        God god;
        int probability;
    };

    const std::vector<GodProbability> godProbabilities = {
        {God::SAGACITY, 15},
        {God::AURORA, 15},
        {God::CHRYSES, 15},
        {God::FERONIA, 10},
        {God::KERES, 15},
        {God::PREYSEYE, 5},
        {God::SANCTORUM, 10},
        {God::BOON, 5},
        //{God::MAGNAR, 15}
    };

    std::string getRandomDialogue(God god) const;

public:
    DivineIntervention();
    God getRandomGod() const;  // Changed to correct function name
    void applyEffect(God god, Entity& player, Entity& enemy) const;
};

#endif
//class DivineIntervention {
//private:
//	std::map<God, std::string> godNames; //map that stores the names of the gods into god names
//	std::map<God, std::vector<std::string>> godDialogues;    //create a map that stores the dialogues of each god, where the key is the god and the value is a vector of strings (dialogues).  
//	std::random_device rd;        //random_device is used to seed the random number generator that is non-determistic.   
//	std::mt19937 gen;            //should be a random number generator
//
//	struct GodProbability {            //struct is a type of user defined data structure that groups keys & values together. In this case, it groups the god and its probability.
//        God god;
//        int probability;
//    };
//
//    const std::vector<GodProbability> godProbabilities = {
//        {God::SAGACITY, 15},  //increase magic attacks
//        {God::AURORA, 15},    //increase attack
//        {God::CHRYSES, 15},   //increase/decrease gold earned
//        {God::FERONIA, 10},   //heals
//        {God::KERES, 15},     //decrease max hp
//        {God::PREYSEYE, 5},   //increase/decrease karma
//        {God::SANCTORUM, 10},  //increase max hp
//        {God::BOON, 5},       //increase crit rate
//        //{God::MAGNAR, 15}    //TBA
//    };
//
//    std::string getRandomDialogue(God god) const;
//
//public:
//    DivineIntervention();
//    God getRandomGod() const;
//    void applyEffect(God god, Entity& player, Entity& enemy) const;
//};

//#endif // DIVINE_INTERVENTION_H