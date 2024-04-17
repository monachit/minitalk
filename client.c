/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:45:14 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/17 13:31:34 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
    (void) ac;
    int i;
    int z;
    int bit;

    i = 0;
    z = 0;
    bit = 0;
    while (av[2][z])
    {
        i = av[2][z] & 1 << bit;
        if (i == 0)
            kill(av[1], SIGUSR1);
        else
            kill(av[1], SIGUSR2);
        bit++;
        if (bit > 8)
        {
            bit = 0;
            z++;
        }
    }
}