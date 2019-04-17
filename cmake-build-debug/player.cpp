//========================================================
//
//  File Name:   player.cpp
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The definition file for the player class
//
// =========================================================

//-----------------------------------------------------------
// Name: Player
//
// Description: This represents either a human or AI player.
//      This is a base abstract class. You then should have
//      derived classes for human, Alpha AI players, and Beta
//      AI players (or more). The human player class will
//      basically be I/O functions that presents info to the
//      game player and gest decisions from a game player.
//      The AI classes should make their own decisions without
//      human input.
//
// -----------------------------------------------------------

#include "bethistory.h"
#include "bet.h"
#include "hand.h"
#include "player.h"
#include <iostream>
using namespace std;

Player::Player() {
    // Default Constructor
}

Player::Player(int id, int chips) {
    playerID = id;
    playerChips = chips;
}

int Player::getBet(Hand opponent, BetHistory bh,
        int bet2player, bool canRaise, int pot) {
    cout << "Fuck you" << endl;
    return 0; // This is overridden by child classes
}

int Player::getID() {
    return playerID;
}

void Player::clearHand() {
    playerHand.clear();
}

void Player::dealCard(Card c) {
    playerHand.addCard(c);
}

Hand Player::getHand() {
    return playerHand.getVisible();
}

void Player::addChips(int chips) {
    playerChips += chips;
}

int Player::getChips() {
    return playerChips;
}