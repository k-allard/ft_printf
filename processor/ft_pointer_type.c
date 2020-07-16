/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/16 21:42:57 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_ptr_aligned(char *arg, int dig, t_format* argformat)
{	
	int n;
	
	n = argformat->width - dig;
	if (argformat->flags.minus)
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
	}
	while (n--)
		write(1, " ", 1);
	if (!(argformat->flags.minus))
	{
		write(1, "0x", 2);
		ft_putstr_fd(arg, 1);
	}
}

t_ok		ft_pointer_type(va_list* argptr, t_format* argformat, int* count)
{
	unsigned long int arg;
	char* print;
	int dig;

	*count = *count + 0;

	arg = (unsigned long int)va_arg(*argptr, unsigned long int);
	print = ft_itoa_convert(arg, 16);
	dig = ft_strlen(print) + 2;

	if (argformat->width <= dig) //ширина и флаги выравнивания не будут нужны
	{
		write(1, "0x", 2);
		ft_putstr_fd(print, 1);
	}
	else
		ft_ptr_aligned(print, dig, argformat);	
	
	return OK;

}