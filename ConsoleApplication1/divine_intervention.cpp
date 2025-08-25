#include "divine_intervention.h"
#include "entity.h"
#include "Player.h"
#include <iostream>
//#include <random>
#include <map>
#include <string>
#include <vector>

DivineIntervention::DivineIntervention() {
    // Initialize random seed (if not already done elsewhere in your application)
    srand(static_cast<unsigned int>(time(nullptr)));

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

    /*godDialogues[God::MAGNAR] = {
        "\"Let the might of a thousand warriors conquer your minds!\"",
        "\"Their flesh and blood will forge our swords! Their veins will be our bowstrings! And their bones will be our daggers!\"",
        "\"Our adversaries' bodies shall be relics of the past!\"",
        "\"Behold, the law of absolute ruin!\""
    };*/
}


class DivineIntervention {
private:
    std::map<God, std::vector<std::string>> godDialogues;
    std::map<God, std::string> godNames;

    // Helper function to generate random integers
    int randomInt(int min, int max) const {
        return min + (rand() % (max - min + 1));
    }

    // Helper function to generate random floats
    float randomFloat(float min, float max) const {
        return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
    }

    // Helper function for boolean distribution
    bool randomBool(float probability = 0.5f) const {
        return (static_cast<float>(rand()) / RAND_MAX) < probability;
    }

public:
    DivineIntervention() {
        // Initialize random seed (should be called once in your application)
        srand(static_cast<unsigned int>(time(nullptr)));

        // Initialize your godDialogues and godNames maps here
    }

    std::string getRandomDialogue(God god) const {
        if (god == God::NONE || godDialogues.find(god) == godDialogues.end()) {
            return "";
        }
        const auto& dialogues = godDialogues.at(god);
        int randomIndex = randomInt(0, dialogues.size() - 1);
        return dialogues[randomIndex];
    }

    void applyEffect(God god, Entity& player, Entity& enemy) const {
        if (god == God::NONE) return;

        std::cout << "\n=== DIVINE INTERVENTION ===\n";
        std::cout << "A sudden presence fills the air...\n";
        std::cout << godNames.at(god) << " manifests before you!\n";
        std::cout << getRandomDialogue(god) << "\n\n";

        bool affectsPlayer = randomBool(0.5f);
        Entity& primaryTarget = affectsPlayer ? player : enemy;
        Entity& secondaryTarget = affectsPlayer ? enemy : player;

        switch (god) {
        case God::SAGACITY: {
            int effect = randomInt(-3, 3);
            if (effect == 0) effect = 1;
            std::cout << "The scent of books and arcane energies swirl around the battlefield!\n";
            primaryTarget.applyBuff("MAGIC", effect);
            secondaryTarget.applyBuff("MAGIC", effect / 2);
            break;
        }
        case God::AURORA: {
            int effect = randomInt(-4, 4);
            if (effect == 0) effect = 1;
            std::cout << "A luminous beam of light and song washes over the combatants!\n";
            primaryTarget.applyBuff("ATK", effect);
            secondaryTarget.applyBuff("ATK", effect / 2);
            break;
        }
        case God::CHRYSES: {
            int effect = randomInt(-10, 10);
            if (effect == 0) effect = 5;
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
            int karmaChange = randomInt(1, 20);
            if (randomBool(0.5f)) {
                karmaChange = -karmaChange;
            }
            float multiplierChange = randomFloat(0.1f, 0.3f);
            if (karmaChange < 0) {
                multiplierChange = -multiplierChange;
            }
            std::cout << "The very fabric of morality bends around you!\n";
            primaryTarget.applyKarmaEffect(karmaChange, 0, multiplierChange);
            secondaryTarget.applyKarmaEffect(karmaChange / 2, 0, multiplierChange / 2);
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
};
