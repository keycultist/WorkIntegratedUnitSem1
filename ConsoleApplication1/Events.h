

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
    void EventTriggered(int& PlayerKarma, int PlayerCurrency);
    void handleSuspiciousFrogEvent(int& PlayerKarma);
    void handleFreePrisonerEvent(int& PlayerKarma);
    void handleMutatedRatEvent(int& PlayerKarma);
    void handleTalkingChestEvent(int& PlayerKarma);
    void handleSpectralEntityEvent(int& PlayerKarma);
    void handleHunchedBackGoblinEvent(int& PlayerCurrency);
    void handleMageKarmaTestEvent(int& PlayerKarma);
    void handleGoblinJesterEvent(int& PlayerCurrency);
    void handleSuspiciousFrog2Event(int& PlayerKarma);
};

#endif // EVENTS_H