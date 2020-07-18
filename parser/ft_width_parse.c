/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 12:50:38 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

static void	basic_width_parse(const char *format, int *i, t_format *argformat)
{
	char	*f;
	int		n;

	f = (char *)format;
	argformat->width = ft_atoi(&(f[*i]));
	n = argformat->width;
	while (n)
	{
		n /= 10;
		(*i)++;
	}
}

void		ft_width_parse(va_list *argptr, const char *format, int *i, \
			t_format *argformat)
{
	argformat->width = 0;
	if (format[*i] == '*')
	{
		argformat->width = va_arg(*argptr, int);
		(*i)++;
		if (argformat->width < 0)
		{
			argformat->flags.minus = 1;
			argformat->flags.zero = 0;
			argformat->width *= -1;
		}
	}
	else if (ft_isdigit(format[*i]))
		basic_width_parse(format, i, argformat);
}
