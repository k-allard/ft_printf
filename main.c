#include "includes/ft_printf.h"

int main()
{
    char *string = "Nastya [%d], X[%d]";

    ft_printf(string, 777, 2333);
    return 0;
}
