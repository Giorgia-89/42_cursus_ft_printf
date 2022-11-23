int	ft_pointer(unsigned long ptr)
{
	char	str[50];
	char	*hexa;
	int		i;

	i = 0;
	hexa = "0123456789abcdef";
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	else
		write(1, "0x", 2);
	while (ptr != 0)
	{
		str[i] = hexa[ptr % 16];
		ft_putchar(str[i]);
		ptr = ptr / 16;
	}
	return (2 + ft_strlen(str));
}


int main()
{
	
}