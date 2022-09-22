#include <stdio.h>

#include "ex00/ft_ft.c"
#include "ex01/ft_ultimate_ft.c"
#include "ex02/ft_swap.c"
#include "ex03/ft_div_mod.c"
#include "ex04/ft_ultimate_div_mod.c"
#include "ex05/ft_putstr.c"
#include "ex06/ft_strlen.c"
#include "ex07/ft_rev_int_tab.c"
#include "ex08/ft_sort_int_tab.c"

void ex00()
{
	int a = 0;
	int *nbr = &a;
	ft_ft(nbr);
	printf("%d", a);
}

void ex01()
{
	int a = 0;
	int *p1, **p2, ***p3, ****p4, *****p5, ******p6, *******p7, ********p8, *********p9; 
	p1 = &a;
	p2 = &p1;
	p3 = &p2;
	p4 = &p3;
	p5 = &p4;
	p6 = &p5;
	p7 = &p6;
	p8 = &p7;
	p9 = &p8;
	 

	ft_ultimate_ft(p9);
	printf("%d", a);
}
void ex02()
{
	int a = 5;
	int b = 7;

	int *pa = &a;
	int *pb = &b;
		
	printf("%d - %d\n", a, b);
	ft_swap(pa, pb);
	printf("%d - %d", a, b);
}
void ex03()
{
	int a = 7;
	int b = 3;
	int result = 0;
	int reste = 0;
	int *div = &result;
	int *mod = &reste;
	
	printf("%d / %d = ", a, b);
	ft_div_mod(a, b, div, mod);
	printf("%d et reste %d", *div, *mod);
}
void ex04()
{
	int c = 15;
	int d = 3;
	int *a = &c;
	int *b = &d;
	
	printf("%d / %d = ", c, d);
	ft_ultimate_div_mod(a, b);
	printf("%d et reste %d", c, d);
}
void ex05()
{
	char *str;
	str = "Test, 0' 123 - 456";
	ft_putstr(str);
}
void ex06()
{
	char *str;
	str = "Test,  dix-huit 42";
	printf("%d", ft_strlen(str));
}
void ex07()
{
	int tab[5] = {1, 2, 3, 4, 5};

	int i;

	i = 0;
	while(i < 5)
	{
		printf("%d, ", tab[i]);
		i++;
	}

	printf("\n\n");
	ft_rev_int_tab(tab, 5);
	

	i = 0;
	while(i < 5)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}

void ex08()
{
	int tab[6] = {5, 3, 2, 10, 5, 1};

	int i;

	i = 0;
	while(i < 6)
	{
		printf("%d, ", tab[i]);
		i++;
	}

	ft_sort_int_tab(tab, 6);
	printf("\n\n");
	
	i = 0;
	while(i < 6)
	{
		printf("%d, ", tab[i]);
		i++;
	}
}

int main(){
	//ex00();
	//ex01();
	//ex02();
	//ex03();
	//ex04();
	//ex05();
	//ex06();
	//ex07();
	ex08();
}