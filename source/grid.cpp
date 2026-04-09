#include "grid.hpp"

Grid::Grid(Vector2 offset, Vector2 axis, int cellSize, int gap){
    this->offset = offset;
    this->cellSize = cellSize;
    this->gap = gap;

    row = axis.x;
    col = axis.y;
    // Initialize neighbor
    nearestNeighbor = {{-1,-1},{0,-1},{1,-1},{-1,0}, {1,0},{-1,1}, {0,1}, {1,1}};
    searchNeighbor = {{0,-1}, {-1,0}, {1,0}, {0,1}};
    // Load texture
    textureMap["mine"] = LoadTexture("../image/mine.png");
    textureMap["flag"] = LoadTexture("../image/flag.png");

    init();
    mineDeploy();
}

// INITIALIZE THE GRID
void Grid::init(){
    grid.resize(row);
    for(int r = 0; r < row; r++){
        for(int c = 0; c < col; c++){
            int posX = (offset.x + (r * cellSize)) + gap;
            int posY = (offset.y + (c * cellSize)) + gap;
            int newSize = cellSize - gap;
            grid[r].emplace_back(posX, posY, newSize);
        }
    }
}

// DRAW AT SCREEN
void Grid::draw(Vector2 mouse_pos){
    // HOVER EFFECT
    Vector2 axis = this->get(mouse_pos);
    hover(axis);
    for(int r = 0; r < row; r++){
        for (int c = 0; c < row; c++){
            grid[r][c].draw();
        }
    }
    
    
}

void Grid::hover(Vector2 axis){
    int posX = (offset.x + axis.x * cellSize) + gap;
    int posY = (offset.y + axis.y * cellSize) + gap;
    int newSize = cellSize - gap;
    DrawRectangle(posX, posY, newSize, newSize, RED);
}

// GET THE ROW AND COL: RETURN VECTOR2
Vector2 Grid::get(Vector2 pos){
    int r= (int)std::floor((pos.x-offset.x) / (cellSize));
    int c = (int)std::floor((pos.y-offset.y) / (cellSize));
    // clamp
    r = std::max(0, std::min(r, row - 1));
    c = std::max(0, std::min(c, col - 1));

    return {(float) r,(float) c};
}

void Grid::Flag(Vector2 pos){
    grid[pos.x][pos.y].flagCell(textureMap["flag"]);
}

void Grid::Search(Vector2 pos){
    if (pos.x >= row || pos.x < 0 || pos.y >= col || pos.y < 0) return; 

    Cell &cell = grid[pos.x][pos.y];

    if (cell.isMine){
        std::cout << "Game Over";
        return;
    }

    
    if(cell.isSearched || cell.isFlagged) return;

    cell.searchCell();

    if (cell.neighbor > 0) return;
    for(int i = 0;i < searchNeighbor.size(); i++){
        Search(Vector2{pos.x + searchNeighbor[i][0], pos.y + searchNeighbor[i][1]}); // recursive DFS
    }
}

void Grid::mineDeploy(){
    srand(time(0));
    int numberOfMines = 50;
    for(int i = 0; i < numberOfMines; i++){
        int r = rand() % row;
        int c = rand() % col;
        if (std::find(mineLocation.begin(), mineLocation.end(), std::make_pair(r,c)) != mineLocation.end()){
            continue;
        }
        mineLocation.push_back({r,c});
        Cell &cell = grid[r][c];
        cell.mineCell(textureMap["mine"]);
    }

    for (int i = 0; i < mineLocation.size(); i++){
        for (int j = 0; j < nearestNeighbor.size(); j++){
            int rn = mineLocation[i].first + nearestNeighbor[j][0];
            int cn = mineLocation[i].second + nearestNeighbor[j][1];
            if (rn >= 0 && rn < row && cn >= 0 && cn < col && grid[rn][cn].isMine == false){
                grid[rn][cn].addNeighbor();
            }
        }
    }
}