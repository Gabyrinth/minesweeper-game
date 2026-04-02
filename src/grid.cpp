#include "grid.hpp"

Grid::Grid(Vector2 offset, Vector2 axis, int cellSize){
    this->offset = offset;
    this->cellSize = cellSize;
    row = axis.x;
    col = axis.y;

    nearestNeighbor = {{-1,-1},{0,-1},{1,-1},{-1,0}, {1,0},{-1,1}, {0,1}, {1,1}};
    
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

void Grid::Flag(Vector2 pos){
    grid[pos.x][pos.y].flagCell();
}

void Grid::Search(Vector2 pos){
    if (pos.x >= row || pos.x < 0 || pos.y >= col || pos.y < 0) return; 

    Cell &cell = grid[pos.x][pos.y];

    if(cell.isSearched || cell.isFlagged) return;

    cell.searchCell();

    if (cell.neighbor > 0) return;
    for(int i = 0;i < nearestNeighbor.size(); i++){
        Search(Vector2{pos.x + nearestNeighbor[i][0], pos.y + nearestNeighbor[i][1]});
    }
}