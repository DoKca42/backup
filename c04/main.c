
#include <stdio.h>
#include <stdlib.h>
#include "ex00/ft_strlen.c"
//#include "ex01/ft_putstr.c"
#include "ex02/ft_putnbr.c"
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"


void ex00()
{
	char *str = "fonction qui compte le nombre";
	printf("%d\n", ft_strlen(str));
}
/*
void ex01()
{
	char *str = "fonction qui affiche";
	ft_putstr(str);
}
*/
void ex02()
{
	ft_putnbr(42);
}

void ex03()
{
	char *str = "   ---+--+1234ab567";
	printf("%d", ft_atoi(str));

}

void ex04()
{
	//ft_putnbr_base(-1654845, "poneyvif");
	ft_putnbr_base(-1654845, "poneyvif");
	//-inyppfv
}

void ex05()
{
	char *str = "   ---+--+inyppfv";
	printf("%d", ft_atoi_base(str, "poneyvif"));
}

int main()
{
	ex03();
	return (0);
}