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
#define NOMINMAX
#include <windows.h> 

using namespace std;

void Map::CreateNewFloor(int Difficulty, Player& MC) {
    // Setup pointer arrays
    char* floorPtrs[128];
    char* innerPtrs[256];
    for (int i = 0; i < 128; ++i) floorPtrs[i] = FloorGrid[i];
    for (int i = 0; i < 256; ++i) innerPtrs[i] = InnerRoom[i];

    // Clear both boards
    fillBoard(floorPtrs, 128, 128, MC);
    fillBoard(innerPtrs, 256, 256, MC);

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
        for (auto& room : rooms) {
            generateEnemiesForRoom(room, Difficulty);
        }

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


}


void Map::renderEnemiesOnBoard(char** Board, int sizeX, int sizeY) {
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
    if (playerX >= 0 && playerX < sizeX && playerY >= 0 && playerY < sizeY) {
        Board[playerY][playerX] = 'P';
    }
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
    //if (!room) return;

    //fillBoard(roomBoard, boardSize, boardSize, MC);
    //std::cout << "AAAAAAAAAAAAAAA" << std::endl;

    //int scale = 8;  // Scale factor for detailed view
    //int scaledWidth = room->width * scale;
    //int scaledHeight = room->height * scale;
    //int centerX = boardSize / 2;
    //int centerY = boardSize / 2;

    //// Render scaled-up version centered on roomBoard
    //for (int x = 0; x < scaledWidth; ++x) {
    //    for (int y = 0; y < scaledHeight; ++y) {
    //        int roomBoardX = centerX - scaledWidth / 2 + x;
    //        int roomBoardY = centerY - scaledHeight / 2 + y;

    //        if (roomBoardX >= 0 && roomBoardX < boardSize && roomBoardY >= 0 && roomBoardY < boardSize) {
    //            // Determine what this scaled pixel should be
    //            int originalX = x / scale;
    //            int originalY = y / scale;

    //            if (originalX == 0 || originalX == room->width - 1 || originalY == 0 || originalY == room->height - 1) {
    //                roomBoard[roomBoardX][roomBoardY] = '#';  // Wall
    //            }
    //            else {
    //                roomBoard[roomBoardX][roomBoardY] = room->floorChar;  // Floor
    //            }
    //        }
    //    }
    //}

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

    // Calculate player position relative to room top-left
    int localX = MC.GetPlayerPosX() - (room->x - room->width / 2);
    int localY = MC.GetPlayerPosY() - (room->y - room->height / 2);

    // Clamp to interior
    if (localX >= 1 && localX < w - 1 && localY >= 1 && localY < h - 1) {
        roomBoardLC[localY][localX] = 'P';
    }

    // Build frame buffer string
    std::string frameBuffer;
    frameBuffer += "Room View:\n";
    for (const auto& row : roomBoardLC) {
        frameBuffer += row + "\n";
    }

    // Move cursor to top-left and print
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD topLeft = { 0, 0 };
    SetConsoleCursorPosition(hConsole, topLeft);
    std::cout << frameBuffer;
}

void Map::switchToRoomView(int playerX, int playerY, Player& MC, Shop& shop) {
    Room* playerRoom = detectPlayerRoom(playerX, playerY);
    
    if (playerRoom) {
        // Use InnerRoom as the isolated room view
        char* innerPtrs[256];
        for (int i = 0; i < 256; ++i) innerPtrs[i] = InnerRoom[i];
        
        renderCurrentRoom(playerRoom, innerPtrs, 256, MC);
        
        std::cout << "Entered " << getRoomTypeName(playerRoom->type) << " room!" << std::endl;
        //drawBoard(innerPtrs, 256, 256);  // Show just this room
        if (playerRoom->type == RoomType::SHOP) {
            shop.DrawShopUI();
        }
    } else {
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

void Map::renderMapWithFOV(Player& MC, int viewWidth = 40, int viewHeight = 20) {
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

            if (mapX == MC.GetPlayerPosX() && mapY == MC.GetPlayerPosY())
                frameBuffer += 'P';
            else
                frameBuffer += FloorGrid[mapY][mapX];
        }
        frameBuffer += "|\n";
    }
    frameBuffer += '+';
    for (int x = 0; x < viewWidth; ++x) frameBuffer += '-';
    frameBuffer += "+\n";
    frameBuffer += "Current Position: ";
    frameBuffer += std::to_string(MC.GetPlayerPosX());
    frameBuffer += ',';
    frameBuffer += std::to_string(MC.GetPlayerPosY());

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

    // Handle miniboss placement (every floor)
    if (!minibossGenerated && (room.type == RoomType::TREASURE ||
        room.type == RoomType::MEDIUM ||
        room.type == RoomType::LARGE)) {
        Enemy miniboss;
        generateBossForRoom(miniboss, "Miniboss", difficulty);
        room.enemies.push_back(miniboss);
        minibossGenerated = true;
        minibossRoom = &room;
        std::cout << "Generated MINIBOSS in " << getRoomTypeName(room.type)
            << " room #" << room.id << std::endl;
        return;
    }

    if (difficulty >= 7) {
        if (!trueBossGenerated && (isLastRoom(&room) && room.type != RoomType::SHOP ||
            room.type == RoomType::LARGE)) {
            Enemy trueBoss;
            generateBossForRoom(trueBoss, "TrueBoss", difficulty);
            room.enemies.push_back(trueBoss);
            trueBossGenerated = true;
            trueBossRoom = &room;
            std::cout << "Generated TRUE BOSS in " << getRoomTypeName(room.type)
                << " room #" << room.id << std::endl;
            return;
        }
    }

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

    // At difficulty 7+, reduce regular enemy spawns slightly to balance with bosses
    if (difficulty >= 7) {
        maxEnemies = std::max(1, maxEnemies - 1);
    }

    // Random number of enemies (0 to maxEnemies)
    int numEnemies = std::rand() % (maxEnemies + 1);

    // Generate enemies
    for (int i = 0; i < numEnemies; ++i) {
        Enemy newEnemy;
        generateEnemyForRoom(newEnemy, room, difficulty, i);
        room.enemies.push_back(newEnemy);
    }

    if (numEnemies > 0) {
        std::cout << "Generated " << numEnemies << " enemies for "
            << getRoomTypeName(room.type) << " room #" << room.id << std::endl;
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

    // Position within room
    int enemyX = room.x + (std::rand() % (room.width - 2)) - (room.width / 2) + 1;
    int enemyY = room.y + (std::rand() % (room.height - 2)) - (room.height / 2) + 1;
    enemy.SetEnemyPos(enemyX, enemyY);

    setEnemyEquipment(enemy, chosenClass, difficulty);
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

void Map::generateBossForRoom(Enemy& enemy, const std::string& bossType, int difficulty) {
    enemy.InitEnemy();

    if (bossType == "Miniboss") {
        int bossChoice = std::rand() % 3;

        switch (bossChoice) {
        case 0:
            enemy.SetEnemyClass("ColorCleaver");
        case 1:
            enemy.SetEnemyClass("DarkSilence");
        case 2:
            enemy.SetEnemyClass("ManiKatti");
        case 3:
            enemy.SetEnemyClass("AzureResonance");
        }

        setEnemyEquipment(enemy, enemy.GetEnemyClass(), difficulty);

        std::cout << "MINIBOSS GENERATED: " << enemy.GetEnemyClass()
            << " (HP: " << enemy.GetEnemyMaxHP()
            << ", Power: " << enemy.GetEnemyPower() << ")" << std::endl;
    }
    else if (bossType == "TrueBoss") {
        // True boss stats - matches your existing boss classes
        int bossChoice = std::rand() % 4; // Choose between the two boss types

        switch (bossChoice) {
        case 0:
            enemy.SetEnemyClass("OneWingedAngel");
        case 1:
            enemy.SetEnemyClass("JovialChaos");
        case 2:
            enemy.SetEnemyClass("Bob");
        case 3:
            enemy.SetEnemyClass("DevilGene");
        case 4:
            enemy.SetEnemyClass("Susanoo");
        }

        setEnemyEquipment(enemy, enemy.GetEnemyClass(), difficulty);

        std::cout << "TRUE BOSS GENERATED: " << enemy.GetEnemyClass()
            << " (HP: " << enemy.GetEnemyMaxHP()
            << ", Power: " << enemy.GetEnemyPower() << ")" << std::endl;
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
    for (auto& room : rooms) {
        for (auto& enemy : room.enemies) {
            if (enemy.GetEnemyHP() > 0 &&
                enemy.GetEnemyPosX() == x &&
                enemy.GetEnemyPosY() == y) {
                return &enemy;
            }
        }
    }
    return nullptr;
}