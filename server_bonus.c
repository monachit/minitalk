/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:52:51 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/21 19:05:21 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void    ft_handler(int signal, siginfo_t *info, void *other)
{
    static int  i;
    static int  a;
    pid_t       pid;
    
    
    (void )other;
    pid = info->si_pid;
    if (signal == SIGUSR1)
        a |= 1 << i;
    i++;
    if (i == 8)
    {
        ft_printf("%c", a);
        if (a == '\0')
            kill(pid , SIGUSR1);
        a = 0;
        i = 0;
    }
}

int main(int ac, char **av)
{
    struct sigaction sa;
    
    (void )av;
    if(ac != 1)
        exit(0);
    ft_printf("PID : %d\n", getpid());
    sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
    {
        
    }
}