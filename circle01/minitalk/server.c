#include "./minitalk.h"


static void action(int sig, siginfo_t *info, void *context)
{
	static int		i;
	static pid_t	client_pid;
	static unsigned char c;
	
	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c |= 1;
	if (++i = 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		printf("%c", c);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int		main(void)
{
	struct sigaction	s_sigaction;
	int		pid;
	
	pid = getpid();
	printf("Server PID : %d", pid);
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return (0);
}
