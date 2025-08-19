#include "divine_intervention.h"
#include <iostream>

DivineIntervention::DivineIntervention() : gen(rd()) {  
    // God names
    godNames = {
        {God::SAGACITY, "Sagacity the Renaissance"},
        {God::AURORA, "Aurora the Concord"},
        {God::CHRYSES, "Chryses the Wherewithal"},
        {God::FERONIA, "Feronia the Fruitfulness"},
        {God::KERES, "Keres the Anathema"},
        {God::PREYSEYE, "Preyseye the Morality"}
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
        "\"Fear not, fear not. My mercy shall save all.\""
    };

    godDialogues[God::KERES] = {
        "\"Death shall cleanse us.. absolve us... and destroy us...\"",
        "\"We are all headed for death; one might as well speed up the process.\"",
        "\"Pain... What a necessary evil. Let me bestow it upon you.\"",
        "\"Hush. The Great Beyond awaits.\""
    };

    godDialogues[God::PREYSEYE] = {
        "\"Morality's dichotomy is a conundrum best left to the omniscient, a distinction reserved for one of superior insight, namely myself.\"",
        "\"The forthcoming calibration of your metaphysical essence is about to commence.\"",
        "\"The division of Virtue and Vice. The antithesis of Rectitude and Iniquity. To which path shall one's predilections be inclined?\"",
        "\"The existential balance of moral gravitas, shall it incline in your direction or not? We shall, in due course, behold the veritable outcome.\""
    };
}

std::string DivineIntervention::getRandomDialogue(God god) const {
    if (god == God::NONE || godDialogues.find(god) == godDialogues.end()) {
        return "";
    }
    const auto& dialogues = godDialogues.at(god);
    std::uniform_int_distribution<> dist(0, dialogues.size() - 1);
    return dialogues[dist(gen)];
}

// ... (keep existing getRandomGod implementation)

void DivineIntervention::applyEffect(God god, Entity& player, Entity& enemy) const {
    if (god == God::NONE) return;

    std::cout << "\n=== DIVINE INTERVENTION ===\n";
    std::cout << "A sudden presence fills the air...\n";
    std::cout << godNames.at(god) << " manifests before you!\n";
    std::cout << getRandomDialogue(god) << "\n\n";

    bool affectsPlayer = std::bernoulli_distribution(0.5)(gen);     //huh?!?!
    Entity& primaryTarget = affectsPlayer ? player : enemy;
    Entity& secondaryTarget = affectsPlayer ? enemy : player;

    switch (god) {
    case God::SAGACITY: {
		int effect = std::uniform_int_distribution<>(-3, 3)(gen);     //uniform_int_distribution is used to generate a random number in a specified range
        if (effect == 0) effect = 1;
        std::cout << "The scent of books and arcane energies swirl around the battlefield!\n";
        primaryTarget.applyBuff("MAGIC", effect);
        secondaryTarget.applyBuff("MAGIC", effect / 2);
        break;
    }
    case God::AURORA: {
        int effect = std::uniform_int_distribution<>(-4, 4)(gen);
        if (effect == 0) effect = 1;
        std::cout << "A luminous beam of light and song washes over the combatants!\n";
        primaryTarget.applyBuff("ATK", effect);
        secondaryTarget.applyBuff("ATK", effect / 2);
        break;
    }
    case God::CHRYSES: {
        int effect = std::uniform_int_distribution<>(-10, 10)(gen);
        if (effect == 0) effect = 5;
        std::cout << "The sound of clinking coins and gems fills the air!\n";
        primaryTarget.applyBuff("GOLD", effect);
        secondaryTarget.applyBuff("GOLD", effect / 2);
        break;
    }
    case God::FERONIA: {
        int effect = std::uniform_int_distribution<>(-15, 15)(gen);
        if (effect == 0) effect = 10;
        std::cout << "Sprouts and blossoms begin to flourish on the ground!\n";
        primaryTarget.applyBuff("HP", effect);
        secondaryTarget.applyBuff("HP", effect / 2);
        break;
    }
    case God::KERES: {
        int effect = -std::uniform_int_distribution<>(5, 15)(gen);
        std::cout << "A suffocating dark miasma shrouds the area!\n";
        primaryTarget.applyBuff("HP", effect);
        secondaryTarget.applyBuff("HP", effect / 2);
        break;
    }
    case God::PREYSEYE: {
        int karmaChange = std::uniform_int_distribution<>(1, 20)(gen);
		if (std::bernoulli_distribution(0.5)(gen)) {                 //srsly what is bernoulli_distribution
            karmaChange = -karmaChange;
        }
        float multiplierChange = std::uniform_real_distribution<float>(0.1f, 0.3f)(gen);
        if (karmaChange < 0) {
            multiplierChange = -multiplierChange;
        }
        std::cout << "The very fabric of morality bends around you!\n";
        primaryTarget.applyKarmaEffect(karmaChange, multiplierChange);
        secondaryTarget.applyKarmaEffect(karmaChange / 2, multiplierChange / 2);
        break;
    }
    default:
        break;
    }
    std::cout << "==========================\n\n";
}