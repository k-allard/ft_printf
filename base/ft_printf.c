#include "../includes/ft_printf.h"
#include "../includes/ft_parser.h"
#include "../includes/ft_processor.h"
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char* format, ...)
{
	int	i;
	int c;
	t_format	argformat;
	t_ok		result;

	va_list argptr;
	va_start(argptr, format);

	c = 0;
	i = 0;
	while(format[i])
	{
		if(format[i] == '%')
		{
			i++;
			argformat = ft_parser(&argptr, format, &i);
			if ((result = ft_processor(&argptr, &argformat, &c)) == ERROR)
				break;
		}
		else
		{
			write(1, &format[i++], 1);
			c++;
		}
	}
	va_end(argptr);
	if(argformat.ok == ERROR || result == ERROR)
		return (-1);
	else
		return (c);
}