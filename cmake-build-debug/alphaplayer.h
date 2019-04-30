//========================================================
//
//  File Name:   alphaplayer.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the alpha AI player class
//
// =========================================================

//-----------------------------------------------------------
// Name: Alpha Player
//
// Description: This is a derived class of Player that
//      evaluates domain information for the current AI
//      player and decides on a player bet. This uses the
//      getBet() method. The Alpha AI should use the attached
//      rules in deciding the bet for the AI player.
//
// -----------------------------------------------------------

#pragma once
#include "player.h"
using namespace std;

class AlphaPlayer : public Player {
public:
    AlphaPlayer(int id, int chips)
    : Player(id, chips) {}

    int getBet(Hand opponent, BetHistory bh,
               int bet2player, bool canRaise, int pot, int report);
};