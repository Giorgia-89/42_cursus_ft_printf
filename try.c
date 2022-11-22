#include <unistd.h>
#include <stdio.h>

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

void	ft_putrevstr(char *str)
{
	int		i;
	int		j;
	char	*rev = " ";

	i = 0;
	j = 0;
	while(str[i])
		i++;
	while (i != 0)
	{
		rev[j] = str[i];
		j++;
		i--;
	}
	ft_putstr(rev);
}

int main ()
{
	char *str = "OLA";

	ft_putrevstr(str);
	return(0);
}