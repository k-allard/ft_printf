#include "includes/ft_printf.h"
#include <limits.h>
#include <stdio.h>

// cspdiuxX%
int main()
{
    char *string = "Nastya [%s]\nPercent: [%%]\n[%d] and [%n] are digits\n[%c] is a char\n[%u] is un int max\n";
    ft_printf(string, "Smirnova", 777, 4, '$', 4294967295);

    char *string2 = "Hex: [%X]\n[%p] is a pointer\n";
    ft_printf(string2, 79, string);
    // printf(string2, 79, string);

    return 0;
}
