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
	ft_printf("My function: decimal is %d, hexadecimal is %X\n", i, i);
	printf("Printf: decimal is %d, hexadecimal is %X\n", i, i);
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