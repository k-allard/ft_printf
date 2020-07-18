/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 14:00:27 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void	u_left(unsigned int arg, int dig, t_format *argformat, int *count)
{
	if (dig >= argformat->prec)
	{
		if (dig)
		{
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
			(*count) += dig;
		}
		width_increase(argformat, argformat->width - dig, count);
		return ;
	}
	writezeros(argformat->prec - dig, count);
	ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
	(*count) += dig;
	width_increase(argformat, argformat->width - argformat->prec, count);
}

static void	u_right(unsigned int arg, int dig, t_format *argformat, int *count)
{
	if (dig >= argformat->prec)
	{
		width_increase(argformat, argformat->width - dig, count);
		if (dig)
		{
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
			(*count) += dig;
		}
		return ;
	}
	width_increase(argformat, argformat->width - argformat->prec, count);
	writezeros(argformat->prec - dig, count);
	if (dig)
	{
		ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
		(*count) += dig;
	}
}

t_ok		ft_un_int_type(va_list *argptr, t_format *argformat, int *count)
{
	unsigned int	arg;
	int				dig;

	arg = (unsigned int)va_arg(*argptr, unsigned int);
	dig = digcount(arg);
	if (argformat->prec_is_present)
	{
		argformat->flags.zero = 0;
		if (argformat->prec == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->prec || argformat->width < dig)
	{
		if (dig <= argformat->prec)
			writezeros(argformat->prec - dig, count);
		ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
		(*count) += dig;
		return (OK);
	}
	argformat->flags.minus ? u_left(arg, dig, argformat, count) :
							u_right(arg, dig, argformat, count);
	return (OK);
}
