//========================================================
//
//  File Name:   card.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the Card class
//
// =========================================================

//-----------------------------------------------------------
// Name: Card
//
// Description: Contains the information for the card (name, value)
//      and methods to retrieve that information.
//
// -----------------------------------------------------------

#pragma once
#include <string>
using namespace std;

class Card {
public:
    Card();
    Card(string cardName, int cardValue);
    void setCard(string cardName, int cardValue);
    string getName();
    int getValue();
    bool isFaceUp();
    void setFaceUp(bool faceUp); // True if ALL players can see the card

private:
    string cardName;
    int cardValue;
    bool faceUp;
};