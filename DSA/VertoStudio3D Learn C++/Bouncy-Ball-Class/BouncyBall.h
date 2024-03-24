#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class BouncyBall {
    public:

    void setTexture(SDL_Texture *tex);
    void draw(SDL_Renderer *rend);
    void update(); // Updates the internal position, x, y, etc of the bouncy ball to draw in the proper position
    
    void setPos(float x, float y);

    private:
    
    SDL_Texture *texture = nullptr; // Pass the texture to the bouncy ball to tell it the texture
    float x = 0, y = 0;
    float dy = 0; // Velocity of ball
    const float gravity = -0.02; // Down is positive
};