/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clientinput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:22:31 by hashammo          #+#    #+#             */
/*   Updated: 2025/09/08 16:42:12 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <limits.h>
int valid_pid(char *s)
{
    int     i;
    long    pid;

    i = 0;
    pid = 0;
    while(s[i])
    {
        if(!ft_isdigit(s[i]))
            return (0);
        pid  = pid * 10 + (s[i] - '0');
            i++;
    }
    if (pid < 0 || pid > __INT_MAX__)
        return (0);
    return (1);
}
int check_input(int ac, char **av)
{
    if (ac != 3)
    {
         ft_printf(ERROR_USAGE);
           return (0);
    }
    if (!valid_pid(av[1]))
    {
        ft_printf(ERROR_PID);
        return (0);
    }
    if (av[2][0] == '\0')
    {
        ft_printf(ERROR_MSG);
        return (0);
    }
    return (1);
}