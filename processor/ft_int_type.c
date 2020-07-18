/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 13:14:27 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void	int_leftaligned(int arg, int dig, t_format *argformat, int *count)
{
	if (!argformat->precision_is_present || dig >= argformat->precision)
	{
		if (dig)
			putnbr_count(arg, dig, count);
		width_increase(argformat, argformat->width - dig, count);
		return ;
	}
	if (arg < 0)
	{
		write(1, "-", 1);
		writezeros(argformat->precision - dig + 1, count);
		putnbr_count(-arg, dig, count);
		writespaces(argformat->width - argformat->precision - 1, count);
		return ;
	}
	writezeros(argformat->precision - dig, count);
	putnbr_count(arg, dig, count);
	width_increase(argformat, argformat->width - argformat->precision, count);
}

static void	int_right_prec(int arg, int dig, t_format *argformat, int *count)
{
	int n;

	n = argformat->width - argformat->precision;
	if (arg < 0)
	{
		width_increase(argformat, n - 1, count);
		write(1, "-", 1);
		writezeros(argformat->precision - dig + 1, count);
		putnbr_count(-arg, dig, count);
		return ;
	}
	width_increase(argformat, n, count);
	writezeros(argformat->precision - dig, count);
	putnbr_count(arg, dig, count);
}

static void	int_rightaligned(int arg, int dig, t_format *argformat, int *count)
{
	if (!argformat->precision_is_present || dig >= argformat->precision)
	{
		if (arg < 0 && argformat->flags.zero)
		{
			write(1, "-", 1);
			arg = -arg;
		}
		width_increase(argformat, argformat->width - dig, count);
		if (dig)
			putnbr_count(arg, dig, count);
	}
	else
		int_right_prec(arg, dig, argformat, count);
}

static t_ok	no_width(int arg, int dig, t_format *argformat, int *count)
{
	int n;

	if (dig > argformat->precision)
	{
		putnbr_count(arg, dig, count);
		return (OK);
	}
	n = 0;
	if (arg < 0)
	{
		write(1, "-", 1);
		n = 1;
		arg = -arg;
	}
	n += argformat->precision - dig;
	writezeros(n, count);
	putnbr_count(arg, dig, count);
	return (OK);
}

t_ok		ft_int_type(va_list *argptr, t_format *argformat, int *count)
{
	int arg;
	int dig;

	arg = va_arg(*argptr, int);
	dig = digcount(arg);
	if (argformat->precision_is_present)
	{
		argformat->flags.zero = 0;
		if (argformat->precision == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->precision || argformat->width < dig)
		return (no_width(arg, dig, argformat, count));
	argformat->flags.minus ? int_leftaligned(arg, dig, argformat, count) :
							int_rightaligned(arg, dig, argformat, count);
	return (OK);
}
