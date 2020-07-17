/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 23:17:46 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_percent_type(t_format* argformat, int* count)
{	
	if (argformat->width <= 1) //ширина и флаги выравнивания не будут нужны
		write(1, "%", 1);
	else if (argformat->flags.minus)
	{
		write(1, "%", 1);
		increase_to_width(argformat, argformat->width - 1, count);
	}
	else
	{
		increase_to_width(argformat, argformat->width - 1, count);
		write(1, "%", 1);
	}
	(*count)++;
	return OK;
}
