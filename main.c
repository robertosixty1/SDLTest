#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>

static const char* music_path = "amogus.mp3";

void scc(int code)
{
    if (code < 0)
    {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
    }
}

int main(void)
{
    scc(SDL_Init(SDL_INIT_EVERYTHING));

    // Setup music

    int result = 0;
    int flags = MIX_INIT_MP3;
    if (flags != (result = Mix_Init(flags))) {
        fprintf(stderr, "Could not initialize mixer (result: %d).\n", result);
        fprintf(stderr, "Mix_Init: %s\n", Mix_GetError());
        exit(1);
    }

    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    Mix_Music *music = Mix_LoadMUS(music_path);
    Mix_PlayMusic(music, 1000000);

    // Setup window & renderer

    SDL_Event event;

    SDL_Window* window = SDL_CreateWindow("AMOGUS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_Surface* image = SDL_LoadBMP("amogus1.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

    SDL_Surface* imageb = SDL_LoadBMP("amogus2.bmp");
    SDL_Texture* textureb = SDL_CreateTextureFromSurface(renderer, imageb);


    SDL_SetRenderDrawColor(renderer, 127, 127, 127, 255);

    // SDL_Rect's
    //{{

    SDL_Rect imagea_rect = {
         .x = 0,
         .y = 0,
         .w = 500,
         .h = 500,
    };

    SDL_Rect imageb_rect = {
         .x = 0,
         .y = 0,
         .w = 500,
         .h = 500,
    };

    bool which = true;
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
                if (which)
                {
                    imagea_rect.x -= velocity;
                }
                else
                {
                    imageb_rect.x -= velocity;
                }
            } break;

            case SDLK_RIGHT:{
                if (which)
                {
                    imagea_rect.x += velocity;
                }
                else
                {
                    imageb_rect.x += velocity;
                }
            } break;

            case SDLK_UP:{
                if (which)
                {
                    imagea_rect.y -= velocity;
                }
                else
                {
                imageb_rect.y -= velocity;
                }
            } break;

            case SDLK_DOWN:{
                if (which)
                {
                    imagea_rect.y += velocity;
                }
                else
                {
                    imageb_rect.y += velocity;
                }
            } break;

            case SDLK_SPACE:{
                which = !which;
            } break;

            }
        } break;

        }

        scc(SDL_RenderCopy(renderer, texture, NULL, &imagea_rect));
        scc(SDL_RenderCopy(renderer, textureb, NULL, &imageb_rect));
        SDL_RenderPresent(renderer);

        scc(SDL_RenderClear(renderer));
    }

    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);

    SDL_DestroyTexture(textureb);
    SDL_FreeSurface(imageb);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Mix_FreeMusic(music);

    Mix_Quit();
    SDL_Quit();

    return 0;
}
