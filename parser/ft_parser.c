/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/11 21:17:30 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

// https://ru.wikipedia.org/wiki/Printf
t_format		ft_parser(va_list* argptr, const char* format, int*	i)
{
	//%[флаги][ширина][.точность][размер]тип
	t_format	argformat;

	argformat.ok = OK;
	ft_flags_parse(format, i, &argformat);
	ft_width_parse(argptr, format, i, &argformat);
	ft_precision_parse(argptr, format, i, &argformat);
	ft_modifier_parse(format, i, &argformat);
	if(format[*i] == 'd' || format[*i] == 'n')
	{
		argformat.type = format[*i];
		*i = *i + 1;
	}
	if(format[*i] == 's')
	{
		argformat.type = format[*i];
		*i = *i + 1;
	}

	return (argformat);
}