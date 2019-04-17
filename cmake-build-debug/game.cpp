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
#include "bethistory.h"
#include <ctime>
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

    // Seed rand function
    srand(time(NULL));

    // Make the two players
    if (p0 == HUMAN) {
        if (p1 == HUMAN) {
            HumanPlayer playerOne(0, 1000);
            HumanPlayer playerTwo(0, 1000);
            return runHH(playerOne, playerTwo, reportFlag);
        } else if (p1 == ALPHA) {
            HumanPlayer playerOne(0, 1000);
            AlphaPlayer playerTwo(0, 1000);
            return runHA(playerOne, playerTwo, reportFlag);
        } else if (p1 == BETA) {
            AlphaPlayer playerOne(0, 1000);
            AlphaPlayer playerTwo(0, 1000);
            return runAA(playerOne, playerTwo, reportFlag);
        }
    } else if (p0 == ALPHA) {
        if (p1 == HUMAN) {
            AlphaPlayer playerOne(0, 1000);
            HumanPlayer playerTwo(0, 1000);
            return runAH(playerOne, playerTwo, reportFlag);
        } else if (p1 == ALPHA) {
            AlphaPlayer playerOne(0, 1000);
            AlphaPlayer playerTwo(0, 1000);
            return runAA(playerOne, playerTwo, reportFlag);
        } else if (p1 == BETA) {
            AlphaPlayer playerOne(0, 1000);
            AlphaPlayer playerTwo(0, 1000);
            return runAA(playerOne, playerTwo, reportFlag);
        }
    } else if (p0 == BETA) {
        if (p1 == HUMAN) {
            AlphaPlayer playerOne(0, 1000);
            HumanPlayer playerTwo(0, 1000);
            return runAH(playerOne, playerTwo, reportFlag);
        } else if (p1 == ALPHA) {
            AlphaPlayer playerOne(0, 1000);
            AlphaPlayer playerTwo(0, 1000);
            return runAA(playerOne, playerTwo, reportFlag);
        } else if (p1 == BETA) {
            AlphaPlayer playerOne(0, 1000);
            AlphaPlayer playerTwo(0, 1000);
            return runAA(playerOne, playerTwo, reportFlag);
        }
    }
}

int randFunc () { return rand()%7;}

bool Game::runHH(HumanPlayer playerOne, HumanPlayer playerTwo, bool reportFlag) {

    completedRounds = 0;
    if (completedRounds % 2 == 0) {
        playerTurn = 0;
    } else {
        playerTurn = 1;
    }
    lastToRaise = 2;

    // Begin betting rounds
    while (completedRounds < 20) {
        // Reset deck and hands
        popDeck();
        playerOne.clearHand();
        playerTwo.clearHand();

        if (reportFlag) {
            cout << "\nBetting Round " << completedRounds + 1 << endl;
        }
        // Reset the pot
        thePot = 0;

        // Shuffle the deck
        std::random_shuffle(deck.begin(), deck.end());

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
            if (reportFlag) {
                cout << "Card added to Player One's Hand." << endl;
            }
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
            if (reportFlag) {
                cout << "Card added to Player Two's Hand." << endl;
            }
        }

        // Put buy in into the pot
        playerOne.addChips(-10);
        playerTwo.addChips(-10);
        thePot = 20; // Increases the pot by the two players buy ins

        // Begin bidding rounds
        playerHasFolded = false;
        biddingRound = 0;
        betHistory.clearHistory();

        while (biddingRound < 3 && playerHasFolded == false) {
            if (reportFlag) {
                cout << "\nBidding Round " << biddingRound + 1 << endl;
            }
            betToPlayer = 0;
            numPlayersChecked = 0;
            numRaises = 0;

            while (playerHasFolded == false && numPlayersChecked < 2) {
                if (lastToRaise == playerTurn) {
                    canRaise = false; // Can't raise your own bet
                } else if (numRaises < 3) {
                    canRaise = true;
                } else {
                    canRaise = false; // Even though you can raise, no more are allowed per the rules
                }

                // Get player's bet
                if (playerTurn == 0) {
                    if (reportFlag) {
                        cout << "Player One's turn to bet." << endl;
                    }
                    playersBet = playerOne.getBet(playerTwo.getHand(), betHistory, betToPlayer, canRaise, thePot);
                    playerOne.addChips(-1*playersBet);
                } else {
                    if (reportFlag) {
                        cout << "Player Two's turn to bet." << endl;
                    }
                    playersBet = playerTwo.getBet(playerTwo.getHand(), betHistory, betToPlayer, canRaise, thePot);
                    playerTwo.addChips(-1*playersBet);
                }

                // Add bet to log
                Bet bet(playersBet, playerTurn);
                betHistory.addBet(bet);


                // Check the bet
                if (playersBet == -1) {
                    return false; // Human wants to exit game
                } else if (playersBet == 0 && betToPlayer == 0) { // Check
                    numPlayersChecked++;
                } else if (playersBet == 0 && betToPlayer > 0) { // Fold
                    playerHasFolded = true;
                } else if (playersBet == betToPlayer) { // Call
                    betToPlayer = 0;
                    thePot += playersBet;
                } else if (playersBet > betToPlayer) { // Raise
                    numRaises += 1;
                    lastToRaise = playerTurn;
                    betToPlayer = playersBet - betToPlayer;
                    thePot += playersBet;
                }

                // Update who next player is
                if (playerTurn == 0) {
                    playerTurn = 1;
                } else {
                    playerTurn = 0;
                }
            } // End of bidding round

            biddingRound++;

            // Deal more cards
            // Player 1
            Card tempCard = deck.back();
            deck.pop_back();
            tempCard.setFaceUp(true);
            playerOne.dealCard(tempCard);
            if (reportFlag) {
                cout << "Card added to Player One's Hand." << endl;
            }
            // Player 2
            tempCard = deck.back();
            deck.pop_back();
            tempCard.setFaceUp(true);
            playerTwo.dealCard(tempCard);
            if (reportFlag) {
                cout << "Card added to Player Two's Hand." << endl;
            }
        }

        if (playerHasFolded == true) {
            if (playerTurn == 0) {
                if (reportFlag) {
                    cout << "Player Two folds. Player One wins the round!" << endl;
                }
                playerOne.addChips(thePot);
            } else {
                if (reportFlag) {
                    cout << "Player One folds. Player Two wins the round!" << endl;
                }
                playerTwo.addChips(thePot);
            }
        } else {
            int p1Score = playerOne.getHand().evaluate();
            int p2Score = playerTwo.getHand().evaluate();
            if (p1Score > p2Score) {
                if (reportFlag) {
                    cout << "Player One's Hand (" << p1Score
                         << ") is greater than Player Two's Hand (" << p2Score
                         << "), Player One wins the round!" << endl;
                }
                playerOne.addChips(thePot);
            } else if (p2Score > p1Score){
                if (reportFlag) {
                    cout << "Player Two's Hand (" << p2Score
                         << ") is greater than Player One's Hand (" << p1Score
                         << "), Player Two wins the round!" << endl;
                }
                playerTwo.addChips(thePot);
            } else {
                if (reportFlag) {
                    cout << "The hands are tied! (" << p1Score << "). No winner." << endl;
                }
                playerOne.addChips(thePot/2);
                playerTwo.addChips(thePot/2);
            }
        }

        if (reportFlag) {
            cout << "Player One has " << playerOne.getChips() << " chips." << endl;
            cout << "Player Two has " << playerTwo.getChips() << " chips." << endl;
        }

        completedRounds++; // End of round
    }

    if (reportFlag && playerOne.getChips() > playerTwo.getChips()) {
        cout << "Player One wins the game!" << endl;
    } else {
        cout << "Player Two wins the game!" << endl;
    }
    return false;
}
bool Game::runHA(HumanPlayer playerOne, AlphaPlayer playerTwo, bool reportFlag) {

    completedRounds = 0;
    if (completedRounds % 2 == 0) {
        playerTurn = 0;
    } else {
        playerTurn = 1;
    }
    lastToRaise = 2;

    // Begin betting rounds
    while (completedRounds < 20) {
        // Reset deck and hands
        popDeck();
        playerOne.clearHand();
        playerTwo.clearHand();

        if (reportFlag) {
            cout << "\nBetting Round " << completedRounds + 1 << endl;
        }
        // Reset the pot
        thePot = 0;

        // Shuffle the deck
        std::random_shuffle(deck.begin(), deck.end());

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
            if (reportFlag) {
                cout << "Card added to Player One's Hand." << endl;
            }
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
            if (reportFlag) {
                cout << "Card added to Player Two's Hand." << endl;
            }
        }

        // Put buy in into the pot
        playerOne.addChips(-10);
        playerTwo.addChips(-10);
        thePot = 20; // Increases the pot by the two players buy ins

        // Begin bidding rounds
        playerHasFolded = false;
        biddingRound = 0;
        betHistory.clearHistory();

        while (biddingRound < 3 && playerHasFolded == false) {
            if (reportFlag) {
                cout << "\nBidding Round " << biddingRound + 1 << endl;
            }
            betToPlayer = 0;
            numPlayersChecked = 0;
            numRaises = 0;

            while (playerHasFolded == false && numPlayersChecked < 2) {
                if (lastToRaise == playerTurn) {
                    canRaise = false; // Can't raise your own bet
                } else if (numRaises < 3) {
                    canRaise = true;
                } else {
                    canRaise = false; // Even though you can raise, no more are allowed per the rules
                }

                // Get player's bet
                if (playerTurn == 0) {
                    if (reportFlag) {
                        cout << "Player One's turn to bet." << endl;
                    }
                    playersBet = playerOne.getBet(playerTwo.getHand(), betHistory, betToPlayer, canRaise, thePot);
                    playerOne.addChips(-1*playersBet);
                } else {
                    if (reportFlag) {
                        cout << "Player Two's turn to bet." << endl;
                    }
                    playersBet = playerTwo.getBet(playerTwo.getHand(), betHistory, betToPlayer, canRaise, thePot);
                    playerTwo.addChips(-1*playersBet);
                }

                // Add bet to log
                Bet bet(playersBet, playerTurn);
                betHistory.addBet(bet);


                // Check the bet
                if (playersBet == -1) {
                    return false; // Human wants to exit game
                } else if (playersBet == 0 && betToPlayer == 0) { // Check
                    numPlayersChecked++;
                } else if (playersBet == 0 && betToPlayer > 0) { // Fold
                    playerHasFolded = true;
                } else if (playersBet == betToPlayer) { // Call
                    betToPlayer = 0;
                    thePot += playersBet;
                } else if (playersBet > betToPlayer) { // Raise
                    numRaises += 1;
                    lastToRaise = playerTurn;
                    betToPlayer = playersBet - betToPlayer;
                    thePot += playersBet;
                }

                // Update who next player is
                if (playerTurn == 0) {
                    playerTurn = 1;
                } else {
                    playerTurn = 0;
                }
            } // End of bidding round

            biddingRound++;

            // Deal more cards
            // Player 1
            Card tempCard = deck.back();
            deck.pop_back();
            tempCard.setFaceUp(true);
            playerOne.dealCard(tempCard);
            if (reportFlag) {
                cout << "Card added to Player One's Hand." << endl;
            }
            // Player 2
            tempCard = deck.back();
            deck.pop_back();
            tempCard.setFaceUp(true);
            playerTwo.dealCard(tempCard);
            if (reportFlag) {
                cout << "Card added to Player Two's Hand." << endl;
            }
        }

        if (playerHasFolded == true) {
            if (playerTurn == 0) {
                if (reportFlag) {
                    cout << "Player Two folds. Player One wins the round!" << endl;
                }
                playerOne.addChips(thePot);
            } else {
                if (reportFlag) {
                    cout << "Player One folds. Player Two wins the round!" << endl;
                }
                playerTwo.addChips(thePot);
            }
        } else {
            int p1Score = playerOne.getHand().evaluate();
            int p2Score = playerTwo.getHand().evaluate();
            if (p1Score > p2Score) {
                if (reportFlag) {
                    cout << "Player One's Hand (" << p1Score
                         << ") is greater than Player Two's Hand (" << p2Score
                         << "), Player One wins the round!" << endl;
                }
                playerOne.addChips(thePot);
            } else if (p2Score > p1Score){
                if (reportFlag) {
                    cout << "Player Two's Hand (" << p2Score
                         << ") is greater than Player One's Hand (" << p1Score
                         << "), Player Two wins the round!" << endl;
                }
                playerTwo.addChips(thePot);
            } else {
                if (reportFlag) {
                    cout << "The hands are tied! (" << p1Score << "). No winner." << endl;
                }
                playerOne.addChips(thePot/2);
                playerTwo.addChips(thePot/2);
            }
        }

        if (reportFlag) {
            cout << "Player One has " << playerOne.getChips() << " chips." << endl;
            cout << "Player Two has " << playerTwo.getChips() << " chips." << endl;
        }

        completedRounds++; // End of round
    }

    if (reportFlag && playerOne.getChips() > playerTwo.getChips()) {
        cout << "Player One wins the game!" << endl;
    } else {
        cout << "Player Two wins the game!" << endl;
    }
    return false;
}
bool Game::runAA(AlphaPlayer playerOne, AlphaPlayer playerTwo, bool reportFlag) {

    completedRounds = 0;
    if (completedRounds % 2 == 0) {
        playerTurn = 0;
    } else {
        playerTurn = 1;
    }
    lastToRaise = 2;

    // Begin betting rounds
    while (completedRounds < 20) {
        // Reset deck and hands
        popDeck();
        playerOne.clearHand();
        playerTwo.clearHand();

        if (reportFlag) {
            cout << "\nBetting Round " << completedRounds + 1 << endl;
        }
        // Reset the pot
        thePot = 0;

        // Shuffle the deck
        std::random_shuffle(deck.begin(), deck.end());

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
            if (reportFlag) {
                cout << "Card added to Player One's Hand." << endl;
            }
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
            if (reportFlag) {
                cout << "Card added to Player Two's Hand." << endl;
            }
        }

        // Put buy in into the pot
        playerOne.addChips(-10);
        playerTwo.addChips(-10);
        thePot = 20; // Increases the pot by the two players buy ins

        // Begin bidding rounds
        playerHasFolded = false;
        biddingRound = 0;
        betHistory.clearHistory();

        while (biddingRound < 3 && playerHasFolded == false) {
            if (reportFlag) {
                cout << "\nBidding Round " << biddingRound + 1 << endl;
            }
            betToPlayer = 0;
            numPlayersChecked = 0;
            numRaises = 0;

            while (playerHasFolded == false && numPlayersChecked < 2) {
                if (lastToRaise == playerTurn) {
                    canRaise = false; // Can't raise your own bet
                } else if (numRaises < 3) {
                    canRaise = true;
                } else {
                    canRaise = false; // Even though you can raise, no more are allowed per the rules
                }

                // Get player's bet
                if (playerTurn == 0) {
                    if (reportFlag) {
                        cout << "Player One's turn to bet." << endl;
                    }
                    playersBet = playerOne.getBet(playerTwo.getHand(), betHistory, betToPlayer, canRaise, thePot);
                    playerOne.addChips(-1*playersBet);
                } else {
                    if (reportFlag) {
                        cout << "Player Two's turn to bet." << endl;
                    }
                    playersBet = playerTwo.getBet(playerTwo.getHand(), betHistory, betToPlayer, canRaise, thePot);
                    playerTwo.addChips(-1*playersBet);
                }

                // Add bet to log
                Bet bet(playersBet, playerTurn);
                betHistory.addBet(bet);


                // Check the bet
                if (playersBet == -1) {
                    return false; // Human wants to exit game
                } else if (playersBet == 0 && betToPlayer == 0) { // Check
                    numPlayersChecked++;
                } else if (playersBet == 0 && betToPlayer > 0) { // Fold
                    playerHasFolded = true;
                } else if (playersBet == betToPlayer) { // Call
                    betToPlayer = 0;
                    thePot += playersBet;
                } else if (playersBet > betToPlayer) { // Raise
                    numRaises += 1;
                    lastToRaise = playerTurn;
                    betToPlayer = playersBet - betToPlayer;
                    thePot += playersBet;
                }

                // Update who next player is
                if (playerTurn == 0) {
                    playerTurn = 1;
                } else {
                    playerTurn = 0;
                }
            } // End of bidding round

            biddingRound++;

            // Deal more cards
            // Player 1
            Card tempCard = deck.back();
            deck.pop_back();
            tempCard.setFaceUp(true);
            playerOne.dealCard(tempCard);
            if (reportFlag) {
                cout << "Card added to Player One's Hand." << endl;
            }
            // Player 2
            tempCard = deck.back();
            deck.pop_back();
            tempCard.setFaceUp(true);
            playerTwo.dealCard(tempCard);
            if (reportFlag) {
                cout << "Card added to Player Two's Hand." << endl;
            }
        }

        if (playerHasFolded == true) {
            if (playerTurn == 0) {
                if (reportFlag) {
                    cout << "Player Two folds. Player One wins the round!" << endl;
                }
                playerOne.addChips(thePot);
            } else {
                if (reportFlag) {
                    cout << "Player One folds. Player Two wins the round!" << endl;
                }
                playerTwo.addChips(thePot);
            }
        } else {
            int p1Score = playerOne.getHand().evaluate();
            int p2Score = playerTwo.getHand().evaluate();
            if (p1Score > p2Score) {
                if (reportFlag) {
                    cout << "Player One's Hand (" << p1Score
                         << ") is greater than Player Two's Hand (" << p2Score
                         << "), Player One wins the round!" << endl;
                }
                playerOne.addChips(thePot);
            } else if (p2Score > p1Score){
                if (reportFlag) {
                    cout << "Player Two's Hand (" << p2Score
                         << ") is greater than Player One's Hand (" << p1Score
                         << "), Player Two wins the round!" << endl;
                }
                playerTwo.addChips(thePot);
            } else {
                if (reportFlag) {
                    cout << "The hands are tied! (" << p1Score << "). No winner." << endl;
                }
                playerOne.addChips(thePot/2);
                playerTwo.addChips(thePot/2);
            }
        }

        if (reportFlag) {
            cout << "Player One has " << playerOne.getChips() << " chips." << endl;
            cout << "Player Two has " << playerTwo.getChips() << " chips." << endl;
        }

        completedRounds++; // End of round
    }

    if (reportFlag && playerOne.getChips() > playerTwo.getChips()) {
        cout << "Player One wins the game!" << endl;
    } else {
        cout << "Player Two wins the game!" << endl;
    }
    return false;
}
bool Game::runAH(AlphaPlayer playerOne, HumanPlayer playerTwo, bool reportFlag) {

    completedRounds = 0;
    if (completedRounds % 2 == 0) {
        playerTurn = 0;
    } else {
        playerTurn = 1;
    }
    lastToRaise = 2;

    // Begin betting rounds
    while (completedRounds < 20) {
        // Reset deck and hands
        popDeck();
        playerOne.clearHand();
        playerTwo.clearHand();

        if (reportFlag) {
            cout << "\nBetting Round " << completedRounds + 1 << endl;
        }
        // Reset the pot
        thePot = 0;

        // Shuffle the deck
        std::random_shuffle(deck.begin(), deck.end());

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
            if (reportFlag) {
                cout << "Card added to Player One's Hand." << endl;
            }
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
            if (reportFlag) {
                cout << "Card added to Player Two's Hand." << endl;
            }
        }

        // Put buy in into the pot
        playerOne.addChips(-10);
        playerTwo.addChips(-10);
        thePot = 20; // Increases the pot by the two players buy ins

        // Begin bidding rounds
        playerHasFolded = false;
        biddingRound = 0;
        betHistory.clearHistory();

        while (biddingRound < 3 && playerHasFolded == false) {
            if (reportFlag) {
                cout << "\nBidding Round " << biddingRound + 1 << endl;
            }
            betToPlayer = 0;
            numPlayersChecked = 0;
            numRaises = 0;

            while (playerHasFolded == false && numPlayersChecked < 2) {
                if (lastToRaise == playerTurn) {
                    canRaise = false; // Can't raise your own bet
                } else if (numRaises < 3) {
                    canRaise = true;
                } else {
                    canRaise = false; // Even though you can raise, no more are allowed per the rules
                }

                // Get player's bet
                if (playerTurn == 0) {
                    if (reportFlag) {
                        cout << "Player One's turn to bet." << endl;
                    }
                    playersBet = playerOne.getBet(playerTwo.getHand(), betHistory, betToPlayer, canRaise, thePot);
                    playerOne.addChips(-1*playersBet);
                } else {
                    if (reportFlag) {
                        cout << "Player Two's turn to bet." << endl;
                    }
                    playersBet = playerTwo.getBet(playerTwo.getHand(), betHistory, betToPlayer, canRaise, thePot);
                    playerTwo.addChips(-1*playersBet);
                }

                // Add bet to log
                Bet bet(playersBet, playerTurn);
                betHistory.addBet(bet);


                // Check the bet
                if (playersBet == -1) {
                    return false; // Human wants to exit game
                } else if (playersBet == 0 && betToPlayer == 0) { // Check
                    numPlayersChecked++;
                } else if (playersBet == 0 && betToPlayer > 0) { // Fold
                    playerHasFolded = true;
                } else if (playersBet == betToPlayer) { // Call
                    betToPlayer = 0;
                    thePot += playersBet;
                } else if (playersBet > betToPlayer) { // Raise
                    numRaises += 1;
                    lastToRaise = playerTurn;
                    betToPlayer = playersBet - betToPlayer;
                    thePot += playersBet;
                }

                // Update who next player is
                if (playerTurn == 0) {
                    playerTurn = 1;
                } else {
                    playerTurn = 0;
                }
            } // End of bidding round

            biddingRound++;

            // Deal more cards
            // Player 1
            Card tempCard = deck.back();
            deck.pop_back();
            tempCard.setFaceUp(true);
            playerOne.dealCard(tempCard);
            if (reportFlag) {
                cout << "Card added to Player One's Hand." << endl;
            }
            // Player 2
            tempCard = deck.back();
            deck.pop_back();
            tempCard.setFaceUp(true);
            playerTwo.dealCard(tempCard);
            if (reportFlag) {
                cout << "Card added to Player Two's Hand." << endl;
            }
        }

        if (playerHasFolded == true) {
            if (playerTurn == 0) {
                if (reportFlag) {
                    cout << "Player Two folds. Player One wins the round!" << endl;
                }
                playerOne.addChips(thePot);
            } else {
                if (reportFlag) {
                    cout << "Player One folds. Player Two wins the round!" << endl;
                }
                playerTwo.addChips(thePot);
            }
        } else {
            int p1Score = playerOne.getHand().evaluate();
            int p2Score = playerTwo.getHand().evaluate();
            if (p1Score > p2Score) {
                if (reportFlag) {
                    cout << "Player One's Hand (" << p1Score
                         << ") is greater than Player Two's Hand (" << p2Score
                         << "), Player One wins the round!" << endl;
                }
                playerOne.addChips(thePot);
            } else if (p2Score > p1Score){
                if (reportFlag) {
                    cout << "Player Two's Hand (" << p2Score
                         << ") is greater than Player One's Hand (" << p1Score
                         << "), Player Two wins the round!" << endl;
                }
                playerTwo.addChips(thePot);
            } else {
                if (reportFlag) {
                    cout << "The hands are tied! (" << p1Score << "). No winner." << endl;
                }
                playerOne.addChips(thePot/2);
                playerTwo.addChips(thePot/2);
            }
        }

        if (reportFlag) {
            cout << "Player One has " << playerOne.getChips() << " chips." << endl;
            cout << "Player Two has " << playerTwo.getChips() << " chips." << endl;
        }

        completedRounds++; // End of round
    }

    if (reportFlag && playerOne.getChips() > playerTwo.getChips()) {
        cout << "Player One wins the game!" << endl;
    } else {
        cout << "Player Two wins the game!" << endl;
    }
    return false;
}