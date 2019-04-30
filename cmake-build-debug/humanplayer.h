//========================================================
//
//  File Name:   humanplayer.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the human player class
//
// =========================================================

//-----------------------------------------------------------
// Name: Human Player
//
// Description: This is a derived class of Player that
//      presents domain information to the  current human
//      player through I/O and then allows the player to
//      input their bet.
//
// -----------------------------------------------------------

#pragma once
#include "player.h"
using namespace std;

class HumanPlayer : public Player {
public:
    HumanPlayer(int id, int chips)
    : Player(id, chips) {}

    int getBet(Hand opponent, BetHistory bh,
               int bet2player, bool canRaise, int pot, int report);
};