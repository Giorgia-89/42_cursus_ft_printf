#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s++, 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

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

int	absolute_value(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int	ft_intlen(long int n)
{
	int	len;

	if (n <= 0)
	{
		n = -n;
		len = 1;
	}
	else
		len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long int n)
{
	int		len;
	char	*ptr;

	len = ft_intlen(n);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n < 0)
		ptr[0] = '-';
	if (n == 0)
		ptr[0] = '0';
	while (n != 0)
	{
		ptr[len - 1] = absolute_value(n % 10) + '0';
		n /= 10;
		len--;
	}
	return (ptr);
}

int	ft_putnbr(int nb)
{
	char	*str;
	int		counter;

	counter = 0;
	str = ft_itoa(nb);
	counter += ft_putstr(str);
	free (str);
	return (counter);
}


int	ft_unsigned(unsigned int n)
{
	char	str[25];
	char	*base_ten;
	int		i;
	int		len;

	i = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	base_ten = "0123456789";
	while (n != 0)
	{
		str[i] = base_ten[n % 10];
		n = n / 10;
		i++;
	}
	len = i;
	while (i--)
		ft_putchar(str[i]);
	return (len);
}

int	ft_hexa(unsigned int n, char *base)
{
	char	str[50];
	char	*hexa_base;
	int		i;
	int		len;

	i = 0;
	hexa_base = base;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n != 0)
	{
		str[i] = hexa_base[n % 16];
		n = n / 16;
		i++;
	}
	len = i;
	while (i--)
		ft_putchar(str[i]);
	return (len);
}

//main function takes the int and the base (fed from ft_printf) and checks
//whether we need to transform to base 10 or 16, then sends n to the 
//corresponding function. 
int	ft_base(unsigned int n, char *base)
{
	if (ft_strcmp(base, "0123456789") == 1)
	{
		//ft_unsigned(n);
		return (ft_unsigned(n));
	}
	else if (ft_strcmp(base, "0123456789abcdef") == 1)
	{
		//ft_hexa(n, base);
		return (ft_hexa(n, base));
	}
	else if (ft_strcmp(base, "0123456789ABCDEF") == 1)
	{
		//ft_hexa(n, base);
		return (ft_hexa(n, base));
	}
	return (0);
}

int	ft_check(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'\
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_convert(char conv, va_list args)
{
	int	count;

	count = 0;
	if (conv == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (conv == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (conv == 'p')
		count += ft_pointer(va_arg(args, unsigned long));
	else if (conv == 'd' || conv == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (conv == 'u')
		count += ft_base(va_arg(args, unsigned int), "0123456789");
	else if (conv == 'x')
		count += ft_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (conv == 'X')
		count += ft_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (conv == '%')
		count += ft_putchar('%');
	return (count);
}


int	ft_start(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (!format)
			return (count);
		if (format[i] == '%')
		{
			i++;
			if (ft_check(format[i]))
				count += ft_convert(format[i], args);
			else
				return (count);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	va_start(args, str);
	i = ft_start(str, args);
	va_end(args);
	return (i);
}




int main ()
{
	printf("U: %u \n", 0);
	ft_printf("My U: %u \n", 0);
	printf("U: %u \n", -1);
	ft_printf("My U: %u \n", 0);
	printf("U: %u \n", 1);
	ft_printf("My U: %u \n", 0);
	printf("U: %u \n", 9);
	ft_printf("My U: %u \n", 0);
	printf("x: %x \n", 0);
	ft_printf("My x: %x \n", 0);
	printf("x: %x \n", -1);
	ft_printf("My x: %x \n", 0);
	printf("x: %x \n", 1);
	ft_printf("My x: %x \n", 0);
	printf("x: %x \n", 9);
}