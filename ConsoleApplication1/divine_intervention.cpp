#include "divine_intervention.h"
#include <iostream>

DivineIntervention::DivineIntervention() : gen(rd()) {
    godNames = {
        {God::SAGACITY, "Sagacity the Renaissance"},
        {God::AURORA, "Aurora the Concord"},
        {God::CHRYSES, "Chryses the Wherewithal"},
        {God::FERONIA, "Feronia the Fruitfulness"},
        {God::KERES, "Keres the Anathema"},
        {God::PREYSEYE, "Preyseye the Morality"} 
    };
}

    // God-specific dialogues
    godDialogues[God::SAGACITY] = {
        "\"Let me enlighten your magical essence!\"",
        "\"The arcane flows through you like never before!\"",
        "\"Knowledge is power - feel my gift!\"",
        "\"Your spells shall sing with new potency!\""
    };

    godDialogues[God::AURORA] = {
        "\"Feel the strength of the dawn in your arms!\"",
        "\"Your strikes shall shine like the morning sun!\"",
        "\"I grant you the power to cleave mountains!\"",
        "\"Let your weapon sing with divine might!\""
    };

    godDialogues[God::CHRYSES] = {
        "\"Gold makes the world turn, does it not?\"",
        "\"Let me adjust your financial fortunes...\"",
        "\"Wealth comes and goes like the tides!\"",
        "\"The clink of coin is my favorite music!\""
    };

    godDialogues[God::FERONIA] = {
        "\"The gift of life is mine to bestow!\"",
        "\"Your vitality ebbs and flows like the seasons!\"",
        "\"Health is the greatest wealth, is it not?\"",
        "\"Let me touch your mortal vessel!\""
    };

    godDialogues[God::KERES] = {
        "\"Suffering is the truest teacher!\"",
        "\"Pain is my gift to you mortals!\"",
        "\"Your life force is but a plaything to me!\"",
        "\"Let me show you true agony!\""
    };

    godDialogues[God::PREYSEYE] = {
        "\"The scales of morality tip before you!\"",
        "\"Your soul's weight shall be measured!\"",
        "\"Right and wrong are but my playthings!\"",
        "\"Let us examine your ethical choices!\""
    };
    }

    int roll = std::uniform_int_distribution<>(1, total)(gen);
    int cumulative = 0;

    for (const auto& gp : godProbabilities) {
        cumulative += gp.probability;
        if (roll <= cumulative) {
            return gp.god;
        }
    }

    return God::NONE;
}

void DivineIntervention::applyEffect(God god, Entity& player, Entity& enemy) const {
    if (god == God::NONE) return;

    std::cout << "\n=== DIVINE INTERVENTION ===\n";
    std::cout << godNames.at(god) << " appears!\n";

    bool affectsPlayer = std::bernoulli_distribution(0.5)(gen); //wtf does this mean???
    Entity& primaryTarget = affectsPlayer ? player : enemy;
    Entity& secondaryTarget = affectsPlayer ? enemy : player;

    switch (god) {
    case God::SAGACITY: {
        int effect = std::uniform_int_distribution<>(-3, 3)(gen);
        if (effect == 0) effect = 1; // Ensure some effect
        primaryTarget.applyBuff("MAGIC", effect);
        secondaryTarget.applyBuff("MAGIC", effect / 2);
        break;
    }
    case God::AURORA: {
        int effect = std::uniform_int_distribution<>(-4, 4)(gen);
        if (effect == 0) effect = 1;
        primaryTarget.applyBuff("ATK", effect);
        secondaryTarget.applyBuff("ATK", effect / 2);
        break;
    }
    case God::CHRYSES: {
        int effect = std::uniform_int_distribution<>(-10, 10)(gen);
        if (effect == 0) effect = 5;
        primaryTarget.applyBuff("GOLD", effect);
        secondaryTarget.applyBuff("GOLD", effect / 2);
        break;
    }
    case God::FERONIA: {
        int effect = std::uniform_int_distribution<>(-15, 15)(gen);
        if (effect == 0) effect = 10;
        primaryTarget.applyBuff("HP", effect);
        secondaryTarget.applyBuff("HP", effect / 2);
        break;
    }
    case God::KERES: {
        int effect = -std::uniform_int_distribution<>(5, 15)(gen);
        primaryTarget.applyBuff("HP", effect);
        secondaryTarget.applyBuff("HP", effect / 2);
        break;
    }
    case God::PREYSEYE: {
        // Karma change between 1-20, positive or negative
        int karmaChange = std::uniform_int_distribution<>(1, 20)(gen);
        if (std::bernoulli_distribution(0.5)(gen)) {
            karmaChange = -karmaChange; // 50% chance to be negative
        }

        // Multiplier change between 0.1 and 0.3
        float multiplierChange = std::uniform_real_distribution<float>(0.1f, 0.3f)(gen);
        if (karmaChange < 0) {
            multiplierChange = -multiplierChange;
        }

        std::cout << "Moral alignment shifts!\n";
        primaryTarget.applyKarmaEffect(karmaChange, multiplierChange);
        secondaryTarget.applyKarmaEffect(karmaChange / 2, multiplierChange / 2);
        break;
    }
    default:
        break;
    }
    std::cout << "==========================\n\n";
}