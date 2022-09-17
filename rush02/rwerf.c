t_dict			parsedict;
parsedict.k = 0;
parsedict.u = 0;
listesize = 0;
parsedict.k = malloc(42 * sizeof(t_parsing));
parsedict.u = malloc(42 * sizeof(t_parsing));

parsedict.k[0].key = 12;
printf("%d\n", parsedict.k[0].key);




void	parsing_read(int fd)
{
	int				listesize;
	unsigned int	wordsize;
	unsigned int	sizeu;
	unsigned int	sizek;
	char			buffer[4096];
	t_parsing		*parsek;
	t_parsing		*parseu;
	t_dict			parsedict;
	wordsize = 0;
	listesize = 0;
	while (read(fd, buffer, 1))
	{
		if (buffer[0] >= '0' & buffer[0] <= '9')
			wordsize++;
		else
		{
			wordsize = 0;
		}
	}
}

while (read(fd, buffer, 1))
		listesize++; 
	tab = malloc((listesize + 1) * sizeof(char));
	listesize = 0;
	while (read(fd, buffer, 1))
		tab[listesize++] = buffer[0];
	int i;
	i = 0;
	while (tab[i])
		printf("%c", tab[i++]);