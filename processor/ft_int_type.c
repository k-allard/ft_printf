/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kallard <kallard@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 11:05:00 by kallard           #+#    #+#             */
/*   Updated: 2020/07/16 22:59:10 by kallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_processor.h"

static void ft_int_leftaligned(int arg, int dig, t_format* argformat, int* count)
{
	int n; 	//n - кол-во пробелов/нулей до требуемой длины
	
	if (!argformat->precision_is_present || dig >= argformat->precision) //точность не нужна
	{
		if (dig)
			ft_putnbr_fd(arg, 1);
		n = argformat->width - dig;
		if (argformat->flags.zero)
			writezeros(n);
		else
			writespaces(n);
		(*count) += n + dig;
		return ;
	}
	//надо дополнять инт до точности
	if (arg < 0)
	{
		write(1, "-", 1);
		n = argformat->precision - dig + 1;
		writezeros(n);
		ft_putnbr_fd(-arg, 1);
		(*count) += n + dig;
		n = argformat->width - argformat->precision - 1;
		writespaces(n);
		(*count) += n;
		return ;
	}
	n = argformat->precision - dig;
	writezeros(n);
	ft_putnbr_fd(arg, 1);
	(*count) += n + dig;
	n = argformat->width - argformat->precision;
	if (argformat->flags.zero)
		writezeros(n);
	else
		writespaces(n);
	(*count) += n;
}

static void ft_int_rightaligned(int arg, int dig, t_format* argformat, int* count)
{
	int n; 	//n - кол-во пробелов/нулей до требуемой длины
	
	if (!argformat->precision_is_present || dig >= argformat->precision) //точность значения не имеет
	{
		if (arg < 0)
		{
			if (argformat->flags.zero)
			{
				write(1, "-", 1);
				n = argformat->width - dig;
				writezeros(n);
				ft_putnbr_fd(-arg, 1);
				(*count) += n + dig;
				return ;
			}
			n = argformat->width - dig;
			writespaces(n);
			ft_putnbr_fd(arg, 1);
			(*count) += n + dig;
			return ;
		}
		n = argformat->width - dig;
		if (argformat->flags.zero)
			writezeros(n);
		else
			writespaces(n);
		if (dig)
			ft_putnbr_fd(arg, 1);
		(*count) += n + dig;
		return ;
	}
	//далее точность значение имеет
	if (arg < 0)
	{
		n = argformat->width - argformat->precision - 1;
		if (argformat->flags.zero)
			writezeros(n);
		else
			writespaces(n);
		(*count) += n;
		write(1, "-", 1);
		n = argformat->precision - dig + 1;
		writezeros(n);
		ft_putnbr_fd(-arg, 1);
		(*count) += n + dig;
		return ;
	}
	n = argformat->width - argformat->precision;
	if (argformat->flags.zero)
		writezeros(n);
	else
		writespaces(n);
	(*count) += n;
	n = argformat->precision - dig;
	writezeros(n);
	ft_putnbr_fd(arg, 1);
	(*count) += n + dig;
}

t_ok		ft_int_type(va_list* argptr, t_format* argformat, int* count)
{
	int arg;
	int n;
	int dig;
	
	// *count = *count + 0;
	
	arg = va_arg(*argptr, int);
	
	n = arg;
	dig = 0;
	while (n)
	{
		n /= 10;
		dig++;
	}
	if (arg <= 0)
		dig++;
	if (argformat->precision_is_present)
	{
		argformat->flags.zero = 0;     //Для типов d, i, o, u, x, X, если точность указана, флаг 0 игнорируется.
		if (argformat->precision == 0 && arg == 0)
			dig = 0;
	}
	if (argformat->width < argformat->precision || argformat->width < dig) //случаи когда ширина и флаги выравнивания не нужны
	{
		if (dig > argformat->precision)	//число < точности -> точность тоже не нужна
		{
			ft_putnbr_fd(arg, 1);
			(*count) += dig;
			return OK;
		}
		if (arg < 0)
		{
			write(1, "-", 1);
			n = argformat->precision - dig + 1; //n - число нулей перед числом для соблюдения точности
			writezeros(n);
			ft_putnbr_fd(-arg, 1);
			(*count) += n + dig;		//it works!!
			return OK;
		}
		n = argformat->precision - dig; //n - число нулей перед числом для соблюдения точности
		writezeros(n);
		ft_putnbr_fd(arg, 1);
		(*count) += n + dig;
		return OK;
	}
	if (argformat->flags.minus)
		ft_int_leftaligned(arg, dig, argformat, count);
	else
		ft_int_rightaligned(arg, dig, argformat, count);

	return OK;
}