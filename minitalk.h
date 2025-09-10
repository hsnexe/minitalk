/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashammo <hashammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:20:29 by hashammo          #+#    #+#             */
/*   Updated: 2025/09/10 15:18:36 by hashammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERROR_USAGE "enter valid arguments: ./client <PID> <message>\n"
# define ERROR_PID "invalid PID\n"
# define ERROR_MSG "ERROR : MESSAGE IS EMPTY "

# include "ft_printf.h"
# include "libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

int		check_input(int ac, char **av);
int		valid_pid(char *s);
void	handler(int signal, siginfo_t *info, void *context);
void	safe_kill(__pid_t pid, int signal);
void	ack_handler(int signal);
void	end_handler(int signal);

#endif 