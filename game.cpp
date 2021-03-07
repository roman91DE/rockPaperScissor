#include "game.h"
#include <random>
#include <iostream>



Game::Game() : options{'r', 'p', 's'}, win_player(0), win_computer(0), draw(0), on(true) {
    srand(time(NULL));
}

Game::~Game() {}

void Game::play() {
    std::cout << "\n--------\nChoose Rock(=r), Paper(=p) or Scissors(=s)?  [x to exit]\n";
    std::cin >> player_choice;
    computer_choice = options[rand()%3];
    std::cout<< "Player: " << getString(player_choice) <<" \nComputer: " << getString(computer_choice) << '\n';
    switch (player_choice) {
    case 'r':
        switch (computer_choice) {
        case 'r':
            ++draw;
            messagePlayer('d');
            break;
        case 'p':
            ++win_computer;
            messagePlayer('c');
            break;
        case 's':
            ++win_player;
            messagePlayer('p');
            break;
        }
        break;
    case 'p':
        switch (computer_choice) {
        case 'r':
            ++win_player;
            messagePlayer('p');
            break;
        case 'p':
            ++draw;
            messagePlayer('d');
            break;
        case 's':
            ++win_computer;
            messagePlayer('c');
            break;
        }
        break;
    case 's':
        switch (computer_choice) {
        case 'r':
            ++win_computer;
            messagePlayer('c');
            break;
        case 'p':
            ++win_player;
            messagePlayer('p');
            break;
        case 's':
            ++draw;
            messagePlayer('d');
            break;
        }
        break;
    case 'x':
        on = false;
    default:
        std::cout << "Error - Invalid Input!\n";
        break;
    }
    printStats();
}

void Game::printStats() const{
    std::cout << "--------\nStats" 
    << "\nTotal Rounds:  " << (win_computer+win_player+draw)
    << "\nWins Player:   " << win_player
    << "\nWins Computer: " << win_computer 
    << "\nDraws:         " << draw << "\n";
}

void Game::messagePlayer(char winner) const{
    switch (winner) {
    case 'p':
        std::cout << "You win this round!\n";
        break;
    case 'c':
        std::cout << "You loose this round!\n";
        break;
    case 'd':
        std::cout << "Draw!\n";
        break;
    default:
        std::cout << "Oops - Something went wrong!\n";
        break;
    }
}

std::string Game::getString(char c) const {
    switch (c) {
    case 'r':
        return std::string{"Rock"};
    case 'p':
        return std::string{"Paper"};
    case 's':
        return std::string{"Scissors"};
    default:
        return std::string{"Error - Invalid Input!"};
    }
}