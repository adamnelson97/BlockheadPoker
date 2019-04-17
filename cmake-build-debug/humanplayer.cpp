//========================================================
//
//  File Name:   humanplayer.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the human player class
//
// =========================================================

//-----------------------------------------------------------
// Name: Human Player
//
// Description: This is a derived class of Player that
//      presents domain information to the  current human
//      player through I/O and then allows the player to
//      input their bet.
//
// -----------------------------------------------------------

#include "player.h"
#include "humanplayer.h"
#include <iostream>
#include <string>
using namespace std;

int HumanPlayer::getBet(Hand opponent, BetHistory bh,
        int bet2player, bool canRaise, int pot) {

    // Display bet history
    for (int i = 0; i < bh.getCount(); i++) {
        cout << "Player " << bh.getBet(i).getPlayer() << " bet " << bh.getBet(i).getAmount() << endl;
    }

    // Display Opponent's Hand
    cout << "\nOpponent's Hand:" << endl;
    for (int i = 0; i < opponent.getCount(); i++) {
        cout << opponent.getCard(i).getName() << endl;
    }

    cout << "\nYour Hand:" << endl;
    for (int i = 0; i < playerHand.getCount(); i++) {
        cout << playerHand.getCard(i).getName() << endl;
    }
    
    // Make Bet
    if (bet2player == 0) {
        cout << "You can Check. Enter a bet of 0." << endl;
    } else {
        cout << "You can Fold. Enter a bet of 0." << endl;
        cout << "You can Call. Enter a bet of " << bet2player << "." << endl;
    }

    if (canRaise) {
        cout << "You can Raise. Enter a bet from " << bet2player + 1 << " to " << bet2player + 10 << "." << endl;
    } else {
        cout << "You cannot Raise." << endl;
    }

    cout << "You can quit the game. Enter a bet of Q" << endl;

    string bet;
    int betAmt;
    while (true) {
        cout << "Bet: " << flush;
        getline(cin, bet);
        if (bet == "Q") {
            return -1; // Game is over
        }
        betAmt = std::stoi(bet, nullptr, 0);
        if (betAmt > bet2player) {
            if (canRaise) {
                if (betAmt < bet2player + 10) {
                    return betAmt; // Player raises an acceptable amount
                } else {
                    cout << "Bet is too large. Enter a smaller bet." << endl;
                }
            } else {
                cout << "You are not allowed to raise right now." << endl;
            }
        } else {
            return betAmt; // Player checks or folds or calls
        }
    }
}