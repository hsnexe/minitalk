/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:20:26 by hashammo          #+#    #+#             */
/*   Updated: 2025/09/01 15:59:57 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " minitalk.h"
#include <stdio.h>
int main()
{
   ft_printf("Server PID=%d\n", getpid());

   signal(SIGUSR1, handler);
   signal(SIGUSR2, handler);
    while(42)
    {
        pause();
    }
    return (0);
}