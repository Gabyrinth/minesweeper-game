#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>
#include <math.h>

#include "colors.hpp"
#include "cell.hpp"

class Grid{
    public:

    Grid(Vector2 offset, Vector2 axis, int cellSize);

    void init();

    void draw();

    void hover(Vector2 mouse_pos);

    Vector2 get(Vector2 pos);

    void Search(Vector2 pos);

    void Flag(Vector2 pos);

    private:
    std::vector<std::vector<Cell>> grid;
    Vector2 offset;
    int row;
    int col;
    int cellSize;
    std::vector<std::vector<int>> nearestNeighbor;
};