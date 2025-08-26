/*
okay so this is basically just for the map class, i.e it handles stuff like
rooms and floors as well as their generation and rendering through the renderer inheritance

theres still stuff to do like actually generating the enemy spawns and etc, but it should be working aside from that
*/

#include "Map.h"
#include "Renderer.h"

using namespace std;

void Map::CreateNewFloor(int Difficulty) {
    // Setup pointer arrays
    char* floorPtrs[128];
    char* innerPtrs[256];
    for (int i = 0; i < 128; ++i) floorPtrs[i] = FloorGrid[i];
    for (int i = 0; i < 256; ++i) innerPtrs[i] = InnerRoom[i];

    // Clear both boards
    fillBoard(floorPtrs, 128, 128);
    fillBoard(innerPtrs, 256, 256);

    // Clear previous room data
    rooms.clear();
    roomLookup.clear();
    currentRoom = nullptr;
    nextRoomId = 1;

    // Create all possible positions
    std::vector<std::pair<int, int>> allPositions;
    int spacing = 30;
    int offset = 15;

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            int x = offset + col * spacing;
            int y = offset + row * spacing;
            allPositions.push_back({ x, y });
        }
    }

    // Shuffle positions for random selection
    std::srand(std::time(nullptr));
    for (int i = allPositions.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(allPositions[i], allPositions[j]);
    }

    int numRooms = std::min(3 + Difficulty * 2, (int)allPositions.size());
    std::vector<std::pair<std::pair<int, int>, RoomType>> roomPlans;
    int positionIndex = 0;

    // Create all rooms EXCEPT the last one first
    for (int i = 0; i < numRooms - 1; ++i) {
        RoomType roomType;

        // Assign room types based on difficulty and randomness
        int randType = std::rand() % 100;

        if (Difficulty >= 2 && randType < 20) {
            roomType = RoomType::LARGE;
        }
        else if (Difficulty >= 2 && randType < 35) {
            roomType = RoomType::TREASURE;
        }
        else if (randType < 60) {
            roomType = RoomType::MEDIUM;
        }
        else {
            roomType = RoomType::SMALL;
        }

        // Create Enemies in rooms.

        roomPlans.push_back({ allPositions[positionIndex++], roomType });
    }

    // The last room is always a shop
    roomPlans.push_back({ allPositions[positionIndex], RoomType::SHOP });

    // Generate all planned rooms
    for (int i = 0; i < roomPlans.size(); ++i) {
        Room newRoom(nextRoomId++, roomPlans[i].first.first, roomPlans[i].first.second, roomPlans[i].second);
        rooms.push_back(newRoom);
        roomLookup[newRoom.id] = &rooms.back();

        // Use InnerRoom for large rooms, FloorGrid for others. (self explanatory)
        if (newRoom.type == RoomType::LARGE) {
            generateLargeRoom(newRoom);
        }
        else {
            generateRoom(newRoom, floorPtrs, 128, 128);
        }
    }

    std::cout << "Generated " << numRooms << " rooms (last room is shop)" << std::endl;

    // Verify the last room is a shop so we can be capitalist pigs
    Room* lastRoom = getLastRoom();
    if (lastRoom && lastRoom->type == RoomType::SHOP) {
        std::cout << "Final shop is room #" << lastRoom->id << " at ("
            << lastRoom->x << "," << lastRoom->y << ")" << std::endl;
    }

    // Cleanup!! JANITOR ON AISLE 108 AND 109!!!

	delete[] floorPtrs;  
    delete[] innerPtrs;
}

void Map::RequestFloorUpdate() {
    char* floorPointers[128];
    for (int i = 0; i < 128; ++i) {
        floorPointers[i] = FloorGrid[i];
    }

    drawBoard(floorPointers, 128, 128);

	delete[] floorPointers;
}

void Map::fillBoard(char** Board, int sizeX, int sizeY)
{
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            Board[h][v] = ' ';
        }
    }
}

void Map::drawBoard(char** Board, int sizeX, int sizeY)
{
    std::cout << "+---------------------------------------+" << endl;
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            std::cout << Board[h][v];
        }
        std::cout << endl;
    }
    std::cout << "+---------------------------------------+" << endl;

}

void Map::generateRoom(const Room& room, char** board, int boardSizeX, int boardSizeY) {
    int halfW = room.width / 2;
    int halfH = room.height / 2;

    // Create walls
    for (int x = room.x - halfW; x <= room.x + halfW; ++x) {
        for (int y = room.y - halfH; y <= room.y + halfH; ++y) {
            if (x >= 0 && x < boardSizeX && y >= 0 && y < boardSizeY) {
                board[x][y] = '#';
            }
        }
    }

    // Create floor interior
    for (int x = room.x - halfW + 1; x < room.x + halfW; ++x) {
        for (int y = room.y - halfH + 1; y < room.y + halfH; ++y) {
            if (x >= 0 && x < boardSizeX && y >= 0 && y < boardSizeY) {
                board[x][y] = room.floorChar;
            }
        }
    }
}

void Map::generateLargeRoom(const Room& room) {
    char* innerPtrs[256];
    for (int i = 0; i < 256; ++i) innerPtrs[i] = InnerRoom[i];

    // Scale up position for 256x256 board
    Room scaledRoom = room;
    scaledRoom.x *= 2;  // Scale position
    scaledRoom.y *= 2;

    generateRoom(scaledRoom, innerPtrs, 256, 256);

	delete[] innerPtrs;
}

Room* Map::detectPlayerRoom(int playerX, int playerY) {
    for (auto& room : rooms) {
        if (isPlayerInRoom(playerX, playerY, room)) {
            currentRoom = &room;
            return &room;
        }
    }
    currentRoom = nullptr;
    return nullptr;  // Player is in corridor/empty space
}

bool Map::isPlayerInRoom(int playerX, int playerY, const Room& room) {
    int halfW = room.width / 2;
    int halfH = room.height / 2;
    
    // Check if player is within room boundaries
    return (playerX >= room.x - halfW + 1 && playerX < room.x + halfW &&
            playerY >= room.y - halfH + 1 && playerY < room.y + halfH &&
            FloorGrid[playerX][playerY] != '#');  // Make sure it's not a wall
}

void Map::renderCurrentRoom(Room* room, char** roomBoard, int boardSize) {
    if (!room) return;

    fillBoard(roomBoard, boardSize, boardSize);

    int scale = 8;  // Scale factor for detailed view
    int scaledWidth = room->width * scale;
    int scaledHeight = room->height * scale;
    int centerX = boardSize / 2;
    int centerY = boardSize / 2;

    // Render scaled-up version centered on roomBoard
    for (int x = 0; x < scaledWidth; ++x) {
        for (int y = 0; y < scaledHeight; ++y) {
            int roomBoardX = centerX - scaledWidth / 2 + x;
            int roomBoardY = centerY - scaledHeight / 2 + y;

            if (roomBoardX >= 0 && roomBoardX < boardSize && roomBoardY >= 0 && roomBoardY < boardSize) {
                // Determine what this scaled pixel should be
                int originalX = x / scale;
                int originalY = y / scale;

                if (originalX == 0 || originalX == room->width - 1 || originalY == 0 || originalY == room->height - 1) {
                    roomBoard[roomBoardX][roomBoardY] = '#';  // Wall
                }
                else {
                    roomBoard[roomBoardX][roomBoardY] = room->floorChar;  // Floor
                }
            }
        }
    }
}

void Map::switchToRoomView(int playerX, int playerY) {
    Room* playerRoom = detectPlayerRoom(playerX, playerY);
    
    if (playerRoom) {
        // Use InnerRoom as the isolated room view
        char* innerPtrs[256];
        for (int i = 0; i < 256; ++i) innerPtrs[i] = InnerRoom[i];
        
        renderCurrentRoom(playerRoom, innerPtrs, 256);
        
        std::cout << "Entered " << getRoomTypeName(playerRoom->type) << " room!" << std::endl;
        drawBoard(innerPtrs, 256, 256);  // Show just this room
        delete[] innerPtrs;
    } else {
        std::cout << "Player is in a corridor or empty space." << std::endl;
    }

}

// Helper function to get room type names
std::string Map::getRoomTypeName(RoomType type) {
    switch(type) {
        case RoomType::SMALL: return "Small";
        case RoomType::MEDIUM: return "Medium";
        case RoomType::LARGE: return "Large";
        case RoomType::SHOP: return "Shop";
        case RoomType::TREASURE: return "Treasure";
        case RoomType::CORRIDOR: return "Corridor";
        default: return "Unknown";
    }
}

Room* Map::getRoomById(int roomId) {
    auto it = roomLookup.find(roomId);
    return (it != roomLookup.end()) ? it->second : nullptr;
}

Room* Map::getRoomByIndex(int index) {
    return (index >= 0 && index < rooms.size()) ? &rooms[index] : nullptr;
}

std::vector<Room*> Map::getRoomsByType(RoomType type) {
    std::vector<Room*> result;
    for (auto& room : rooms) {
        if (room.type == type) {
            result.push_back(&room);
        }
    }
    return result;
}

void Map::markRoomVisited(int roomId) {
    Room* room = getRoomById(roomId);
    if (room) room->visited = true;
}

void Map::markRoomCleared(int roomId) {
    Room* room = getRoomById(roomId);
    if (room) room->cleared = true;
}

bool Map::isRoomVisited(int roomId) {
    Room* room = getRoomById(roomId);
    return room ? room->visited : false;
}

bool Map::isRoomCleared(int roomId) {
    Room* room = getRoomById(roomId);
    return room ? room->cleared : false;
}

int Map::getVisitedRoomCount() {
    int count = 0;
    for (const auto& room : rooms) {
        if (room.visited) count++;
    }
    return count;
}

int Map::getClearedRoomCount() {
    int count = 0;
    for (const auto& room : rooms) {
        if (room.cleared) count++;
    }
    return count;
}

int Map::getRoomCountByType(RoomType type) {
    int count = 0;
    for (const auto& room : rooms) {
        if (room.type == type) count++;
    }
    return count;
}

void Map::printRoomInfo() {
    std::cout << "\n=== ROOM INFO ===" << std::endl;
    std::cout << "Total Rooms: " << rooms.size() << std::endl;
    for (const auto& room : rooms) {
        std::cout << "Room " << room.id << ": " << getRoomTypeName(room.type)
            << " at (" << room.x << "," << room.y << ")"
            << " - Visited: " << (room.visited ? "Yes" : "No")
            << " - Cleared: " << (room.cleared ? "Yes" : "No") << std::endl;
    }
    std::cout << "=================" << std::endl;
}

bool Map::isLastRoom(int roomId) {
    if (rooms.empty()) return false;
    return rooms.back().id == roomId;  // Check if it's the last room created
}

bool Map::isLastRoom(Room* room) {
    if (!room || rooms.empty()) return false;
    return room->id == rooms.back().id;
}

Room* Map::getLastRoom() {
    return rooms.empty() ? nullptr : &rooms.back();
}

int Map::getLastRoomId() {
    return rooms.empty() ? -1 : rooms.back().id;
}
    
bool Map::isLastRoomShop() {
    Room* lastRoom = getLastRoom();
    return lastRoom && lastRoom->type == RoomType::SHOP;
}

Room* Map::getFinalShop() {
    Room* lastRoom = getLastRoom();
    return (lastRoom && lastRoom->type == RoomType::SHOP) ? lastRoom : nullptr;
}

