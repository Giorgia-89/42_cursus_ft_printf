/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:51:41 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/22 13:52:25 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *ft_strrev(char *str)
{
	int i;
	int j;
	int size;
	int temp;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	size = i - 1;	
	while (j < (size/2) && str[j] != '\0') 
	{
		temp = str[j];
		str[j] = str[i - j - 1];
		str[i - j - 1] = temp;
		j++;
	}
	return(str);
}

int main()
{
	char str[] = "hello world";
	char str2[] = "12345678 910";

	printf("%s\n", ft_strrev(str));
	printf("%s\n", ft_strrev(str2));
}