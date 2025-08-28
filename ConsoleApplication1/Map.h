#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Renderer.h"
#include "Player.h"
#include "Enemy.h"
#include "Shop.h"
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
	std::vector<Enemy> enemies; // Enemy Table
    bool enemiesCleared = false;

    Room(int id, int x, int y, RoomType type) : id(id), x(x), y(y), type(type), visited(false), cleared(false) {
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
    bool minibossGenerated = false; 
    bool trueBossGenerated = false;
    Room* minibossRoom = nullptr;
    Room* trueBossRoom = nullptr;
    
    char getEnemyDisplayChar(const Enemy& enemy);
    void renderEnemiesOnBoard(char** Board, int sizeX, int sizeY);
    void generateEnemiesForRoom(Room& room, int difficulty);
    void generateEnemyForRoom(Enemy& enemy, const Room& room, int difficulty, int enemyIndex);
    void setEnemyEquipment(Enemy& enemy, const std::string& enemyClass, int difficulty);
protected:

public:

    void CreateNewFloor(int Difficulty, Player& MC, Shop& shop);

    void RequestFloorUpdate(Player& MC);

    void RequestRoomUpdate();
        
    void fillBoard(char** Board, int sizeX, int sizeY, Player& MC);

    void fillBoardPlayer(char** Board, int sizeX, int sizeY, Player& MC);

    void drawBoard(char** Board, int sizeX, int sizeY);

    void generateRoom(const Room& room, char** board, int boardSizeX, int boardSizeY);
    void generateLargeRoom(const Room& room);  // Uses InnerRoom for big rooms
    
    Room* detectPlayerRoom(int playerX, int playerY);
    void renderCurrentRoom(Room* room, char** roomBoard, int boardSize, Player& MC);
    bool isPlayerInRoom(int playerX, int playerY, const Room& room);
    void switchToRoomView(int playerX, int playerY, Player& MC, Shop& shop, bool& FinishShopping);

    Room* getRoomById(int roomId);
    Room* getRoomByIndex(int index);
    std::vector<Room*> getRoomsByType(RoomType type);
    int getRoomCount() { return rooms.size(); }
    int getCurrentRoomId() { return currentRoom ? currentRoom->id : -1; }
    Room* getCurrentRoom() { return currentRoom; }

    void markRoomVisited(int roomId);
    void markRoomCleared(int roomId);
    bool isRoomVisited(int roomId);
    bool isRoomCleared(int roomId);

    int getVisitedRoomCount();
    int getClearedRoomCount();
    int getRoomCountByType(RoomType type);

    std::string getRoomTypeName(RoomType type);
    void printRoomInfo();  // Debug function to show all rooms

    bool isLastRoom(int roomId);
    bool isLastRoom(Room* room);
    Room* getLastRoom();
    int getLastRoomId();

    bool isLastRoomShop();
    Room* getFinalShop();

    std::vector<Enemy*> getEnemiesInRoom(Room* room);
    bool isRoomEnemiesCleared(Room* room);
    bool checkForCombat(Room* room, Player& MC);
    Room* getMinibossRoom() { return minibossRoom; }
    Room* getTrueBossRoom() { return trueBossRoom; }
    bool hasMiniboss() { return minibossGenerated; }
    bool hasTrueBoss() { return trueBossGenerated; }

    void generateBossForRoom(Enemy& enemy, const std::string& bossType, int difficulty);
    void removeDefeatedEnemies();
	Enemy* getEnemyAtPosition(int x, int y);

    void renderMapWithFOV(Player& MC, int viewWidth, int viewHeight);
};
