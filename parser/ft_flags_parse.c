/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/12 23:14:58 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"

void		ft_flags_parse(const char* format, int*	i, t_format* argformat)
{
	
	while (format[*i] == '-' || format[*i] == '0')
	{
		if (format[*i] == '-')
		{
			argformat->flags.minus = 1;
			argformat->flags.zero = 0;
			*i = *i + 1;
		}
		if (format[*i] == '0')
		{
			argformat->flags.zero = 1;
			*i = *i + 1;
		}

	}
}