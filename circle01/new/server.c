#include <signal.h>
#include "./libft/libft.h"


void	action(int sig)
{
	static unsigned char	c;
	static int		i;

	if (sig == SIGUSR2)
		c |= 1;
	if (++i == 8)
	{
		if (!c)
			ft_putstr_fd("\n", 2);
		else
			ft_putchar_fd(c, 2);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}


int	main(void)
{
	ft_putstr_fd("SERVER : ", 2);
	ft_putnbr_fd(getpid(),2);
	ft_putstr_fd("\n", 2);
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	while (1)
		pause();
	return (0);
}
