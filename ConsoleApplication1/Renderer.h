#pragma once

class Renderer {
public:
    virtual void fillBoard(char** board, int sizeX, int sizeY);
    
    virtual void drawBoard(char** board, int sizeX, int sizeY);
protected:

private:
    int tilesFilled;
};