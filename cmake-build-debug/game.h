//========================================================
//
//  File Name:   game.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the Game class
//
// =========================================================

//-----------------------------------------------------------
// Name: Game
//
// Description: The Game class creates a poker game between
//      the specified player types.
//
// -----------------------------------------------------------

#pragma once
#include "playertype.h"
using namespace std;

class Game {
public:
    Game();
    bool playGame(PlayerType p0, PlayerType p1,
            int &chips0, int &chips1, bool reportFlag);

private:
    PlayerType p0;
    PlayerType p1;
    int chips0;
    int chips1;
    bool reportFlag;
};