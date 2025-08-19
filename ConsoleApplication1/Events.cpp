#include "Events.h"
#include <iostream>
#include <random>
#include <ctime>

Events::Events() {
    initializeEvents();
    // Random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Events::initializeEvents() {
    // Initialize Minor Events
    minorEvents = {
        "You stumble upon an old campfire. Ashes still warm, someone was here previously",
        "A run-down statue in the corner of the room catches your eye. You pray and hope for safe travels (+5 HP)",
        "A suspicious frog hops next to you. It asks, \"You come across a dying enemy at its last breath. They beg for mercy to spare their lives. Do you end their life or try to save them even though they could very well take your kindness for granted?\" (+- Karma)",
        "You come across a slime! It does nothing and bounces away",
        "An enemy you slain drops a dusty diary, flipping past the torn out pages. You managed to decrypt one sentence, \"if you are reading this..turn back, for some doors were never meant to be opened.\"",
        "You came across a golden treasure chest! Oh wait, it was just an illusion playing tricks on you",
        "You discovered a prisoner chained to the wall, \"please..free me\" He whispers weakly. Upon further inspection, the prisoner does not seem to be human but a monster race. Do you free him? (+- Karma)",
        "A mutated rat taps you on the shoulder and demands for 5 gold pieces. It assures you that it needs it for food but his darting eyes and fidgety demeanor suggests otherwise. Do you spare 5 gold pieces? (+- Karma)",
        "The torches stuck to the wall all flicker at the same time..sending chills down your spine, guess it was just the wind.. in a dungeon..?",
        "A talking chest fills the once silent air with complaints of his \"mimic\" appearance, do you spend some time keeping it company? (+- Karma)"
    };

    // Initialize Medium Events
    mediumEvents = {
        "A skeletal warrior emerges from the darkness and ambushes you! (Trigger combat event)",
        "A spectral entity presents you with a choice, to burn the straw doll in its hands and be rewarded with a rare weapon but suffer a karma penalty.",
        "A hunchedback goblin wants to test your knowledge with a series of riddles! Answer all of them right to gain gold!\n- What has keys but cant open locks? A piano\n- What goes up but never comes down? Age\n- What can you catch but not throw? A cold",
        "A mage wants to test your luck on a dice throw! Roll 5 or 6 and be rewarded with a health potion! Any other number and gain nothing! (luck is determined by current karma level)",
        "You could have sworn that the statue moved when you turned away..lets ignore it..for now.",
        "In an attempt to raise morale by singing your favorite childhood song, you accidentally awakened a sleeping orc.. Its anger is immeasurable! (Trigger combat event)",
        "A goblin dressed in jester attire steals your gold! Fight for your belongings back or admit defeat and lose your gold (Trigger combat event or go on as per normal)",
        "You entered a room where the familiarity of darkness envelops the room but scribbles on the wall catches your attention. The mural on the wall tells tales of an ancient-sealed entity wreaking havoc who can only be stopped by a person possessing unwavering courage."
    };
}

void Events::EventTriggered() {
    // Generate random number between 1-100 for event type selection
    int eventTypeChance = std::rand() % 100 + 1;

    if (eventTypeChance <= 60) {
        // 60% chance for Minor Event
        int eventIndex = std::rand() % minorEvents.size();
        std::cout << minorEvents[eventIndex] << std::endl;
    }
    else {
        // 40% chance for Medium Event
        int eventIndex = std::rand() % mediumEvents.size();
        std::cout << mediumEvents[eventIndex] << std::endl;
    }
}