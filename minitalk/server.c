#include "minitalk.h"

// static void	ft_process_bar(void)
// {
// 	int i = 0;
// 	char *arrows[5];

// 	arrows[0] = "\u25aa";
// 	arrows[1] = "\u25fc";
// 	arrows[2] = "\u2588";
// 	arrows[3] = "\u25fc";
// 	arrows[4] = "\u25aa";

// 	while (1)
// 	{
// 		ft_printf(RED"%s", arrows[i]);
// 		i++;
// 		if (i > 4)
// 			i = 0;
// 		usleep(200000);
// 		write(1, "\b", 1);
// 	}
// }

#include <signal.h>

static void	handler(int sig)
{
	static int				bite = 0;
	static unsigned char	ch = '\0';
    static int              i = 0;
    static char             *str = NULL;
    static long             size;
    static long             pos = 0;

        if (i <= 64)
    {
        i++;
        size <<= 1;
        if (sig == SIGUSR1)
            size |= 1;
        bite++;
        if (bite == 64)
        {
            bite = 0;
            str = (char*)malloc(size * sizeof(char));
        }
    }
    else
    {
        ch <<= 1;
        if (sig == SIGUSR1)
            ch |= 1;
        bite++;
        if (bite == 8)
        {
            str[pos++] = ch;
            bite = 0;
            ch = '\0';
        }
    }
    if (pos == size)
    printf("%s", str);
}

static void	ft_get_pid(void)
{
	int	pid;

	pid = getpid();
	if (!pid)
		ft_message(DANGER, MSG_DAN_1);
	ft_printf(ORANGE" Pid: %i\n"WHITE, pid);
}

static void	init(int *i)
{
	struct sigaction	sa;
    if (i < 64)
    {
        *i++;

    }
    else{
        sa.sa_handler = handler;
        sa.sa_flags = SA_RESTART;
        if (sigaction(SIGUSR1, &sa, NULL) == -1)
            exit(EXIT_FAILURE);
        if (sigaction(SIGUSR2, &sa, NULL) == -1)
            exit(EXIT_FAILURE);
    }
}

int	main(void)
{
    int i;

    i = 0;
	ft_get_pid();
	init(&i);
	while (1)
		sleep(300);
	return (0);
}