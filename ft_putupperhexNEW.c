/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupperhexNEW.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:10:34 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/22 18:45:44 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
//#include "libftprintf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (*s)
	{
		write(1, s++, 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char *ft_strrev(char *str)
{
	int i;
	int j;
	int size;
	int temp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	size = i - 1;	
	while (j < (size/2) && str[j] != '\0') 
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
		j++;
	}
	return(str);
}
//dividend (n) = divisor(16)*quotient(n) + remainder (resto)

int	ft_putupperhex(int n)
{
	//initialise var for result of division
	long int	quotient;
	//initialise var for remainder
	long int	remainder;
	int 		i;
	char		hexa[100];
	char 		*copy;
	
	quotient = n;
	i = 0;
	while (quotient != 0)
	{
		remainder = (quotient % 16);
		//printf("%d: remainder is %ld\n", i, remainder);
		if (remainder < 10)
		{ 	hexa[i++] = remainder + 48;
			ft_putchar(*hexa);
			//printf("%d: current hexa is %s\n", i, hexa);
		}
		else
		{	hexa[i++] = remainder + 55;
			ft_putchar(*hexa);
			//printf("%d: current hexa is %c\n", i, *hexa);
		}
		quotient = quotient / 16;
		//printf("%d: quotient is %ld\n", i, quotient);
	}
	copy = malloc(sizeof(char) * ft_strlen(hexa));
	copy = hexa;
	//printf("reversed string is %s\n", ft_strrev(copy));
	//ft_putstr(copy);
	return(ft_strlen(copy));
}


int main()
{
	int i = 30;
//	int j = 1567;

//	printf("Printf: decimal is %d, hexadecimal is %X\n", i, i);
	ft_putupperhex(i);
	//printf("my function returns %d\n", ft_putupperhex(i));
//	printf("Printf: decimal is %d, hexadecimal is %x\n", j, j);
//	printf("my function returns %s\n", ft_putupperhex(j));
	return(0);

}