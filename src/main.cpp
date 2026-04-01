#include <iostream>

#include <raylib.h>
#include "grid.hpp"

int main(){
    InitWindow(772,847, "MineSweeper");

    Vector2 offset = Vector2{0,75};
    Vector2 axis = Vector2{24,24};

    int cellSize = 32;

    Grid grid = Grid(offset, axis, cellSize);

    while (WindowShouldClose() == false){
        Vector2 mouse_pos = GetMousePosition();
        if (IsMouseButtonPressed(0)){
            std::cout << "Left click pressed";
            Vector2 pos = grid.get(mouse_pos);
            std::cout << grid.grid[pos.x][pos.y] << "\n";
            grid.grid[pos.x][pos.y] = 1;
        }
        BeginDrawing();
        ClearBackground(WHITE);
        grid.draw();
        grid.hover(mouse_pos);
        EndDrawing();
    }
    CloseWindow();
}