#ifndef __GAME__
#define __GAME__

#include <cstdlib>
#include <array>
#include <string>

class Game{
    private:
        std::array <char, 3> options;
        // chars representing each choice
        char player_choice, computer_choice;
        // keeping stats with:
        int win_player, win_computer, draw;
    public:
        Game();
        ~Game();
        void play();
        void printStats() const;
        void messagePlayer(char winner) const;
        std::string getString(char c) const;
        // flip to exit Game
        bool on;

};

#endif