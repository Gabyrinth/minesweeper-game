#include "grid.hpp"

Grid::Grid(Vector2 offset, Vector2 axis, int cellSize){
    this->offset = offset;
    this->cellSize = cellSize;
    row = axis.x;
    col = axis.y;
    
    init();
}

// can be use to reset
void Grid::init(){
    grid.resize(row);
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            grid[r].emplace_back(offset.x + r * cellSize + 4, offset.y + c * cellSize + 4, cellSize - 4);
        }
    }
}
// draw rectangles at screen
void Grid::draw(){
    for(int r = 0; r < row; r++){
        for (int c = 0; c < row; c++){
            grid[r][c].draw();
        }
    }
}
// 
void Grid::hover(Vector2 mouse_pos){
    Vector2 axis = this->get(mouse_pos);
    DrawRectangle(offset.x+axis.x * cellSize+4,offset.y+ axis.y * cellSize+4, cellSize-4,cellSize-4, RED);
}

Vector2 Grid::get(Vector2 pos){
    int r= (int)std::floor((pos.x-offset.x) / cellSize);
    int c = (int)std::floor((pos.y-offset.y) / cellSize);

    // clamp
    r = std::max(0, std::min(r, row - 1));
    c = std::max(0, std::min(c, col - 1));

    return {(float) r,(float) c};
}
