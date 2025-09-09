/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:17:45 by hashammo          #+#    #+#             */
/*   Updated: 2025/09/09 15:58:09 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
volatile int g_server = 0;
void handler(int signal)
{

   static char      c;
   static int        bit;
    char nl;

    nl = '\n';
    if (signal  == SIGUSR1)
        c |= (0b10000000 >> bit);
    else if (SIGUSR2 == signal)
        c &= ~(0b10000000 >> bit);
    bit++;
    if(bit == 8)
    {
        write(1, &c, 1);
        if(c == '\0')
        write(1, &nl, 1);    
        c = 0;
        bit = 0;
    }
}
void safe_kill(__pid_t pid, int signal)
{
    if(kill(pid,signal) < 0)
    {
        write(2,"ERROR", 5);
        exit(EXIT_FAILURE);
    }
}
void ack_handler(int signal)
{
     (void)signal;
     g_server = 1;
}
void end_handler(int signal)
{
    (void)signal;
    ft_printf("MESSAGE RECEIVED");
}