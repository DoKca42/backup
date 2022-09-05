void	ft_putstr_non_printable(char *str);

int main()
{
	ft_putstr_non_printable("asdf\x7f\x1fhi\x01\xfflol");
	return (0);
}