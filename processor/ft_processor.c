/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/13 00:13:34 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

char	*ft_itoa_convert(unsigned long value, unsigned long base)
{
	char				*s;
	unsigned long 		n;
	int					len;

	len = 1;
	n = value;
	while ((n /= base) >= 1)
		len++;
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len] = '\0';
	n = value;
	while (len--)
	{
		s[len] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}

t_ok		ft_processor(va_list* argptr, t_format* argformat)
{
	if (argformat->type == d || argformat->type == n)
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