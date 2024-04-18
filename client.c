/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:45:14 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/18 15:45:19 by mnachit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	n_p;
	int	r;
	int	i;

	i = 0;
	n_p = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n_p = n_p * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - 48;
		i++;
	}
	return (n_p * r);
}

void    ft_pass(char *str, int pid)
{
    int bit;
    int i;
    
    i = 0;
    while (str[i])
    {
        bit = 0;
        while (bit < 8)
        {
            if ((str[i] & (1 << bit)) != 0)
                kill(pid, SIGUSR1);
            else if ((str[i] & (1 << bit)) == 0)
                kill(pid, SIGUSR2);
            bit++;
            usleep(300);
        }
        i++;
    }
}

void    ft_digit(char *av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (av[i] <= '0' || av[i] >= '9')
            exit(1);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 3)
        exit(1);
    ft_digit(av[1]);
    ft_pass(av[2], ft_atoi(av[1]));
}