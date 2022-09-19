#include "algo.h"
#include <stdio.h>
#include <stdlib.h>
/*
int check_mini(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}

}

int ft_check(int y, int x, t_map *cmap)
{
	int	bas;
	int	droite;
	int	diago;

	if (y >= cmap.height || x >= cmap.length)
		return (0);
	if (cmap.matrice[y][x] == -1)
	{
		bas = ft_check(y + 1, x, cmap);
		droite = ft_check(y, x + 1, cmap);
		diago = ft_check(y + 1, x + 1, cmap);
		cmap.matrice[y][x] = 0;
		if (cmap.map[y][x] == cmap.empty)
		{
			cmap.matrice[y][x] = 1 + check_mini(bas, droite, diago);
		}
	}
	return (cmap.matrice[y][x]);
}

void	ft_init(t_map **cmap)
{
	int	a;
	int b;

	cmap.matrice = (int **)malloc((cmap.length - 1) * sizeof(int *));
	a = 0;
	while (a < cmap.length)
	{
		b = 0;
		cmap.matrice[a] = malloc(cmap.height - 1 * sizeof(int));
		while (b < cmap.height)
		{
			cmap.matrice[a][b] = -1;
			b++;
		}
		a++;
	}
	ft_check(0, 0, cmap);
}

*/
int main()
{
	t_map *cmap;

	cmap->length = 9;
	cmap->height = 27;
	cmap->empty = '.';
	cmap->obstacle = 'o';
	cmap->full = 'x';
	cmap->map = malloc(9 * sizeof(char *));
	cmap->map[0] = "...........................";
	cmap->map[1] = "....o......................";
	cmap->map[2] = "............o..............";
	cmap->map[3] = "...........................";
	cmap->map[4] = "....o......................";
	cmap->map[5] = "...............o...........";
	cmap->map[6] = "...........................";
	cmap->map[7] = "......o..............o.....";
	cmap->map[8] = "..o.......o................";
	//ft_init(&cmap);

	return (0);
}

