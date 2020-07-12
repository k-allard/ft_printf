/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/13 01:20:28 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

void ft_width_parse(va_list* argptr, const char* format, int*	i, t_format* argformat)
{	
	char *f;
	int n;
	if (format[*i] == '*')
		argformat->width = va_arg(*argptr, int);
	else if (ft_isdigit(format[*i]))
	{
		f = (char *)format;
		argformat->width = ft_atoi(&(f[*i]));
	}
		
	
	n = argformat->width;
	while ((n /= 10) >= 1)
		(*i)++;
}
