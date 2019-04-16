//========================================================
//
//  File Name:   bethistory.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the BetHistory class
//
// =========================================================

//-----------------------------------------------------------
// Name: BetHistory
//
// Description: The BetHistory contains all log of all bets
//      in a single round.
//
// -----------------------------------------------------------

#pragma once
#include "bet.h"
#include <vector>
using namespace std;

class BetHistory {
public:
    BetHistory();
    void clearHistory();
    void addBet(Bet bet);
    int getCount();
    Bet getBet(int n);

private:
    vector<Bet> bets;
};