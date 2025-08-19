#pragma once
#include <string>
#include <iostream>
#include <vector>

class Map
{

private:
    char FloorGrid[128][128];
    int tilesFilled;
    char InnerRoom[256][256];
	
protected:

public:

    Map() : tilesFilled(0) {
        for (int h = 0; h < 128; ++h) {
            for (int v = 0; v < 128; ++v) {
                FloorGrid[h][v] = ' ';
            }
        }

    }



    void CreateNewFloor(int Difficulty) const {

    }
};
