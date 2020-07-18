/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 12:43:11 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

static void	basic_prec_parse(const char *format, int *i, t_format *argformat)
{
	char	*f;
	int		n;

	while (format[*i] == '0')
		(*i)++;
	f = (char *)format;
	argformat->precision = ft_atoi(&(f[*i]));
	n = argformat->precision;
	while (n)
	{
		n /= 10;
		(*i)++;
	}
}

void		ft_prec_parse(va_list *argptr, const char *format, int *i, \
			t_format *argformat)
{
	argformat->precision_is_present = 0;
	argformat->precision = 0;
	if (format[*i] == '.')
	{
		argformat->precision_is_present = 1;
		(*i)++;
	}
	else
		return ;
	if (format[*i] == '*')
	{
		argformat->precision = va_arg(*argptr, int);
		(*i)++;
		if (argformat->precision < 0)
			argformat->precision_is_present = 0;
	}
	else if (ft_isdigit(format[*i]))
		basic_prec_parse(format, i, argformat);
}
