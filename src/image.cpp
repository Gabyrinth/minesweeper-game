#include "image.hpp"

const Texture2D mineImage = LoadTexture("image/mine.png");
const Texture2D flagImage = LoadTexture("image/flag.png");

std::vector<Texture2D> getImages(){
    return {mineImage, flagImage};
}
