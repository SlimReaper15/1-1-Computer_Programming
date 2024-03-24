#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct {
    int x, y;
    short life;
    char *name;
} Man;

int processEvents(SDL_Window *window, Man *man) {

    SDL_Event event;
    int done = 0;

    while (SDL_PollEvent(&event)) {
        // This loop runs until the game quits

        // PollEvent returns true if there is an event to be processed or returns false
        // The inner while loop processes events in the event system and return them to us, doesn't run for a very long time, a few times at most per frame 

        // event struct will now (after PollEvent returns) contain the type of event and data specific to the event

        switch(event.type) {
            case SDL_WINDOWEVENT_CLOSE:
                if (window) {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    done = 1;
                }
                break;

            case SDL_KEYDOWN: // User presses a key on the keyboard
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE: // Escape key
                        done = 1;
                        break;
                    
                    // case SDLK_RIGHT:
                    //     man->x += 10;
                    //     break;

                    // case SDLK_LEFT:
                    //     man->x -= 10;
                    //     break;
                }
                break;

            case SDL_QUIT:
                // Quit out of the game
                done = 1;
                break;
        }
    }

    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_LEFT])
        man->x -= 10;
    if (state[SDL_SCANCODE_RIGHT])
        man->x += 10;
    if (state[SDL_SCANCODE_UP])
        man->y -= 10;
    if (state[SDL_SCANCODE_DOWN])
        man->y += 10;

    // If the if statement is true when the function is called (once per frame)
    // If the key we're interested in is down at all
    // It will be down the whole frame


    // We continuously see if the key we're interested in is down
    // More fluid animation

    return done;
}

void doRender(SDL_Renderer *renderer, Man *man) {
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect rect = { man->x, man->y, 200, 200 };

    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {

    SDL_Window *window; // Declare a window
    SDL_Renderer *renderer; // Declare a renderer

    SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2
    // SDL_Init is a function, argument to it tells which susbsystems we're gonna use

    Man man;
    man.x = 220;
    man.y = 140;

    // Create an application window with the following settings

    window = SDL_CreateWindow("Game Window", // Window title
                              SDL_WINDOWPOS_UNDEFINED, // Initial x position
                              SDL_WINDOWPOS_UNDEFINED, // Initial y position
                              640, // Width, in pixels
                              480, // Height, in pixels
                              0 // Flags
                              );

    // Creates a 640 x 480 game window, we don't care about the window position on the screen                          

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // We pass the window we just created, and the flag that says it is accelerated renderer 



    // The window is open: Enter program loop (See SDL_PollEvent)
    int done = 0;

    // Event loop
    while (!(done)) {
        // Check for events
        done = processEvents(window, &man);

        // Render display
        doRender(renderer, &man);

        // Don't burn up the CPU
        // SDL_Delay(10);
        // Replace with vsync
    }

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Clean up
    SDL_Quit();

    return 0;
}