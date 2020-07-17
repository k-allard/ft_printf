/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_xx_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 22:25:01 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_xx_leftaligned(char *arg, int symb, t_format* argformat, int *count)
{
	// int n;
	
	if (!argformat->precision_is_present || argformat->precision <= symb) //точность не дополняет нулями число
	{
		if (symb)
		{
			ft_putstr_fd(arg, 1);
			(*count) += symb;
		}
		writespaces(argformat->width - symb, count);
	}
	else //точность дополняет нулями число
	{
		writezeros(argformat->precision - symb, count);
		ft_putstr_fd(arg, 1);
		(*count) += symb;
		writespaces(argformat->width - argformat->precision, count);
	}
}

static void ft_xx_rightaligned(char *arg, int symb, t_format* argformat, int *count)
{
	// int n;
	
	if (!argformat->precision_is_present || argformat->precision <= symb) //точность не дополняет нулями число
		increase_to_width(argformat, argformat->width - symb, count);
	else //точность дополняет нулями число
	{
		increase_to_width(argformat, argformat->width - argformat->precision, count);
		writezeros(argformat->precision - symb, count);
	}
	if (symb)
	{
		ft_putstr_fd(arg, 1);
		(*count) += symb;
	}	
}

t_ok		ft_un_xx_type(va_list* argptr, t_format* argformat, int *count)
{
	unsigned int arg;
	char* print;
	int dig;
	int n;
	
	arg = (unsigned int)va_arg(*argptr, unsigned int);
	print = ft_itoa_convert(arg, 16);
	dig = ft_strlen(print);
	n = dig;
	if (argformat->type == X)
		while (n--)
			print[n] = (char)ft_toupper((int)print[n]);
	if (argformat->precision_is_present)
	{
		argformat->flags.zero = 0;   //Для типов d, i, o, u, x, X, если точность указана, флаг 0 игнорируется.
		if (argformat->precision == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->precision || argformat->width < dig) //ширина и ее флаги не нужны
	{
		if (dig > argformat->precision)	//число < точности -> точность тоже не нужна
		{
			ft_putstr_fd(print, 1);
			(*count) += dig;
		}
		else
		{
			writezeros(argformat->precision - dig, count);
			ft_putstr_fd(print, 1);
			(*count) += dig;
		}
		return OK;
	}
	argformat->flags.minus ? ft_xx_leftaligned(print, dig, argformat,count) : ft_xx_rightaligned(print, dig, argformat, count);	
	return OK;
}