#include "../includes/ft_printf.h"
#include "../includes/ft_parser.h"
#include "../includes/ft_processor.h"
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char* format, ...)
{
	int	i;
	t_format	argformat;
	t_ok		result;

	va_list argptr;                     //Сначала нужно объявить переменную типа va_list
    va_start(argptr, format);                //Затем, до обработки первого аргумента, вызвать макрос va_start, передав в него нашу переменную, а также аргумент s 
                                    //(последний, идущий перед списком переменной длины)

    i = 0;
    while(format[i])
    {
    	if(format[i] == '%')
	    {
	    	i++;
	    	argformat = ft_parser(&argptr, format, &i);
    		if ((result = ft_processor(&argptr, format, &i, &argformat)) == ERROR)
    			break;
	    }
	    else
    		write(1, &format[i++], 1);
    }

    
    va_end(argptr);
    if(argformat.ok == ERROR || result == ERROR)
    	return (-1);
    else
		return (i);
}