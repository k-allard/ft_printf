/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/13 00:35:53 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_un_int_type(va_list* argptr, t_format* argformat)
{
	
	unsigned int arg;
	arg = (unsigned int)va_arg(*argptr, unsigned int);
	
	ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
	
	if (argptr == NULL)
	{
		argformat = NULL;
		return ERROR;
	}
	return OK;
}