

#pragma once

#ifndef EVENTS_H
#define EVENTS_H
#include "Combat.h"

#include <string>
#include <vector>
#include "Player.h"

class Events {
private:
    std::vector<std::string> minorEvents;
    std::vector<std::string> mediumEvents;

    void initializeEvents();

public:
    Events();
    void EventTriggered(Player& MC, Enemy& target);
    void handleSuspiciousFrogEvent(Player& MC);
    void handleFreePrisonerEvent(Player& MC);
    void handleMutatedRatEvent(Player& MC);
    void handleTalkingChestEvent(Player& MC);
    void handleSpectralEntityEvent(Player& MC);
    void handleHunchedBackGoblinEvent(Player& MC);
    void handleMageKarmaTestEvent(Player& MC);
    void handleGoblinJesterEvent(Player& MC, Enemy& target);
    void handleSuspiciousFrog2Event(Player& MC);
	void handleBrokenPuppetEvent(Player& MC);
    void handleLockpickingEvent(Player& MC);
	void handleMemoryRuneEvent(Player& MC);
};

#endif // EVENTS_H