//========================================================
//
//  File Name:   hand.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the hand class
//
// =========================================================

//-----------------------------------------------------------
// Name: Hand
//
// Description: The Hand contains all of the cards in a
//      player's possession.
//
// -----------------------------------------------------------

#pragma once
#include <vector>
#include "card.h"
using namespace std;

class Hand {
public:
    Hand();
    void clear();
    void addCard(Card card);
    int getCount();
    Card getCard(int n);
    Hand getVisible();
    int evaluate();

private:
    vector<Card> cards;
};