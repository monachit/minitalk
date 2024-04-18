/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:52:28 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/17 18:16:38 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handel_signal(int signal)
{
    static int a;
    static int i;

    if (signal == SIGUSR1)
       a = a | 1 << i;
    i++;
    if(i == 8)
    {
        printf("OK\n"); 
        i = 0;
        a = 0;
    }
}

int main()
{
    printf("%d\n", getpid());
    while (1)
    {
        signal(SIGUSR1, handel_signal);
        signal(SIGUSR2, handel_signal);
    }
}