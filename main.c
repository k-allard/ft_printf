/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 19:06:38 by csnowbal          #+#    #+#             */
/*   Updated: 2020/07/18 14:14:45 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
    // int std;
    // int my;
    // // ("%10.2p", NULL)
    // printf("\n\n1) standart PRINTF : |");
    // std = printf("%10.2p", NULL);
    // printf("|\n");
    // ft_printf("1) my       PRINTF : |");
    // my = ft_printf("%10.2p", NULL);
    // ft_printf("|\n");
    // printf("___________________\n");
    // printf("Output: %d vs %d\n\n", std, my);
    
    // // ("%2.5p", NULL)
    // printf("2) standart PRINTF : |");
    // std = printf("%2.5p", NULL);
    // printf("|\n");
    // ft_printf("2) my       PRINTF : |");
    // my = ft_printf("%2.5p", NULL);
    // ft_printf("|\n");
    // printf("___________________\n");
    // printf("Output: %d vs %d\n\n", std, my);
    
    //     // char *str = "HELLO";
    //     printf("\n\nstandart PRINTF : |");
    // std = printf("%3.3s", NULL);
    //     printf("|\n");
    //     ft_printf("my       PRINTF : |");
    // my = ft_printf("%3.3s", NULL);
    //     ft_printf("|\n");
    //     printf("___________________\n");
    //     printf("Output: %d vs %d\n\n", std, my);

    // // ("kekw %Z")
    // printf("\n\n4) standart PRINTF : |");
    // std = printf("kekw %Z");
    // printf("|\n");
    // ft_printf("4) my       PRINTF : |");
    // my = ft_printf("kekw %Z");
    // ft_printf("|\n");
    // printf("___________________\n");
    // printf("Output: %d vs %d\n\n", std, my);

    
    // // ("%")
    // printf("5) standart PRINTF : |");
    // std = printf("%");
    // printf("|\n");
    // ft_printf("5) my       PRINTF : |");
    // my = ft_printf("%");
    // ft_printf("|\n");
    // printf("___________________\n");
    // printf("Output: %d vs %d\n\n", std, my);
    
    // // ("%%%")
    // printf("6) standart PRINTF : |");
    // std = printf("%%%");
    // printf("|\n");
    // ft_printf("6) my       PRINTF : |");
    // my = ft_printf("%%%");
    // ft_printf("|\n");
    // printf("___________________\n");
    // printf("Output: %d vs %d\n\n", std, my);

    // printf("[%8.5x]\n", 34);
    ft_printf("[%8.5x]\n\n", 34);

    // printf("[%7x]\n", 33);
    ft_printf("[%7x]\n\n", 33);

    getc(stdin);
    
    return 0;

}
