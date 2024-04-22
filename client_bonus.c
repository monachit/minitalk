/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnachit <mnachit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:53:07 by mnachit           #+#    #+#             */
/*   Updated: 2024/04/21 19:00:14 by mnachit          ###   ########.fr       */
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

void    ft_message(int signal)
{
    (void )signal;
    ft_printf("message wsall 9ta3");
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
            usleep(300);
            bit++;
        }
        i++;
    }
}

void    ft_exit(char *s)
{
    ft_printf("%s", s);
    exit(1);
}

void    ft_digit(char *av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (av[i] < '0' || av[i] > '9')
            ft_exit("error");
        i++;
    }
}

void ft_pass_n(char c, int pid)
{
	int bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit++;
	}
}

int main(int ac, char **av)
{
    if (ac != 3)
        ft_exit("error");
    ft_digit(av[1]);
	signal(SIGUSR1, ft_message);
    ft_pass(av[2], ft_atoi(av[1]));
	ft_pass_n('\0', ft_atoi(av[1]));
}