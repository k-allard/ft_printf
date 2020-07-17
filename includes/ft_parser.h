/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/18 00:06:59 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef enum	e_type
{
	d = 'd',
	i = 'i',
	o = 'o',
	u = 'u',
	x = 'x',
	s = 's',
	X = 'X',
	c = 'c',
	p = 'p',
	percent = '%'
}				t_type;

typedef struct	s_flags
{
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
}				t_flags;

typedef	enum	e_ok
{
	OK,
	ERROR
}				t_ok;

typedef	struct	s_format
{
	t_flags		flags;
	int			width;
	int			precision_is_present;
	int			precision;
	int			length;
	t_type		type;
	t_ok		ok;
}				t_format;

void			ft_flags_parse(const char *format, int *i, t_format *argformat);
void			ft_length_parse(const char *format, int *i, \
				t_format *argformat);
t_format		ft_parser(va_list *argptr, const char *format, int *i);
void			ft_precision_parse(va_list *argptr, const char *format, \
				int *i, t_format *argformat);
void			ft_width_parse(va_list *argptr, const char *format, int *i, \
				t_format *argformat);

#endif
