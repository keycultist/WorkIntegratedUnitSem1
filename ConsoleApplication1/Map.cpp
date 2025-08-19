#include "Map.h"
#include "Renderer.h"

using namespace std;

void Map::CreateNewFloor(int Difficulty) {
    char* floorPointers[128];
    for (int i = 0; i < 128; ++i) {
        floorPointers[i] = FloorGrid[i]; 
    }
    fillBoard(floorPointers, 128, 128);

    std::vector<std::pair<int, int>> possibleNodes;

    int spacing = 30;
    int offset = 15;

    for (int row = 0; row < 4; ++row) {
        for (int col = 0; col < 4; ++col) {
            int x = offset + col * spacing;
            int y = offset + row * spacing;
            possibleNodes.push_back({ x, y });
        }
    }
       
    std::srand(std::time(nullptr));

    int numRooms = std::min(1 + Difficulty * 2, (int)possibleNodes.size());

    for (int i = possibleNodes.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(possibleNodes[i], possibleNodes[j]);
    }

    for (int i = 0; i < numRooms; ++i) {
        int x = possibleNodes[i].first;
        int y = possibleNodes[i].second;

        // Create a room (7x7 outer walls)
        for (int roomX = x - 3; roomX <= x + 3 && roomX < 128; ++roomX) {
            for (int roomY = y - 3; roomY <= y + 3 && roomY < 128; ++roomY) {
                if (roomX >= 0 && roomY >= 0) {
                    FloorGrid[roomX][roomY] = '#';  // Wall
                }
            }
        }

        // Create floor space inside (5x5)
        for (int roomX = x - 2; roomX <= x + 2 && roomX < 127; ++roomX) {
            for (int roomY = y - 2; roomY <= y + 2 && roomY < 127; ++roomY) {
                if (roomX >= 1 && roomY >= 1) {
                    FloorGrid[roomX][roomY] = '.';  // Floor
                }
            }
        }
    }

    // Add connecting corridors between adjacent rooms
    for (int i = 0; i < numRooms - 1; ++i) {
        int startX = possibleNodes[i].first;
        int startY = possibleNodes[i].second;
        int endX = possibleNodes[i + 1].first;
        int endY = possibleNodes[i + 1].second;

        // Create L-shaped corridor
        // Horizontal line
        int minX = std::min(startX, endX);
        int maxX = std::max(startX, endX);
        for (int x = minX; x <= maxX && x < 128; ++x) {
            if (x >= 0) {
                FloorGrid[x][startY] = '.';
            }
        }

        // Vertical line
        int minY = std::min(startY, endY);
        int maxY = std::max(startY, endY);
        for (int y = minY; y <= maxY && y < 128; ++y) {
            if (y >= 0) {
                FloorGrid[endX][y] = '.';
            }
        }
    }

    if (numRooms > 0) {
        // Mark entrance
        FloorGrid[possibleNodes[0].first][possibleNodes[0].second] = 'S'; // Start

        // Mark exit
        if (numRooms > 1) {
            FloorGrid[possibleNodes[numRooms - 1].first][possibleNodes[numRooms - 1].second] = 'E'; // Exit
        }
    }
}

void Map::RequestFloorUpdate() {
    char* floorPointers[128];
    for (int i = 0; i < 128; ++i) {
        floorPointers[i] = FloorGrid[i];
    }

    drawBoard(floorPointers, 128, 128);
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