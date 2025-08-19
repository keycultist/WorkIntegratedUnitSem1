#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Renderer.h"

class Map : public Renderer
{

private:
    char FloorGrid[128][128];
    int tilesFilled;
    char InnerRoom[256][256];
	
protected:

public:

    void CreateNewFloor(int Difficulty);

    void RequestFloorUpdate() const;
        
    void fillBoard(char** Board, int sizeX, int sizeY) override;
};
