#include "cell.hpp"

Cell::Cell(int x, int y, int size){
    this->size = size;
    position = Vector2{(float) x, (float) y};
    isMine = false;
    isFlagged = false;
    neighbor = 0;
    isSearched = false;
    tilecolor = color[0];
}

void Cell::draw(){
    DrawRectangle(position.x, position.y, size, size, tilecolor);

    if (isFlagged){
        DrawTexture(texture, position.x, position.y, WHITE);
    }

    if (isMine){
        DrawTexture(texture, position.x, position.y, WHITE);
    }

    if (neighbor > 0 && isSearched){
        DrawText(std::to_string(neighbor).c_str(),position.x, position.y, 22, RED);
    }
}

void Cell::flagCell(){
    if (isSearched) return;
    if (isFlagged) return;

    texture = getImages()[1];
    isFlagged = true;
}

void Cell::searchCell(){
    tilecolor = color[2];
    isSearched = true;
}

void Cell::mineCell(){
    isMine = true;
    texture = getImages()[0];
}

void Cell::addNeighbor(){
    if (isMine) return;
    neighbor++;
}