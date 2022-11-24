/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:59:48 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/24 13:08:02 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//next function transforms an unsigned int in decimal (base 10)
int	ft_unsigned(unsigned int n)
{
	char	str[25];
	char	*base_ten;
	int		i;
	int		len;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	base_ten = "0123456789";
	while (n != 0)
	{
		str[i] = base_ten[n % 10];
		n = n / 10;
		i++;
	}
	len = i;
	while (i--)
		ft_putchar(str[i]);
	return (len);
}

//next function transforms an unsigned int in hexadecimal (base 16)
int	ft_hexa(unsigned int n, char *base)
{
	char	str[50];
	char	*hexa_base;
	int		i;
	int		len;

	i = 0;
	hexa_base = base;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n != 0)
	{
		str[i] = hexa_base[n % 16];
		n = n / 16;
		i++;
	}
	len = i;
	while (i--)
		ft_putchar(str[i]);
	return (len);
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
		ft_hexa(n, base);
		return (ft_hexa(n, base));
	}
	else if (ft_strcmp(base, "0123456789ABCDEF") == 1)
	{
		ft_hexa(n, base);
		return (ft_hexa(n, base));
	}
	return (0);
}
