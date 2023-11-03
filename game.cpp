#include "intro.h"
#include "game.h"
#include <iostream>

// displayBoard displays the board in the terminal
void displayBoard(char *row)
{
    std::cout << '\n';
    std::cout << "        |       |      " << '\n';
    std::cout << "     " << row[0] << "  |   " << row[1] << "   |   " << row[2] << "   " << '\n';
    std::cout << "        |       |      " << '\n';
    std::cout << "  ---------------------" << '\n';
    std::cout << "        |       |      " << '\n';
    std::cout << "     " << row[3] << "  |   " << row[4] << "   |   " << row[5] << "   " << '\n';
    std::cout << "        |       |      " << '\n';
    std::cout << "  ---------------------" << '\n';
    std::cout << "        |       |      " << '\n';
    std::cout << "     " << row[6] << "  |   " << row[7] << "   |   " << row[8] << "   " << '\n';
    std::cout << "        |       |      " << '\n';
    std::cout << '\n';
}

// selectSquare prompts the player for a number
int selectSquare()
{
    int square{};
    std::cout << " Select square (1-9): ";
    std::cin >> square;

    return square;
}

// calculateWinner returns true if it finds three characters in a row
bool calculateWinner(char *row, char m)
{
    if ((row[0] == m && row[1] == m && row[2] == m) || 
        (row[3] == m && row[4] == m && row[5] == m) || 
        (row[6] == m && row[7] == m && row[8] == m) ||
        (row[0] == m && row[4] == m && row[8] == m) ||
        (row[0] == m && row[3] == m && row[6] == m) ||
        (row[1] == m && row[4] == m && row[7] == m) ||
        (row[2] == m && row[5] == m && row[8] == m) ||
        (row[2] == m && row[4] == m && row[6] == m)) 
        return true;
    return false;
}

// runGame runs the game
void runGame()
{
    char player1{'X'};
    char player2{'O'};
    
    char row[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int marker{0};
    
    displayBoard(row);
    bool running{ true };

    while (running)
    {
        std::cout << player1Text << '\n';
        marker = { selectSquare() };
        row[marker-1] = player1;

        clearScreen();
        displayBoard(row);
        if (calculateWinner(row, player1))
        {
            std::cout << player1Win << '\n';
            running = false;
            return;
        }
        
        std::cout << player2Text << '\n';
        marker = { selectSquare() };
        row[marker-1] = player2;

        clearScreen();
        displayBoard(row);
        if (calculateWinner(row, player2))
        {
            std::cout << player2Win << '\n';
            running = false;
            return;
        }
    }
}

