#include <stdio.h>
#include "mmdm/sdl_utils.h"

int main()
{
    int x = 10, y = 5;
    printf("Addition of %d and %d is: %d\n", x, y, add(x, y));
    printf("Subtraction of %d and %d is: %d\n", x, y, subtract(x, y));
    return 0;
}
