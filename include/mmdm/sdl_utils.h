#ifndef MMDM_SDL_UTILS_H
#define MMDM_SDL_UTILS_H

#include <SDL.h>
#include <SDL_image.h>

void init_sdl(SDL_Window **pWindow, SDL_Renderer **pRenderer, int pWidth, int pHeight);

void quit_sdl(SDL_Window *pWindow, SDL_Renderer *pRenderer);

void clear_screen(SDL_Renderer *pRenderer, int pR, int pG, int pB, int pA);

void present_screen(SDL_Renderer *pRenderer);

void load_texture(SDL_Renderer *pRenderer,
  const char *pFilename,
  SDL_Texture **pTexture,
  int *pResult);

#endif// MMDM_SDL_UTILS_H
