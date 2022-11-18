/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giorgia <giorgia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:46:24 by giorgia           #+#    #+#             */
/*   Updated: 2022/11/18 15:04:08 by giorgia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

int main ()
{
	int j = -15;
	char c = 'a';
	char *str = "Hello world";
	void *p = &j;

	//print a single char
	printf("char is %c\n", c);
	//converts the int arg to an unsigned char
	printf("Char: %c\n", 90);
	//print a string
	printf("String is %s\n", str);
	//prints the void *pointer argument in hexadecimal format
	printf("Hexadecimal ptr is %p\n", p);
	//prints a decimal number (base 10)
	printf("Numbers: %d, %d\n", 90, j);
	//prints an integer in base 10
	printf("%%i:Numbers: %i, %i\n", 60, j);
	//prints an unsigned decimal in base 10 - input cannot be negative
	printf("%%u: Numbers: %u, %u\n", 60, j);
	//print a number in hexadecimal (base 16) lowercase
	printf("%d Hexadecimal: %x\n", 255, 255);
	//print a number in hexadecimal (base 16) lowercase
	printf("%d Hexadecimal: %X\n", 255, 255);
	//print a % sign
	printf("%%\n");	

	//the following converts an int argument to decimal
	printf("%.2d Decimal: %.2u\n", 255, 255);
	


	return(0);
}