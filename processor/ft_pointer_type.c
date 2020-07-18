/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 14:40:39 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void	nullptr_prec(char *arg, int dig, t_format *argformat, int *count)
{
	if (argformat->width <= argformat->prec + 2)
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
		(*count) += dig;
		writezeros(argformat->prec - dig + 2, count);
		return ;
	}
	if (argformat->flags.minus)
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
		(*count) += dig;
		writezeros(argformat->prec - dig + 2, count);
		writespaces(argformat->width - argformat->prec - 2, count);
		return ;
	}
	writespaces(argformat->width - argformat->prec - 2, count);
	write(1, "0x", 2);
	ft_putstr_fd(arg, 1);
	(*count) += dig;
	writezeros(argformat->prec - dig + 2, count);
}

static void	ft_ptr_aligned(char *arg, int dig, t_format *argformat, int *count)
{
	if (argformat->flags.minus)
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
	}
	writespaces(argformat->width - dig, count);
	if (!(argformat->flags.minus))
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
	}
	(*count) += dig;
}

t_ok		ft_pointer_type(va_list *argptr, t_format *argformat, int *count)
{
	unsigned long int	arg;
	char				*print;
	int					dig;

	arg = (unsigned long int)va_arg(*argptr, unsigned long int);
	if (!(print = ft_itoa_convert(arg, 16)))
		return (ERROR);
	dig = ft_strlen(print) + 2;
	if (!arg && argformat->prec_is_present && argformat->prec > dig - 2)
		nullptr_prec(print, dig, argformat, count);
	else if (argformat->width <= dig)
	{
		write(1, "0x", 2);
		ft_putstr_fd(print, 1);
		(*count) += dig;
		if (argformat->prec > dig - 2)
			writezeros(argformat->prec - dig + 2, count);
	}
	else
		ft_ptr_aligned(print, dig, argformat, count);
	free(print);
	return (OK);
}
