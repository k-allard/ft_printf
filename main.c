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

    // // char *str = "HELLO";


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

    // printf("[%.0d]\n", 0);
    // ft_printf("[%.0d]\n\n", 0);

    // printf("[%-5.0d]\n", 0);
    // ft_printf("[%-5.0d]\n", 0);

    // printf("[%.*s]\n", -3, NULL);

    // ft_printf("[%.*s]\n", -3, 0);

    // printf("[%7x]\n", 33);
    // ft_printf("[%7x]\n\n", 33);

    // printf("[%8.5x]\n", 34);
    // ft_printf("[%8.5x]\n\n", 34);

    // printf("[%7x]\n", 33);
    // ft_printf("[%7x]\n\n", 33);


    // printf("[%-8.3x]\n", 8375);
    // ft_printf("[%-8.3x]\n", 8375);

    // printf("[%5.0x]\n", 0);
    // ft_printf("[%5.0x]\n\n", 0);

    // printf("[%.0x]\n", 0);
    // ft_printf("[%.0x]\n\n", 0);

    // printf("[%3u]\n", 0);
    // ft_printf("[%3u]\n", 0);

    // printf("[%*s]\n", 32, "abc");
    // ft_printf("[%*s]\n\n", 32, "abc");

    // printf("[%*s]\n", -32, "abc");
    // ft_printf("[%*s]\n\n", -32, "abc");


    // printf("%% *.5i 42 == |%*.5i|\n", 4, 42);
    // ft_printf("%% *.5i 42 == |%*.5i|\n", 4, 42);

    // int n;

    // n = ft_printf("[%-06d]", -123);
    // printf("\n%d\n", n - 2);


	

	printf("04) standart PRINTF : |");
	printf("kekw %Z");
	printf("|\n");
	ft_printf("04) my       PRINTF : |");
	ft_printf("kekw %Z");
	ft_printf("|\n");
	
    printf("05) standart PRINTF : |");
	int a = printf("%");
	printf("|\n");
	ft_printf("05) my       PRINTF : |");
	int b = ft_printf("%");
	ft_printf("|\n");
	printf("06) standart PRINTF : |");
	printf("%%%");
	printf("|\n");
	ft_printf("06) my       PRINTF : |");
	ft_printf("%%%");
	ft_printf("|\n\n");
	ft_printf("return fr st PRINTF : %d\nreturn fr my PRINTF : %d\n\n", a, b);

	


    return 0;

}
