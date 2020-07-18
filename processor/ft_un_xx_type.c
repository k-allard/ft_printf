/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_xx_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 14:20:58 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void	xx_left(char *arg, int symb, t_format *argformat, int *count)
{
	if (!argformat->prec_is_present || argformat->prec <= symb)
	{
		if (symb)
		{
			ft_putstr_fd(arg, 1);
			(*count) += symb;
		}
		writespaces(argformat->width - symb, count);
		return ;
	}
	writezeros(argformat->prec - symb, count);
	ft_putstr_fd(arg, 1);
	(*count) += symb;
	writespaces(argformat->width - argformat->prec, count);
}

static void	xx_right(char *arg, int symb, t_format *argformat, int *count)
{
	if (!argformat->prec_is_present || argformat->prec <= symb)
		width_increase(argformat, argformat->width - symb, count);
	else
	{
		width_increase(argformat, argformat->width - argformat->prec, count);
		writezeros(argformat->prec - symb, count);
	}
	if (symb)
	{
		ft_putstr_fd(arg, 1);
		(*count) += symb;
	}
}

static t_ok	no_width(char *print, int dig, t_format *argformat, int *count)
{
	if (dig > argformat->prec)
	{
		ft_putstr_fd(print, 1);
		(*count) += dig;
		return (OK);
	}
	writezeros(argformat->prec - dig, count);
	ft_putstr_fd(print, 1);
	(*count) += dig;
	return (OK);
}

t_ok		ft_un_xx_type(va_list *argptr, t_format *argformat, int *count)
{
	unsigned int	arg;
	char			*print;
	int				dig;
	int				n;

	arg = (unsigned int)va_arg(*argptr, unsigned int);
	print = ft_itoa_convert(arg, 16);
	dig = ft_strlen(print);
	n = dig;
	while (argformat->type == X && n--)
		print[n] = (char)ft_toupper((int)print[n]);
	if (argformat->prec_is_present)
	{
		argformat->flags.zero = 0;
		if (argformat->prec == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->prec || argformat->width < dig)
		no_width(print, dig, argformat, count);
	else
		argformat->flags.minus ? xx_left(print, dig, argformat, count) :
								xx_right(print, dig, argformat, count);
	free(print);
	return (OK);
}
