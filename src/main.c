#include "mmdm/main.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

void main_loop() {}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    init_sdl(&window, &renderer, 700, 700);

    main_loop();

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(main_loop, 0, 1);
#endif

    return 0;
}