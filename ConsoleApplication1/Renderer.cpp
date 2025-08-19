#include "Renderer.h"

void Renderer::fillBoard(char** Board, int sizeX, int sizeY) {
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            Board[h][v] = ' ';
        }
    }
}