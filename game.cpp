#include "intro.h"
#include "game.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

// displayBoard displays the board in the terminal
void displayBoard(char *row)
{
    std::cout << '\n'
     << "        |       |      " << '\n'
     << "     " << row[0] << "  |   " << row[1] << "   |   " << row[2] << "   " << '\n'
     << "        |       |      " << '\n'
     << "  ---------------------" << '\n'
     << "        |       |      " << '\n'
     << "     " << row[3] << "  |   " << row[4] << "   |   " << row[5] << "   " << '\n'
     << "        |       |      " << '\n'
     << "  ---------------------" << '\n'
     << "        |       |      " << '\n'
     << "     " << row[6] << "  |   " << row[7] << "   |   " << row[8] << "   " << '\n'
     << "        |       |      " << '\n'
     << '\n';
}

// selectSquare prompts the player for a number
int selectSquare()
{
    int square{};
    std::cout << " Select a square (1-9): ";
    std::cin >> square;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << " Invalid input. Please try again: " << '\n';
        selectSquare();
    }
    if (square < 1 || square > 9)
    {
        std::cerr << " Number not within 1-9 range. Please try again: " << '\n';
        selectSquare();
    }

    return square;
}

// validateSelection validates square is available
int validateSelection(std::vector<int>& selected)
{
    int marker{ selectSquare() };
    if (std::find(selected.begin(), selected.end(), marker) != selected.end())
    {
        std::cout << " Square has already been selected. Please make another selection." << '\n';
        marker = validateSelection(selected);
    }
    else
    {
        selected.push_back(marker);
    }

    return marker;
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

// playAgain prompts the player to play the game again
void playAgain()
{
    char answer;
    std::cout << " Would you like to play again (Y or N) ?: ";
    std::cin >> answer;

    if (toupper(answer) == 'Y')
    {
        clearScreen();
        runGame();
    }

    return;
}

// runGame runs the game
void runGame()
{
    char player1{'X'};
    char player2{'O'};
    
    char row[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    displayBoard(row);

    int marker{0};
    bool running{ true };
    std::vector<int> selected;

    while (running)
    {
        std::cout << player1Text << '\n';
        marker = validateSelection(selected);
        row[marker-1] = player1;

        clearScreen();
        displayBoard(row);
        if (calculateWinner(row, player1))
        {
            std::cout << player1Win << '\n';
            running = false;
            playAgain();
            return;
        }

        if (selected.size() == 9)
        {
            running = false;
            std::cout << " Tie!" << '\n';
            playAgain();
            return;
        }
        
        std::cout << player2Text << '\n';
        marker = validateSelection(selected);
        row[marker-1] = player2;

        clearScreen();
        displayBoard(row);
        if (calculateWinner(row, player2))
        {
            std::cout << player2Win << '\n';
            running = false;
            playAgain();
            return;
        }
    }
}

