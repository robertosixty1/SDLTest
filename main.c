#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "ERROR: could not initialize SDL: %s", SDL_GetError());
        exit(1);
    }

    // Setup window & renderer
    
    SDL_Event event;
    
    SDL_Window* window = SDL_CreateWindow("AMOGUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* image = SDL_LoadBMP("amogus.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // SDL_Rect's

    SDL_Rect image_rect = {
         .x = 0,
         .y = 0,
         .w = 500,
         .h = 500,
     };
    
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
	
	SDL_RenderCopy(renderer, texture, NULL, &image_rect);
	SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    
    return 0;
}
