//========================================================
//
//  File Name:   game.h
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The header file for the Game class
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

#pragma once
#include <vector>
#include "card.h"
#include "bethistory.h"
#include "humanplayer.h"
#include "alphaplayer.h"
#include "betaplayer.h"

using namespace std;


enum PlayerType { HUMAN, ALPHA, BETA };

class Game {
public:
    Game();
    bool playGame(PlayerType p0, PlayerType p1,
            int &chips0, int &chips1, bool reportFlag, bool monteCarloSim);
    PlayerType p0;
    PlayerType p1;
    int chips0;
    int chips1;
    bool reportFlag;
    bool monteCarloSim;
    vector<Card> deck;

private:
    void popDeck();
    bool runHH(HumanPlayer playerOne, HumanPlayer playerTwo, bool reportFlag);
    bool runHA(HumanPlayer playerOne, AlphaPlayer playerTwo, bool reportFlag);
    bool runHB(HumanPlayer playerOne, BetaPlayer playerTwo, bool reportFlag);
    bool runAH(AlphaPlayer playerOne, HumanPlayer playerTwo, bool reportFlag);
    bool runAA(AlphaPlayer playerOne, AlphaPlayer playerTwo, bool reportFlag);
    bool runAB(AlphaPlayer playerOne, BetaPlayer playerTwo, bool reportFlag);
    bool runBH(BetaPlayer playerOne, HumanPlayer playerTwo, bool reportFlag);
    bool runBA(BetaPlayer playerOne, AlphaPlayer playerTwo, bool reportFlag);
    bool runBB(BetaPlayer playerOne, BetaPlayer playerTwo, bool reportFlag);
    bool monteCarlo(AlphaPlayer playerOne, BetaPlayer playerTwo, bool reportFlag);

    int thePot; // Tracks the total monies in the betting pool
    BetHistory betHistory;
    int playersBet;
    int betToPlayer;
    int playerTurn;
    bool playerHasFolded;
    int numPlayersChecked;
    int completedRounds;
    int biddingRound;
    bool canRaise;
    int numRaises;
    int lastToRaise;
};