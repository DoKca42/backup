#include <stdio.h>
#include <string.h>
#include "ex00/ft_strcmp.c"
#include "ex01/ft_strncmp.c"
#include "ex02/ft_strcat.c"
#include "ex03/ft_strncat.c"
#include "ex04/ft_strstr.c"
#include "ex05/ft_strlcat.c"

void ex00()
{
	char *s1 = "Ft65";
	char *s2 = "Ft65";
	printf("%d\n", strcmp(s1, s2));
	printf("%d\n", ft_strcmp(s1, s2));
}

void ex01()
{
	char *s1 = "Salut ?";
	char *s2 = "Salut !";
	printf("%d\n", strncmp(s1, s2, 0));
	printf("%d\n", ft_strncmp(s1, s2, 0));
}

void ex02()
{
	char dest[25] = "Salut, ";
	char *src = "comment ca va ?";
	ft_strcat(dest, src);
	printf("%s\n", dest);
}

void ex03()
{
	char dest[25] = "Salut, ";
	char *src = "comment ca va ?";
	ft_strncat(dest, src, 5);
	printf("%s\n", dest);
}

void ex04()
{
	char *s1 = "Recherchep la première occurrence d'une sous-chaîne";
	char *s2 = "première";
	char *res;

	res = strstr(s1, s2);
	if (res == NULL )
		printf("NULL");
	else
		printf("%d", *(int *)res);

	printf("\n");

	res = ft_strstr(s1, s2);
	if (res == NULL )
		printf("NULL");
	else
		printf("%d", *(int *)res);


}

void ex05()
{
	char s1[] = "ABC";
	char s2[] = "DEF";
	printf("- %lu\n", strlcat(s1, s2, 2));
	//printf("- %u\n", ft_strlcat(s1, s2, 2));
	printf("- %s\n", s1);
}


int main()
{
	ex01();
	return(0);
}