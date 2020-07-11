#include "includes/ft_printf.h"

int main()
{
    char *string = "Nastya [%s], X[%d]";

    ft_printf(string, "Smirnova", 777);
    return 0;
}
