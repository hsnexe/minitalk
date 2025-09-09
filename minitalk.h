/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:20:29 by hashammo          #+#    #+#             */
/*   Updated: 2025/09/09 15:59:06 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
#define MINI_TALK_H

#define ERROR_USAGE "enter valid arguments: ./client <PID> <message>\n"
#define ERROR_PID "invalid PID\n -_-"
#define ERROR_MSG "ERROR : MESSAGE IS EMPTY -_-"

#include "ft_printf.h"
#include "libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int check_input(int ac, char **av);
int valid_pid(char *s);
void    handler(int signal);
void safe_kill(__pid_t pid, int signal);
void ack_handler(int signal);
void end_handler(int signal);

extern volatile int g_server;


#endif