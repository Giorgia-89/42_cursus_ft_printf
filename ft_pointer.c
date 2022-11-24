/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-innoc <gd-innoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:24:20 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/24 13:19:02 by gd-innoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long ptr)
{
	char	str[50];
	char	*hexa;
	int		i;

	i = 0;
	hexa = "0123456789abcdef";
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	else
		write(1, "0x", 2);
	while (ptr != 0)
	{
		str[i] = hexa[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_putchar(str[i]);
	return (2 + ft_strlen(str));
}

/*
int main ()
{
	void *ptr;
	int i;
	//char *res;

	i = 12;
	ptr = &i;
	printf("%p\n", i);
	//ft_pointer(ptr);
	//res = ft_pointer(ptr);
	//return (res);_

}*/