#include <stdio.h>
#include "includes/ft_printf.h"


int main()
{
   int i = -1;
    while (i<2)
    {
        printf("[%04.2d]\n", i);
        ft_printf("[%04.2d]\n\n", i);
        i++;
    }
    return 0;
}