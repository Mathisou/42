int ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int i = -10;
	while (i <= 255)
	{
		printf("mine = %d\n", ft_isascii(i));
		printf("real = %d\n", isascii(i));
		i++;
	}
}
