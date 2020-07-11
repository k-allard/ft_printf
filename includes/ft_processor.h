/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/11 11:11:18 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROCESSOR_H
# define FT_PROCESSOR_H

# include <stdarg.h>
# include <unistd.h>
# include "ft_parser.h"

t_ok		ft_char_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_e_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_f_inf_nan(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_f_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_int_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_n_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_percent_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_pointer_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_processor(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_string_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_un_int_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_un_o_type(va_list* argptr, const char* format, int*	i, t_format* argformat);
t_ok		ft_un_xx_type(va_list* argptr, const char* format, int*	i, t_format* argformat);

#endif