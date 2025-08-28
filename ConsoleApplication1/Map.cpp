/*
okay so this is basically just for the map class, i.e it handles stuff like
rooms and floors as well as their generation and rendering through the renderer inheritance

theres still stuff to do like actually generating the enemy spawns and etc, but it should be working aside from that
*/

#include "Map.h"
#include "Renderer.h"
#include "Player.h"
#include "Enemy.h"
#include "Shop.h"
#include "Combat.h"
#include "conio.h"
#include <queue>
#define NOMINMAX
#include <windows.h> 

using namespace std;

void Map::CreateNewFloor(int Difficulty, Player& MC, Shop& shop) {
    // Setup pointer arrays
    char* floorPtrs[128];
    char* innerPtrs[256];
    for (int i = 0; i < 128; ++i) floorPtrs[i] = FloorGrid[i];
    for (int i = 0; i < 256; ++i) innerPtrs[i] = InnerRoom[i];

    //Init Shop
    shop.SetShopItemSlot(MC, MC.GetInventory().GetItem());

    // Clear both boards
    fillBoard(floorPtrs, 128, 128, MC);
    fillBoard(innerPtrs, 256, 256, MC);

    // Clear previous room data
    rooms.clear();
    roomLookup.clear();
    currentRoom = nullptr;
    nextRoomId = 1;
    minibossGenerated = false;
    trueBossGenerated = false;
    minibossRoom = nullptr;
    trueBossRoom = nullptr;

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

        roomPlans.push_back({ allPositions[positionIndex++], roomType });
    }

    // The last room is always a shop
    roomPlans.push_back({ allPositions[positionIndex], RoomType::SHOP });

    // Generate all planned rooms AND their enemies
    for (int i = 0; i < roomPlans.size(); ++i) {
        Room newRoom(nextRoomId++, roomPlans[i].first.first, roomPlans[i].first.second, roomPlans[i].second);
        rooms.push_back(newRoom);
        roomLookup[newRoom.id] = &rooms.back();

        // Use InnerRoom for large rooms, FloorGrid for others
        if (newRoom.type == RoomType::LARGE) {
            generateLargeRoom(newRoom);
        }
        else {
            generateRoom(newRoom, floorPtrs, 128, 128);
        }

        // NOW generate enemies for this room (after the room is fully created)
        generateEnemiesForRoom(rooms.back(), Difficulty);
    }

    // NOW ggenerate roaming enemies for this floor (after all rooms are created)
    generateRoamingEnemies(Difficulty);

    enemyMoveCounter = 0; // initialize movecounter

    std::cout << "Generated " << numRooms << " rooms (last room is shop)" << std::endl;

    // Verify the last room is a shop
    Room* lastRoom = getLastRoom();
    if (lastRoom && lastRoom->type == RoomType::SHOP) {
        std::cout << "Final shop is room #" << lastRoom->id << " at ("
            << lastRoom->x << "," << lastRoom->y << ")" << std::endl;
    }
}


void Map::renderEnemiesOnBoard(char** Board, int sizeX, int sizeY) {
    // Render room enemies
    for (const auto& room : rooms) {
        for (const auto& enemy : room.enemies) {
            if (enemy.GetEnemyHP() > 0) {
                int enemyX = enemy.GetEnemyPosX();
                int enemyY = enemy.GetEnemyPosY();

                if (enemyX >= 0 && enemyX < sizeX && enemyY >= 0 && enemyY < sizeY) {
                    char enemyChar = getEnemyDisplayChar(enemy);
                    Board[enemyY][enemyX] = enemyChar;
                }
            }
        }
    }

    // Render roaming enemies
    for (const auto& enemy : roamingEnemies) {
        if (enemy.GetEnemyHP() > 0) {
            int enemyX = enemy.GetEnemyPosX();
            int enemyY = enemy.GetEnemyPosY();

            if (enemyX >= 0 && enemyX < sizeX && enemyY >= 0 && enemyY < sizeY) {
                char enemyChar = 'R';  // 'R' for roaming enemies
                Board[enemyY][enemyX] = enemyChar;
            }
        }
    }
}





void Map::fillBoard(char** Board, int sizeX, int sizeY, Player& MC)
{
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            Board[h][v] = ' ';
        }
    }
    fillBoardPlayer(Board, sizeX, sizeY, MC);
}

void Map::fillBoardPlayer(char** Board, int sizeX, int sizeY, Player& MC) {
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            if (Board[h][v] == 'P')
                Board[h][v] = ' ';
        }
    }

    renderEnemiesOnBoard(Board, sizeX, sizeY);

    int playerX = MC.GetPlayerPosX();
    int playerY = MC.GetPlayerPosY();
    /*if (playerX >= 0 && playerX < sizeX && playerY >= 0 && playerY < sizeY) {
        Board[playerY][playerX] = 'P';
    }*/
}

void Map::drawBoard(char** Board, int sizeX, int sizeY)
{
    std::cout << "+";
    for (int i = 0; i < 128; i++) {
        std::cout << "-";
    }
    std::cout << "+" << endl;
    std::string buffer;
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            buffer += Board[h][v];
        }
        buffer += '\n';
    }
    std::cout << buffer << std::endl;
    std::cout << "+";
    for (int i = 0; i < 128; i++) {
        std::cout << "-";
    }
    std::cout << "+" << endl;

}

void Map::generateRoom(const Room& room, char** board, int boardSizeX, int boardSizeY) {
    int halfW = room.width / 2;
    int halfH = room.height / 2;

    // Create walls
    for (int x = room.x - halfW; x <= room.x + halfW; ++x) {
        for (int y = room.y - halfH; y <= room.y + halfH; ++y) {
            if (x >= 0 && x < boardSizeX && y >= 0 && y < boardSizeY) {
                board[y][x] = '#';
            }
        }
    }

    // Create floor interior
    for (int x = room.x - halfW + 1; x < room.x + halfW; ++x) {
        for (int y = room.y - halfH + 1; y < room.y + halfH; ++y) {
            if (x >= 0 && x < boardSizeX && y >= 0 && y < boardSizeY) {
                board[y][x] = room.floorChar;
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
    if (room.type == RoomType::CORRIDOR) {
        return false;
    }
    int halfW = room.width / 2;
    int halfH = room.height / 2;

    // Check if player is within room boundaries
    return (playerX >= room.x - halfW + 1 && playerX < room.x + halfW &&
        playerY >= room.y - halfH + 1 && playerY < room.y + halfH &&
        FloorGrid[playerY][playerX] != '#' &&
        FloorGrid[playerY][playerX] != ' ' &&
        (FloorGrid[playerY][playerX] == '.' ||
            FloorGrid[playerY][playerX] == '$' ||
            FloorGrid[playerY][playerX] == 'B'
            ));  // Make sure it's not a wall
}

void Map::renderCurrentRoom(Room* room, char** roomBoard, int boardSize, Player& MC) {
    if (!room) return;

    int w = room->width;
    int h = room->height;

    // Local room buffer
    std::vector<std::string> roomBoardLC(h, std::string(w, ' '));

    // Draw walls and floor
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
                roomBoardLC[y][x] = '#';  // wall
            else
                roomBoardLC[y][x] = room->floorChar;  // floor
        }
    }

    // Calculate room bounds in world coordinates
    int roomLeftX = room->x - room->width / 2;
    int roomTopY = room->y - room->height / 2;

    // Add enemies to the room view
    for (const auto& enemy : room->enemies) {
        if (enemy.GetEnemyHP() > 0) {
            // Convert world coordinates to local room coordinates
            int localEnemyX = enemy.GetEnemyPosX() - roomLeftX;
            int localEnemyY = enemy.GetEnemyPosY() - roomTopY;

            // Check if enemy is within room bounds
            if (localEnemyX >= 0 && localEnemyX < w &&
                localEnemyY >= 0 && localEnemyY < h) {
                roomBoardLC[localEnemyY][localEnemyX] = getEnemyDisplayChar(enemy);
            }
        }
    }

    // Calculate player position relative to room top-left
    int localPlayerX = MC.GetPlayerPosX() - roomLeftX;
    int localPlayerY = MC.GetPlayerPosY() - roomTopY;

    // Add player (player overrides enemy if they're on same tile)
    if (localPlayerX >= 0 && localPlayerX < w && localPlayerY >= 0 && localPlayerY < h) {
        roomBoardLC[localPlayerY][localPlayerX] = 'P';
    }

    // Build frame buffer string
    std::string frameBuffer;
    frameBuffer += "Room View:\n";
    for (const auto& row : roomBoardLC) {
        frameBuffer += row + "\n";
    }

    // Add enemy info
    frameBuffer += "\nEnemies in room:\n";
    int aliveEnemies = 0;
    for (const auto& enemy : room->enemies) {
        if (enemy.GetEnemyHP() > 0) {
            aliveEnemies++;
            char enemyChar = getEnemyDisplayChar(enemy);
            frameBuffer += enemyChar;
            frameBuffer += " - ";
            frameBuffer += enemy.GetEnemyClass();
            frameBuffer += " (HP: ";
            frameBuffer += std::to_string(enemy.GetEnemyHP());
            frameBuffer += ")\n";
        }
    }
    if (aliveEnemies == 0) {
        frameBuffer += "Room cleared!\n";
    }

    // Move cursor to top-left and print
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = { 0, 0 };
    SetConsoleCursorPosition(hConsole, topLeft);
    std::cout << frameBuffer;
}

void Map::switchToRoomView(int playerX, int playerY, Player& MC, Shop& shop, bool& FinishShopping) {
    Room* playerRoom = detectPlayerRoom(playerX, playerY);

    if (playerRoom) {
        // Use InnerRoom as the isolated room view
        char* innerPtrs[256];
        for (int i = 0; i < 256; ++i) innerPtrs[i] = InnerRoom[i];

        renderCurrentRoom(playerRoom, innerPtrs, 256, MC);

        std::cout << "Entered " << getRoomTypeName(playerRoom->type) << " room!" << std::endl;
        //drawBoard(innerPtrs, 256, 256);  // Show just this room
        if (playerRoom->type == RoomType::SHOP) {
            //
            shop.SetShopItemSlot(MC, MC.GetInventory().GetItem());
            while (!FinishShopping) {
                shop.SetPlayerIsShopping(true);
                std::cout << shop.DrawShopUI(MC, MC.GetInventory().GetItem(), MC.GetInventory()) << std::endl;
                if (shop.PromptPlayerShopInteraction(MC, MC.GetInventory().GetItem(), MC.GetInventory()) == 0) {
                    FinishShopping = true;
                    system("cls");
                }
                else {
                    FinishShopping = false;
                    system("cls");
                }
            }
        }
    }
    else {
        std::cout << "Player is in a corridor or empty space." << std::endl;
    }

}

// Helper function to get room type names
std::string Map::getRoomTypeName(RoomType type) {
    switch (type) {
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

void Map::renderMapWithFOV(Player& MC, int viewWidth, int viewHeight) {
    int mapWidth = 128, mapHeight = 128;

    int topLeftX = MC.GetPlayerPosX() - viewWidth / 2;
    int topLeftY = MC.GetPlayerPosY() - viewHeight / 2;

    if (topLeftX < 0) topLeftX = 0;
    if (topLeftY < 0) topLeftY = 0;
    if (topLeftX + viewWidth > mapWidth) topLeftX = mapWidth - viewWidth;
    if (topLeftY + viewHeight > mapHeight) topLeftY = mapHeight - viewHeight;

    std::string frameBuffer;
    frameBuffer += '+';
    for (int x = 0; x < viewWidth; ++x) frameBuffer += '-';
    frameBuffer += "+\n";

    for (int y = 0; y < viewHeight; ++y) {
        frameBuffer += '|';
        for (int x = 0; x < viewWidth; ++x) {
            int mapX = topLeftX + x;
            int mapY = topLeftY + y;

            if (mapX == MC.GetPlayerPosX() && mapY == MC.GetPlayerPosY()) {
                frameBuffer += 'P';
            }
            else {
                // Check if there's an enemy at this position
                Enemy* enemyAtPos = getEnemyAtPosition(mapX, mapY);
                if (enemyAtPos && enemyAtPos->GetEnemyHP() > 0) {
                    frameBuffer += getEnemyDisplayChar(*enemyAtPos);
                }
                else {
                    frameBuffer += FloorGrid[mapY][mapX];
                }
            }
        }
        frameBuffer += "|\n";
    }
    frameBuffer += '+';
    for (int x = 0; x < viewWidth; ++x) frameBuffer += '-';
    frameBuffer += "+\n";

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = { 0,0 };
    SetConsoleCursorPosition(hConsole, topLeft);

    std::cout << frameBuffer;
}


void Map::generateEnemiesForRoom(Room& room, int difficulty) {
    room.enemies.clear();
    room.enemiesCleared = false;

    // Don't spawn enemies in shops or corridors
    if (room.type == RoomType::SHOP || room.type == RoomType::CORRIDOR) {
        return;
    }

    // Handle miniboss placement (every floor) - but don't return early!
    bool isMinibossRoom = false;
    if (!minibossGenerated && (room.type == RoomType::TREASURE ||
        room.type == RoomType::MEDIUM ||
        room.type == RoomType::LARGE)) {
        Enemy miniboss;
        generateBossForRoom(miniboss, "Miniboss", difficulty);

        // Position the miniboss at room center
        miniboss.SetEnemyPos(room.x, room.y);

        room.enemies.push_back(miniboss);
        minibossGenerated = true;
        minibossRoom = &room;
        isMinibossRoom = true;

        std::cout << "Generated MINIBOSS in " << getRoomTypeName(room.type)
            << " room #" << room.id << " at (" << room.x << "," << room.y << ")" << std::endl;

        // Don't return here - we can still add regular enemies!
    }

    // Handle true boss (difficulty 7+)
    if (difficulty >= 7 && !trueBossGenerated && !isMinibossRoom) {
        if ((isLastRoom(&room) && room.type != RoomType::SHOP) ||
            room.type == RoomType::LARGE) {
            Enemy trueBoss;
            generateBossForRoom(trueBoss, "TrueBoss", difficulty);

            // Position the true boss at room center
            trueBoss.SetEnemyPos(room.x, room.y);

            room.enemies.push_back(trueBoss);
            trueBossGenerated = true;
            trueBossRoom = &room;

            std::cout << "Generated TRUE BOSS in " << getRoomTypeName(room.type)
                << " room #" << room.id << " at (" << room.x << "," << room.y << ")" << std::endl;
            return; // True boss rooms only have the boss
        }
    }

    // Determine max regular enemies for this room type
    int maxEnemies = 0;
    switch (room.type) {
    case RoomType::SMALL:
        maxEnemies = (difficulty >= 2) ? 2 : 1;
        break;
    case RoomType::MEDIUM:
        maxEnemies = 2;
        break;
    case RoomType::LARGE:
        maxEnemies = (difficulty >= 3) ? 3 : 2;
        break;
    case RoomType::TREASURE:
        maxEnemies = (difficulty >= 1) ? 2 : 1;
        break;
    default:
        maxEnemies = 1;
        break;
    }

    // Reduce regular enemies if there's already a miniboss
    if (isMinibossRoom) {
        maxEnemies = std::max(0, maxEnemies - 1);
    }

    // At difficulty 7+, reduce regular enemy spawns slightly
    if (difficulty >= 7) {
        maxEnemies = std::max(1, maxEnemies - 1);
    }

    // FIXED: Ensure at least 1 enemy in non-boss rooms (unless it's a miniboss room)
    int numEnemies;
    if (maxEnemies <= 0) {
        numEnemies = 0;
    }
    else if (isMinibossRoom) {
        // Miniboss rooms can have 0-maxEnemies additional enemies
        numEnemies = std::rand() % (maxEnemies + 1);
    }
    else {
        // Regular rooms always have at least 1 enemy
        numEnemies = 1 + (std::rand() % maxEnemies);
    }

    // Generate regular enemies
    for (int i = 0; i < numEnemies; ++i) {
        Enemy newEnemy;
        generateEnemyForRoom(newEnemy, room, difficulty, i);
        room.enemies.push_back(newEnemy);
    }

    if (numEnemies > 0 || isMinibossRoom) {
        std::cout << "Generated " << numEnemies << " regular enemies";
        if (isMinibossRoom) std::cout << " + 1 miniboss";
        std::cout << " for " << getRoomTypeName(room.type) << " room #" << room.id << std::endl;
    }
}

void Map::generateEnemyForRoom(Enemy& enemy, const Room& room, int difficulty, int enemyIndex) {
    enemy.InitEnemy();

    // Base stats scaling with difficulty
    int baseHP = 40;
    int basePower = 5;
    int baseCrit = 5;
    int baseXP = 10;
    int baseCurrency = 5;

    // Room type modifiers
    float hpMultiplier = 1.0f;
    float powerMultiplier = 1.0f;

    switch (room.type) {
    case RoomType::TREASURE:
        hpMultiplier = 1.5f;
        powerMultiplier = 1.3f;
        break;
    case RoomType::LARGE:
        hpMultiplier = 1.2f;
        powerMultiplier = 1.1f;
        break;
    case RoomType::MEDIUM:
        hpMultiplier = 1.1f;
        break;
    default:
        break;
    }

    int finalHP = static_cast<int>(baseHP * hpMultiplier);
    int finalPower = static_cast<int>(basePower * powerMultiplier);

    // Choose enemy class based on difficulty
    std::vector<std::string> enemyClasses;
    enemyClasses.push_back("Grunt");

    if (difficulty >= 1) {
        enemyClasses.push_back("Grunt");
        enemyClasses.push_back("Rogue");
    }

    if (difficulty >= 2) {
        enemyClasses.push_back("Necromancer");
        enemyClasses.push_back("Silent");
    }

    if (difficulty >= 3) {
        enemyClasses.push_back("Mani");
        enemyClasses.push_back("Cleaver");
    }

    if (difficulty >= 4) {
        enemyClasses.push_back("Resonant");
        enemyClasses.push_back("ColorCleaver");
    }

    if (difficulty >= 5) {
        enemyClasses.push_back("DarkSilence");
        enemyClasses.push_back("ManiKatti");
    }

    if (difficulty >= 6) {
        enemyClasses.push_back("AzureResonance");
    }

    std::string chosenClass = enemyClasses[std::rand() % enemyClasses.size()];

    enemy.SetEnemyClass(chosenClass);
    enemy.SetEnemyMaxHP(finalHP);
    enemy.SetEnemyHP(finalHP);
    enemy.SetEnemyPower(finalPower);
    enemy.SetEnemyCritChance(baseCrit);
    enemy.SetEnemyXP(baseXP);
    enemy.SetEnemyCurrency(baseCurrency);
    enemy.SetEnemyLvl(difficulty + 1);

    // FIXED: Position within room interior only, and validate it's on a floor tile
    int halfW = room.width / 2;
    int halfH = room.height / 2;
    int attempts = 0;
    int enemyX, enemyY;

    do {
        // Calculate interior bounds (avoid walls)
        enemyX = room.x - halfW + 1 + (std::rand() % (room.width - 2));
        enemyY = room.y - halfH + 1 + (std::rand() % (room.height - 2));
        attempts++;

        // Safety check to avoid infinite loop
        if (attempts > 50) {
            // Fallback to room center if we can't find a good spot
            enemyX = room.x;
            enemyY = room.y;
            break;
        }
    } while (enemyX < 0 || enemyX >= 128 || enemyY < 0 || enemyY >= 128 ||
        (FloorGrid[enemyY][enemyX] != room.floorChar &&
            FloorGrid[enemyY][enemyX] != '.' &&
            FloorGrid[enemyY][enemyX] != '$' &&
            FloorGrid[enemyY][enemyX] != 'B'));

    enemy.SetEnemyPos(enemyX, enemyY);

    setEnemyEquipment(enemy, chosenClass, difficulty);

    // Debug output
    std::cout << "Placed " << chosenClass << " at (" << enemyX << "," << enemyY
        << ") in room at (" << room.x << "," << room.y << ")" << std::endl;
}

void Map::generateBossForRoom(Enemy& enemy, const std::string& bossType, int difficulty) {
    enemy.InitEnemy();

    if (bossType == "Miniboss") {
        int bossChoice = std::rand() % 4;

        switch (bossChoice) {
        case 0:
            enemy.SetEnemyClass("ColorCleaver");
            break;
        case 1:
            enemy.SetEnemyClass("DarkSilence");
            break;
        case 2:
            enemy.SetEnemyClass("ManiKatti");
            break;
        case 3:
            enemy.SetEnemyClass("AzureResonance");
            break;
        }

        // Enhanced miniboss stats
        int baseHP = 80 + (difficulty * 20);
        int basePower = 12 + (difficulty * 3);

        enemy.SetEnemyMaxHP(baseHP);
        enemy.SetEnemyHP(baseHP);
        enemy.SetEnemyPower(basePower);
        enemy.SetEnemyCritChance(15 + difficulty);
        enemy.SetEnemyXP(50 + difficulty * 10);
        enemy.SetEnemyCurrency(25 + difficulty * 5);
        enemy.SetEnemyLvl(difficulty + 3);

        setEnemyEquipment(enemy, enemy.GetEnemyClass(), difficulty);

        std::cout << "MINIBOSS STATS: " << enemy.GetEnemyClass()
            << " (HP: " << enemy.GetEnemyMaxHP()
            << ", Power: " << enemy.GetEnemyPower() << ")" << std::endl;
    }
    else if (bossType == "TrueBoss") {
        int bossChoice = std::rand() % 5;

        switch (bossChoice) {
        case 0:
            enemy.SetEnemyClass("OneWingedAngel");
            break;
        case 1:
            enemy.SetEnemyClass("JovialChaos");
            break;
        case 2:
            enemy.SetEnemyClass("Bob");
            break;
        case 3:
            enemy.SetEnemyClass("DevilGene");
            break;
        case 4:
            enemy.SetEnemyClass("Susanoo");
            break;
        }

        int baseHP = 200 + (difficulty * 50);
        int basePower = 25 + (difficulty * 5);

        enemy.SetEnemyMaxHP(baseHP);
        enemy.SetEnemyHP(baseHP);
        enemy.SetEnemyPower(basePower);
        enemy.SetEnemyCritChance(25 + difficulty);
        enemy.SetEnemyXP(200 + difficulty * 20);
        enemy.SetEnemyCurrency(100 + difficulty * 15);
        enemy.SetEnemyLvl(difficulty + 5);

        setEnemyEquipment(enemy, enemy.GetEnemyClass(), difficulty);

        std::cout << "TRUE BOSS STATS: " << enemy.GetEnemyClass()
            << " (HP: " << enemy.GetEnemyMaxHP()
            << ", Power: " << enemy.GetEnemyPower() << ")" << std::endl;
    }
}

void Map::setEnemyEquipment(Enemy& enemy, const std::string& enemyClass, int difficulty)
{
    if (enemyClass == "Grunt") {
        enemy.SetEnemyEquippedWeapon("Rusty Iron Sword");
        enemy.SetEnemyEquippedArmor("Ragged Clothing");
    }
    else if (enemyClass == "Rogue") {
        enemy.SetEnemyEquippedWeapon("Rusty Iron Dagger");
        enemy.SetEnemyEquippedArmor("Ragged Clothing");
    }
    else if (enemyClass == "Necromancer") {
        enemy.SetEnemyEquippedWeapon("Steel Staff");
        enemy.SetEnemyEquippedArmor("Tough Leather Tunic");
    }
    else if (enemyClass == "Silent") {
        enemy.SetEnemyEquippedWeapon("Steel Longsword");
        enemy.SetEnemyEquippedArmor("Tough Leather Tunic");
    }
    else if (enemyClass == "Cleaver") {
        enemy.SetEnemyEquippedWeapon("Adamantite Heavyblade");
        enemy.SetEnemyEquippedArmor("Chainmail Chestplate");
    }
    else if (enemyClass == "Mani") {
        enemy.SetEnemyEquippedWeapon("Bloodstone Totem");
        enemy.SetEnemyEquippedArmor("Chainmail Chestplate");
    }
    else if (enemyClass == "Resonant") {
        enemy.SetEnemyEquippedWeapon("Titanium Dagger");
        enemy.SetEnemyEquippedArmor("Chainmail Chestplate");
    }
    else if (enemyClass == "ColorCleaver") {
        enemy.SetEnemyEquippedWeapon("Enchanted Greatsword");
        enemy.SetEnemyEquippedArmor("Knight's Chestplate");
    }
    else if (enemyClass == "DarkSilence") {
        enemy.SetEnemyEquippedWeapon("Enchanted Greatsword");
        enemy.SetEnemyEquippedArmor("Knight's Chestplate");
    }
    else if (enemyClass == "ManiKatti") {
        enemy.SetEnemyEquippedWeapon("Infernal Flare Totem");
        enemy.SetEnemyEquippedArmor("Knight's Chestplate");
    }
    else if (enemyClass == "AzureResonance") {
        enemy.SetEnemyEquippedWeapon("Zephyrous Dagger of the Acrobat");
        enemy.SetEnemyEquippedArmor("Chainmail Chestplate");
    }
    else if (enemyClass == "OneWingedAngel") {
        enemy.SetEnemyEquippedWeapon("Derelictus");
        enemy.SetEnemyEquippedArmor("Titanic Chestplate of the Colossal");
    }
    else if (enemyClass == "JovialChaos") {
        enemy.SetEnemyEquippedWeapon("Providence");
        enemy.SetEnemyEquippedArmor("Titanic Chestplate of the Colossal");
    }
    else if (enemyClass == "Bob") {
        enemy.SetEnemyEquippedWeapon("Annihilation");
        enemy.SetEnemyEquippedArmor("Titanic Chestplate of the Colossal");
    }
    else if (enemyClass == "DevilGene") {
        enemy.SetEnemyEquippedWeapon("Resonance");
        enemy.SetEnemyEquippedArmor("Titanic Chestplate of the Colossal");
    }
    else if (enemyClass == "Susanoo") {
        enemy.SetEnemyEquippedWeapon("Celestial");
        enemy.SetEnemyEquippedArmor("Titanic Chestplate of the Colossal");
    }
    else {
        enemy.SetEnemyEquippedWeapon("None");
        enemy.SetEnemyEquippedArmor("None");
    }
}

char Map::getEnemyDisplayChar(const Enemy& enemy) {
    std::string enemyClass = enemy.GetEnemyClass();

    // Boss characters
    if (enemyClass == "OneWingedAngel" || enemyClass == "JovialChaos" || enemyClass == "Bob" || enemyClass == "Susanoo" || enemyClass == "DevilGene") {
        return '?';
    }
    else if (enemyClass == "ColorCleaver" || enemyClass == "DarkSilence" || enemyClass == "ManiKatti" || enemyClass == "AzureResonance") {
        return 'M';
    }
    else {
        return 'E';
    }
}

std::vector<Enemy*> Map::getEnemiesInRoom(Room* room) {
    std::vector<Enemy*> enemyPtrs;
    if (room) {
        for (auto& enemy : room->enemies) {
            if (enemy.GetEnemyHP() > 0) {
                enemyPtrs.push_back(&enemy);
            }
        }
    }
    return enemyPtrs;
}

bool Map::isRoomEnemiesCleared(Room* room) {
    if (!room) return true;

    for (const auto& enemy : room->enemies) {
        if (enemy.GetEnemyHP() > 0) {
            return false;
        }
    }
    room->enemiesCleared = true;
    return true;
}

void Map::removeDefeatedEnemies() {
    for (auto& room : rooms) {
        // Remove enemies with HP <= 0 from the vector
        room.enemies.erase(
            std::remove_if(room.enemies.begin(), room.enemies.end(),
                [](const Enemy& enemy) { return enemy.GetEnemyHP() <= 0; }),
            room.enemies.end()
        );
    }
}

Enemy* Map::getEnemyAtPosition(int x, int y) {
    // Check room enemies first
    for (auto& room : rooms) {
        for (auto& enemy : room.enemies) {
            if (enemy.GetEnemyHP() > 0 &&
                enemy.GetEnemyPosX() == x &&
                enemy.GetEnemyPosY() == y) {
                return &enemy;
            }
        }
    }

    // Check roaming enemies
    return getRoamingEnemyAtPosition(x, y);
}
bool Map::checkForCombat(Room* room, Player& MC) {
    if (!room || room->enemiesCleared) {
        return false;
    }

    Enemy* enemyAtPlayerPos = getEnemyAtPosition(MC.GetPlayerPosX(), MC.GetPlayerPosY());

    if (enemyAtPlayerPos && enemyAtPlayerPos->GetEnemyHP() > 0) {
        std::string enemyClass = enemyAtPlayerPos->GetEnemyClass();

        if (enemyClass == "OneWingedAngel" || enemyClass == "JovialChaos" || enemyClass == "Bob" || enemyClass == "Susanoo" || enemyClass == "DevilGene") {
            std::cout << "\n!!! TRUE BOSS ENCOUNTER !!!" << std::endl;
            std::cout << "The final challenge awaits..." << std::endl;
        }
        else if (enemyClass == "ColorCleaver" || enemyClass == "DarkSilence" || enemyClass == "ManiKatti" || enemyClass == "AzureResonance") {
            std::cout << "\n!!! MINIBOSS ENCOUNTER !!!" << std::endl;
            std::cout << "A powerful guardian blocks your path..." << std::endl;
        }
        else {
            std::cout << "\nEnemy encountered: " << enemyClass << "!" << std::endl;
        }

        std::cout << "Press any key to engage!" << std::endl;
        int chP = _getch();
        system("cls");

        Combat combat;
        combat.InitCombat(MC, *enemyAtPlayerPos);

        if (enemyAtPlayerPos->GetEnemyHP() <= 0) {
            removeDefeatedEnemies();

            if (enemyClass == "OneWingedAngel" || enemyClass == "JovialChaos") {
                std::cout << "\n!!! TRUE BOSS DEFEATED !!!" << std::endl;
                std::cout << "Victory is yours!" << std::endl;
            }
            else if (enemyClass == "Guardian Elite") {
                std::cout << "\n!!! MINIBOSS DEFEATED !!!" << std::endl;
                std::cout << "The guardian has fallen!" << std::endl;
            }
        }
        isRoomEnemiesCleared(room);

        return true;
    }

    return false;
}

void Map::generateRoamingEnemies(int difficulty) {
    roamingEnemies.clear();

    // Determine number of roaming enemies based on difficulty
    int numRoamingEnemies = 3 + (difficulty);  // 2-5 enemies typically
    if (numRoamingEnemies > 10) numRoamingEnemies = 10;  // Cap at 8

    std::cout << "Generating " << numRoamingEnemies << " roaming enemies..." << std::endl;

    for (int i = 0; i < numRoamingEnemies; ++i) {
        Enemy roamingEnemy;
        generateRoamingEnemy(roamingEnemy, difficulty);
        roamingEnemies.push_back(roamingEnemy);
    }
}

void Map::generateRoamingEnemy(Enemy& enemy, int difficulty) {
    enemy.InitEnemy();

    int baseHP = 25 + (difficulty * 8);
    int basePower = 3 + (difficulty * 2);

    std::vector<std::string> roamingClasses = { "Grunt", "Rogue" };

    if (difficulty >= 2) {
        roamingClasses.push_back("Necromancer");
    }
    if (difficulty >= 3) {
        roamingClasses.push_back("Silent");
    }

    std::string chosenClass = roamingClasses[std::rand() % roamingClasses.size()];

    enemy.SetEnemyClass(chosenClass);
    enemy.SetEnemyMaxHP(baseHP);
    enemy.SetEnemyHP(baseHP);
    enemy.SetEnemyPower(basePower);
    enemy.SetEnemyCritChance(5);
    enemy.SetEnemyXP(8);
    enemy.SetEnemyCurrency(3);
    enemy.SetEnemyLvl(difficulty);

    setEnemyEquipment(enemy, chosenClass, difficulty);

    // Position enemy in corridor space (not in any room)
    int attempts = 0;
    int enemyX, enemyY;

    do {
        enemyX = std::rand() % 128;
        enemyY = std::rand() % 128;
        attempts++;

        if (attempts > 100) {
            // Fallback to a known corridor spot
            enemyX = 64;
            enemyY = 64;
            break;
        }
    } while (enemyX < 0 || enemyX >= 128 || enemyY < 0 || enemyY >= 128 ||
        FloorGrid[enemyY][enemyX] != ' ' ||  // Only spawn in empty space
        isPositionInAnyRoom(enemyX, enemyY)); // Don't spawn inside rooms

    enemy.SetEnemyPos(enemyX, enemyY);

    std::cout << "Roaming " << chosenClass << " placed at ("
        << enemyX << "," << enemyY << ")" << std::endl;
}

bool Map::isPositionInAnyRoom(int x, int y) {
    for (const auto& room : rooms) {
        if (isPlayerInRoom(x, y, room)) {
            return true;
        }
    }
    return false;
}

std::vector<Enemy*> Map::getRoamingEnemies() {
    std::vector<Enemy*> alivePtrs;
    for (auto& enemy : roamingEnemies) {
        if (enemy.GetEnemyHP() > 0) {
            alivePtrs.push_back(&enemy);
        }
    }
    return alivePtrs;
}

void Map::removeDefeatedRoamingEnemies() {
    roamingEnemies.erase(
        std::remove_if(roamingEnemies.begin(), roamingEnemies.end(),
            [](const Enemy& enemy) { return enemy.GetEnemyHP() <= 0; }),
        roamingEnemies.end()
    );
}

Enemy* Map::getRoamingEnemyAtPosition(int x, int y) {
    for (auto& enemy : roamingEnemies) {
        if (enemy.GetEnemyHP() > 0 &&
            enemy.GetEnemyPosX() == x &&
            enemy.GetEnemyPosY() == y) {
            return &enemy;
        }
    }
    return nullptr;
}

bool Map::checkForRoamingCombat(Player& MC) {
    Enemy* roamingEnemy = getRoamingEnemyAtPosition(MC.GetPlayerPosX(), MC.GetPlayerPosY());

    if (roamingEnemy && roamingEnemy->GetEnemyHP() > 0) {
        std::cout << "\nRoaming enemy encountered: " << roamingEnemy->GetEnemyClass() << "!" << std::endl;
        std::cout << "Press any key to engage!" << std::endl;
        int chP = _getch();
        system("cls");

        Combat combat;
        combat.InitCombat(MC, *roamingEnemy);

        if (roamingEnemy->GetEnemyHP() <= 0) {
            removeDefeatedRoamingEnemies();
        }

        return true;
    }

    return false;
}

std::vector<std::pair<int, int>> Map::findPathAStar(int startX, int startY, int goalX, int goalY, int maxDistance) {
    std::vector<std::pair<int, int>> path;

    if (startX == goalX && startY == goalY) {
        return path;
    }

    if (calculateManhattanDistance(startX, startY, goalX, goalY) > maxDistance) {
        return path;
    }

    std::priority_queue<AStarNode> openSet;

    std::vector<std::vector<bool>> closedSet(128, std::vector<bool>(128, false));

    std::vector<std::unique_ptr<AStarNode>> nodeStorage;

    std::vector<std::vector<AStarNode*>> nodeGrid(128, std::vector<AStarNode*>(128, nullptr));

    auto startNode = std::make_unique<AStarNode>(startX, startY);
    startNode->gCost = 0;
    startNode->hCost = calculateHeuristic(startX, startY, goalX, goalY);
    startNode->fCost = startNode->hCost;

    AStarNode* startPtr = startNode.get();
    nodeGrid[startY][startX] = startPtr;
    nodeStorage.push_back(std::move(startNode));
    openSet.push(*startPtr);

    int nodesEvaluated = 0;
    const int MAX_NODES = 200;

    while (!openSet.empty() && nodesEvaluated < MAX_NODES) {
        AStarNode current = openSet.top();
        openSet.pop();
        nodesEvaluated++;

        if (closedSet[current.y][current.x]) {
            continue;
        }

        closedSet[current.y][current.x] = true;

        if (current.x == goalX && current.y == goalY) {
            AStarNode* pathNode = nodeGrid[current.y][current.x];
            while (pathNode && pathNode->parent) {
                path.push_back({ pathNode->x, pathNode->y });
                pathNode = pathNode->parent;
            }

            std::reverse(path.begin(), path.end());
            return path;
        }

        int directions[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

        for (int i = 0; i < 4; ++i) {
            int newX = current.x + directions[i][0];
            int newY = current.y + directions[i][1];

            if (!isValidPathPosition(newX, newY) || closedSet[newY][newX]) {
                continue;
            }

            int tentativeGCost = nodeGrid[current.y][current.x]->gCost + 1;

            AStarNode* neighborNode = nodeGrid[newY][newX];

            if (!neighborNode) {
                auto newNode = std::make_unique<AStarNode>(newX, newY);
                newNode->gCost = tentativeGCost;
                newNode->hCost = calculateHeuristic(newX, newY, goalX, goalY);
                newNode->fCost = newNode->gCost + newNode->hCost;
                newNode->parent = nodeGrid[current.y][current.x];

                neighborNode = newNode.get();
                nodeGrid[newY][newX] = neighborNode;
                nodeStorage.push_back(std::move(newNode));

                openSet.push(*neighborNode);
            }
            else if (tentativeGCost < neighborNode->gCost) {
                neighborNode->gCost = tentativeGCost;
                neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
                neighborNode->parent = nodeGrid[current.y][current.x];

                openSet.push(*neighborNode);
            }
        }
    }

    return path;
}

void Map::moveEnemyTowardsPlayer(Enemy& enemy, int playerX, int playerY) {
    int enemyX = enemy.GetEnemyPosX();
    int enemyY = enemy.GetEnemyPosY();

    // Calculate Manhattan distance to player
    int currentDistance = calculateManhattanDistance(enemyX, enemyY, playerX, playerY);

    // Don't move if already adjacent to player (let combat handle it)
    if (currentDistance <= 1) {
        return;
    }

    // Don't chase if player is too far away (avoid cross-map chasing)
    if (currentDistance > 15) {
        return;
    }

    int bestX = enemyX;
    int bestY = enemyY;
    int bestDistance = currentDistance;

    int directions[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

    for (int i = 0; i < 4; ++i) {
        int newX = enemyX + directions[i][0];
        int newY = enemyY + directions[i][1];

        if (isValidEnemyPosition(newX, newY)) {
            int newDistance = calculateManhattanDistance(newX, newY, playerX, playerY);

            if (newDistance < bestDistance) {
                bestX = newX;
                bestY = newY;
                bestDistance = newDistance;
            }
        }
    }

    if (bestX != enemyX || bestY != enemyY) {
        enemy.SetEnemyPos(bestX, bestY);
    }
}

int Map::calculateManhattanDistance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool Map::isValidEnemyPosition(int x, int y) {
    if (x < 0 || x >= 128 || y < 0 || y >= 128) {
        return false;
    }

    if (FloorGrid[y][x] == '#') {
        return false;
    }

    if (isPositionInAnyRoom(x, y)) {
        return false;
    }

    for (const auto& otherEnemy : roamingEnemies) {
        if (otherEnemy.GetEnemyHP() > 0 &&
            otherEnemy.GetEnemyPosX() == x &&
            otherEnemy.GetEnemyPosY() == y) {
            return false;
        }
    }

    return (FloorGrid[y][x] == ' ' || FloorGrid[y][x] == '.');
}

void Map::moveEnemyTowardsPlayerAStar(Enemy& enemy, int playerX, int playerY) {
    int enemyX = enemy.GetEnemyPosX();
    int enemyY = enemy.GetEnemyPosY();

    int currentDistance = calculateManhattanDistance(enemyX, enemyY, playerX, playerY);

    // Don't move if already adjacent
    if (currentDistance <= 1) {
        return;
    }

    std::vector<std::pair<int, int>> path = findPathAStar(enemyX, enemyY, playerX, playerY, 15);

    if (!path.empty()) {
        int nextX = path[0].first;
        int nextY = path[0].second;

        if (isValidEnemyPosition(nextX, nextY)) {
            enemy.SetEnemyPos(nextX, nextY);

            std::cout << "Enemy " << enemy.GetEnemyClass()
                << " following A* path to (" << nextX << "," << nextY
                << ") towards player at (" << playerX << "," << playerY << ")" << std::endl;
        }
    }
    else {
        moveEnemyTowardsPlayer(enemy, playerX, playerY);
    }
}

int Map::calculateHeuristic(int x1, int y1, int x2, int y2) {
  
    return abs(x1 - x2) + abs(y1 - y2);
}

bool Map::isValidPathPosition(int x, int y) {

    if (x < 0 || x >= 128 || y < 0 || y >= 128) {
        return false;
    }


    if (FloorGrid[y][x] == '#') {
        return false;
    }


    if (isPositionInAnyRoom(x, y)) {
        return false;
    }


    return (FloorGrid[y][x] == ' ' || FloorGrid[y][x] == '.');
}

void Map::updateRoamingEnemyAI(Player& MC) {
    enemyMoveCounter++;

    if (enemyMoveCounter >= 3) {
        enemyMoveCounter = 0;

        int playerX = MC.GetPlayerPosX();
        int playerY = MC.GetPlayerPosY();

        for (auto& enemy : roamingEnemies) {
            if (enemy.GetEnemyHP() > 0) {
                moveEnemyTowardsPlayerAStar(enemy, playerX, playerY);
            }
        }
    }
}