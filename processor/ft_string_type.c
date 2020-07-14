/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/14 23:36:13 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

// static void ft_str_leftaligned(char *arg, int symb, t_format* argformat)
// {
// 	int n;

// 	if (!argformat->precision_is_present || argformat->precision >= symb) //точность не отрежет строку
// 	{
// 		ft_putstr_fd(arg, 1);
// 		n = argformat->width - symb;
// 		while (n--)
// 			write(1, " ", 1);
// 	}
// 	else
// 	{
// 		n = argformat->precision;
// 		write(1, arg, n);
// 		n = argformat->width - argformat->precision;
// 		while (n--)
// 			write(1, " ", 1);
// 	}
// }

// static void ft_str_rightaligned(char *arg, int symb, t_format* argformat)
// {
// 	int n;

// 	if (!argformat->precision_is_present || argformat->precision >= symb) //точность не отрежет строку // добавить "или пресижн отсутствует"!!
// 	{
// 		n = argformat->width - symb;
// 		while (n--)
// 			write(1, " ", 1);
// 		ft_putstr_fd(arg, 1);
// 	}
// 	else
// 	{
// 		n = argformat->width - argformat->precision;
// 		while (n--)
// 			write(1, " ", 1);
// 		n = symb - argformat->precision;
// 		write(1, arg, n);
// 	}
// }

// t_ok		ft_string_type(va_list* argptr, t_format* argformat)
// {
// 	char *arg;
// 	// int n;
// 	int symb;	//кол-во символов в строке
	
// 	arg = va_arg(*argptr, char *);
// 	symb = ft_strlen(arg);
	
// 	if (argformat->width <= symb) 		//ширина и флаги не будут имеют значения
// 	{
// 		if (!argformat->precision_is_present) 
// 			ft_putstr_fd(arg, 1);
// 		else 
// 		{
// 			if (argformat->width <= argformat->precision)
// 			{
// 				if (argformat->precision < symb)
// 					write(1, arg, argformat->precision);
// 				else
// 					ft_putstr_fd(arg, 1);	
// 			}
// 			else
// 			{
// 				/* code */
// 			}
// 		}
// 	}
// 	else 
// 	{
// 		if (argformat->flags.minus)
// 			ft_str_leftaligned(arg, symb, argformat);
// 		else
// 			ft_str_rightaligned(arg, symb, argformat);
// 	}

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

t_ok		ft_string_type(va_list* argptr, t_format* argformat)
{
	char *arg;
	// int n;
	char *arg_new;
	int symb;	//кол-во символов в строке
	
	arg = va_arg(*argptr, char *);
	
	symb = ft_strlen(arg);
	
	if (argformat->precision_is_present && argformat->precision < symb)
	{
		if (!(arg_new = (char*)malloc(sizeof(*arg_new) * (argformat->precision + 1))))
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
