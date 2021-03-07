#include "game.h"

/*
Console Game: Rock, Paper Scissors!
Compile using g++: <g++ -o rpsGame main.cpp game.cpp>
*/ 

int main() {
    Game g;
    while(g.on) {
        g.play();
    }
    return 0;
}