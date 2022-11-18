/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:15:02 by gd-innoc          #+#    #+#             */
/*   Updated: 2022/11/18 15:46:55 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return(-1) ;
	while (*s)
	{
		write(1, s++, 1);
		i++;
	}
	return(i);
}
/*
int main()
{
	char str[] = "Hello world";
	ft_putstr(str);
}*/