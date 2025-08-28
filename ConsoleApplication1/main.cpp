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
#include "Shop.h"
#include "Renderer.h"
#include "Item.h"
#include "Sound.h"

static void CheckEnemyPlayerCollision(Player& MC, Enemy& target)
{
    int EnemyX = 0;
    int EnemyY = 0;
    EnemyX = target.GetEnemyPosX();
    EnemyY = target.GetEnemyPosY();

    // Check if player touches enemy (collision)
    if (EnemyX == MC.GetPlayerPosX() && EnemyY == MC.GetPlayerPosY()) {
        // Enter combat with this enemy
        Combat::InitCombat(MC, target);
    }
}

//bool GameRunning(Player& MC, Enemy& Enemies, Map& GMap, bool& InsideRoom) {
//    //system("cls");
//    if (InsideRoom) {
//        GMap.switchToRoomView(MC.GetPlayerPosX(), MC.GetPlayerPosY(), MC);
//    }
//    else {
//        GMap.renderMapWithFOV(MC, 80, 30);
//    }
//
//    std::cout << "X: " << MC.GetPlayerPosX() << "    Y: " << MC.GetPlayerPosY() << std::endl;
//
//    if (GMap.detectPlayerRoom(MC.GetPlayerPosX(), MC.GetPlayerPosY())) {
//        InsideRoom = true;
//    }
//    else {
//        InsideRoom = false;
//    }
//
//    //GMap.RequestFloorUpdate(MC);
//    return true;
//}

void PlayerInput(Player& MC) {
    if (_kbhit()) {  // Check if key pressed
        char key = tolower(_getch());  // Read key without blocking


        switch (key) {
        case 'w':
            MC.PUpMove();
            break;
        case 's':
            MC.PDownMove();
            break;
        case 'a':
            MC.PLeftMove();
            break;
        case 'd':
            MC.PRightMove();
            break;
        case 'i':
        case 'e':
            MC.UpdateInventoryPlayerStats();
            std::cout << MC.GetInventory().DrawInventoryUI() << std::endl;
            std::cout << "Press any key to exit" << std::endl;
            int chP = _getch();
            MC.UpdatePlayerStatsInventory();
            system("cls");
        }
    }
}

//void clearConsole() {
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//    GetConsoleScreenBufferInfo(hConsole, &csbi);
//    DWORD consoleSize = csbi.dwSize.X * csbi.dwSize.Y;
//    DWORD charsWritten;
//
//    COORD topLeft = { 0, 0 };
//    FillConsoleOutputCharacter(hConsole, ' ', consoleSize, topLeft, &charsWritten);
//    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, consoleSize, topLeft, &charsWritten);
//    SetConsoleCursorPosition(hConsole, topLeft);
//}

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
    Renderer render;
    int StartGame = false;
    bool debugEnd = false;
    while (!StartGame) {
        render.drawASCII("TitleScreenUIString");

        int chP = _getch();
        if (chP == 13) {
            StartGame = true;
        }
        else if (chP == 'h') {
            debugEnd = true;
            StartGame = true;
        }
        system("cls");
    }
    system("cls");
    srand(time(0));
    Player MC;
    Item items;
    Shop shop;
    MC.InitPlayer();
    MC.GetInventory().GetItem().SetItemPlayerClass(MC.GetPlayerClass());
    MC.GetInventory().GetItem().SetItemList(); MC.GetInventory().GetItem().SetItemDescriptionList(); MC.GetInventory().GetItem().SetItemCostList(); MC.GetInventory().GetItem().SetItemTypeList(); MC.GetInventory().GetItem().SetEquipmentStatsList(); MC.GetInventory().GetItem().SetWeaponList(); items.SetWeaponList();
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
    if (debugEnd) {
        MC.SetCurrentDifficulty(6);
        GMap.CreateNewFloor(MC.GetCurrentDifficulty(), MC, shop);
    }
    else {
        MC.SetCurrentDifficulty(0);
        GMap.CreateNewFloor(MC.GetCurrentDifficulty(), MC, shop);
    }
    //GMap.RequestFloorUpdate(MC);

    // GMap.RequestFloorUpdate(MC);

    system("cls");
    //Kombat Tutorial Insert Here
    std::cout << "Guardsman: Welcome to the Abyss, let's make sure you're up to the challenge." << std::endl;
    int chP = _getch();
    std::cout << std::endl;
    std::cout << "Guardsman: There are some Grunts here, show me what you can do." << std::endl;
    Combat::InitTutorialCombat(MC, *Enemies[0]);
    if (MC.GetHP() > 0) {
        delete Enemies[0];
        Enemies[0] = nullptr;
    }
    system("cls");
    std::cout << "Guardsman: Great job (even if you ran away)!." << std::endl;
    chP = _getch();
    std::cout << std::endl;
    std::cout << "Guardsman: Be warned though, on each floor is is an enemy stronger than any other enemies(M)." << std::endl;
    chP = _getch();
    std::cout << std::endl;
    std::cout << "Guardsman: Defeating these enemies will cause the Abyss to force you into the next floor, you have been warned." << std::endl;
    chP = _getch();
    std::cout << std::endl;
    system("cls");

    bool RUNNINGHORSE = true;
    bool InsideRoom = false;
    bool Clearcheck = false;
    bool FinishShopping = false;
    while (RUNNINGHORSE) {
        //RUNNINGHORSE = GameRunning(MC, *Enemies[0], GMap, InsideRoom);
        auto startTime = std::chrono::high_resolution_clock::now();

        if (MC.GetHP() <= 0) {
            RUNNINGHORSE = false;
        }

        // 1. Handle input if any
        PlayerInput(MC);

        // 2. Handle roaming enemies
        if (!InsideRoom) {
            if (GMap.checkForRoamingCombat(MC)) {
                // Combat happened, continue
            }
        }

        // 3. Update roaming enemies
        GMap.updateRoamingEnemyAI(MC);

        // 4. Update game state
        InsideRoom = (GMap.detectPlayerRoom(MC.GetPlayerPosX(), MC.GetPlayerPosY()) != nullptr);


        // 5. Render
        if (InsideRoom) {
            if (!Clearcheck) {
                //clearConsole();
                system("cls");
                Clearcheck = true;
            }
            GMap.switchToRoomView(MC.GetPlayerPosX(), MC.GetPlayerPosY(), MC, shop, FinishShopping);

            Room* currentRoom = GMap.detectPlayerRoom(MC.GetPlayerPosX(), MC.GetPlayerPosY());

            if (GMap.checkForCombat(currentRoom, MC)) {
                if (GMap.checkTruebossKilled()) {
                    RUNNINGHORSE = false;
                }

                if (GMap.checkForCombat(currentRoom, MC)) {
                    if (GMap.checkMinibossKilled()) {
                        // Force progression to next floor
                        std::cout << "The Abyss forces you deeper..." << std::endl;
                        int chP = _getch();
                        system("cls");

                        MC.SetCurrentDifficulty(MC.GetCurrentDifficulty() + 1);
                        GMap.CreateNewFloor(MC.GetCurrentDifficulty(), MC, shop);
                    }
                }
            }


        }
        else {
            if (GMap.isMinibossKilled()) {
                //MC.SetCurrentDifficulty(MC.GetCurrentDifficulty() + 1);
                //GMap.CreateNewFloor(MC.GetCurrentDifficulty(), MC, shop);
                MC.SetCurrentDifficulty(MC.GetCurrentDifficulty() + 1);
                MC.SetPlayerPos(0, 0);
                GMap.CreateNewFloor(MC.GetCurrentDifficulty(), MC, shop);
                GMap.renderMapWithFOV(MC, 50, 25);
                Clearcheck = false;
                FinishShopping = false;
                system("cls");
            }

            GMap.renderMapWithFOV(MC, 50, 25);
            Clearcheck = false;
            FinishShopping = false;
        }

        // 6. Wait until next frame (~16ms for ~60 FPS)
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> elapsed = endTime - startTime;
        int frameDelay = 1000 / 30; // 30 FPS
        if (elapsed.count() < frameDelay)
            std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay) - elapsed);
    }




    //When init combat
    //if (Collide) {
        //Combat::InitCombat(MC, CollidedEnemy);
    //}

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
