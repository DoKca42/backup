 #include <unistd.h>
#include <stdio.h>
#include "ex00/ft_foreach.c"
#include "ex01/ft_map.c"
#include "ex04/ft_is_sort.c"
#include "ex06/ft_sort_string_tab.c"
#include "ex07/ft_advanced_sort_string_tab.c"


int	ft_tqt(int a)
{
	return (a * 10);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}	
		ft_putchar(nb % 10 + '0');
	}
}

int diff(int a, int b)
{
	return (a - b);
}

void ex00()
{
	int tab[5] = {1, 2, 3, 4, 5};
	ft_foreach(tab, 5, &ft_putnbr);
}

void ex01()
{
	int tab[5] = {1, 2, 3, 4, 5};
	int *arr;
	arr = ft_map(tab, 5, &ft_tqt);
	int i = 0;
	while (arr[i])
		printf("%d", arr[i++]);
}

void ex04()
{
	int tab[5] = {5, 4, 3, 2, 1};
	printf("%d\n", ft_is_sort(tab, 5, &diff));
}

void ex06()
{
	char	**strs;

	strs = (char **)malloc(5 * sizeof(strs));
	strs[0] = "testB";
	strs[1] = "testA";
	strs[2] = "testC";
	strs[3] = "testZ";
	strs[4] = "testD";
	ft_sort_string_tab(strs);
	int i = 0;
	while (i < 5)
	{
		printf("%s\n", strs[i]);
		i++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}


void ex07()
{
	char	**strs;

	strs = (char **)malloc(5 * sizeof(strs));
	strs[0] = "testB";
	strs[1] = "testA";
	strs[2] = "testC";
	strs[3] = "testZ";
	strs[4] = "testD";
	ft_advanced_sort_string_tab(strs, &ft_strcmp);
	int i = 0;
	while (i < 5)
	{
		printf("%s\n", strs[i]);
		i++;
	}

}

int main()
{
	ex05();
	return (0);
}