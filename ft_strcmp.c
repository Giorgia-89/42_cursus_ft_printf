/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:50:05 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/23 18:02:54 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
//#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	ixi;

	ixi = 0;
	while ((s1[ixi] == s2[ixi]) && ((s1[ixi] != '\0') || (s2[ixi] != '\0')))
		ixi++;
	if (((unsigned char)s1[ixi] - (unsigned char)s2[ixi]) == 0)
		return (1);
	else
		return (0);
}
