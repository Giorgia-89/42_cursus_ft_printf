/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:44:04 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/21 21:40:08 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nbr;

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

char	*ft_putlowerhex(int n)
{
	long int	num;
	long int	quotient;
	int 		i;
	char		hexa[100];

	if (n < 0)
		return(0);
	quotient = n;
	while (quotient != 0)
	{
		num = (quotient % 16);
		if (num < 10)
			num = num + 80;//check if this needs to be increased by 32
		else
			num = num + 87;
		hexa[i++] = num;
		quotient = quotient / 16;
	}
	ft_putstr(hexa);
	return(0);
}

int	main()
{
	int i = 35631;
	char *str;
//	char j;
	//void *p = &i;
	//void *q = &j;

//	ft_puthex("My function: decimal is %d, hex is %x\n", i, i);
	printf("     Printf: decimal is %d, hex is %x\n", i, i);
	str = ft_puthex(i);
	printf("%s", str);

	return(0);
}