//========================================================
//
//  File Name:   hand.cpp
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The definition file for the hand class
//
// =========================================================

//-----------------------------------------------------------
// Name: Hand
//
// Description: The Hand contains all of the cards in a
//      player's possession.
//
// -----------------------------------------------------------

#include "hand.h"
#include <vector>
#include "card.h"
using namespace std;

void Hand::clear() {
    cards.clear();
}

void Hand::addCard(Card card) {
    cards.push_back(card);
}

int Hand::getCount() {
    return cards.size();
}

Card Hand::getCard(int n) {
    return cards[n+1];
}

Hand Hand::getVisible() {
    vector<Card> visibleCards;
    for (Card currCard : cards) {
        if (currCard.isFaceUp()) {
            visibleCards.push_back(currCard);
        }
    }

    return visibleCards;
}

int Hand::evaluate() {
    return 0;
    // TODO complete evaluate method for Hand class
}