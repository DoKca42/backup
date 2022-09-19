#ifndef ALGO_H
# define ALGO_H
/*
typedef struct s_start
{
	int y;
	int x;
}	t_start;

typedef struct s_pose
{
	int y;
	int x;
}	t_pose;

typedef struct s_charmap
{
	char empty;
	char obst;
	char fill;
}	t_charmap;
*/

typedef struct	s_map
{
	char	**map;
	int		length;
	int		height;
	char	obstacle;
	char	empty;
	char	full;
	int 	**matrice;
}	t_map;

#endif