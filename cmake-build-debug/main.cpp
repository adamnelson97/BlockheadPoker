//========================================================
//
//  File Name:   main.cpp
//
//  Author:  Adam Nelson
//
//  Course and Assignment:   CSCI 477, Project 2 - Phase 1
//
//  Description:  The main driver for the Blockhead Poker game
//
// =========================================================

#include <iostream>
#include "game.h"
using namespace std;

void printComms();
void play();

int main() {
    cout << "=== BLOCKHEAD POKER ===" << endl;
    cout << "Enter HELP for a list of commands" << endl;

    bool quit = false; // Tracks if the user wishes to end the graph or not
    string command;

    while (!quit) {
        cout << "\n$ " << flush;
        getline(cin, command);

        if (command == "HELP" || command == "help") {
            printComms();
        } else if (command == "PLAY" || command == "play") {
           play();
        } else if (command == "QUIT" || command == "quit") {
            quit = true;
        } else if (command == "TEST1" || command =="test1") {
            Game game;
            int chips0, chips1;

            if (game.playGame(ALPHA, ALPHA, chips0, chips1, true) == false) {
                cout << "Thank you for playing!" << endl;
            } else {
                cerr << "Error: playGame returned true." << endl;
            }
        }
        else if (command == "") {
            cout << endl;
        }
        else {
            cout << "Invalid command.\n" << endl;
        }
    }

    return 0;
}

void printComms() {
    cout << "\nCOMMANDS" << endl;
    cout << "HELP - Prints this page." << endl;
    cout << "PLAY - Starts a game." << endl;
    cout << "TEST1 - Runs test between two Alpha players with console output." << endl;
    cout << "QUIT - Ends the program.\n" << endl;
}

void play() {
    cout << "\nPlayer Types:\tHUMAN\tALPHA\tBETA" << endl;
    string player1Type, player2Type;
    PlayerType playerOne, playerTwo;

    // Set first player type
    cout << "\nWhat type is Player 1: " << flush;
    getline(cin, player1Type);

    if (player1Type == "HUMAN" || player1Type == "human") {
        playerOne = HUMAN;
    } else if (player1Type == "ALPHA" || player1Type == "alpha") {
        playerOne = ALPHA;
    } else if (player1Type == "BETA" || player1Type == "beta") {
        playerOne = BETA;
    } else {
        cerr << "Invalid player type." << endl;
        return;
    }

    // Set second player type
    cout << "\nWhat type is Player 2: " << flush;
    getline(cin, player2Type);

    if (player2Type == "HUMAN" || player2Type == "human") {
        playerTwo = HUMAN;
    } else if (player2Type == "ALPHA" || player2Type == "alpha") {
        playerTwo = ALPHA;
    } else if (player2Type == "BETA" || player2Type == "beta") {
        playerTwo = BETA;
    } else {
        cerr << "Invalid player type." << endl;
        return;
    }

    string output;
    bool outputBool;
    cout << "\nDo you want to print output? (y/n): " << flush;
    getline(cin, output);
    if (output == "Y" || output == "y") {
        outputBool = true;
    } else if (output == "N" || output == "n") {
        outputBool = false;
    } else {
        cerr << "Invalid option." << endl;
        return;
    }

    Game game;
    int chips0, chips1;

    if (game.playGame(playerOne, playerTwo, chips0, chips1, outputBool) == false) {
        cout << "Thank you for playing!" << endl;
        return;
    } else {
        cerr << "Error: playGame returned true." << endl;
        return;
    }

}