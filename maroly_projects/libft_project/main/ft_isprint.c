int ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (16384);
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;
	while (i <= 255)
	{
		printf("mine = %d\n", ft_isprint(i));
		printf("real = %d\n", isprint(i));
		i++;
	}
}
