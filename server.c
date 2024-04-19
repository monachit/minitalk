/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:52:28 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/19 13:47:40 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handel_signal(int signal)
{
    static int a;
    static int i;

    if (signal == SIGUSR1)
       a |= (1 << i);
    i++;
    if(i == 8)
    {
        ft_printf("%c", a);
        i = 0;
        a = 0;
    }
}

int main(int ac, char **av)
{
    (void) av;

    if (ac != 1)
        exit(1);
    ft_printf("PID : %d\n", getpid());
    signal(SIGUSR1, handel_signal);
    signal(SIGUSR2, handel_signal);
    while (1)
    {
        sleep(1);
    }
    return (0);
}