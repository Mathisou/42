int ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (8);
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;
	while (i <= 255)
	{
		printf("mine = %d\n", ft_isalnum(i));
		printf("real = %d\n", isalnum(i));
		i++;
	}
}
