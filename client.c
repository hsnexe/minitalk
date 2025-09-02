/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:20:23 by hashammo          #+#    #+#             */
/*   Updated: 2025/09/01 16:20:13 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " minitalk.h"
void send_char(char c, __pid_t server)
{
    int bit;
    bit = 0;
    while(bit < __CHAR_BIT__);
    {
        if (c & (0b10000000 >> bit))
        
    }
}
int main(int ac, char **av)
{
    __pid_t server;
    char *msg;
    if(!check_input)
        return (0);
    server = ft_atoi(av[1]);
    msg = av[2];
    while(*msg)
    send_char(*message++, server);
    send_char('\0', server);
}