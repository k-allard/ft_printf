/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 15:07:37 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void	u_left(char *print, int dig, t_format *argformat, int *count)
{
	if (dig >= argformat->prec)
	{
		if (dig)
		{
			ft_putstr_fd(print, 1);
			(*count) += dig;
		}
		width_increase(argformat, argformat->width - dig, count);
		return ;
	}
	writezeros(argformat->prec - dig, count);
	ft_putstr_fd(print, 1);
	(*count) += dig;
	width_increase(argformat, argformat->width - argformat->prec, count);
}

static void	u_right(char *print, int dig, t_format *argformat, int *count)
{
	if (dig >= argformat->prec)
	{
		width_increase(argformat, argformat->width - dig, count);
		if (dig)
		{
			ft_putstr_fd(print, 1);
			(*count) += dig;
		}
		return ;
	}
	width_increase(argformat, argformat->width - argformat->prec, count);
	writezeros(argformat->prec - dig, count);
	if (dig)
	{
		ft_putstr_fd(print, 1);
		(*count) += dig;
	}
}

static void	un_nowidth(char *print, int dig, t_format *argformat, int *count)
{
	if (dig <= argformat->prec)
		writezeros(argformat->prec - dig, count);
	ft_putstr_fd(print, 1);
	(*count) += dig;
}

t_ok		ft_un_int_type(va_list *argptr, t_format *argformat, int *count)
{
	unsigned int	arg;
	int				dig;
	char			*print;

	arg = (unsigned int)va_arg(*argptr, unsigned int);
	dig = digcount(arg);
	if (!(print = ft_itoa_convert(arg, 10)))
		return (ERROR);
	if (argformat->prec_is_present)
	{
		argformat->flags.zero = 0;
		if (argformat->prec == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->prec || argformat->width < dig)
		un_nowidth(print, dig, argformat, count);
	else
		argformat->flags.minus ? u_left(print, dig, argformat, count) :
								u_right(print, dig, argformat, count);
	free(print);
	return (OK);
}
