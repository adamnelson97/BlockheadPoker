//========================================================
//
//  File Name:   bet.cpp
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The definition file for the Bet class
//
// =========================================================

//-----------------------------------------------------------
// Name: Bet
//
// Description: Contains the information representing
//      a player's bet
//
// -----------------------------------------------------------

#include "bet.h
using namespace std;

Bet::Bet(int amount, int player) {
    this->amount = amount;
    this->player = player;
}

int Bet::getPlayer() {
    return player;
}

int Bet::getAmount() {
    return amount;
}