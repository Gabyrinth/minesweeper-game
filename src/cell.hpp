#pragma once
#include <raylib.h>
#include "colors.hpp"
#include "image.hpp"

struct Cell{
    bool isMine;
    bool isFlagged;
    int neighbor;
    bool isSearched;
    Vector2 position;
    int size;
    Texture2D texture;
    Cell(int x, int y, int size);
    void draw();
    void drawTexture();
};