/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 13:34:47 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_str_aligned(char *arg, int symb, t_format* argformat, int *count)
{
	if (argformat->flags.minus)
	{
		ft_putstr_fd(arg, 1);
		writespaces(argformat->width - symb, count);
	}
	else
	{
		writespaces(argformat->width - symb, count);
		ft_putstr_fd(arg, 1);
	}
	(*count) += symb;
}

static t_ok ft_nullstring(t_format* argformat, int *count)
{
	char *arg;
	int symb;

	symb = 6;
	if (argformat->prec_is_present && argformat->prec < symb) // то есть (null) обрежется
		symb = argformat->prec;
	if (!(arg = ft_strnew(symb)))
		return ERROR;
	ft_strlcpy(arg, "(null)", symb + 1);
	if (argformat->width <= symb) 		//ширина и флаги не будут имеют значения
	{
		ft_putstr_fd(arg, 1);
		(*count) += symb;
	}
	else
		ft_str_aligned(arg, symb, argformat, count);
	free(arg);
	return OK;
}

t_ok		ft_string_type(va_list *argptr, t_format *argformat, int *count)
{
	char *arg;
	char *arg_new;
	int symb;	//кол-во символов в строке
		
	arg = va_arg(*argptr, char *);
	if (!arg)
	{
		ft_nullstring(argformat, count);
		return OK;
	}
	symb = ft_strlen(arg);
	if (argformat->prec_is_present && argformat->prec < symb) 	//точность имеет значение
	{
		if (!(arg_new = ft_strnew(argformat->prec)))
			return (ERROR);
		ft_strlcpy(arg_new, arg, argformat->prec + 1);
		symb = argformat->prec;
		if (argformat->width <= symb) 		//ширина и флаги не будут имеют значения
		{
			ft_putstr_fd(arg_new, 1);
			(*count) += symb;
		}
		else
			ft_str_aligned(arg_new, symb, argformat, count);
		free(arg_new);
	}
	//точность больше не имеет значения
	else if (argformat->width <= symb) 		//ширина и флаги не будут имеют значения
	{
		ft_putstr_fd(arg, 1);
		(*count) += symb;
	}
	else
		ft_str_aligned(arg, symb, argformat, count);
	return OK;
}
