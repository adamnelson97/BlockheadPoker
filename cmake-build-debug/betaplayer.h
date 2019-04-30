//========================================================
//
//  File Name:   betaplayer.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 2
//
//  Description:  The header file for the beta AI player class
//
// =========================================================

//-----------------------------------------------------------
// Name: Beta Player
//
// Description: This is a derived class of Player that
//      evaluates domain information for the current AI
//      player and decides on a player bet. This uses the
//      getBet() method.
//
// -----------------------------------------------------------

#pragma once
#include "player.h"
using namespace std;

class BetaPlayer : public Player {
public:
    BetaPlayer(int id, int chips)
            : Player(id, chips) {}

    int getBet(Hand opponent, BetHistory bh,
               int bet2player, bool canRaise, int pot);
};