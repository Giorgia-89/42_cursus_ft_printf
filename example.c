/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:21:56 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/18 17:15:02 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>//remove this as it's only to use strlen

//the first parameter indicates the type of the other arguments
void	print(char *placeholder, ...) 
{
	int num_args = strlen(placeholder);

	va_list args;
	va_start(args, placeholder);

	int i = 0;
	while (i < num_args)
	{
		if (placeholder[i] == 'd')
		//set parameter as int
		{
			//va_arg updates the args list so that the next call
			// fetches the next argument
			int x = va_arg(args, int);
			printf("%d\n", x);
		}
		else if (placeholder[i] == 'f')
		//double and floats can both be handled by doubles
		{
			double x = va_arg(args, double);
			printf("%f\n", x);
		}
		i++;
	}
	va_end(args);
}

int main(void)
{
	print("ddfd", 4, 5, 5.6, 7);
	return(0);
}
//first we need to create a va_list variable
/*int max(int num_args, ...)
{
	int	max;
	int i;
	int x;
	va_list args; 
//function va_start takes as first arg the name of the list, and as second the 
//last arg before the ...
	va_start(args, num_args);
	
	max = 0;
	i = 0;
	x = 0;
	while (i < num_args)
	{
		i++;
		x = va_arg(args, int);
		if (i == 0)
			max = x;
		else if (x > max)
			max = x;	
	}
	va_end(args);
	return (max);
}

int	main(void)
{
	int max_num;

	max_num = max(7, 10, 12, 14, 16, 200, 45, 1);
	printf("max is %d\n", max_num);
	return(0);
}*/