//========================================================
//
//  File Name:   player.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the player class
//
// =========================================================

//-----------------------------------------------------------
// Name: Player
//
// Description: This represents either a human or AI player.
//      This is a base abstract class. You then should have
//      derived classes for human, Alpha AI players, and Beta
//      AI players (or more). The human player class will
//      basically be I/O functions that presents info to the
//      game player and gest decisions from a game player.
//      The AI classes should make their own decisions without
//      human input.
//
// -----------------------------------------------------------

#pragma once
#include "bethistory.h"
#include "bet.h"
#include "hand.h"
using namespace std;

class Player {
public:
    Player(int id, int chips);
    virtual int getBet(Hand opponent, BetHistory bh,
            int bet2player, bool canRaise, int pot);
    int getID();
    void clearHand();
    void dealCard(Card c);
    Hand getHand();
    void addChips(int chips);
    int getChips();

private:
    int playerID;
    int playerChips;
    Hand playerHand;
};