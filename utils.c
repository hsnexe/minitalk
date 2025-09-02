#include " minitalk.h"

void handler(int signal)
{
    if(signal == SIGUSR1)
        ft_printf("GOT SIGUSR1\n");
    else if (signal == SIGUSR2)
        ft_printf("GOT SIGUSR2\n");
}