/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 22:01:49 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_int_leftaligned(int arg, int dig, t_format* argformat, int* count)
{	
	if (!argformat->precision_is_present || dig >= argformat->precision) //точность не нужна
	{
		if (dig)
			putnbr_count(arg, dig, count);
		increase_to_width(argformat, argformat->width - dig, count);
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
	increase_to_width(argformat, argformat->width - argformat->precision, count);
}

static void ft_int_rightaligned(int arg, int dig, t_format* argformat, int* count)
{	
	if (!argformat->precision_is_present || dig >= argformat->precision) //точность значения не имеет
	{
		if (arg < 0 && argformat->flags.zero)
        {
            write(1, "-", 1);
            arg = -arg;
        } 
        increase_to_width(argformat, argformat->width - dig, count);
        if (dig)
            putnbr_count(arg, dig, count);
		return ;
	}
	if (arg < 0)
	{
		increase_to_width(argformat, argformat->width - argformat->precision - 1, count);
		write(1, "-", 1);
		writezeros(argformat->precision - dig + 1, count);
		putnbr_count(-arg, dig, count);
		return ;
	}
	increase_to_width(argformat, argformat->width - argformat->precision, count);
	writezeros(argformat->precision - dig, count);
	putnbr_count(arg, dig, count);
}

static t_ok no_width(int arg, int dig, t_format* argformat, int* count)
{
	int n;
	
	if (dig > argformat->precision)	//точность тоже не нужна
	{
		putnbr_count(arg, dig, count);
		return OK;
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
	return OK;
}

t_ok		ft_int_type(va_list* argptr, t_format* argformat, int* count)
{
	int arg;
	int n;
	int dig;
		
	arg = va_arg(*argptr, int);
	dig = digcount(arg);
	if (argformat->precision_is_present)
	{
		argformat->flags.zero = 0;     //Для типов d, i, o, u, x, X, если точность указана, флаг 0 игнорируется.
		if (argformat->precision == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->precision || argformat->width < dig) //случаи когда ширина и флаги выравнивания не нужны
		return(no_width(arg, dig, argformat, count));
	argformat->flags.minus ? ft_int_leftaligned(arg, dig, argformat, count) : ft_int_rightaligned(arg, dig, argformat, count);
	return OK;
}