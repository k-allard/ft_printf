#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

// cspdiuxX%
int main()
{
    // char *string = "Nastya [%s]\nPercent: [%%]\n[%d] and [%i] are digits\n[%c] is a char\n[%u] is un int max\n";
    // ft_printf(string, "Smirnova", 777, 4, '$', 4294967295);

    // char *string2 = "Hex: [%X]\n[%p] is a pointer\n";
    // ft_printf(string2, 79, string);

    // char *str = "HELLO";


    // printf("hello, [%s].", NULL);
    //     printf("\n");
    // ft_printf("hello, [%s].", NULL);
    //     printf("\n\n");

    // printf("[%s]", NULL);
    //     printf("\n");
    // ft_printf("[%s]", NULL);
    //     printf("\n\n");


    // printf("[%32s]", NULL);
    //     printf("\n");
    // ft_printf("[%32s]", NULL);
    //     printf("\n\n");

    // printf("[%2s]", NULL);
    //     printf("\n");
    // ft_printf("[%2s]", NULL);
    //     printf("\n\n");

    // printf("[%-16s]", NULL);
    //     printf("\n");
    // ft_printf("[%-16s]", NULL);
    //     printf("\n\n");

    // printf("[%-3.2s]", NULL);
    //     printf("\n");
    // ft_printf("[%-3.2s]", NULL);
    //     printf("\n\n");

    // printf("[%-1.02s]\n", "123"); 
    // ft_printf("[%-1.02s]\n", "123"); 

    // printf("[%07d]\n", -54);
    // ft_printf("[%07d]\n\n", -54);

    // printf("[%7d]\n", -14);
    // ft_printf("[%7d]\n\n", -14);

    // printf("[%10.5d]\n", -216);
    // ft_printf("[%10.5d]\n\n", -216);

    // printf("[%3.7d]\n", -2375);
    // ft_printf("[%3.7d]\n\n", -2375);

    // printf("[%-10.5d]\n", -216);
    // ft_printf("[%-10.5d]\n", -216);

    printf("[%.0d]\n", 0);
    ft_printf("[%.0d]\n\n", 0);

    printf("[%-5.0d]\n", 0);
    ft_printf("[%-5.0d]\n", 0);

    return 0;
}
