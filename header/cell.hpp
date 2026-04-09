#pragma once
#include <raylib.h>
#include <string>

#include "colors.hpp"

struct Cell{
    bool isMine;
    bool isFlagged;
    int neighbor;
    bool isSearched;
    Color tilecolor;
    Vector2 position;
    int size;
    Texture2D *texture;

    Cell(int x, int y, int size); // instructor

    void draw();

    void searchCell();

    void flagCell(Texture2D &image);

    void mineCell(Texture2D &image);

    void addNeighbor();

    void setTexture(Texture2D &image);
};