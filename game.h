#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <vector>

void displayBoard(char, int, char);
void runGame();
int selectSquare();
bool calculateWinner(char*, char);
void playAgain();

#endif

// Display color in the Linux terminal
#ifdef __linux__ 
    const std::string player1Text = " \033[1;34mPlayer 1\033[0m\n";
    const std::string player2Text = " \033[1;31mPlayer 2\033[0m\n";
    const std::string player1Win  = " \033[1;34mPlayer 1 Wins!\033[0m\n";
    const std::string player2Win  = " \033[1;31mPlayer 2 Wins!\033[0m\n";
#else
    const std::string player1Text = " Player 1";
    const std::string player2Text = " Player 2";
    const std::string player1Win  = " Player 1 Wins!";
    const std::string player2Win  = " Player 2 Wins!";
#endif

