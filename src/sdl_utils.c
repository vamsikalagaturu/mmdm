#include "mmdm/sdl_utils.h"

void init_sdl(SDL_Window **pWindow, SDL_Renderer **pRenderer, int pWidth, int pHeight)
{
    SDL_Init(SDL_INIT_VIDEO);

    *pWindow = SDL_CreateWindow("Daagudumoothalu",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      pWidth,
      pHeight,
      SDL_WINDOW_ALLOW_HIGHDPI);
    *pRenderer = SDL_CreateRenderer(*pWindow, -1, 0);
}

void quit_sdl(SDL_Window *pWindow, SDL_Renderer *pRenderer)
{
    SDL_DestroyRenderer(pRenderer);
    SDL_DestroyWindow(pWindow);
    SDL_Quit();
}

void clear_screen(SDL_Renderer *pRenderer, int pR, int pG, int pB, int pA)
{
    SDL_SetRenderDrawColor(pRenderer, pR, pG, pB, pA);
    SDL_RenderClear(pRenderer);
}

void present_screen(SDL_Renderer *pRenderer) { SDL_RenderPresent(pRenderer); }

void load_texture(SDL_Renderer *pRenderer,
  const char *pFilename,
  SDL_Texture **pTexture,
  int *pResult)
{
    *pTexture = IMG_LoadTexture(pRenderer, pFilename);
    if (*pTexture == NULL) {
        fprintf(stderr, "Error creating texture: %s\n", SDL_GetError());
        *pResult = 1;
    } else {
        *pResult = 0;
    }
}