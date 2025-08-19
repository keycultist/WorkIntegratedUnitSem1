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