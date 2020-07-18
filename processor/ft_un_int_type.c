/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 13:00:07 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_un_int_leftaligned(unsigned int arg, int dig, t_format* argformat, int *count)
{	
	if (dig >= argformat->precision) //если число >= точности, точность значения не имеет
	{
		if (dig)
		{
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
			(*count) += dig;
		}
		width_increase(argformat, argformat->width - dig, count);
		return ;
	}
	writezeros(argformat->precision - dig, count);
	ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
	(*count) += dig;
	width_increase(argformat, argformat->width - argformat->precision, count);
}

static void ft_un_int_rightaligned(unsigned int arg, int dig, t_format* argformat, int *count)
{
	if (dig >= argformat->precision) //если число >= точности, точность значения не имеет
	{
		width_increase(argformat, argformat->width - dig, count);
		if (dig)
		{
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
			(*count) += dig;
		}
		return ;
	}
	width_increase(argformat, argformat->width - argformat->precision, count);
	writezeros(argformat->precision - dig, count);
	if (dig)
	{
		ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
		(*count) += dig;
	}
}

t_ok		ft_un_int_type(va_list* argptr, t_format* argformat, int *count)
{
	unsigned int arg;
	int dig;
	
	arg = (unsigned int)va_arg(*argptr, unsigned int);
	dig = digcount(arg);
	if (argformat->precision_is_present)
	{
		argformat->flags.zero = 0;   //Для типов d, i, o, u, x, X, если точность указана, флаг 0 игнорируется.
		if (argformat->precision == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->precision || argformat->width < dig) //случаи когда ширина и флаги выравнивания не нужны
	{
		if (dig <= argformat->precision)	//число < точности -> точность тоже не нужна
			writezeros(argformat->precision - dig, count);
		ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
		(*count) += dig;
		return OK;
	}
	argformat->flags.minus ? ft_un_int_leftaligned(arg, dig, argformat, count) : ft_un_int_rightaligned(arg, dig, argformat, count);	
	return OK;
}