/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/13 00:12:37 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_pointer_type(va_list* argptr, t_format* argformat)
{
	unsigned long int arg;
	arg = (unsigned long int)va_arg(*argptr, unsigned long int);
	write(1, "0x", 2);
	ft_putstr_fd(ft_itoa_convert(arg, 16), 1);
	
	if (argptr == NULL)
	{
		argformat = NULL;
		return ERROR;
	}
	return OK;
}