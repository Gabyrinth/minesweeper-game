#include <iostream>

#include <raylib.h>
#include "game.hpp"

using namespace std;

const string TITLE = "Minesweeper";
const int WIDTH = 772;
const int HEIGHT = 847;


int main(){
    Game game = Game(WIDTH, HEIGHT, TITLE);

    Vector2 offset = {0,75};
    int cellSize = 32;
    int row = 24;
    int col = 24;

    game.initGrid(row,col,cellSize, offset);


    game.mainloop();
}