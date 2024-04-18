/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:45:14 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/17 18:14:00 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int ac, char **av)
{
    int z;
    int bit;

    if (ac != 3)
        exit(0);
    z = 0;
    bit = 0;
    while (av[2][z])
    {
        if ((av[2][z] & 1 << bit) != 0)
            kill(atoi(av[1]), SIGUSR1);
        else if ((av[2][z] & 1 << bit) == 0)
            kill(atoi(av[1]), SIGUSR2);
        bit++;
        if (bit == 8)
        {
            bit = 0;
            z++;
        }
    }
}