#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

void scc(int code)
{
    if (code < 0)
    {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
    }
}

int main(void)
{
    scc(SDL_Init(SDL_INIT_VIDEO));

    // Setup window & renderer
    
    SDL_Event event;
    
    SDL_Window* window = SDL_CreateWindow("AMOGUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* image = SDL_LoadBMP("amogus.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);

    // SDL_Rect's
    //{{

    SDL_Rect image_rect = {
         .x = 0,
         .y = 0,
         .w = 500,
         .h = 500,
    };

    int velocity = 20;
    
    //}}

    
    bool quit = false;
    
    while (!quit)
    {
        SDL_WaitEvent(&event);

	switch (event.type)
        {
        case SDL_QUIT: {
            quit = true;
	} break;
	case SDL_KEYDOWN:{
	   switch (event.key.keysym.sym)
	   {
	   case SDLK_LEFT:{
	       image_rect.x -= velocity;
	   } break;
	   
	   case SDLK_RIGHT:{
	       image_rect.x += velocity;
	   } break;
	   
	   case SDLK_UP:{
	       image_rect.y -= velocity;
	   } break;
	   
	   case SDLK_DOWN:{
	       image_rect.y += velocity;
	   } break;

	   case SDLK_SPACE:{

	   } break;
	   }
        } break;
	}
	
	scc(SDL_RenderCopy(renderer, texture, NULL, &image_rect));
	SDL_RenderPresent(renderer);

	scc(SDL_RenderClear(renderer));
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    
    SDL_Quit();
    
    return 0;
}
