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
// Description: Represents a hand or partial hand of cards
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