#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "ERROR: could not initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    SDL_Event event;
    
    SDL_Window* window = SDL_CreateWindow("AMOGUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* image = SDL_LoadBMP("amogus.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    bool quit = false;
    
    while (!quit)
    {
        SDL_WaitEvent(&event);

	switch (event.type)
        {
        case SDL_QUIT: {
            quit = true;
	} break;
        }

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    
    return 0;
}
