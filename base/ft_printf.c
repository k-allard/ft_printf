/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 23:25:09 by kallard           #+#    #+#             */
/*   Updated: 2020/07/17 23:37:13 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_parser.h"
#include "../includes/ft_processor.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	t_format	argformat;
	t_ok		result;
	va_list		argptr;

	va_start(argptr, format);
	count = 0;
	i = 0;
	while (format[i])
		if (format[i] == '%')
		{
			i++;
			argformat = ft_parser(&argptr, format, &i);
			if ((result = ft_processor(&argptr, &argformat, &count)) == ERROR)
				break ;
		}
		else
		{
			write(1, &format[i++], 1);
			count++;
		}
	va_end(argptr);
	return ((argformat.ok == ERROR || result == ERROR) ? -1 : count);
}
