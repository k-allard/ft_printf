/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/14 19:00:56 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_char_type(va_list* argptr, t_format* argformat)
{
	char arg;
	// int n;

	arg = (char)va_arg(*argptr, int);

	if (argformat->width <= 1) //ширина и флаги выравнивания не будут нужны
		ft_putchar_fd(arg, 1);
	else if (argformat->flags.minus)
	{
		ft_putchar_fd(arg, 1);
		while (--argformat->width)
			write(1, " ", 1);
	}
	else
	{
		while (--argformat->width)
			write(1, " ", 1);
		ft_putchar_fd(arg, 1);
	}
	
	return OK;
}