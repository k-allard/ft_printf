/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/13 22:58:56 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_str_leftaligned(char *arg, int symb, t_format* argformat)
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
		n = symb - argformat->precision;
		while (n--)
			write(1, arg++, 1);
		n = argformat->width - argformat->precision;
		while (n--)
			write(1, " ", 1);
	}
}

static void ft_str_rightaligned(char *arg, int symb, t_format* argformat)
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
		while (n--)
			write(1, arg++, 1);
	}
}

t_ok		ft_string_type(va_list* argptr, t_format* argformat)
{
	char *arg;
	int n;
	int symb;	//кол-во символов в строке
	
	arg = va_arg(*argptr, char *);
	symb = ft_strlen(arg);
	
	if (argformat->width <= argformat->precision && argformat->width <= symb) //когда точность и кол-во символов в строке >= ширины, ширина и флаги не имеют значения
	{
		if (argformat->precision < symb)
		{
			n = symb - argformat->precision;
			while (n--)
				write(1, arg++, 1);
		}
		else
			ft_putstr_fd(arg, 1);
	}
	else if (argformat->flags.minus)
		ft_str_leftaligned(arg, symb, argformat);
	else
		ft_str_rightaligned(arg, symb, argformat);
	
	return OK;
}
	
	
// 	// ft_putstr_fd(arg, 1);

// 	return OK;
// }