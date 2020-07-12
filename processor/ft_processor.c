/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/13 00:54:48 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_processor(va_list* argptr, t_format* argformat)
{
	if (argformat->type == d || argformat->type == i)
		return ft_int_type(argptr, argformat);
	if (argformat->type == s)
		return ft_string_type(argptr, argformat);
	if (argformat->type == percent)
		return ft_percent_type(argptr, argformat);
	if (argformat->type == c)
		return ft_char_type(argptr, argformat);
	if (argformat->type == u)
		return ft_un_int_type(argptr, argformat);
	if (argformat->type == x || argformat->type == X)
		return ft_un_xx_type(argptr, argformat);
	if (argformat->type == p)
		return ft_pointer_type(argptr, argformat);
	return ERROR;
}