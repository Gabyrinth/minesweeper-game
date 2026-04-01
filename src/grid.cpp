#include "grid.hpp"

Grid::Grid(Vector2 offset, Vector2 axis, int cellSize){
    this->offset = offset;
    this->row = axis.x;
    this->col = axis.y;
    this->cellSize = cellSize;

    this->init();
}

// can be use to reset
void Grid::init(){
    this->grid.resize(this->row);
    for(int row = 0; row < this->row; row++){
        this->grid[row].resize(this->col);
        for(int col = 0; col < this->col; col++){
            this->grid[row][col] = 0;
        }
    }
}
// draw rectangles at screen
void Grid::draw(){
    for(int row = 0; row < this->row; row++){
        for (int col = 0; col < this->row; col++){
            int val = this->grid[row][col];
            DrawRectangle(this->offset.x+row * this->cellSize+4,this->offset.y+ col * this->cellSize+4, this->cellSize-4,this->cellSize-4, color[val]);
        }
    }
}
// 
void Grid::hover(Vector2 mouse_pos){
    Vector2 axis = this->get(mouse_pos);
    DrawRectangle(this->offset.x+axis.x * this->cellSize+4,this->offset.y+ axis.y * this->cellSize+4, this->cellSize-4,this->cellSize-4, RED);
}

Vector2 Grid::get(Vector2 pos){
    int row = (int)std::floor((pos.x-this->offset.x) / this->cellSize);
    int col = (int)std::floor((pos.y-this->offset.y) / this->cellSize);

    // clamp
    row = std::max(0, std::min(row, this->row - 1));
    col = std::max(0, std::min(col, this->col - 1));

    return {(float) row,(float) col};
}
