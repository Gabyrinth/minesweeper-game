#include "game.hpp"

Game::Game(int width, int height, string title){
    // INITIALIZE WINDOW
    InitWindow(width, height, title.c_str());
    SetTargetFPS(30);
}

void Game::initGrid(int row, int col, int cellSize, Vector2 offset){
    Vector2 axis = {(float) row,(float) col};
    grid = make_unique<Grid>(offset, axis, cellSize);
}

void Game::mainloop(){
    while(WindowShouldClose() == false){
        // EVENTS
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
        grid->draw();
        EndDrawing();
    }
    // CLOSE WINDOW AFTER GAME CLOSE
    CloseWindow();
}

void Game::gameOver(){

}