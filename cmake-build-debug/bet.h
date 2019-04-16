//========================================================
//
//  File Name:   bet.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the Bet class
//
// =========================================================

//-----------------------------------------------------------
// Name: Bet
//
// Description: Represent a single player’s single bet.
//
// -----------------------------------------------------------

#pragma once
using namespace std;

class Bet {
public:
    Bet(int amount, int player);
    int getPlayer();
    int getAmount();

private:
    int player;
    int amount;
};