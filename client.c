/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktalbi <ktalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:30:36 by ktalbi            #+#    #+#             */
/*   Updated: 2021/12/15 13:18:52 by ktalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(char *str)
{
	long int	res;
	long int	sign;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + (*str - 48);
		if (res * sign > INT_MAX)
			return (-1);
		if (res * sign < INT_MIN)
			return (0);
		str++;
	}
	return (res * sign);
}

//transforme le charactere c en bit à l'aide des operateurs bitwise
//le bit est envoyé à l'envers !
//et envoie les elements 1 par 1 vers le serveur

void	char_to_bit(int pid, char c)
{
	char	z;
	int		bit;

	z = 0;
	while (z < 8)
	{
		bit = (c >> z++) & 1;
		usleep(100);
		if (bit == 0)
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		if (bit == 1)
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
	}
}

//Envoie dans char_to_bit le pid et les caractères 1 par 1
//puis un caractere final \0

void	send_str(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		char_to_bit(pid, str[i]);
		i++;
	}
	char_to_bit(pid, 0);
}

// Ecris error si le programme est mal utilisé
// Récupere le pid dans argv[1]

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
	return (0);
}
