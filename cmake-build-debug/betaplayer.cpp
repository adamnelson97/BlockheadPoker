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

        /*
         * The Beta AI is aggresive, but cautious. It adheres to the following logic:
         * 1) If the bet2player == 0:
         *   a) If the Beta's hand is worth less than their opponents hand they check
         *   b) If their hand is worth more, they make a small bet of 5
         * 2) If the bet2player > 0:
         *   a) If the Beta's hand is worth less than their opponents hand the fold
         *   b) If their hand is worth more, they raise by 7. If they cannot raise, they call
         *   c) If their hand is worth the same, they call
         *
         * The Beta will always bet if they have the advantage, but always fold if
         * they are at a disadvantage. The logic is to cut your losses early and
         * don't dig bigger holes.
         */

        if (bet2player == 0) {
            if (playerHand.evaluate() < opponent.evaluate()) return 0; // Check
            else return 5; // Raise
        } else {
            if (playerHand.evaluate() < opponent.evaluate()) return 0; // Fold
            else if (playerHand.evaluate() > opponent.evaluate()) return bet2player + 7; // Raise
            else return bet2player; // Call
        }
    }
}