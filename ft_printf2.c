#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return(0);
	while (*s)
	{
		write(1, s++, 1);
		i++;
	}
	return(i);
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

//authorised functions:
//malloc, free, write, 
//va_start, va_copy, va_arg, va_end



//in the printf function, check specifier then use a 
//auxiliary function (saved at root) to convert as needed. 
int	ft_printf(const char *str, ...)
{
	//initialise list of arguments 
	va_list	args;
	//initialise counter for args
	int		length;
	//initialise counter to loop through str
	int 	i;

	//start list; second par should be last known one
	va_start(args, str);
	//count length of str
	length = ft_strlen(str);
	//initialise counter from 1 as first char cannot be a specifier
	i = 1;
	//loop through str to find the format specifiers
	while (i < length)
	{
		if (str[i] != '%')
			write(1, &str[i], 1);
		//use va_args to loop through the args
		else if (str[i] == '%' && str[i + 1] == 'd')
		{
			//and declare the type of the current arg	
			//int x = va_arg(args, int);
			ft_putnbr(va_arg(args, int));
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
		}
		i++;

	}
	va_end(args);
	//return will have to be changed
	return(1);
}

int	main()
{
	/*char *str = "HELLO";
	char c = 'A';
	ft_printf("My function: String is %s, char is %c\n", str, c);
	printf("Printf: String is %s, char is %c\n", str, c);
	*/
	int i = 15;
	int j = 3;

	ft_printf("ft_printf: Number is %d, %% is the percentage\n", i);
	printf("printf: Number is %d, %% is the percentage\n", i);
	ft_printf("ft_printf: first number is %d, second one is %d\n", i, j);
	printf("printf: first number is %d, second one is %d\n", i, j);

	return(0);
}