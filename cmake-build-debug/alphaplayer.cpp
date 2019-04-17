//========================================================
//
//  File Name:   alphaplayer.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The definition file for the alpha AI
//      player class
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

#include "player.h"
#include "alphaplayer.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int AlphaPlayer::getBet(Hand opponent, BetHistory bh,
                   int bet2player, bool canRaise, int pot) {

    int betAmt;
    while (true) {
        srand(time(NULL));
        betAmt = rand() % (bet2player + 10); // Randomly chooses to Check/Fold/Call/Raise

        if (betAmt > bet2player) {
            if (canRaise) {
                if (betAmt < bet2player + 10) {
                    cout << "Alpha Player has bet." << endl;
                    return betAmt; // Player raises an acceptable amount
                }
            }
        } else {
            cout << "Alpha Player has bet." << endl;
            return betAmt; // Check or Fold or Call
        }
    }
}