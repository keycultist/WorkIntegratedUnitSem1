// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Combat.h"
#include "Enemy.h"
#include "Map.h"
#include "Renderer.h"

int main()
{
    srand(time(0));
    Player MC;
    MC.InitPlayer();
    Enemy* Enemies[10]{};
    for (int i = 0; i < 10; i++) {
        Enemies[i] = nullptr;
    }
    Enemies[1] = new Enemy;
    Enemies[1]->InitEnemy();
    MC.ShowPlayerStats();

    Map GMap;

    GMap.CreateNewFloor(2);

    //...

    //When init combat
    Combat::InitCombat(MC, *Enemies[1]);

    //...

    //Print map again
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
