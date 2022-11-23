/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:35:54 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/23 10:37:01 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*This function returns a pointer to a new string which is a duplicate of 
the string s. Memory for the new string is allocated with malloc */
#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		len;
	int		j;

	len = 0;
	j = 0;
	while (s[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (s[j])
	{
		dup[j] = s[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}