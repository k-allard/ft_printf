/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/11 21:28:51 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_string_type(va_list* argptr, t_format* argformat)
{
	char *arg;
	if ((argptr == NULL || argformat == NULL))
	{
		return ERROR;
	}
	arg = va_arg(*argptr, char *);
	ft_putstr_fd(arg, 1);

	return OK;
}