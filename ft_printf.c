/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:57:50 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/23 13:07:22 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//authorised functions:
//malloc, free, write, 
//va_start, va_copy, va_arg, va_end

//first function checks whether the current char is one of the conversion
//specifiers
int	ft_check(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
		|| c == 'x' || c == 'X'|| c == '%')
		return (1);
	return (0);
}

//second function is to count the number of written chars, and to send the
//current chars to the subfunctions for conversions if it satisfies
//the ft_check (i.e., if it's one of the specifiers). 
int	ft_convert(char conv, va_list args)
{
	int	count;

	count = 0;
	if (conv == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (conv == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (conv == 'p')
		count += ft_pointer(va_arg(args, unsigned long));
	else if (conv == 'd' || conv == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (conv == 'u')
		count += ft_base(va_arg(args, unsigned int), "0123456789");
	else if (conv == 'x')	
		count += ft_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (conv == 'X')	
		count += ft_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (conv == '%')
		count =+ ft_putchar('%');
	return (count);
}

//third function is to start writing the chars of the first arg to output
//and count the number of written chars
int	ft_start(const char *format, va_list args)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (!format)
			return (count);
		if (format[i] == '%')
		{
			i++;
			if (ft_check(format[i]))
				count += ft_convert(format[i], args);
			else
				return (count);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

//main printf function initialises in int to start writing the chars
//of the first arg., launches all the auxiliary functions and returns
//tot n of chars written 
int	ft_printf(const char *str, ...)
{
	//initialise list of arguments 
	va_list	args;
	//initialise counter to loop through str
	int 	i;
	
	//start list; second par should be last known one
	va_start(args, str);
	//initialise counter 
	i = ft_start(str, args);
	va_end(args);
	return(i);
}
/*
int	main()
{
	char *str = "HELLO";
	char e = 'A';

	int i = 15;
	int j = 3;
//	void *p = &j;
	char c = 'a';
	int res;
	ft_printf("My function: String is %s, char is %c\n", str, e);
	printf("Printf: String is %s, char is %c\n", str, e);
	//ft_printf("My function: n is %d, ptr is %p\n", i, p);
	//printf("   Printf: n is %d, ptr is %p\n", i, p);
	ft_printf("My function: decimal is %d, hexadecimal is %x\n", i, i);
	printf("Printf: decimal is %d, hexadecimal is %x\n", i, i);
	ft_printf("My function: decimal is %d, hexadecimal is %X\n", i, i);
	printf("Printf: decimal is %d, hexadecimal is %X\n", i, i);
	ft_printf("ft_printf: Number is %d, %% is the percentage\n", i);
	printf("printf: Number is %d, %% is the percentage\n", i);
	ft_printf("ft_printf: first number is %i, second one is %i\n", i, j);
	printf("printf: first number is %i, second one is %d\n", i, j);
	ft_printf("ft_printf: char is %c\n", c);
	printf("printf: char is %c\n", c);
	res = ft_printf("Hello\n");
	ft_printf("Total printed chars are: %d\n", res);

	return(0);
}*/