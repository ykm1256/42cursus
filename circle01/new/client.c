#include <signal.h>
#include "./libft/libft.h"

void	ft_kill(int pid, char *str)
{
	char	c;
	int	i;

	while (*str)
	{
		c = *str;
		i = 8;
		while (i)
		{
			if (c >> --i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
		str++;

	}
	while (++i <= 8)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	ft_kill(ft_atoi(argv[1]), argv[2]);
	return (0);
}
