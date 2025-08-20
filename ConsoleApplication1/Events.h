

#pragma once

#ifndef EVENTS_H
#define EVENTS_H

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
    void CombatEventTriggered();
    void EventTriggered(Player& MC);
    void handleSuspiciousFrogEvent(Player& MC);
    void handleFreePrisonerEvent(Player& MC);
    void handleMutatedRatEvent(Player& MC);
    void handleTalkingChestEvent(Player& MC);
    void handleSpectralEntityEvent(Player& MC);
    void handleHunchedBackGoblinEvent(Player& MC);
    void handleMageKarmaTestEvent(Player& MC);
    void handleGoblinJesterEvent(Player& MC);
    void handleSuspiciousFrog2Event(Player& MC);
};

#endif // EVENTS_H