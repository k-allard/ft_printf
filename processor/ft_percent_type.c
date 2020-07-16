/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/16 21:39:27 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_percent_type(t_format* argformat, int* count)
{
	*count = *count + 0;
	
	if (argformat->width <= 1) //ширина и флаги выравнивания не будут нужны
		write(1, "%", 1);
	
	else if (argformat->flags.minus)
	{
		write(1, "%", 1);
		while (--argformat->width)
		{
			if (argformat->flags.zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	}
	else
	{
		while (--argformat->width)
		{
			if (argformat->flags.zero)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		write(1, "%", 1);
	}

	return OK;
}