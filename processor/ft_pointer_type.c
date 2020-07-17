/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 15:59:34 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_nullptr_with_prec(char *arg, int dig, t_format* argformat, int *count)
{
	int zeros;
	int spases;
	
	if (argformat->width <= argformat->precision + 2)//width значения не имеет
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
		zeros = argformat->precision - dig + 2;
		writezeros(zeros);
		(*count) += dig + zeros;
		return ;
	}
	if (argformat->flags.minus)
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
		zeros = argformat->precision - dig + 2;
		writezeros(zeros);
		spases = argformat->width - argformat->precision - 2;
		writespaces(spases);
		(*count) += dig + zeros + spases;
		return ;
	}
	spases = argformat->width - argformat->precision - 2;
	writespaces(spases);
	write(1, "0x", 2);
	ft_putstr_fd(arg, 1);
	zeros = argformat->precision - dig + 2;
	writezeros(zeros);
	(*count) += spases + dig + zeros;
}

static void ft_ptr_aligned(char *arg, int dig, t_format* argformat, int *count)
{	
	int n;

	n = argformat->width - dig;
	if (argformat->flags.minus)
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
	}
	writespaces(n);
	if (!(argformat->flags.minus))
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
	}
	(*count) += dig + n;

}

t_ok		ft_pointer_type(va_list* argptr, t_format* argformat, int *count)
{
	unsigned long int arg;
	char* print;
	int dig;
	int n;


	arg = (unsigned long int)va_arg(*argptr, unsigned long int);

	print = ft_itoa_convert(arg, 16);
	dig = ft_strlen(print) + 2;	

	if (!arg && argformat->precision_is_present && argformat->precision > dig - 2)
		ft_nullptr_with_prec(print, dig, argformat, count);
	else if (argformat->width <= dig) //ширина и флаги выравнивания не будут нужны
	{
		write(1, "0x", 2);
		ft_putstr_fd(print, 1);
		n = 0;
		if(argformat->precision > dig - 2)
		{
			n = argformat->precision - dig + 2;
			writezeros(n);
		}
		(*count) += dig + n;
	}
	else
		ft_ptr_aligned(print, dig, argformat, count);	
	
	return OK;

}