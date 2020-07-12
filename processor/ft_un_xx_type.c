/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_xx_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/12 22:15:38 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_un_xx_type(va_list* argptr, t_format* argformat)
{
	unsigned int arg;
	char* print;
	int i;
	
	arg = (unsigned int)va_arg(*argptr, unsigned int);
	print = ft_itoa_convert(arg, 16);
	if (argformat->type == X)
	{
		i = 0;
		while (print[i])
		{
			print[i] = (char)ft_toupper((int)print[i]);
			i++;
		}
	}
	ft_putstr_fd(print, 1);
	
	if (argptr == NULL)
	{
		argformat = NULL;
		return ERROR;
	}
	return OK;
}