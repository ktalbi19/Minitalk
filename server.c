/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktalbi <ktalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:07:24 by ktalbi            #+#    #+#             */
/*   Updated: 2021/11/28 17:16:17 by ktalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((-n), fd);
	}
	else
	{
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}

void	bit_to_char(int bit)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (bit << i++);
	if (i > 7)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			write(1, &c, 1);
		}
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		bit_to_char(0);
	else if (signal == SIGUSR2)
		bit_to_char(1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	if (signal(SIGUSR1, signal_handler) == SIG_ERR)
		exit(1);
	if (signal(SIGUSR2, signal_handler) == SIG_ERR)
		exit(1);
	while (1)
		pause();
	return (0);
}
