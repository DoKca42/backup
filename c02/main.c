#include <stdio.h>

//#include "ex00/ft_strcpy.c"
//#include "ex01/ft_strncpy.c"
//#include "ex02/ft_str_is_alpha.c"
//#include "ex03/ft_str_is_numeric.c"
//#include "ex04/ft_str_is_lowercase.c"
//#include "ex05/ft_str_is_uppercase.c"
//#include "ex06/ft_str_is_printable.c"
//#include "ex07/ft_strupcase.c"
//#include "ex08/ft_strlowcase.c"
#include "ex09/ft_strcapitalize.c"
//#include "ex10/ft_strlcpy.c"
//#include "ex11/ft_putstr_non_printable.c"
//#include "ex12/ft_print_memory.c"
/*
void ex00()
{

	char src[] = "Test 0 1, c'est super";
	//char src[] = "";
	char dest[2];

	printf("%s\n\n", src);
	ft_strcpy(dest, src);
	printf("%s", dest);
}

void ex01()
{
	char src[] = "Test 1 2, c'est super";
	//char src[] = "";
	char dest[100] = {0};

	printf("%s\n\n", src);
	ft_strncpy(dest, src, 25);
	printf("%s", dest);
}

void ex02()
{
	char str[] = "Test";
	printf("%s\n\n", str);
	
	printf("%d", ft_str_is_alpha(str));
}

void ex03()
{
	char str[] = "1230077859";
	printf("%s\n\n", str);
	
	printf("%d", ft_str_is_numeric(str));
}

void ex04()
{
	char str[] = "aghfyf";
	printf("%s\n\n", str);
	
	printf("%d", ft_str_is_lowercase(str));
}

void ex05()
{
	char str[] = "ABUUYUYFHJ";
	printf("%s\n\n", str);
	
	printf("%d", ft_str_is_uppercase(str));
}

void ex06()
{
	char str[] = "ABUUY(UYFHJ%+";
	//printf("%s\n\n", str);
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	
	printf("\n%d", ft_str_is_printable(str));
}

void ex07()
{
	char str[] = "saLut HeLlo !";
	printf("%s\n\n", str);
	ft_strupcase(str);
	printf("%s\n\n", str);
}

void ex08()
{
	char str[] = "saLut HeLlo !";
	printf("%s\n\n", str);
	ft_strlowcase(str);
	printf("%s\n\n", str);
}
*/
void ex09()
{
	//char str[] = "salut, il a .comMent tu vas ? 42mots quarante-deux; cinquante+et+un";
	
	//char str[] = "A*Ttcue,P        D?9p[Hq^u/Ssnukv,p9M;B:K(P7";	//AFK
	//char str[] = "Kg*Zx#Q]8:4b,Uni[Ps[Lo?p        Gc*5e";			//AFK
	//char str[] = "~l9Nto Y8{Er[[h..Rut*@-T";						//ERROR
	//char str[] = "        0sfmk.V#=Lg4>^        +&C)5xwxmcg>}";	//AFK		
	//char str[] = "`/'Bcc+@9f}Rud-Wmgbi?S*B>H!Fp";					//AFK
	//char str[] = "@*Kmroxjnzsqavm(G_.Gr        j(Nnl2t%";			//AFK
	char str[] = "Whxt!~$Va#v#Lvc#[,{Pjf!/Sv<`~Muf";				//AFK

	ft_strcapitalize(str);
	printf("%s\n", str);
}
/*
void ex10()
{
	char src[] = "AABB";
	char dest[100] = {0};

	printf("%s\n\n", src);
	ft_strlcpy(dest, src, 4);
	printf("%s", dest);
}

void ex11()
{
	//char str[] = "Coucou\ntu vas bien ?";
	char str [4];
	str [0] = -1;
	str [1] = 67;
	str [2] = 90;
	ft_putstr_non_printable(str);
}

void ex12()
{
	char	*str;

	str = "Bonjour les aminches\t\n\tc  est fou.tout.ce qu on peut faire avec...print_memory....lol.lol. i";
	//printf(": %lu\n", str);
	ft_print_memory(str, 200);
}
*/
int main()
{
ex09();
}
