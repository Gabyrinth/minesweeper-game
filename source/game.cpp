#include "game.hpp"

Game::Game(int width, int height, string title){
    // INITIALIZE WINDOW
    InitWindow(width, height, title.c_str());
    SetTargetFPS(30);
}

void Game::initGrid(int row, int col,int gap, int cellSize, Vector2 offset){
    Vector2 axis = {(float) row,(float) col};
    grid = make_unique<Grid>(offset, axis, cellSize, gap);
}

void Game::mainloop(){
    while(WindowShouldClose() == false){
        // EVENTS

        // GET MOUSE POSITION
        Vector2 mouse_position = GetMousePosition();

        if (IsMouseButtonPressed(0)) {
            // LEFT CLICK
        }

        if (IsMouseButtonPressed(1)) {
            // RIGHT CLICK

        }
        // DRAW
        BeginDrawing();
        // CLEAR
        ClearBackground(WHITE);
        // GRID DRAW
        grid->draw(mouse_position);
        EndDrawing();
    }
    // CLOSE WINDOW AFTER GAME CLOSE
    CloseWindow();
}

void Game::gameOver(){

}