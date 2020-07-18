/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 12:53:55 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok	ft_char_type(va_list *argptr, t_format *argformat, int *count)
{
	char	arg;
	int		n;

	arg = (char)va_arg(*argptr, int);
	if (argformat->width <= 1)
	{
		ft_putchar_fd(arg, 1);
		(*count)++;
	}
	else if (argformat->flags.minus)
	{
		ft_putchar_fd(arg, 1);
		(*count)++;
		n = argformat->width - 1;
		writespaces(n, count);
	}
	else
	{
		n = argformat->width - 1;
		writespaces(n, count);
		ft_putchar_fd(arg, 1);
		(*count)++;
	}
	return (OK);
}
