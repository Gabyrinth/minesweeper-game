#include <iostream>

#include <raylib.h>
#include "game.hpp"

using namespace std;

const string TITLE = "Minesweeper Game";
const int WIDTH = 772;
const int HEIGHT = 847;


int main(){
    Game game = Game(WIDTH, HEIGHT, TITLE);

    Vector2 offset = {0,75};
    int cellSize = 32;
    int row = 24;
    int col = 24;
    int gap = 2;

    game.initGrid(row, col, cellSize, gap, offset);

    game.mainloop();
}