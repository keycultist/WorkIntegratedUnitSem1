// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

#include <chrono>
#include <thread>
#define NOMINMAX
#include <windows.h> 

#include "Player.h"
#include "Combat.h"
#include "Enemy.h"
#include "Events.h"
#include "Map.h"
#include "Renderer.h"
#include "Item.h"

static void CheckEnemyPlayerCollision(Player& MC, Enemy& target)
{
    int EnemyX = 0;
    int EnemyY = 0;
    EnemyX = target.GetEnemyPosX();
    EnemyY = target.GetEnemyPosY();

    // Check if player touches enemy (collision)
    if (EnemyX == MC.GetPlayerPosX() && EnemyY == MC.GetPlayerPosY()) {
        // Enter combat with this enemy
        Combat::InitCombat(MC, target);           //suspects that it can be solved by enemy inheiriting from entity class. checkenemy func not being called
    }
}

bool GameRunning(Player& MC, Enemy& Enemies, Map& GMap, bool& InsideRoom) {
    //system("cls");
    if (InsideRoom) {
        GMap.switchToRoomView(MC.GetPlayerPosX(), MC.GetPlayerPosY(), MC);
    }
    else {
        GMap.renderMapWithFOV(MC, 80, 30);
    }

    std::cout << "X: " << MC.GetPlayerPosX() << "    Y: " << MC.GetPlayerPosY() << std::endl;

    if (GMap.detectPlayerRoom(MC.GetPlayerPosX(), MC.GetPlayerPosY())) {
        InsideRoom = true;
    }
    else {
        InsideRoom = false;
    }

    //GMap.RequestFloorUpdate(MC);
    return true;
}

void PlayerInput(Player& MC) {
    if (_kbhit()) {  // Check if key pressed
        char key = tolower(_getch());  // Read key without blocking


        switch (key) {
        case 'w': MC.PUpMove(); break;
        case 's': MC.PDownMove(); break;
        case 'a': MC.PLeftMove(); break;
        case 'd': MC.PRightMove(); break;
        }
    }
}

void clearConsole() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    DWORD charsWritten;

    COORD topLeft = { 0, 0 };
    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &charsWritten);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, topLeft, &charsWritten);
    SetConsoleCursorPosition(hConsole, topLeft);
}

//Event Collsion check, what does player have to collide with? idk like a tile lol.
//static void CheckEventPlayerCollision(Player& MC, ???)
//{
//    int EventX, EventY;
//    // Check events
//    for (int b = 1; b <= 3; b++) {
//        // Skip if this event doesn't exist
//        if (events[b] != nullptr) {
//            // Get event's position
//            EventX == events[b]->GetPosX();
//            EventY == events[b]->GetPosY();
//
//            // Check if player touches event (collision)
//            if (EventX == GetPosX() && EventY == GetPosY()) {
//                // Enter the event
//                EventTriggered(events[b]);
//                break;  // Stop checking after first event
//            }
//        }
//    }
//}


int main()
{
    srand(time(0));
    Player MC;
    Item items;
    MC.InitPlayer();
    items.SetItemPlayerClass(MC.GetPlayerClass());
    items.SetItemList();
    // init player's inventory
    Enemy* Enemies[10]{};
    for (int i = 0; i < 10; i++) {
        Enemies[i] = nullptr;
    }
    Enemies[0] = new Enemy;
    Enemies[0]->InitEnemy();
    //MC.ShowPlayerStats();

    //82308 bytes of stack!!

    Map GMap;

    GMap.CreateNewFloor(6, MC);
    //GMap.RequestFloorUpdate(MC);

    int chP = _getch();
    system("cls");

    bool RUNNINGHORSE = true;
    bool InsideRoom = false;
    bool Clearcheck = false;
    while (RUNNINGHORSE) {
        //RUNNINGHORSE = GameRunning(MC, *Enemies[0], GMap, InsideRoom);
        auto startTime = std::chrono::high_resolution_clock::now();

        // 1. Handle input if any
        PlayerInput(MC);

        // 2. Update enemies
        //updateEnemies();

        // 3. Update game state
        InsideRoom = (GMap.detectPlayerRoom(MC.GetPlayerPosX(), MC.GetPlayerPosY()) != nullptr);

        // 4. Render
        if (InsideRoom) {
            if (!Clearcheck) {
                clearConsole();
                Clearcheck = true;
            }
            GMap.switchToRoomView(MC.GetPlayerPosX(), MC.GetPlayerPosY(), MC);
        }
        else {
            GMap.renderMapWithFOV(MC, 40, 20);
            Clearcheck = false;
        }

        // 5. Wait until next frame (~16ms for ~60 FPS)
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = endTime - startTime;
        int frameDelay = 1000 / 30; // 30 FPS
        if (elapsed.count() < frameDelay)
            std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay) - elapsed);
    }

    //...
    //Combat::InitCombat(MC, *Enemies[0]);
    //When init combat
    /*if (Collide) {
        Combat::InitCombat(MC, CollidedEnemy);
    }*/
            
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
