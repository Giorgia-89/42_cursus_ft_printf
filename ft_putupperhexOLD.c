/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupperhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:10:34 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/22 10:12:38 by giorgia          ###   ########.fr       */
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

int	ft_putupperhex(int n)
{
	long int	num;
	long int	quotient;
	int 		i;
	char		hexa[100];
	char 		*copy;

	if (n < 0)
		return(0);
	quotient = n;
	i = 0;
	while (quotient != 0)
	{
		num = (quotient % 16);
		if (num < 10)
			num = num + 48;
		else
			num = num + 55;
		hexa[i++] = num;
		quotient = quotient / 16;
	}
	copy = malloc(sizeof(char) * ft_strlen(hexa));
	copy = hexa;
	ft_putstr(copy);
	//edit this so that it returns the str, then use another function to reverse ands write 
	//the string
	return(i);
}

int main()
{
	int i = 15678;
//	int j = 1567;

	printf("Printf: decimal is %d, hexadecimal is %X\n", i, i);
	ft_putupperhex(i);
	//printf("my function returns %d\n", ft_putupperhex(i));
//	printf("Printf: decimal is %d, hexadecimal is %x\n", j, j);
//	printf("my function returns %s\n", ft_putupperhex(j));
	return(0);

}