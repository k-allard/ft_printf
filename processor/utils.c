/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 21:26:26 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 21:14:06 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"
# include <unistd.h>

void	writespaces(int n, int* count)
{
	(*count) += n;
	while (n--)
		write(1, " ", 1);
}

void	writezeros(int n, int* count)
{
	(*count) += n;
	while (n--)
		write(1, "0", 1);
}

void increase_to_width(t_format* argformat, int n, int* count)
{
	if (argformat->flags.zero)
		writezeros(n, count);
	else
		writespaces(n, count);
}

int digcount(long long arg)
{
	long long n;
	int dig;

	n = arg;
	dig = 0;
	while(n)
	{
		n /= 10;
		dig++;
	}
	if (arg <= 0)
		dig++;
	return(dig);
}