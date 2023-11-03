#include <iostream>
#include <thread>
#include <chrono>

// clearScreen clears the terminal
void clearScreen()
{
#ifdef __linux__ 
    system("clear");
#elifdef __APPLE__ 
    system("clear");
#elifdef _WIN32
    system("cls");
#else
    return;
#endif
}

// displayAnimation displays unicode characters to spell out TIC TAC TOE 
void displayAnimation()
{
    clearScreen();
    std::cout << '\n';
    std::cout << " LET'S PLAY...." << '\n';
    std::cout << '\n';
    std::cout << "  ████████╗██╗ ██████╗ " << '\n';
    std::cout << "  ╚══██╔══╝██║██╔════╝ " << '\n';
    std::cout << "     ██║   ██║██║      " << '\n';
    std::cout << "     ██║   ██║██║      " << '\n';
    std::cout << "     ██║   ██║╚██████╗ " << '\n';
    std::cout << "     ╚═╝   ╚═╝ ╚═════╝ " << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));

    clearScreen();
    std::cout << '\n';
    std::cout << " LET'S PLAY...." << '\n';
    std::cout << '\n';
    std::cout << "  ████████╗██╗ ██████╗  ████████╗ █████╗  ██████╗ " << '\n';
    std::cout << "  ╚══██╔══╝██║██╔════╝  ╚══██╔══╝██╔══██╗██╔════╝ " << '\n';
    std::cout << "     ██║   ██║██║          ██║   ███████║██║      " << '\n';
    std::cout << "     ██║   ██║██║          ██║   ██╔══██║██║      " << '\n';
    std::cout << "     ██║   ██║╚██████╗     ██║   ██║  ██║╚██████╗ " << '\n';
    std::cout << "     ╚═╝   ╚═╝ ╚═════╝     ╚═╝   ╚═╝  ╚═╝ ╚═════╝ " << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));

    clearScreen();
    std::cout << '\n';
    std::cout << " LET'S PLAY...." << '\n';
    std::cout << '\n';
    std::cout << "  ████████╗██╗ ██████╗  ████████╗ █████╗  ██████╗  ████████╗ ██████╗ ███████╗ " << '\n';
    std::cout << "  ╚══██╔══╝██║██╔════╝  ╚══██╔══╝██╔══██╗██╔════╝  ╚══██╔══╝██╔═══██╗██╔════╝ " << '\n';
    std::cout << "     ██║   ██║██║          ██║   ███████║██║          ██║   ██║   ██║█████╗   " << '\n';
    std::cout << "     ██║   ██║██║          ██║   ██╔══██║██║          ██║   ██║   ██║██╔══╝   " << '\n';
    std::cout << "     ██║   ██║╚██████╗     ██║   ██║  ██║╚██████╗     ██║   ╚██████╔╝███████╗ " << '\n';
    std::cout << "     ╚═╝   ╚═╝ ╚═════╝     ╚═╝   ╚═╝  ╚═╝ ╚═════╝     ╚═╝    ╚═════╝ ╚══════╝ " << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(1));

    clearScreen();
}

