#include "Renderer.h"
#include <iostream>
#include <string>
#include <cctype>
#include <random>
#include <vector>
#include <algorithm>
#include <conio.h> 
#include <windows.h>
#include <chrono>

using namespace std;

void Renderer::fillBoard(char** board, int sizeX, int sizeY) {
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            board[h][v] = ' ';
        }
    }


}

void Renderer::drawBoard(char** Board, int sizeX, int sizeY) {
    std::cout << "+---------------------------------------+" << endl;
    for (int h = 0; h < sizeX; ++h) {
        for (int v = 0; v < sizeY; ++v) {
            std::cout << Board[h][v];
        }
        std::cout << endl;
    }
    std::cout << "+---------------------------------------+" << endl;
}

void Renderer::drawASCII(std::string asciiArt) {
    std::cout << asciiArt << std::endl;
}