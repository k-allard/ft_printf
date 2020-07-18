/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 18:52:25 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

t_format		ft_parser(va_list *argptr, const char *format, int *i)
{
	t_format	argformat;

	argformat.ok = OK;
	ft_flags_parse(format, i, &argformat);
	ft_width_parse(argptr, format, i, &argformat);
	ft_prec_parse(argptr, format, i, &argformat);
	if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 's' || \
		format[*i] == '%' || format[*i] == 'c' || format[*i] == 'u' || \
		format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'p')
		argformat.type = format[(*i)++];
	return (argformat);
}
