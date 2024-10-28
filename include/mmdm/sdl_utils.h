#ifndef MMDM_SDL_UTILS_H
#define MMDM_SDL_UTILS_H

// Function declaration for addition
int add(int pA, int pB);

// Function declaration for subtraction
int subtract(int pA, int pB);

int multiply(int pA, int pB)
{
    int result = 0;
    int run = 0;
    for (int i = 0; i < pB; i++) { result = add(result, pA); }
    return result;
}

#endif// MMDM_SDL_UTILS_H
