//========================================================
//
//  File Name:   betaplayer.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 2
//
//  Description:  The definition file for the beta AI
//      player class
//
// =========================================================

//-----------------------------------------------------------
// Name: Beta Player
//
// Description: This is a derived class of Player that
//      evaluates domain information for the current AI
//      player and decides on a player bet.
//
// -----------------------------------------------------------

#include "player.h"
#include "betaplayer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int BetaPlayer::getBet(Hand opponent, BetHistory bh,
                        int bet2player, bool canRaise, int pot) {

    int betAmt;
    while (true) {
        srand(time(NULL));

        if (canRaise) {
            betAmt = rand() % (bet2player + 10); // Alpha will always raise if possible
            cout << "Alpha Player has bet." << endl;
            return betAmt; // Player raises an acceptable amount
        } else {
            cout << "Alpha Player has bet." << endl;
            return bet2player; // Check or Call
        }
    }
}