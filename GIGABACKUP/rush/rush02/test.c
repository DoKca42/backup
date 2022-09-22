#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "includes/parsing.h"

void ft_test(t_parsing *k, t_parsing *u)
{
	k[0].key = 1235;
	u[0].key = 777;
	k[0].value = "iyewrf";
	u[0].value = "rttgw4g";

	printf("%d * %s\n", k[0].key, k[0].value);
	printf("%d * %s\n", u[0].key, u[0].value);
}

int main()
{
	t_dict			parse;

	parse.k = malloc(2 * sizeof(struct s_parsing));
	parse.u = malloc(2 * sizeof(struct s_parsing));
	ft_test(parse.k, parse.u);

	printf("%d = %s\n", parse.k[0].key, parse.k[0].value);
	printf("%d = %s\n", parse.u[0].key, parse.u[0].value);
	return (0);
}