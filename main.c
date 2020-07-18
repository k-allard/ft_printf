#include <stdio.h>
#include "includes/ft_printf.h"

#define PAGES 999
#define BLURB "Authentic imitation!"

int main()
{
	ft_printf("1--->\t *%d*\n", PAGES);
	ft_printf("2--->\t *%2d*\n", PAGES);
	ft_printf("3--->\t *%10d*\n", PAGES);
	ft_printf("4--->\t *%-10d*\n", PAGES);
	ft_printf("\n");

    ft_printf("5--->\t %x %X %#x\n", 31, 31, 31);
	ft_printf("6--->\t **%d**% d% d **\n", 42, 42, -42);
	ft_printf("7--->\t [%5d] [%5.3d] [%05d] [%05.3d]\n", 6, 6, 6, 6);
	ft_printf("\n");

    ft_printf("8--->\t [%2s]\n", BLURB);
	ft_printf("9--->\t [%24s]\n", BLURB);
	ft_printf("10-->\t [%24.5s]\n", BLURB);
	ft_printf("11-->\t [%-24.5s]\n", BLURB);

    getc(stdin);

	return 0;
}

/*
1--->    *999*
2--->    *999*
3--->    *       999*
4--->    *999       *

5--->    1f 1F 0x1f
6--->    **42** 42-42 **
7--->    [    6] [  006] [00006] [  006]

8--->    [Authentic imitation!]
9--->    [    Authentic imitation!]
10-->    [                   Authe]
11-->    [Authe                   ]
*/
