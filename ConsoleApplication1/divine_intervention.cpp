#include "divine_intervention.h"
#include "entity.h"
#include "Player.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int DivineIntervention::randomInt(int min, int max) const {    //randomInt picks a random whole number between two numbers
    return min + (rand() % (max - min + 1));      // +1 to include max in the range

}

float DivineIntervention::randomFloat(float min, float max) const {       //randomFloat picks a random decimal number between two numbers

    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));    // Scale rand() to the desired range

}
  
bool DivineIntervention::randomBool(float probability) const {    //randomBool gives you a true or false answer/returns true with a certain probability (default is 50%)

    return (static_cast<float>(rand()) / RAND_MAX) < probability;  // Generate a random float between 0 and 1, and compare it to the probability

}

DivineIntervention::DivineIntervention() {   //Constructor initializes god names and dialogues, and seeds the random number generator

    // God names
    godNames = {
        {God::SAGACITY, "Sagacity the Renaissance"},
        {God::AURORA, "Aurora the Concord"},
        {God::CHRYSES, "Chryses the Wherewithal"},
        {God::FERONIA, "Feronia the Fruitfulness"},
        {God::KERES, "Keres the Anathema"},
        {God::PREYSEYE, "Preyseye the Morality"},
        {God::SANCTORUM, "Sanctorum the Conservation"},
        {God::BOON, "Boon the Probability"},
        /*{God::MAGNAR, "Magnar the Valour"}*/
    };

    // God-specific dialogues
    godDialogues[God::SAGACITY] = {
        "\"All shalt beest elighten'd!\"",
        "\"Illusions and enigmas, they crumble because of me!\"",
        "\"Knowledge is pow'r, and pow'r bows bef're me!\"",
        "\"Erudition and charm, all within mine own grasp!\""
    };

    godDialogues[God::AURORA] = {
        "\"Such beautiful voices... Chant with me to build our strength!\"",
        "\"Our strength and hope shall harmonise into one seraphic reverie!\"",
        "\"Let us raise our chalices for unity and kinship! Till Queendom Come!\"",
        "\"The Gods' benevolence embraces all, and I am no exception.\""
    };

    godDialogues[God::CHRYSES] = {
        "\"Gold makes the world turn, does it not?~\"",
        "\"Money can't solve problems... unless you throw enough at it~\"",
        "\"Trick or treat, what would it be?~\"",
        "\"It feels sooo delightful being the solution to all's predicaments!\""
    };

    godDialogues[God::FERONIA] = {
        "\"My tender sprouts shall cure all of sickness and poison!\"",
        "\"No one has to die for one to see the light!\"",
        "\"It pains me to see that life has been so cruel... Let me heal you all...\"",
        "\"Fear not, fear not. My mercy shall save us all.\""
    };

    godDialogues[God::KERES] = {
        "\"Death shall cleanse us... absolve us... and destroy us...\"",
        "\"We are all headed for death; one might as well speed up the process.\"",
        "\"Pain... What a necessary evil. Let me bestow it upon you.\"",
        "\"Hush. The Great Beyond awaits.\""
    };

    godDialogues[God::SANCTORUM] = {
        "\"I grant a shield of quartz. May your vessels endure the worst of hardships.\"",
        "\"I grant a screen of diamond. May your bodies be as resilient as stone.\"",
        "\"I grant a cocoon of sapphire. May your souls never erode for aeons to come.\"",
        "\"I grant a shell of ruby. May your agony dissipate to but a scratch on skin.\""
    };

    godDialogues[God::PREYSEYE] = {
        "\"Morality'as dichotomy is a conundrum best left to the omniscient, a distinction reserved for one of superior insight, namely myself.\"",
        "\"The forthcoming calibration of your metaphysical essence is about to commence.\"",
        "\"The division of Virtue and Vice. The antithesis of Rectitude and Iniquity. To which path shall one's predilections be inclined?\"",
        "\"The existential balance of moral gravitas, shall it incline in your direction or not? We shall, in due course, behold the veritable outcome.\""
    };

    godDialogues[God::BOON] = {
        "\"How marvellously lucky for you all to encounter me~\"",
        "\"Just one strum of the threads of fate may tip the tides in your favour~\"",
        "\"Observe! This is chaos theory in action!\"",
        "\"Watch the threads of fate weave into an endless universal fabric of possibility...\""
    };
}

God DivineIntervention::getRandomGod() const {   // a function that gives back a random god quote

    // Calculate total probability
    int totalProbability = 0;    //empty "space" to pick out a god probability
    for (const auto& godProb : godProbabilities) {       
		totalProbability += godProb.probability;   //add up all the god probabilities
    }

    // Generate random number between 1 and total probability
	int randomValue = randomInt(1, totalProbability);   //pick a random number between 1 and the total probability
	int cumulative = 0;  //empty "space" to keep track of cumulative probability

    // Find which god corresponds to the random value
	for (const auto& godProb : godProbabilities) {    //go through each god and their probability
		cumulative += godProb.probability;   //add the god's probability to the cumulative total
		if (randomValue <= cumulative) {   //if the random number is less than or equal to the cumulative total, we've found our god
			return godProb.god;  //return that god
        }
    }

    // Fallback (should never reach here if probabilities are set correctly)
    return God::NONE;
}

std::string DivineIntervention::getRandomDialogue(God god) const {   // a function that gives back a random god quote

    if (god == God::NONE || godDialogues.find(god) == godDialogues.end()) {  //Is this the 'NO GOD' god? OR Searches the map for god and quote (Do I even know who this god is? Do I have any quotes for them?)

        return "";    // Return an empty string if no dialogues are found
    }
    const auto& dialogues = godDialogues.at(god);  // Get the vector of dialogues for the specified god
    int randomIndex = randomInt(0, static_cast<int>(dialogues.size()) - 1);
    return dialogues[randomIndex];   // Return the dialogue at the random index
}

void DivineIntervention::applyEffect(God god, Entity& player, Entity& enemy) const {     //applies the effect of the god to the player and enemy. Entity pass by reference
    if (god == God::NONE) return;

    std::cout << "\n=== DIVINE INTERVENTION ===\n";
    std::cout << "A sudden presence fills the air...\n";
    std::cout << godNames.at(god) << " manifests before you!\n";
    std::cout << getRandomDialogue(god) << "\n\n";

    bool affectsPlayer = randomBool(0.5f);    // flip a coin for 50% chance to affect player or enemy. if affectsPlayer is true, it affects the player, otherwise it affects the enemy
    Entity& primaryTarget = affectsPlayer ? player : enemy;  // If the coin landed on HEADS, primary target = PLAYER. Otherwise, primary target = ENEMY
    Entity& secondaryTarget = affectsPlayer ? enemy : player;     //If the coin landed on HEADS, secondary target = ENEMY. Otherwise, secondary target = PLAYER
    //If player is primary -> enemy becomes secondary
    //If enemy is primary -> player becomes secondary

    switch (god) {
    case God::SAGACITY: {
        int effect = randomInt(1, 3);  //rolls a number between 1 and 3
        std::cout << "The scent of books and arcane energies swirl around the battlefield!\n";
        primaryTarget.applyBuff("MAGIC", effect);  //applies the full effect to the primary target
        secondaryTarget.applyBuff("MAGIC", effect / 2);   //applies half the effect to the secondary target
        break;
    }
    case God::AURORA: {
        int effect = randomInt(1, 4); //rolls a number between 1 and 4
        std::cout << "A luminous beam of light and song washes over the combatants!\n"; 
        primaryTarget.applyBuff("ATK", effect);    //applies the full effect to the primary target
        secondaryTarget.applyBuff("ATK", effect / 2);    //applies half the effect to the secondary target
        break;
    }
    case God::CHRYSES: {
        int effect = randomInt(1, 10);
        std::cout << "The sound of clinking coins and gems fills the air!\n";
        primaryTarget.applyBuff("GOLD", effect);
        secondaryTarget.applyBuff("GOLD", effect / 2);
        break;
    }
    case God::FERONIA: {
        int healAmount = randomInt(10, 25);
        std::cout << "Flourishing plants and blossoms begin to sprout on the ground!\n";
        primaryTarget.heal(healAmount);
        secondaryTarget.heal(healAmount / 2);
        break;
    }
    case God::KERES: {
        int effect = -randomInt(5, 15);
        std::cout << "A suffocating dark miasma shrouds the area!\n";
        primaryTarget.applyBuff("HP", effect);
        secondaryTarget.applyBuff("HP", effect / 2);
        break;
    }
    case God::SANCTORUM: {
        int maxHpIncrease = randomInt(5, 15);
        std::cout << "A profound feeling of invigoration descends on the field!\n";
        primaryTarget.increaseMaxHP(maxHpIncrease);
        secondaryTarget.increaseMaxHP(maxHpIncrease / 2);
        break;
    }
    case God::PREYSEYE: {
        int karmaChange = randomInt(1, 20);  // Pick number to determine how much karma changes
        if (randomBool(0.5f)) {              // Flip a coin. 50% chance to make karma positive or negative
            karmaChange = -karmaChange;      // If coin landed on heads, make karma NEGATIVE
        }
        float multiplierChange = randomFloat(0.1f, 0.3f);  // Pick random decimal number
        if (karmaChange < 0) {               // If karma is negative
            multiplierChange = -multiplierChange;  // Make multiplier negative too
        }
        std::cout << "The very fabric of morality bends around you!\n";
        if (affectsPlayer) {
            // If primary target is player, secondary (enemy) gets half effect
            primaryTarget.applyKarmaEffect(karmaChange, 0, multiplierChange);
        }
        else {
            // If primary target is enemy, player (who is secondary) gets the karma effect
            secondaryTarget.applyKarmaEffect(-karmaChange, 0, multiplierChange);
        }
        break;
    }
    case God::BOON: {
        float critChanceChange = randomFloat(0.05f, 0.15f);
        if (randomBool(0.3f)) {
            critChanceChange = -critChanceChange;
        }
        std::cout << "The threads of fate begin to wave and warp!\n";
        primaryTarget.modifyCritChance(critChanceChange);
        secondaryTarget.modifyCritChance(critChanceChange / 2);
        break;
    }
    default:
        break;
    }
    std::cout << "==========================\n\n";
}