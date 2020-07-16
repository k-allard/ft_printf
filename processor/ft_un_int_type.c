/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/16 21:40:06 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_un_int_leftaligned(unsigned int arg, int dig, t_format* argformat)
{
	int n; 	//n - кол-во пробелов/нулей до требуемой длины
	
	if (dig >= argformat->precision) //если число >= точности, точность значения не имеет
	{
		n = argformat->width - dig;
		if (dig)
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
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
		ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
		n = argformat->width - argformat->precision;
		if (argformat->flags.zero)
			while (n--)
				write(1, "0", 1);
		else
			while (n--)
				write(1, " ", 1);
	}
}

static void ft_un_int_rightaligned(unsigned int arg, int dig, t_format* argformat)
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
		if (dig)
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
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
		if (dig)
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
	}
}

t_ok		ft_un_int_type(va_list* argptr, t_format* argformat, int *count)
{
	
	unsigned int arg;
	unsigned int n;
	int dig;

*count = *count + 0;

	arg = (unsigned int)va_arg(*argptr, unsigned int);

	n = arg;
	dig = 0;
	while (n)
	{
		n /= 10;
		dig++;
	}
	if (arg == 0)
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
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
		else
		{
			n = argformat->precision - dig; //n - число нулей перед числом для соблюдения точности
			while (n--)
				write(1, "0", 1);
			ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
		}
	}
	else if (argformat->flags.minus)
		ft_un_int_leftaligned(arg, dig, argformat);
	else
		ft_un_int_rightaligned(arg, dig, argformat);	

	return OK;
}