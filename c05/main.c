#include <stdio.h>
#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"
#include "ex08/ft_ten_queens_puzzle.c"


void ex00()
{
	printf("%d\n", ft_iterative_factorial(10));
}
void ex01()
{
	printf("%d\n", ft_recursive_factorial(10));
}
void ex02()
{
	printf("%d\n", ft_iterative_power(5 , 6));
}
void ex03()
{
	printf("%d\n", ft_recursive_power(5 , 6)); 
}
void ex04()
{
	printf("%d\n", ft_fibonacci(16));
}
void ex05()
{
	printf("%d\n", ft_sqrt(144));
}
void ex06()
{
	printf("%d\n",  ft_is_prime(401));
}
void ex07()
{
	printf("%d\n",  ft_find_next_prime(165));
}
void ex08()
{
	printf("%d\n",  ft_ten_queens_puzzle());
}

int main()
{
	ex00();
	ex01();
	ex02();
	ex03();
	ex04();
	ex05();
	ex06();
	ex07();
}