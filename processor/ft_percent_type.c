/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 13:30:57 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok	ft_percent_type(t_format *argformat, int *count)
{
	if (argformat->width <= 1)
		write(1, "%", 1);
	else if (argformat->flags.minus)
	{
		write(1, "%", 1);
		width_increase(argformat, argformat->width - 1, count);
	}
	else
	{
		width_increase(argformat, argformat->width - 1, count);
		write(1, "%", 1);
	}
	(*count)++;
	return (OK);
}
