#include "Map.h"
#include "Renderer.h"

void Map::CreateNewFloor(int Difficulty) {
	
}

void Map::RequestFloorUpdate() const {

}

void Map::fillBoard(char** Board, int sizeX, int sizeY)
{
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            Board[h][v] = ' ';
        }
    }
}