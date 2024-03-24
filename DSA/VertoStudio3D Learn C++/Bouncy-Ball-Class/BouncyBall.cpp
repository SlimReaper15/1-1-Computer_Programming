#include "BouncyBall.h"
#include <math.h>

void BouncyBall::setTexture(SDL_Texture *tex) {
    texture = tex; // Current texture = argument
}

void BouncyBall::draw(SDL_Renderer *rend) {
    SDL_Rect rect = { (int)x, (int)y, 32, 32 };
    SDL_RenderCopy(rend, texture, nullptr, &rect);
}

void BouncyBall::update() {
    if (y > 0) {
        y += dy;
        dy += gravity;
    }
    else {
        dy *= -0.5;

        if (fabs(dy) < 0.01)
            dy = 0;
    }

}
    
void BouncyBall::setPos(float x, float y) {
    // We have to do x = x, how will we do it?
    // 'this' is a keyword, it is a pointer to the caller of the function

    // BouncyBall *this; // this points to the object that calls this function

    this->x = x;
    this->y = y;
}