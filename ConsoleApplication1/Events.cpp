#include "Events.h"
#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <cstdlib>
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
        "A talking chest fills the once silent air with complaints of his \"mimic\" appearance, do you spend some time keeping it company? (+- Karma)",
        "You find a child's toy sword, wooden and worn. Somehow, it feels heavier with the weight of lost innocence than any real blade",
        "A ghostly cat phases through the wall and purrs at you before vanishing. You feel oddly blessed by this furry encounter",
        "A weathered journal page finds itself beneath you, it reads, \"The gods watch not with eyes, but with balance in hand. Those who walk in light, leaving kindness in their wake, may find unseen hands guiding their steps… and perhaps, a blessing when most needed.\"",
        "A small shrine dedicated to forgotten gods sit in an alcove. Shrouded in thick vines and layers of time, you cant help but to leave an offering out of respect (+5 HP)",
        "You find a vibrant patch of green, vines sprouting from cracks within the stone and sprouts pulsing faintly with a slight golden hue. The air humming softly around them as if the roots whisper ancient prayers, this looks like the work of Feronia The Fruithfulness..",
        "You discover a pool of crystal-clear water that reflects not your face, but your deepest fears. You quickly look away.",
        "A soft humming echoes within the cracked walls. Pressing your ear against it, you hear a lullaby in a language you dont understand. Yet, it brings you comfort, sorrow and strength..could this be the voice of Aurora The Concord..?",
        "A broken puppet slumps against a wall. As you pass, its head creaks toward you. Strings are cut... but its eyes shine briefly. (+-Karma)",
        "A skeleton slumps against the wall, hand outstretched toward a faded pouch.You open it, expecting dust—but find a small stash of gold.Seems you were luckier than they were. (+5 Gold)",
        "A gentle rainfall begins to fall indoors, though there’s no roof above. As quickly as it starts, it stops. Your skin tingles, and the air smells of something divine.",
    };

    // Initialize Medium Events
    mediumEvents = {
        "A skeletal warrior emerges from the darkness and ambushes you!",
        "A spectral entity presents you with a choice, to burn the straw doll in its hands and be rewarded with a rare weapon but suffer a karma penalty.",
        "A hunchedback goblin wants to test your knowledge with a series of riddles! Answer all of them right to gain gold!\n- What has keys but cant open locks? A piano\n- What goes up but never comes down? Age\n- What can you catch but not throw? A cold",
        "A mage wants to test your luck on a dice throw! Roll 5 or 6 and be rewarded with a health potion! Any other number and gain nothing! (luck is determined by current karma level)",
        "You could have sworn that the statue moved when you turned away..lets ignore it..for now.",
        "In an attempt to raise morale by singing your favorite childhood song, you accidentally awakened a sleeping orc.. Its anger is immeasurable!",
        "A goblin dressed in jester attire steals your gold! Fight for your belongings back or admit defeat and lose your gold (Trigger combat event or go on as per normal)",
        "You entered a room where the familiarity of darkness envelops the room but scribbles on the wall catches your attention. The mural on the wall tells tales of an ancient-sealed entity wreaking havoc who can only be stopped by a person possessing unwavering courage."
        "The suspicious frog, seemingly appearing out of nowhere asks you a question again, “You are doomed to die by an ancient curse. Luckily, there lies a chest with a potion which would save you. However, guarding the chest is a child possessing the same fate as you. Do you take the cure for yourself or let the child take the cure.”"
        "You have been ignoring it, but the whispers of the dungeon have been getting louder. You decided to respond to the whispers only to be replied with a sudden deafening silence.. The dungeon knows of your presence."
        "You discover an ornate chest with an intricate lock mechanism. The craftsmanship suggests valuable contents within. (Trigger lockpicking minigame)",
        "You discover an ancient stone tablet etched with glowing runes. As you trace the symbols with your fingers, they flash briefly before fading .Suddenly, the tablet challenges you to replicate the sequence to unlock a hidden reward. Will your memory serve you well? (Trigger Memory Test minigame)"
        "You find a room filled with mirrors, each showing a different version of yourself making different life choices. One mirror cracks as you approach.",
    };
}

void Events::EventTriggered(Player& MC) {
    int eventTypeChance = std::rand() % 100 + 1;

    if (eventTypeChance <= 60) {
        // 60% chance for Minor Event
        int eventIndex = std::rand() % minorEvents.size();

        // Check if it's the suspicious frog event (index 2)
        if (eventIndex == 1) {
			std::cout << "\"A run - down statue in the corner of the room catches your eye.You pray and hope for safe travels(+5 HP)\"" << std::endl;
            MC.SetPlayerHP(MC.GetPlayerHP() + 5);
        }
        if (eventIndex == 2) {
            handleSuspiciousFrogEvent(MC);
        }
        if (eventIndex == 6) {
            handleFreePrisonerEvent(MC);
        }
        if (eventIndex == 7) {
            handleMutatedRatEvent(MC);
        }
        if (eventIndex == 9) {
            handleTalkingChestEvent(MC);
        }
        if (eventIndex == 13) {
			std::cout << "\"A small shrine dedicated to forgotten gods sit in an alcove.Shrouded in thick vines and layers of time,you cant help but to leave an offering out of respect(+5 HP)\"" << std::endl;
            MC.SetPlayerHP(MC.GetPlayerHP() + 5);
        }
        if (eventIndex == 17) {
            handleBrokenPuppetEvent(MC);
        }
        else {
            std::cout << minorEvents[eventIndex] << std::endl;
        }
    }
    else {
        // 40% chance for Medium Event
        int eventIndex = std::rand() % mediumEvents.size();

        if (eventIndex == 20) { 
			std::cout << "\"A skeletal warrior emerges from the darkness and ambushes you! You lose 5 HP!\"" << std::endl;
            MC.SetPlayerHP(MC.GetPlayerHP() - 5);
        }
        if (eventIndex == 11) {
            handleSpectralEntityEvent(MC);
        }
        if (eventIndex == 12) {
            handleHunchedBackGoblinEvent(MC);
        }
        if (eventIndex == 13) {
            handleMageKarmaTestEvent(MC);
        }
        if (eventIndex == 25) { 
            std::cout << "\"In an attempt to raise morale by singing your favorite childhood song, you accidentally awakened a sleeping orc..Its anger is immeasurable! You lose 8 HP!\"" << std::endl;
            MC.SetPlayerHP(MC.GetPlayerHP() - 8);
        }
        if (eventIndex == 16) { 
            handleGoblinJesterEvent(MC);
        }
        if (eventIndex == 18) { 
            handleSuspiciousFrog2Event(MC);
        }
        if (eventIndex == 30) {
            handleLockpickingEvent(MC);
        }
        if (eventIndex == 31) {
            handleMemoryRuneEvent(MC);
        }
        else {
            std::cout << mediumEvents[eventIndex] << std::endl;
        }
    }
}

void Events::handleSuspiciousFrogEvent(Player& MC) {
    std::cout << "A suspicious frog hops next to you. It asks, \"You come across a dying enemy at its last breath. They beg for mercy to spare their lives. Do you end their life or try to save them even though they could very well take your kindness for granted?\"" << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Save the dying enemy" << std::endl;
    std::cout << "2. End their life" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    // Input validation
    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to save the enemy
        MC.SetPlayerKarma(MC.GetPlayerKarma() + 10);  // Gain karma for showing mercy
        std::cout << "\nYou choose compassion and try to save the dying enemy." << std::endl;
        std::cout << "The frog nods approvingly. \"Compassion in the face of betrayal shows true strength\"" << std::endl;
        std::cout << "Karma increased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }
    else {
        // Player chooses to end the enemy's life
        MC.SetPlayerKarma(MC.GetPlayerKarma() - 10);  // Lose karma for showing no mercy
        std::cout << "\nYou choose to end the enemy's suffering permanently." << std::endl;
        std::cout << "The frog shakes its head sadly. \"Sometimes the easy path comes at a cost.\"" << std::endl;
        std::cout << "Karma decreased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }

    std::cout << "The frog croaks once more before hopping away into the shadows. You wonder if you made the right choice." << std::endl;
}

void Events::handleFreePrisonerEvent(Player& MC) {
    std::cout << "You discovered a prisoner chained to the wall, “please..free me” He whispers weakly. Upon further inspection, the prisoner does not seem to be human but a monster race. Do you free him? " << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Free the prisoner" << std::endl;
    std::cout << "2. Leave it up to fate to decide" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to free the prisoner
        MC.SetPlayerKarma(MC.GetPlayerKarma() + 10); // Gain karma 
        std::cout << "You chose to free the prisoner" << std::endl;
        std::cout << "\"Thank you so much..i will never forget the kindess you have showed me..may the gods have mercy on your soul.\"" << std::endl;
        std::cout << "Karma increased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }
    else {
        // Player chooses NOT to free the prisoner
        MC.SetPlayerKarma(MC.GetPlayerKarma() - 10); // Lose karma 
        std::cout << "You chose NOT to free the prisoner" << std::endl;
        std::cout << "\"I see..i guess it was to be expected..may the gods have mercy on your soul.\"" << std::endl;
        std::cout << "Karma decreased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }

    std::cout << "You left the prisoner..pondering if you made the right choice. " << std::endl;
}

void Events::handleMutatedRatEvent(Player& MC) {
    std::cout << "A mutated rat taps you on the shoulder and demands for 5 gold pieces. It assures you that it needs it for food but his darting eyes and fidgety demeanor suggests otherwise. Do you spare 5 gold pieces?" << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Give the rat your gold" << std::endl;
    std::cout << "2. The rat can go and find his own gold" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to give 5 gold to the rat
        MC.SetPlayerKarma(MC.GetPlayerKarma() + 10);  // Gain karma, lose gold
        MC.SetPlayerCurrency(MC.GetPlayerCurrency() - 5);
        std::cout << "You chose to give the rat your gold" << std::endl;
        std::cout << "The rat chuckled.\" You are one kind fellow, see you around!!\"" << std::endl;
        std::cout << "Karma increased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }
    else {
        // Player chooses NOT to give 5 gold to the rat
        MC.SetPlayerKarma(MC.GetPlayerKarma() - 10);  // Lose karma, gold stays the same
        std::cout << "You chose NOT to give the rat your gold" << std::endl;
        std::cout << "The rat snorted. \"Whatever, you better watch your back now..\"" << std::endl;
        std::cout << "Karma decreased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }

    std::cout << "After making your choice with the rat, you reminisced the days where you used to hunt rats for food" << std::endl;
}

void Events::handleTalkingChestEvent(Player& MC) {
    std::cout << "A talking chest fills the once silent air with complaints of his “mimic” appearance, do you spend some time keeping it company?" << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Have a conversation with the chest" << std::endl;
    std::cout << "2. You have better things to do" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to talk to the chest
        MC.SetPlayerKarma(MC.GetPlayerKarma() + 10);  // Gain karma, maybe gain certain stat increases? magic power increase?
        MC.SetPlayerPower(MC.GetPlayerPower() + 2);
        std::cout << "You chose to talk to the chest" << std::endl;
        std::cout << "You find yourself having a pleasant and knowledge-filled conversation with the chest" << std::endl;
        std::cout << "Karma increased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }
    else {
        // Player chooses NOT to talk to the chest
        MC.SetPlayerKarma(MC.GetPlayerKarma() - 10); // Lose karma
        std::cout << "You chose NOT to talk to the chest" << std::endl;
        std::cout << "The chest voice creaked disappointedly like rusty hinges, low and weary" << std::endl;
        std::cout << "Karma decreased by 5! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }

    std::cout << "After making your choice with the chest, you wondered if the chest could store things inside of itself" << std::endl;
}

void Events::handleSpectralEntityEvent(Player& MC) {
    std::cout << "A spectral entity presents you with a choice, to burn the straw doll in its hands and be rewarded with gold but suffer a karma penalty." << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Burn the doll and lose karma but earn gold" << std::endl;
    std::cout << "2. Nothing, i dont want to lose karma" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to burn the straw doll
        MC.SetPlayerKarma(MC.GetPlayerKarma() - 10);  //Lose karma but gain gold
        
        std::cout << "You chose to burn the strawdoll, you felt a slight chill run down your spine but your gold bag getting heavier" << std::endl;
        std::cout << "The entity hummed lowly. \"Lets see if your sacrifice will prove useful down the road..\"" << std::endl;
        std::cout << "Karma decreased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
        MC.SetPlayerCurrency(MC.GetPlayerCurrency() + 5);
        std::cout << "You have... " << MC.GetPlayerCurrency() << " gold coins.";
    }
    else {
        // Player chooses NOT to burn the strawdoll
        std::cout << "You chose NOT to burn the strawdoll" << std::endl;
        std::cout << "The entity seems surprised with your decision. \"Highly unexpected, your kind are always highly materialistic and filled with greed.\"  " << std::endl;
    }

    std::cout << "After making your choice with the entity. You wondered if it was a decision worth making." << std::endl;
}

void Events::handleHunchedBackGoblinEvent(Player& MC) {
    std::cout << "A hunchedback goblin emerges from the shadows and insists that his riddles are so hard, no living soul can crack them! He bets his gold on it" << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Bring it on!" << std::endl;
    std::cout << "2. I dont want to answer your riddles" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to answer the riddles
       
    std::string answer;
            // Riddle 1
            std::cout << "Riddle 1: What has keys but cannot open any door\n> ";
            std::getline(std::cin, answer);
            std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
            if (answer == "piano" || answer == "a piano") {
                std::cout << "The goblin snarls, disappointed. \"Grrr... correct.\"\n";
                MC.SetPlayerCurrency(MC.GetPlayerCurrency() + 10);

            }
            else {
                std::cout << "The goblin cackles. \"Wrong! The answer was 'piano'.\"\n";
            }

            // Riddle 2
            std::cout << "\nRiddle 2: What goes up but will never come down\n> ";
            std::getline(std::cin, answer);
            std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
            if (answer == "age") {
                std::cout << "The goblin grumbles. \"Another one right...\"\n";
                MC.SetPlayerCurrency(MC.GetPlayerCurrency() + 10);
            }
            else {
                std::cout << "The goblin snickers. \"Wrong again! The answer was 'age'.\"\n";
            }

            // Riddle 3
            std::cout << "\nRiddle 3: What can be caught but not thrown\n> ";
            std::getline(std::cin, answer);
            std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
            if (answer == "cold" || answer == "a cold") {
                std::cout << "The goblin glares. \"You... you cheated! Still, correct.\"\n";
                MC.SetPlayerCurrency(MC.GetPlayerCurrency() + 5);
            }
            else {
                std::cout << "The goblin dances with glee. \"Wrong! The answer was 'a cold'.\"\n";
            }

            std::cout << "\nThe goblin hisses: \"Your reward... " << MC.GetPlayerCurrency() << " gold coins. Begone before I change my mind!\"\n";
        }

    else {
        // Player chooses NOT to answer the riddle
        std::cout << "You chose NOT to answer the riddles" << std::endl;
        std::cout << "\"Hah! I knew you were a wuss! No living being alive could possibly answer my riddles!\"" << std::endl;
    }

    std::cout << "The hunchedback goblin disappears into the shadows, you hope you never see it again" << std::endl;
}

void Events::handleMageKarmaTestEvent(Player& MC) {
    std::cout << "A mage wants to test your karma, have a high enough karma and be rewarded" << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Lets go for it" << std::endl;
    std::cout << "2. Maybe next time" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to test his karma
        std::cout << "You chose to test your karma" << std::endl;
        if (MC.GetPlayerKarma() >= 70) {
            std::cout << "\"Ahh..a karma worthy of respect, may your path stay true..the dungeon always watches\"" << std::endl;
            MC.SetPlayerCurrency(MC.GetPlayerCurrency() + 5);
            std::cout << "Your reward... " << MC.GetPlayerCurrency() << " gold coins.";
            
        }
        else {
            std::cout << "\"This place has many monsters..but you..you wear your evil like armor.\"" << std::endl;
        }

    }
    else {
        // Player chooses NOT to test his karma
        std::cout << "You chose NOT to test your karma" << std::endl;
        std::cout << "The mage mumbles and stumbles away in disappointment" << std::endl;
    }

    std::cout << "After your interaction with the mage, you cant help but think that a lucky rock could help you in your future endeavours" << std::endl;
}

void Events::handleGoblinJesterEvent(Player& MC) {
    std::cout << "A goblin dressed in jester attire steals your gold! Fight for your precious gold back or admit defeat and lose it!" << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Fight the goblin" << std::endl;
    std::cout << "2. Not worth the blood" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to fight the goblin
        std::cout << "You chose to fight the goblin" << std::endl;
        std::cout << "You easily slayed the goblin and regained your gold" << std::endl;
    }
    else {
        // Player chooses NOT to fight the goblin
        std::cout << "You chose NOT to fight the goblin" << std::endl;
        std::cout << "The goblin quickly darts around the room gleefully before making his exit" << std::endl;
        MC.SetPlayerCurrency(MC.GetPlayerCurrency() - 5);
        std::cout << "You have... " << MC.GetPlayerCurrency() << " gold coins.";
    }

    std::cout << "After that close encounter with the goblin, you cant help but remember why you always hated goblins" << std::endl;
}

void Events::handleSuspiciousFrog2Event(Player& MC) {
    std::cout << "A suspicious frog hops next to you. It asks, \"You are doomed to die by an ancient curse. Luckily, there lies a chest with a potion which would save you. However, guarding the chest is a child possessing the same fate as you. Do you take the cure for yourself or let the child take the cure?\"" << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Take the cure for yourself" << std::endl;
    std::cout << "2. Let the child have the cure" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    // Input validation
    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to take the cure for himself
        MC.SetPlayerKarma(MC.GetPlayerKarma() - 10);  // Lose karma for saving himself
        std::cout << "\nYou chose to save yourself." << std::endl;
        std::cout << "The frog shakes its head disappointingly. You may have saved yourself..but the dungeon grows colder with your decision.\"\"" << std::endl;
        std::cout << "Karma decreased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }
    else {
        // Player chooses to save the child
        MC.SetPlayerKarma(MC.GetPlayerKarma() + 10);  // Gain karma for saving the child
        std::cout << "\nYou choose to save the child instead." << std::endl;
        std::cout << "The frog nods its head approvingly. \"A noble sacrifice, a soul freely given may find peace.\"" << std::endl;
        std::cout << "Karma increased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }

    std::cout << "The frog croaks once more before hopping away into the shadows. You wonder if you made the right choice." << std::endl;
}

void Events::handleBrokenPuppetEvent(Player& MC) {
    std::cout << "A broken puppet slumps against a wall. As you pass, its head creaks toward you. Strings are cut... but its eyes shine briefly. Do you fix its strings out of pity or smash it to pieces just in case?" << std::endl;
    std::cout << "\nWhat do you choose?" << std::endl;
    std::cout << "1. Fix the puppet" << std::endl;
    std::cout << "2. Smash it.." << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    int choice;
    std::cin >> choice;

    while (choice != 1 && choice != 2) {
        std::cout << "Invalid choice! Please enter 1 or 2: ";
        std::cin >> choice;
    }

    if (choice == 1) {
        // Player chooses to fix the puppets strings
        MC.SetPlayerKarma(MC.GetPlayerKarma() + 10); // Gain karma 
        std::cout << "You chose to fix the puppet" << std::endl;
        std::cout << "The puppet shook violently in response to its newly fixed strings before freezing abruptly. You noticed a slight smile forming by the puppet" << std::endl;
        std::cout << "Karma increased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }
    else {
        // Player chooses to smash the puppet
        MC.SetPlayerKarma(MC.GetPlayerKarma() - 10); // Lose karma 
        std::cout << "You chose to smash the puppet into pieces" << std::endl;
        std::cout << "You ruthlessly raised the surprisingly light puppet above your head before smashing it into the ground. The puppet effortlessly shattered into pieces.." << std::endl;
        std::cout << "Karma decreased by 10! Current karma: " << MC.GetPlayerKarma() << std::endl;
    }

    std::cout << "You left after your encounter with the puppet, you wondered what that puppet was doing in a dungeon in the first place" << std::endl;
}

void Events::handleLockpickingEvent(Player& MC) {
    std::cout << "You discover an ornate locked chest. The lock mechanism looks complex but pickable." << std::endl;
    std::cout << "Do you attempt to pick the lock?" << std::endl;
    std::cout << "1. Yes, try to pick it" << std::endl;
    std::cout << "2. Leave it alone" << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "\n=== LOCKPICKING CHALLENGE ===" << std::endl;
        std::cout << "Listen carefully! Press ENTER when you see the 'click'!" << std::endl;
        std::cout << "You have 3 attempts to get the timing right..." << std::endl;

        int attempts = 3;
        bool success = false;

        while (attempts > 0 && !success) { //game stops when player succeeds OR run out of attempts
            std::cout << "\nAttempt " << (4 - attempts) << "/3" << std::endl;
            std::cout << "Get ready... ";

            // generates a raandom timing between 1-4 seconds
            int waitTime = (std::rand() % 4 + 1) * 1000;
            std::this_thread::sleep_for(std::chrono::milliseconds(waitTime));

            std::cout << "CLICK! Press ENTER now!" << std::endl;

            auto start = std::chrono::high_resolution_clock::now(); //starts timing the duration
            std::cin.ignore(); //clears any leftover input
            std::cin.get(); //waiting for player to click enter
            auto end = std::chrono::high_resolution_clock::now(); //stops timing the duration

            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start); //compares and calculates how long it took in milliseconds

            if (duration.count() < 800) { // if player clicks enter within 0.8 seconds, they succeed
                success = true;
                std::cout << "Perfect! The lock clicks open!" << std::endl;
                MC.SetPlayerCurrency(MC.GetPlayerCurrency() + 10);
                std::cout << "You found 25 gold pieces!" << std::endl;
                std::cout << "You have... " << MC.GetPlayerCurrency() << " gold coins.";
            }
            else {
                attempts--;
                if (attempts > 0) { //playrer failed an attempt
                    std::cout << "Too slow! The pick slips. Try again..." << std::endl;
                }
            }
        }

        if (!success) { //player runs out of attempts
            std::cout << "The lockpick breaks! The chest remains sealed." << std::endl;

        }
    }
}

void Events::handleMemoryRuneEvent(Player& MC) {
    std::cout << "\n=== ANCIENT RUNE MEMORY CHALLENGE ===" << std::endl;
    std::cout << "A mystical stone tablet glows with runes. Memorize the sequence!" << std::endl;

    std::vector<char> runes = { 'A', 'B', 'C', 'D' };
    std::vector<char> sequence;

    // generate random sequence of 4-6 runes
    int sequenceLength = std::rand() % 3 + 4; // 4-6 length
    for (int i = 0; i < sequenceLength; i++) {
        sequence.push_back(runes[std::rand() % 4]); //A = 0, B = 1, C = 2, D = 3
    }

    // flashes each rune with a 0.8 second interval
    std::cout << "\nMemorize this sequence" << std::endl;
    std::cout << "Get ready..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000)); //delays for 3 seconds to give player time to prepare

    for (int i = 0; i < sequence.size(); i++) {
        std::cout << "\nRune " << (i + 1) << ": " << sequence[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }

    // clear screen effect - push the sequence to the top and off screen by couting blank spaces
    std::cout << "\n\n--- SEQUENCE COMPLETE ---" << std::endl;
    std::cout << "The runes fade away..." << std::endl;
    for (int i = 0; i < 20; i++) {
        std::cout << std::endl;
    }

    std::cout << "Now enter the sequence!" << std::endl;
    std::cout << "Enter " << sequenceLength << " runes (A, B, C, or D), separated by spaces:" << std::endl;
    std::cout << "Example: A B C D" << std::endl;
    std::cout << "Your sequence: ";

    // getting player input
    std::vector<char> playerInput;
    for (int i = 0; i < sequenceLength; i++) {
        char input;
        std::cin >> input;
        playerInput.push_back(toupper(input));
    }

    // show what they entered vs if its correct
    std::cout << "\nYour answer:    ";
    for (char rune : playerInput) {
        std::cout << rune << " ";
    }
    std::cout << "\nCorrect answer: ";
    for (char rune : sequence) {
        std::cout << rune << " ";
    }
    std::cout << std::endl;

    // check if correct
    if (playerInput == sequence) {
        std::cout << "\nPerfect! The ancient magic rewards you!" << std::endl;
        int reward = sequenceLength + 1;
        MC.SetPlayerCurrency(MC.GetPlayerCurrency() + reward);
        std::cout << "You gained " << reward << " gold!" << std::endl;
    }
    else {
        std::cout << "\nWrong sequence! The runes burn your mind!" << std::endl;
        MC.SetPlayerHP(MC.GetPlayerHP() - 3);
        std::cout << "You lose 3 HP!" << std::endl;
    }
}