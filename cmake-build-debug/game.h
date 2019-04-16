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
// Description: Plays a game between a player of type p0 and p1.
//      Chips is the number of chips each player respectively
//      has at start and end of the game. reportFlag is just
//      a flag to turn on and off I/O within the game
//      (so you can do Monte Carlo runs without a lot of output).
//      The method returns true if someone wants to quit the
//      program.
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