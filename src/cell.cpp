#include "cell.hpp"

Cell::Cell(int x, int y, int size){
    this->position = Vector2{(float) x, (float) y};
    this->size = size;
    this->isMine = false;
    this->isFlagged = false;
    this->neighbor = 0;
    this->isSearched = false;
}

void Cell::draw(){
    DrawRectangle(position.x, position.y, size, size, color[0]);
}

void Cell::drawTexture(){
    DrawText(getImages(0));
}

