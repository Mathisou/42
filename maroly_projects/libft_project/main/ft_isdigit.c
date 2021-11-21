# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <libgen.h>
# include <ctype.h>


int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int main(int ac, char **av)
{
	int i = 0;
	while (i <= 255)
	{
		printf("mine = %d et i = %d\n", ft_isdigit(i), i);
		printf("real = %d et i = %d\n", isdigit(i), i);
		i++;
	}
}
