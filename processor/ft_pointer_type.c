/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 18:59:30 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_nullptr_with_prec(char *arg, int dig, t_format* argformat, int *count)
{	
	if (argformat->width <= argformat->precision + 2)//width значения не имеет
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
		(*count) += dig;
		writezeros(argformat->precision - dig + 2, count);
		return ;
	}
	if (argformat->flags.minus)
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
		(*count) += dig;
		writezeros(argformat->precision - dig + 2, count);
		writespaces(argformat->width - argformat->precision - 2, count);
		return ;
	}
	writespaces(argformat->width - argformat->precision - 2, count);
	write(1, "0x", 2);
	ft_putstr_fd(arg, 1);
	(*count) += dig;
	writezeros(argformat->precision - dig + 2, count);
}

static void ft_ptr_aligned(char *arg, int dig, t_format* argformat, int *count)
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

t_ok		ft_pointer_type(va_list* argptr, t_format* argformat, int *count)
{
	unsigned long int arg;
	char* print;
	int dig;

	arg = (unsigned long int)va_arg(*argptr, unsigned long int);
	print = ft_itoa_convert(arg, 16);
	dig = ft_strlen(print) + 2;	
	if (!arg && argformat->precision_is_present && argformat->precision > dig - 2)
		ft_nullptr_with_prec(print, dig, argformat, count);
	else if (argformat->width <= dig) //ширина и флаги выравнивания не будут нужны
	{
		write(1, "0x", 2);
		ft_putstr_fd(print, 1);
		(*count) += dig;
		if(argformat->precision > dig - 2)
			writezeros(argformat->precision - dig + 2, count);
	}
	else
		ft_ptr_aligned(print, dig, argformat, count);	
	return OK;
}