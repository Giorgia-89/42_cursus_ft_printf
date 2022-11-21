#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//needs to be edited to return length of what was written
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

//authorised functions:
//malloc, free, write, 
//va_start, va_copy, va_arg, va_end



//in the printf function, check specifier then use a 
//auxiliary function (saved at root) to convert as needed. 
int	ft_printf(const char *str, ...)
{
	//initialise list of arguments 
	va_list	args;
	//initialise counter to loop through str
	int 	i;
	
	//start list; second par should be last known one
	va_start(args, str);
	//initialise counter 
	i = 0;
	//loop through str to find the format specifiers
	while (i < ft_strlen(str))
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		//use va_args to loop through the args
		else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		{
			//and declare the type of the current arg	
			//int x = va_arg(args, int);
			ft_putnbr(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'c')
		{
			ft_putchar(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 's')
		{
			ft_putstr(va_arg(args, char*));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == 'x')
		{
			ft_putlowerhex(va_arg(args, int));
			i++;
		}
		i++;
	}
	va_end(args);
	return(i);
}

int	main()
{
	char *str = "HELLO";
	char e = 'A';

	int i = 15;
	int j = 3;
//	void *p = &j;
	char c = 'a';
	int res;
	ft_printf("My function: String is %s, char is %c\n", str, e);
	printf("Printf: String is %s, char is %c\n", str, e);
	//ft_printf("My function: n is %d, ptr is %p\n", i, p);
	//printf("   Printf: n is %d, ptr is %p\n", i, p);
	ft_printf("My function: decimal is %d, hexadecimal is %x\n", i, i);
	printf("Printf: decimal is %d, hexadecimal is %x\n", i, i);

	ft_printf("ft_printf: Number is %d, %% is the percentage\n", i);
	printf("printf: Number is %d, %% is the percentage\n", i);
	ft_printf("ft_printf: first number is %i, second one is %i\n", i, j);
	printf("printf: first number is %i, second one is %d\n", i, j);
	ft_printf("ft_printf: char is %c\n", c);
	printf("printf: char is %c\n", c);
	res = ft_printf("Hello\n");
	ft_printf("Total printed chars are: %d\n", res);

	return(0);
}