/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:06 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/23 10:43:53 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//bea did this function differently, using a function to find the length of the
//int, one for absolute value, itoa and finally putnbr, but my version should
//work too. 
#include "libft.h"

int	ft_putnbr(int n)
{
	unsigned int	nbr;
	int				count;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	ft_putchar((char)(nbr % 10 + 48));
	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return(count);
}
