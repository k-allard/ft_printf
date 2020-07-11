#include "includes/ft_printf.h"

int main()
{
    char *string = "Nastya%d, X%d";

    ft_printf(string, 1, 2);

    return 0;
}
