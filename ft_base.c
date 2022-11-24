/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:59:48 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/24 16:54:57 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//next function transforms an int into an unsigned decimal (base 10)
int	ft_unsigned(int n)
{
	long int	quotient;
	long int	remainder;
	int			i;
	int			len;
	char		deca[50];

	quotient = n;
	i = 0;
	while (quotient != 0)
	{
		remainder = quotient % 10;
		if (remainder < 10)
			deca[i++] = remainder + 48;
		else
			deca[i++] = remainder + 55;
		quotient = quotient / 10;
	}
	len = i;
	while (i--)
		ft_putchar(deca[i]);
	return (len);
}

//next function transforms an integer to lower letters hexadecimal (base 16)
int	ft_lowerhex(int n)
{
	long int	quotient;
	long int	remainder;
	int			i;
	int			len;
	char		hexa[50];

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
	len = i;
	while (i--)
		ft_putchar(hexa[i]);
	return (len);
}

//next function transforms an unsigned int in uppercase letters hexadecimal (base 16)
int	ft_upperhex(int n)
{
	long int	quotient;
	long int	remainder;
	int			i;
	int			len;
	char		hexa[50];

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
	len = i;
	while (i--)
		ft_putchar(hexa[i]);
	return (len);
}

//main function takes the int and the base (fed from ft_printf) and checks
//whether we need to transform to base 10 or 16, then sends n to the 
//corresponding function. 
int	ft_base(unsigned int n, char *base)
{
	int	res;

	res = 0;
	if (ft_strcmp(base, "0123456789") == 1)
		res = ft_unsigned(n);
	else if (ft_strcmp(base, "0123456789abcdef") == 1)
		res = ft_lowerhex(n);
	else if (ft_strcmp(base, "0123456789ABCDEF") == 1)
		res = ft_upperhex(n);
	return (res);
}
