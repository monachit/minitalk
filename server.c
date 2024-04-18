/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:52:28 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/18 15:46:12 by mnachit          ###   ########.fr       */
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

int main()
{
    ft_printf("PID : %d\n", getpid());
    signal(SIGUSR1, handel_signal);
    signal(SIGUSR2, handel_signal);
    while (1)
    {
        
    }
    return (0);
}