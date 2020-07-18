/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 13:34:47 by kallard          ###   ########.fr       */
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
	argformat->prec = ft_atoi(&(f[*i]));
	n = argformat->prec;
	while (n)
	{
		n /= 10;
		(*i)++;
	}
}

void		ft_prec_parse(va_list *argptr, const char *format, int *i, \
			t_format *argformat)
{
	argformat->prec_is_present = 0;
	argformat->prec = 0;
	if (format[*i] == '.')
	{
		argformat->prec_is_present = 1;
		(*i)++;
	}
	else
		return ;
	if (format[*i] == '*')
	{
		argformat->prec = va_arg(*argptr, int);
		(*i)++;
		if (argformat->prec < 0)
			argformat->prec_is_present = 0;
	}
	else if (ft_isdigit(format[*i]))
		basic_prec_parse(format, i, argformat);
}
