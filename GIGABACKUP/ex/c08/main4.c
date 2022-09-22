#include "ex04/ft_strs_to_tab.c"
#include "ex05/ft_show_tab_main.c"
#include <stdio.h>

int	main(void)
{
	//int		i;
	char	**strs;

	strs = (char **)malloc(5 * sizeof(strs));
	strs[0] = "Salut";
	strs[1] = "testA testB testC";
	strs[2] = "uuuu";
	strs[3] = "Rhh Rhhh";
	strs[4] = "Ahhhhhhhh";
	ft_show_tab(ft_strs_to_tab(5, strs));
	return (0);
}
