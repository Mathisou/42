#include "printflib.h"

int ft_printf(const char *s, ...)
{
	va_list args;
	int i;
	char *str;
	int num = strlen(s);

	i = 0;
	va_start(args, s);
	printf("%d\n", num);
	while (i < num)
	{
		str = va_arg(args, char *);
		printf("%s\n", str);
		i++;		
	}
	va_end(args);
	return (0);
}

int main()
{
	ft_printf("He","yo", "ca va");
}
