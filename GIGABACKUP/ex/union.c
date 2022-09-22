#include <unistd.h>

void ft_union(int *hash, char *argv)
{
	int i;
	int c;

	i = 0;
	while (argv[i])
	{
		c = argv[i];
		if (hash[c] == 0)
		{
			write(1, &argv[i], 1);
			hash[c] = 1;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int hash[129];
	int i;

	i = 0;
	while (i < 129)
		hash[i++] = 0;

	if (argc == 3)
	{
		ft_union(hash, argv[1]);
		ft_union(hash, argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}