#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    SDL_Window *window; // Declare a window
    SDL_Renderer *renderer; // Declare a renderer

    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2
    // SDL_Init is a function, argument to it tells which susbsystems we're gonna use

    // Create an application window with the following settings

    window = SDL_CreateWindow("Game Window", // Window title
                              SDL_WINDOWPOS_UNDEFINED, // Initial x position
                              SDL_WINDOWPOS_UNDEFINED, // Initial y position
                              640, // Width, in pixels
                              480, // Height, in pixels
                              0 // Flags
                              );

    // Creates a 640 x 480 game window, we don't care about the window position on the screen                          

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // We pass the window we just created, and the flag that says it is accelerated renderer 

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    // Sets the draw color, r, g, b and alpha (How opaque or translucent (rip) the object is)

    // Clear the screen (to blue)
    SDL_RenderClear(renderer);

    // Set the drawing color to white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Declaring a SDL Rect struct or object type
    SDL_Rect rect = { 220, 140, 200, 200 };
    // x, y, w, h
    SDL_RenderFillRect(renderer, &rect);

    // We are done drawing, now we present to the screen what we've drawn
    SDL_RenderPresent(renderer);

    // Wait a few seconds before quitting
    SDL_Delay(2000);

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Clean up
    SDL_Quit();

    return 0;
}