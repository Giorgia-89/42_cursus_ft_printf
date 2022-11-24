/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:59:48 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/24 15:59:53 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//next function transforms an int into an unsigned decimal (base 10)
int	ft_unsigned(int n)
{
	long int	quotient;
	long int	remainder;
	int			i;
	char		hexa[50];
	char		*copy;

	quotient = n;
	i = 0;
	while (quotient != 0)
	{
		remainder = quotient % 10;
		if (remainder < 10)
			hexa[i++] = remainder + 48;
		else
			hexa[i++] = remainder + 55;
		quotient = quotient / 10;
	}
	copy = malloc(sizeof(char) * ft_strlen(hexa));
	copy = hexa;
	while (i--)
		ft_putchar(copy[i]);
	return (ft_strlen(copy));
}

//next function transforms an integer to lower letters hexadecimal (base 16)
int	ft_lowerhex(int n)
{
	long int	quotient;
	long int	remainder;
	int			i;
	char		hexa[50];
	char		*copy;

	quotient = n;
	i = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexa[i++] = remainder + 80;
		else
			hexa[i++] = remainder + 87;
		quotient = quotient / 16;
	}
	copy = malloc(sizeof(char) * ft_strlen(hexa));
	copy = hexa;
	while (i--)
		ft_putchar(copy[i]);
	return (ft_strlen(copy));
}

//next function transforms an unsigned int in uppercase letters hexadecimal (base 16)
int	ft_upperhex(int n)
{
	long int	quotient;
	long int	remainder;
	int			i;
	char		hexa[50];
	char		*copy;

	quotient = n;
	i = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder < 10)
			hexa[i++] = remainder + 48;
		else
			hexa[i++] = remainder + 55;
		quotient = quotient / 16;
	}
	copy = malloc(sizeof(char) * ft_strlen(hexa));
	copy = hexa;
	while (i--)
		ft_putchar(copy[i]);
	return (ft_strlen(copy));
}

//main function takes the int and the base (fed from ft_printf) and checks
//whether we need to transform to base 10 or 16, then sends n to the 
//corresponding function. 
int	ft_base(unsigned int n, char *base)
{
	if (ft_strcmp(base, "0123456789") == 1)
	{
		ft_unsigned(n);
		return (ft_unsigned(n));
	}
	else if (ft_strcmp(base, "0123456789abcdef") == 1)
	{
		ft_lowerhex(n);
		return (ft_lowerhex(n));
	}
	else if (ft_strcmp(base, "0123456789ABCDEF") == 1)
	{
		ft_upperhex(n);
		return (ft_upperhex(n));
	}
	return (0);
}
