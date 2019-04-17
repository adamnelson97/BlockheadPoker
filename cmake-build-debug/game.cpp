//========================================================
//
//  File Name:   game.cpp
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The definition file for the Game class
//
// =========================================================

//-----------------------------------------------------------
// Name: Game
//
// Description: Plays a game between a player of type p0 and p1.
//      Chips is the number of chips each player respectively
//      has at start and end of the game. reportFlag is just
//      a flag to turn on and off I/O within the game
//      (so you can do Monte Carlo runs without a lot of output).
//      The method returns true if someone wants to quit the
//      program.
//
// -----------------------------------------------------------

#include <iostream>
#include "game.h"
#include "player.h"
#include "humanplayer.h"
#include "alphaplayer.h"
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

Game::Game() {
    // Default constructor

    // Populate the deck of cards
    popDeck();
}

// Populate the deck of cards
void Game::popDeck() {
    string suit, value, name;
    int points;
    for (int i = 0; i < 4; i++) {
        // Get suit
        switch(i) {
            case 0:
                suit = "Spades";
                break;
            case 1:
                suit = "Clubs";
                break;
            case 2:
                suit = "Hearts";
                break;
            case 3:
                suit = "Diamonds";
                break;
        }
        for (int j = 1; j <= 13; j++) {
            switch(j) {
                case 1:
                    value = "Ace";
                    points = 1;
                    break;
                case 2:
                    value = "Two";
                    points = 2;
                    break;
                case 3:
                    value = "Three";
                    points = 3;
                    break;
                case 4:
                    value = "Four";
                    points = 4;
                    break;
                case 5:
                    value = "Five";
                    points = 5;
                    break;
                case 6:
                    value = "Six";
                    points = 6;
                    break;
                case 7:
                    value = "Seven";
                    points = 7;
                    break;
                case 8:
                    value = "Eight";
                    points = 8;
                    break;
                case 9:
                    value = "Nine";
                    points = 9;
                    break;
                case 10:
                    value = "Ten";
                    points = 10;
                    break;
                case 11:
                    value = "Jack";
                    points = 10;
                    break;
                case 12:
                    value = "Queen";
                    points = 10;
                    break;
                case 13:
                    value = "King";
                    points = 10;
                    break;
            }
            name = value + " of " + suit;
            deck.push_back(Card(name, points));
        }
    }

}

bool Game::playGame(PlayerType p0, PlayerType p1,
        int &chips0, int &chips1, bool reportFlag) {

    // Make the two players
    Player playerOne, playerTwo;
    if (p0 == HUMAN) {
        playerOne = HumanPlayer(0, 1000);
    } else if (p0 == ALPHA) {
        playerOne = AlphaPlayer(0, 1000);
    } else if (p0 == BETA) {
        playerOne = AlphaPlayer(0, 1000);
    }
    // TODO Change this to BetaPlayer for Phase 2

    if (p1 == HUMAN) {
        playerTwo = HumanPlayer(0, 1000);
    } else if (p1 == ALPHA) {
        playerTwo = AlphaPlayer(0, 1000);
    } else if (p1 == BETA) {
        playerTwo = AlphaPlayer(0, 1000);
    }
    // TODO Change this to BetaPlayer for Phase 2

    int completedRounds = 0;
    
    while (completedRounds < 20) {
        // Shuffle the deck
        random_shuffle(deck.begin(), deck.end());

        // Deal each player cards
        //Player One
        for (int i = 0; i < 3; i++) {
            Card tempCard = deck.back();
            deck.pop_back(); // Removes the card from the deck
            if (i == 0) {
                tempCard.setFaceUp(false);
            } else {
                tempCard.setFaceUp(true);
            }
            playerOne.dealCard(tempCard);
        }
        //Player Two
        for (int i = 0; i < 3; i++) {
            Card tempCard = deck.back();
            deck.pop_back(); // Removes the card from the deck
            if (i == 0) {
                tempCard.setFaceUp(false);
            } else {
                tempCard.setFaceUp(true);
            }
            playerTwo.dealCard(tempCard);
        }

        // Put money into the pot
        playerOne.addChips(-10);
        if (playerOne.getChips() < 0) {
            cout << "Player One can't buy in, they lose!" << endl;
            return false;
        }
        playerTwo.addChips(-10);
        if (playerTwo.getChips() < 0) {
            cout << "Player Two can't buy in, they lose!" << endl;
            return false;
        }

        thePot = 20;


        completedRounds++;
    }

    return false;
}