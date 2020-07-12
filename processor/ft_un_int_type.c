/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_int_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/12 21:52:16 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"


// char		*ft_un_itoa(unsigned int n)
// {
// 	char	*str;
// 	unsigned int dig;
// 	int		len;

// 	dig = n;
// 	len = 1;
// 	while ((dig /= 10) > 0)
// 		len++;
// 	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
// 		return (NULL);
// 	str[len--] = '\0';
// 	while (len >= 0)
// 	{
// 		str[len] = n % 10 + '0';
// 		n /= 10;
// 		len--;
// 	}
// 	return (str);
// }

t_ok		ft_un_int_type(va_list* argptr, t_format* argformat)
{
	
	unsigned int arg;
	arg = (unsigned int)va_arg(*argptr, unsigned int);
	
	ft_putstr_fd(ft_itoa_convert(arg, 10), 1);
	
	if (argptr == NULL)
	{
		argformat = NULL;
		return ERROR;
	}
	return OK;
}