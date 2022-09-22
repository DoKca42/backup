#include <stdio.h>
#include <unistd.h>
#include "01.c"

int main()
{
	//char *str = "Ç---è---Å---ø";
	//ft_putstr_non_printable(str);

	//===============================

	char *str = "ff";
	char	*basehex;
	basehex = "0123456789abcdef";

	int a = 0;
	int b = 0;
	int result = 0;
	while (str[b])
	{
		a = 0;
		while (basehex[a] && basehex[a] != str[b])
			a++;
		if (b % 2 == 1)
			result = result + (a * 16);
		else
			result = result + a;
		b++;
	}
	printf("Le decimal : %d", result);
	char c[3] = "Ç";
	write(1, &c , 3);
	//char test = -65;
	//printf("\n[%c][%d]", test, test);
	return (0);
}
