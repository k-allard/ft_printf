/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/15 10:21:24 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_str_aligned(char *arg, int symb, t_format* argformat)
{
	int n;
	n = argformat->width - symb;
	
	if (argformat->flags.minus) 	// ft_str_leftaligned
	{
		ft_putstr_fd(arg, 1);
		while (n--)
			write(1, " ", 1);
	}
	else 							// ft_str_rightaligned
	{
		while (n--)
			write(1, " ", 1);
		ft_putstr_fd(arg, 1);
	}
}

static t_ok ft_nullstring(t_format* argformat)
{
	char *arg;
	int symb = 6;
	
	if (argformat->precision_is_present && argformat->precision < symb) // то есть (null) обрежется
		symb = argformat->precision;

	if (!(arg = ft_strnew(symb)))
		return ERROR;
	ft_strlcpy(arg, "(null)", symb + 1);
	
	if (argformat->width <= symb) 		//ширина и флаги не будут имеют значения
		ft_putstr_fd(arg, 1);
	else
		ft_str_aligned(arg, symb, argformat);
	free(arg);	
	return OK;
}

t_ok		ft_string_type(va_list* argptr, t_format* argformat)
{
	char *arg;
	// int n;
	char *arg_new;
	int symb;	//кол-во символов в строке
	
	arg = va_arg(*argptr, char *);

	if (arg == NULL)
	{
		ft_nullstring(argformat);
		return OK;
	}
	
	symb = ft_strlen(arg);
	
	if (argformat->precision_is_present && argformat->precision < symb)
	{
		if (!(arg_new = ft_strnew(argformat->precision)))
			return (ERROR);
		ft_strlcpy(arg_new, arg, argformat->precision + 1);
		symb = argformat->precision;
		if (argformat->width <= symb) 		//ширина и флаги не будут имеют значения
			ft_putstr_fd(arg_new, 1);
		else
			ft_str_aligned(arg_new, symb, argformat);
		free(arg_new);
	}
	//точность больше не имеет значения
	else if (argformat->width <= symb) 		//ширина и флаги не будут имеют значения
			ft_putstr_fd(arg, 1);
	else
			ft_str_aligned(arg, symb, argformat);


	return OK;
}
