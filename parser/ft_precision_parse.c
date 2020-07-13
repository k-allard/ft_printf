/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_parse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/13 17:14:00 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

void		ft_precision_parse(va_list* argptr, const char* format, int*	i, t_format* argformat)
{
	int n;
	char *f;


	argformat->precision = 0;
	if (format[*i] == '.')
		(*i)++;
	else return ;
	
	if (format[*i] == '*')
		argformat->precision = va_arg(*argptr, int);
		
	else if (ft_isdigit(format[*i]))
	{
		f = (char *)format;
		argformat->precision = ft_atoi(&(f[*i]));
	}
	
	n = argformat->precision;
    while (n) 
	{
        n/=10;
        (*i)++; 
	}
}