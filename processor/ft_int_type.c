/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/14 13:28:34 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_int_leftaligned(int arg, int dig, t_format* argformat)
{
	int n; 	//n - кол-во пробелов/нулей до требуемой длины
	
	if (dig >= argformat->precision) //если число >= точности, точность значения не имеет
	{
		n = argformat->width - dig;
		ft_putnbr_fd(arg, 1);
		if (argformat->flags.zero)
			while (n--)
				write(1, "0", 1);
		else
			while (n--)
				write(1, " ", 1);
	}
	else 							//если число < точности
	{
		n = argformat->precision - dig;
		while (n--)
				write(1, "0", 1);
		ft_putnbr_fd(arg, 1);
		n = argformat->width - argformat->precision;
		if (argformat->flags.zero)
			while (n--)
				write(1, "0", 1);
		else
			while (n--)
				write(1, " ", 1);
	}
}

static void ft_int_rightaligned(int arg, int dig, t_format* argformat)
{
	int n; 	//n - кол-во пробелов/нулей до требуемой длины
	
	if (dig >= argformat->precision) //если число >= точности, точность значения не имеет
	{
		n = argformat->width - dig;
		if (argformat->flags.zero)
			while (n--)
				write(1, "0", 1);
		else
			while (n--)
				write(1, " ", 1);
		ft_putnbr_fd(arg, 1);
	}
	else 							//если число < точности
	{
		n = argformat->width - argformat->precision;
		if (argformat->flags.zero)
			while (n--)
				write(1, "0", 1);
		else
			while (n--)
				write(1, " ", 1);
		n = argformat->precision - dig;
		while (n--)
				write(1, "0", 1);
		ft_putnbr_fd(arg, 1);
	}
}

t_ok		ft_int_type(va_list* argptr, t_format* argformat)
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
	if (arg < 0)
		dig++;
	
	if (argformat->precision)
		argformat->flags.zero = 0;
		
	if (argformat->width < argformat->precision || argformat->width < dig) //случаи когда ширина и флаги выравнивания не нужны
	{
		if (dig > argformat->precision)	//число < точности -> точность тоже не нужна
			ft_putnbr_fd(arg, 1);
		else
		{
			n = argformat->precision - dig; //n - число нулей перед числом для соблюдения точности
			while (n--)
				write(1, "0", 1);
			ft_putnbr_fd(arg, 1);
		}
	}
	else if (argformat->flags.minus)
		ft_int_leftaligned(arg, dig, argformat);
	else
		ft_int_rightaligned(arg, dig, argformat);

	return OK;
}