/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlowerhex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:07:51 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/22 10:07:54 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_putlowerhex(int n)
{
	long int	num;
	long int	quotient;
	int 		i;
	char		hexa[100];
	char 		*copy;

	if (n < 0)
		return(0);
	quotient = n;
	while (quotient != 0)
	{
		num = (quotient % 16);
		if (num < 10)
			num = num + 80;
		else
			num = num + 87;
		hexa[i++] = num;
		quotient = quotient / 16;
	}
	copy = malloc(sizeof(char) * ft_strlen(hexa));
	copy = hexa;
	return(copy);
}

int main()
{
	int i = 255;
	int j = 1567;

	printf("Printf: decimal is %d, hexadecimal is %x\n", i, i);
	printf("my function returns %s\n", ft_putlowerhex(i));
	printf("Printf: decimal is %d, hexadecimal is %x\n", j, j);
	printf("my function returns %s\n", ft_putlowerhex(j));
	return(0);

}
