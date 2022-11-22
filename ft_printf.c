/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 09:57:50 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/22 15:16:31 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//authorised functions:
//malloc, free, write, 
//va_start, va_copy, va_arg, va_end

//in the printf function, check specifier then use a 
//auxiliary function (saved at root) to convert as needed. 
int	ft_printf(const char *str, ...)
{
	//initialise list of arguments 
	va_list	args;
	//initialise counter to loop through str
	int 	i;
	
	//start list; second par should be last known one
	va_start(args, str);
	//initialise counter 
	i = 0;
	//loop through str to find the format specifiers
	while (i < ft_strlen(str))
	{
		//write char by char until we find a %
		if (str[i] != '%')
			write(1, &str[i], 1);
		//use va_args to loop through the args
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			//and declare the type of the current arg	
			//int x = va_arg(args, int);
			ft_putnbr(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'c')
		{
			ft_putchar(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			ft_putstr(va_arg(args, char*));
			i++;
		}
		/*
		else if (str[i] == '%' && str[i + 1] == 'x')
		{
			ft_putlowerhex(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'X')
		{
			ft_putupperhex(va_arg(args, int));
			i++;
		}*/
		i++;
	}
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