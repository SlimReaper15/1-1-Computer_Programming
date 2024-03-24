#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "BouncyBall.h"

static SDL_Texture *ball = nullptr;

int processEvents(SDL_Window *window) {
    SDL_Event event;
    int done = 0p;

    while (SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_WINDOWEVENT_CLOSE
        }
    }
}