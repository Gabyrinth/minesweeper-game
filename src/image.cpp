#include "image.hpp"

std::vector<Texture2D> getImages(){
    Texture2D mineImage = LoadTexture("image/mine.png");
    Texture2D flagImage = LoadTexture("image/flag.png");
    return {mineImage, flagImage};
}
