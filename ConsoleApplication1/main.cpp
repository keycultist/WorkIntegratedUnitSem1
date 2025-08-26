// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Player.h"
#include "Combat.h"
#include "Enemy.h"
#include "Events.h"
#include "Map.h"
#include "Renderer.h"
#include "Item.h"

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
    MC.ShowPlayerStats();

    //82308 bytes of stack!!

    Map GMap;

    GMap.CreateNewFloor(0);
    GMap.RequestFloorUpdate();

    //...
    Combat::InitCombat(MC, *Enemies[0]);
    //When init combat
    /*if (Collide) {
        Combat::InitCombat(MC, CollidedEnemy);
    }*/

    //...

    //Print map again
}

static void CheckEnemyPlayerCollision(Player& MC, Enemy& target)
{
    int EnemyX, EnemyY;
    EnemyX == target.GetEnemyPosX();
    EnemyY == target.GetEnemyPosY();

    // Check if player touches enemy (collision)
    if (EnemyX == MC.GetPlayerPosX() && EnemyY == MC.GetPlayerPosY()) {
        // Enter combat with this enemy
        Combat::InitCombat(MC, target);           //suspects that it can be solved by enemy inheiriting from entity class. checkenemy func not being called
    }
}

//Event Collsion check, what does player have to collide with?
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
