/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    minitalk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:20:29 by hashammo          #+#    #+#             */
/*   Updated: 2025/09/01 15:57:56 by hashammo         ###   ########.fr       */
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


int check_input(int ac, char **av);
int valid_pid(char *s);
void handler(int signal);


#endif