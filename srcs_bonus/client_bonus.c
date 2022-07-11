/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeonjeon <jeonjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:32:10 by jeonjeon          #+#    #+#             */
/*   Updated: 2022/07/08 18:56:54 by jeonjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_strlen(char *s)
{
	int		idx;
	char	*cpy;

	cpy = s;
	idx = 0;
	while (cpy[idx])
		idx++;
	return (idx);
}

static void	send_msg(char *str, pid_t pid, int len)
{
	int	idx;
	int	shift;

	idx = 0;
	while (idx <= len)
	{
		shift = 0;
		while (shift < 8)
		{
			if (kill(pid, SIGUSR1 + (((str[idx] >> shift) & 1) > 0)) == -1)
				ft_error();
			shift++;
			usleep(100);
		}
		idx++;
	}
}

void	check_receive(int signal)
{
	(void)signal;
	write(1, "Signal received\n", 16);
	exit(0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3 || !argv)
		ft_error();
	if (is_digit_str(argv[1]) == 0)
		ft_error();
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		ft_error();
	signal(SIGUSR1, check_receive);
	send_msg(argv[2], pid, ft_strlen(argv[2]));
	while (1)
		pause();
	return (0);
}
