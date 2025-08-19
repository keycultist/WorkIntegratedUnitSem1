#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Renderer.h"
#include <map>

enum class RoomType {
    SMALL,      // 7x7 room
    MEDIUM,     // 11x11 room
    LARGE,      // 15x15 room
    SHOP,       // 19x19 room
    TREASURE,   // 9x9 room
    CORRIDOR    // 3x3 connector
};

struct Room {
    int id;             // Unique room identifier
    int x, y;           // Center position
    RoomType type;      // What kind of room
    int width, height;  // Dimensions
    char floorChar;     // What character to fill floor with
    bool visited;       // Has player been here?
    bool cleared;       // Has room been completed?

    Room(int id, int x, int y, RoomType type) : id(id), x(x), y(y), type(type), visited(false), cleared(false) {
        // Set dimensions based on type
        switch (type) {
        case RoomType::SMALL:    width = 7; height = 7; floorChar = '.'; break;
        case RoomType::MEDIUM:   width = 11; height = 11; floorChar = '.'; break;
        case RoomType::LARGE:    width = 15; height = 15; floorChar = '.'; break;
        case RoomType::SHOP:     width = 11; height = 11; floorChar = 'B'; break;
        case RoomType::TREASURE: width = 9; height = 9; floorChar = '$'; break;
        case RoomType::CORRIDOR: width = 3; height = 3; floorChar = '.'; break;
        }
    }
};

class Map : public Renderer
{

private:
    char FloorGrid[128][128];
    int tilesFilled;
    char InnerRoom[256][256];
	
    std::vector<Room> rooms;    
    std::map<int, Room*> roomLookup;  
    Room* currentRoom;                 
    int nextRoomId;                    
protected:

public:

    void CreateNewFloor(int Difficulty);

    void RequestFloorUpdate();

    void RequestRoomUpdate();
        
    void fillBoard(char** Board, int sizeX, int sizeY) override;

    void drawBoard(char** Board, int sizeX, int sizeY) override;
};
