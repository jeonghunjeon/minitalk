/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 01:28:55 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/07/11 20:02:32 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sig_handler(int signal, siginfo_t *siginfo, void *unused)
{
	static t_msg	msg;

	(void)unused;
	msg.c += ((signal & 1) << msg.len);
	msg.len++;
	if (msg.len == 8)
	{
		ft_putchar_fd(msg.c, 1);
		if (!msg.c)
		{
			if (kill(siginfo->si_pid, SIGUSR1) == -1)
				ft_error();
			ft_putchar_fd('\n', 1);
		}
		msg = (t_msg){0, 0};
	}
}

int	main(void)
{
	struct sigaction	sig;

	write(1, "PID : ", 7);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sig_handler;
	while (1)
	{
		sigaction(SIGUSR1, &sig, 0);
		sigaction(SIGUSR2, &sig, 0);
		pause();
	}
	return (0);
}
