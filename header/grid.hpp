#pragma once
#include <iostream>
#include <raylib.h>
#include <vector>
#include <map>
#include <math.h>
#include <time.h>
#include <string>
#include <algorithm>

#include "colors.hpp"
#include "cell.hpp"

class Grid{
    public:

    Grid(Vector2 offset, Vector2 axis, int cellSize, int gap);

    void draw(Vector2 mouse_pos);

    void hover(Vector2 axis);

    Vector2 get(Vector2 pos);

    void Search(Vector2 pos);

    void Flag(Vector2 pos);

    private:
    // variables
    std::vector<std::vector<Cell>> grid;
    Vector2 offset;
    int row;
    int col;
    int gap;
    int cellSize;
    std::vector<std::pair<int,int>> mineLocation;
    std::vector<std::vector<int>> nearestNeighbor;
    std::vector<std::vector<int>> searchNeighbor;
    std::map<std::string, Texture2D> textureMap;
    // private methods
    void mineDeploy();

    void init();
};