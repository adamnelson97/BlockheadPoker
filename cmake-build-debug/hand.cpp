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
// Description: Represents a hand or partial hand of cards
//
// -----------------------------------------------------------

#include "hand.h"
#include <vector>
#include "card.h"
using namespace std;

Hand::Hand() {

}

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
    return cards[n-1];
}

Hand Hand::getVisible() {
    Hand visible;
    for (Card currCard : cards) {
        if (currCard.isFaceUp()) {
            visible.cards.push_back(currCard);
        }
    }

    return visible;
}

int Hand::evaluate() {
    return 0;
    // TODO complete evaluate method for Hand class
}