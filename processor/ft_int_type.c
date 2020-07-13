/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/13 15:15:22 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

t_ok		ft_int_type(va_list* argptr, t_format* argformat)
{
	int arg;
	int n;
	int dig;
	
	arg = va_arg(*argptr, int);
	
	n = arg;
	dig = 0;
	while (n)
	{
		n /= 10;
		dig++;
	}
	if (argformat->width > dig)
	{
		n = argformat->width - dig;
		if (argformat->flags.minus == 0)
		{
			if (argformat->flags.zero)
				while (n--)
					write(1, "0", 1);
			else
				while (n--)
					write(1, " ", 1);
			ft_putnbr_fd(arg, 1);
		}
		else if (argformat->flags.minus == 1)
		{
			ft_putnbr_fd(arg, 1);
			if (argformat->flags.zero)
				while (n--)
					write(1, "0", 1);
			else
				while (n--)
					write(1, " ", 1);
		}		
	}
	else ft_putnbr_fd(arg, 1);

	return OK;
}