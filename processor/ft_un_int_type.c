/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 18:01:33 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_un_int_leftaligned(unsigned int arg, int dig, t_format* argformat, int *count)
{
	int n;
	
	if (dig >= argformat->precision) //если число >= точности, точность значения не имеет
	{
		n = argformat->width - dig;
		if (dig)
		{
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
			(*count) += dig;
		}
		increase_to_width(argformat, n, count);
		return ;
	}
	//если число < точности
	n = argformat->precision - dig;
	writezeros(n, count);
	ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
	(*count) += dig;
	n = argformat->width - argformat->precision;
	increase_to_width(argformat, n, count);
}

static void ft_un_int_rightaligned(unsigned int arg, int dig, t_format* argformat, int *count)
{
	int n; 	//n - кол-во пробелов/нулей до требуемой длины

	if (dig >= argformat->precision) //если число >= точности, точность значения не имеет
	{
		n = argformat->width - dig;
		increase_to_width(argformat, n, count);
		if (dig)
		{
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
			(*count) += dig;
		}
		return ;
	}
	n = argformat->width - argformat->precision;
	increase_to_width(argformat, n, count);
	n = argformat->precision - dig;
	writezeros(n, count);
	if (dig)
	{
		ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
		(*count) += dig;
	}
}

t_ok		ft_un_int_type(va_list* argptr, t_format* argformat, int *count)
{
	
	unsigned int arg;
	unsigned int n;
	int dig;
	
	arg = (unsigned int)va_arg(*argptr, unsigned int);
	n = arg;
	dig = 0;
	while (n)
	{
		n /= 10;
		dig++;
	}
	if (!arg)
		dig++;
	if (argformat->precision_is_present)
	{
		argformat->flags.zero = 0;   //Для типов d, i, o, u, x, X, если точность указана, флаг 0 игнорируется.
		if (argformat->precision == 0 && arg == 0)
			dig = 0;
	}
	
	if (argformat->width < argformat->precision || argformat->width < dig) //случаи когда ширина и флаги выравнивания не нужны
	{
		if (dig > argformat->precision)	//число < точности -> точность тоже не нужна
		{
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
			(*count) += dig;
		}
		else
		{
			n = argformat->precision - dig; //n - число нулей перед числом для соблюдения точности
			writezeros(n, count);
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
			(*count) += dig;
		}
	}
	else if (argformat->flags.minus)
		ft_un_int_leftaligned(arg, dig, argformat, count);
	else
		ft_un_int_rightaligned(arg, dig, argformat, count);	

	return OK;
}