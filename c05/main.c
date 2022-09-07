#include <stdio.h>
#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"


void ex00()
{
	printf("%d", ft_iterative_factorial(10));
}
void ex01()
{
	printf("%d", ft_recursive_factorial(10));
}
void ex02()
{
	printf("%d", ft_iterative_power(5 , 6));
}
void ex03()
{
	printf("%d", ft_recursive_power(5 , 6)); 
}
void ex04()
{
	printf("%d", ft_fibonacci(16));
}
void ex05()
{
	printf("%d", ft_sqrt(144));
}
void ex06()
{
	printf("%d",  ft_is_prime(401));
}
void ex07()
{
	printf("%d",  ft_find_next_prime(165));
}
void ex08()
{

}




int main()
{
	ex07();
}