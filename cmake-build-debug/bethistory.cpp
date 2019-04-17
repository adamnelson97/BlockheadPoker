//========================================================
//
//  File Name:   bethistory.cpp
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The definition file for the BetHistory class
//
// =========================================================

//-----------------------------------------------------------
// Name: BetHistory
//
// Description: The BetHistory contains all log of all bets
//      in a single round.
//
// -----------------------------------------------------------

#include "bethistory.h"
#include "bet.h"
#include <vector>
using namespace std;

BetHistory::BetHistory() {
    // Default Constructor
}

void BetHistory::clearHistory() {
    bets.clear();
}

void BetHistory::addBet(Bet bet) {
    bets.push_back(bet);
}

int BetHistory::getCount() {
    return bets.size();
}

Bet BetHistory::getBet(int n) {
    return bets[n-1];
}