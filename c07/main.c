#include <stdio.h>
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
//#include "ex04/ft_convert_base.c"
//#include "ex04/ft_convert_base2.c"
#include "ex05/ft_split.c"

//gcf main.c ex04/ft_convert_base.c ex04/ft_convert_base2.c && gca
//gcerr main.c ex04/ft_convert_base.c ex04/ft_convert_base2.c && gca

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

void	ex00(void)
{
	char src[] = "ABC ede erf:";
	printf("%s", ft_strdup(src));
}
void	ex01(void)
{
	int	min = 10;
	int	max = 52;
	int	*i = ft_range(min, max);
	int	a = 0;
	while (a < max - min)
	{
		printf("%d\n", i[a]);
		a++;
	}
}
void	ex02(void)
{
	int min = 10;
	int max = 52;
	int *i;
	printf(" - %d - \n\n",ft_ultimate_range(&i, min, max));
	int a = 0;
	while (a < max - min)
	{
		printf("%d\n", i[a]);
		a++;
	}
}
void	ex03(void)
{
	char **strs;
	char *dy;

	strs = (char **)malloc(5 * sizeof(strs));
	strs[0] = "Salut";
	strs[1] = "testA testB testC";
	strs[2] = "uuuu";
	strs[3] = "Rhh Rhhh";
	strs[4] = "Ahhhhhhhh";
	char	*sep = " | CUT | ";
	dy = ft_strjoin(5, strs, sep);
	printf("{ %s }", dy);
}
void	ex04(void)
{

	printf("%s\n", ft_convert_base("	+---+--gytisyy", "abcdefghijklmnopqrstuvwxyz", "0123456789abcdef"));
}
void	ex05(void)
{
	ft_split("Salut, ca va ? ,a, b, , cd", ", ");
}

int	main(void)
{
	ex04();
	return (0);
}