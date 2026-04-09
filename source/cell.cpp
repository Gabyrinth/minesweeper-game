#include "cell.hpp"

Cell::Cell(int x, int y, int size){
    this->size = size;
    position = Vector2{(float) x, (float) y};
    isMine = false;
    isFlagged = false;
    neighbor = 0;
    isSearched = false;
    tilecolor = color[0];
    texture = nullptr;
}

void Cell::draw(){
    DrawRectangle(position.x, position.y, size, size, tilecolor);

    if (isFlagged){
        DrawTexture(*texture, position.x, position.y, WHITE);
    }

    if (neighbor > 0 && isSearched){
        DrawText(std::to_string(neighbor).c_str(),position.x, position.y, 22, fontColor[neighbor-1]);
    } 
}

void Cell::setTexture(Texture2D &image){
    texture = &image;
}

void Cell::flagCell(Texture2D &image){
    if (isSearched) return;
    if (isFlagged) return;

    setTexture(image);
    isFlagged = true;
}

void Cell::searchCell(){
    tilecolor = color[1];
    isSearched = true;
}

void Cell::mineCell(){
    isMine = true;
}

void Cell::addNeighbor(){
    if (isMine) return;
    neighbor++;
}