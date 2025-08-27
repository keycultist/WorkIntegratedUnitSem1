#pragma once
#include <string>

class Renderer {
public:
    virtual void fillBoard(char** board, int sizeX, int sizeY);

    virtual void drawBoard(char** board, int sizeX, int sizeY);

    virtual void drawASCII(std::string asciiArt);
protected:

private:
    int tilesFilled;
};