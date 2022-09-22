#include "ft_show_tab.c"

int	main(void)
{
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