#include "algo.h"
#include <stdio.h>

void	ft_pose_check(char **arr, t_charmap cmap)
{
	int	yt;
	int	xt;
	t_start start;
	t_pose pose;

	start.y = 0;
	start.x = 0;
	pose.y = 0;
	pose.x = 0;
	yt = start.y;
	xt = start.x;

	while (arr[yt][xt] == cmap.empty)
		xt++;
	printf("xt : %d | pose.x : %d | yt : %d\n", xt, pose.x, yt);
	pose.x = xt - 1;
	xt = start.x;
	yt += 1;
	printf("xt : %d | pose.x : %d | yt : %d\n", xt, pose.x, yt);
	while (arr[yt][xt] <= pose.x && arr[yt][xt] == cmap.empty)
	{
		printf("%d = %d", xt, pose.x);
		xt++;
	}
	
	if (xt - 1 == pose.x)
		printf("good\n");
	else
		printf("not\n");
	//printf("%d", pose.x);
	//(void)obst;
	//(void)fill;
}


int main()
{
	t_charmap cmap;
	cmap.empty = '.';
	cmap.obst = 'o';
	cmap.fill = 'x';
	char *arr[9];
	
	arr[0] = "...........................";
	arr[1] = "....o......................";
	arr[2] = "............o..............";
	arr[3] = "...........................";
	arr[4] = "....o......................";
	arr[5] = "...............o...........";
	arr[6] = "...........................";
	arr[7] = "......o..............o.....";
	arr[8] = "..o.......o................";
	/*
	arr[0] = "...........................";
	arr[1] = "...........................";
	arr[2] = "............o..............";
	arr[3] = "...........................";
	arr[4] = "....o......................";
	arr[5] = "...............o...........";
	arr[6] = "...........................";
	arr[7] = "......o..............o.....";
	arr[8] = "..o.......o................";*/
	ft_pose_check(arr, cmap);

	return (0);
}