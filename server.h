/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktalbi <ktalbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:09:19 by ktalbi            #+#    #+#             */
/*   Updated: 2021/11/28 17:21:44 by ktalbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>

int		main(void);
void	ft_putnbr_fd(int n, int fd);
void	signal_handler(int signal);
void	bit_to_char(int bit);
void	ft_putchar_fd(char c, int fd);

#endif