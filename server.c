/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:52:28 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/15 20:01:49 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handel_signal(int signal)
{
    int i;
    
}

int main()
{
    printf("%d ", getpid());

    signal(SIGUSR1, handel_signal);
    signal(SIGUSR2, handel_signal);
    while (1)
    {
        pause();
    }
}