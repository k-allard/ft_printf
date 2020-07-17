/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 18:05:21 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_int_leftaligned(int arg, int dig, t_format* argformat, int* count)
{
	int n; 	//n - кол-во пробелов/нулей до требуемой длины
	
	if (!argformat->precision_is_present || dig >= argformat->precision) //точность не нужна
	{
		if (dig)
		{
			ft_putnbr_fd(arg, 1);
			(*count) += dig;
		}
		increase_to_width(argformat, argformat->width - dig, count);
		return ;
	}
	//надо дополнять инт до точности
	if (arg < 0)
	{
		write(1, "-", 1);
		writezeros(argformat->precision - dig + 1, count);
		ft_putnbr_fd(-arg, 1);
		(*count) += dig;
		writespaces(argformat->width - argformat->precision - 1, count);
		return ;
	}
	writezeros(argformat->precision - dig, count);
	ft_putnbr_fd(arg, 1);
	(*count) += dig;
	increase_to_width(argformat, argformat->width - argformat->precision, count);
}

static void ft_int_rightaligned(int arg, int dig, t_format* argformat, int* count)
{
	int n; 	//n - кол-во пробелов/нулей до требуемой длины
	
	if (!argformat->precision_is_present || dig >= argformat->precision) //точность значения не имеет
	{
		n = argformat->width - dig;
		if (arg < 0 && argformat->flags.zero)
        {
            write(1, "-", 1);
            arg = -arg;
        } 
        increase_to_width(argformat, n, count);
        if (dig)
		{
            ft_putnbr_fd(arg, 1);
			(*count) += dig;
		}
		return ;
	}
	//далее точность значение имеет
	if (arg < 0)
	{
		increase_to_width(argformat, argformat->width - argformat->precision - 1, count);
		write(1, "-", 1);
		writezeros(argformat->precision - dig + 1, count);
		ft_putnbr_fd(-arg, 1);
		(*count) += dig;
		return ;
	}
	increase_to_width(argformat, argformat->width - argformat->precision, count);
	writezeros(argformat->precision - dig, count);
	ft_putnbr_fd(arg, 1);
	(*count) += dig;
}

t_ok		ft_int_type(va_list* argptr, t_format* argformat, int* count)
{
	int arg;
	int n;
	int dig;
		
	arg = va_arg(*argptr, int);
	n = arg;
	dig = 0;
	while (n)
	{
		n /= 10;
		dig++;
	}
	if (arg <= 0)
		dig++;
	if (argformat->precision_is_present)
	{
		argformat->flags.zero = 0;     //Для типов d, i, o, u, x, X, если точность указана, флаг 0 игнорируется.
		if (argformat->precision == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->precision || argformat->width < dig) //случаи когда ширина и флаги выравнивания не нужны
	{
		if (dig > argformat->precision)	//число < точности -> точность тоже не нужна
		{
			ft_putnbr_fd(arg, 1);
			(*count) += dig;
			return OK;
		}
		n = 0; //мб не нужно
		if (arg < 0)
		{
			write(1, "-", 1);
			n = 1; //n - число нулей перед числом для соблюдения точности
			arg = -arg;
		}
		n += argformat->precision - dig; //n - число нулей перед числом для соблюдения точности
		writezeros(n, count);
		ft_putnbr_fd(arg, 1);
		(*count) += dig;
		return OK;
	}
	if (argformat->flags.minus)
		ft_int_leftaligned(arg, dig, argformat, count);
	else
		ft_int_rightaligned(arg, dig, argformat, count);

	return OK;
}