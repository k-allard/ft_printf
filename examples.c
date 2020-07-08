#include <stdio.h>

#define PAGES 999
#define BLURB "Authentic imitation!"

int main()
{
	printf("1--->\t *%d*\n", PAGES);
	printf("2--->\t *%2d*\n", PAGES);
	printf("3--->\t *%10d*\n", PAGES);
	printf("4--->\t *%-10d*\n", PAGES);
	printf("\n");

    printf("5--->\t %x %X %#x\n", 31, 31, 31);
	printf("6--->\t **%d**% d% d **\n", 42, 42, -42);
	printf("7--->\t [%5d] [%5.3d] [%05d] [%05.3d]\n", 6, 6, 6, 6);
	printf("\n");

    printf("8--->\t [%2s]\n", BLURB);
	printf("9--->\t [%24s]\n", BLURB);
	printf("10-->\t [%24.5s]\n", BLURB);
	printf("11-->\t [%-24.5s]\n", BLURB);

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
