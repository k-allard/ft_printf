/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_xx_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/14 14:43:10 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_xx_leftaligned(char *arg, int symb, t_format* argformat)
{
	int n;

	if (argformat->precision >= symb) //точность не отрежет строку
	{
		ft_putstr_fd(arg, 1);
		n = argformat->width - symb;
		while (n--)
			write(1, " ", 1);
	}
	else
	{
		n = argformat->precision;
		write(1, arg, n);
		n = argformat->width - argformat->precision;
		while (n--)
			write(1, " ", 1);
	}
}

static void ft_xx_rightaligned(char *arg, int symb, t_format* argformat)
{
	int n;

	if (argformat->precision >= symb) //точность не отрежет строку
	{
		n = argformat->width - symb;
		while (n--)
			write(1, " ", 1);
		ft_putstr_fd(arg, 1);
	}
	else
	{
		n = argformat->width - argformat->precision;
		while (n--)
			write(1, " ", 1);
		n = symb - argformat->precision;
		write(1, arg, n);
	}
}

t_ok		ft_un_xx_type(va_list* argptr, t_format* argformat)
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

	if (argformat->precision)
		argformat->flags.zero = 0;   //Для типов d, i, o, u, x, X, если точность указана, флаг 0 игнорируется.
	
	if (argformat->width < argformat->precision || argformat->width < dig) //случаи когда ширина и флаги выравнивания не нужны
	{
		if (dig > argformat->precision)	//число < точности -> точность тоже не нужна
			ft_putstr_fd(print, 1);
		else
		{
			n = argformat->precision - dig; //n - число нулей перед числом для соблюдения точности
			while (n--)
				write(1, "0", 1);
			ft_putstr_fd(print, 1);
		}
	}
	else if (argformat->flags.minus)
		ft_xx_leftaligned(print, dig, argformat);
	else
		ft_xx_rightaligned(print, dig, argformat);	
	
	
	return OK;
}