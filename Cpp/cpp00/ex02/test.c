#include <unistd.h>
#include <stdio.h>
 #include <sys/wait.h>
 #include <fcntl.h>

int main(int ac, char **av, char **env)
{
//	(void) ac;
//fork();
int enfantneeprematurementalhopital;

char *tab[] = {"-e", av[1], NULL};
char *tab1[] = {"-la", NULL};
	if (ac != 2)
		return 0;
	enfantneeprematurementalhopital = fork();
	if (enfantneeprematurementalhopital == 0)
		execve("/bin/cat", tab, env);
	execve("/bin/ls", tab1, env);
	return (0);
}