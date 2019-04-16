//========================================================
//
//  File Name:   card.cpp
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The definition file for the Card class
//
// =========================================================

//-----------------------------------------------------------
// Name: Card
//
// Description: Represents a single card in a deck
//
// -----------------------------------------------------------

#include "card.h"
#include <string>
using namespace std;

Card::Card(string cardName, int cardValue) {
    this->cardName = cardName;
    this->cardValue = cardValue;
    faceUp = false;
}

void Card::setCard(string cardName, int cardValue) {
    this->cardName = cardName;
    this->cardValue = cardValue;
    faceUp = false;
}

string Card::getName() {
    return cardName;
}

int Card::getValue() {
    return cardValue;
}

bool Card::isFaceUp() {
    return faceUp;
}

void Card::setFaceUp(bool faceUp) {
    this->faceUp = faceUp;
}