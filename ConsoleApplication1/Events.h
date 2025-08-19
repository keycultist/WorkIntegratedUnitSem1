#pragma once

#ifndef EVENTS_H
#define EVENTS_H

#include <string>
#include <vector>

class Events {
private:
    std::vector<std::string> minorEvents;
    std::vector<std::string> mediumEvents;

    void initializeEvents();

public:
    Events();
    void EventTriggered();
};

#endif // EVENTS_H