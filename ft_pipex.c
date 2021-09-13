/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:33:05 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 18:17:48 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_child(t_param *p, cmd1)
{
	int	check;

	check = dup2(p->f1, 0);
	if (check < 0)
		return (0);
	check = dup2(end[1], 1);
	if (check < 0)
		return (0);
	close (end[0]);
	close (p->f1);

	return (1);
}

int	ft_parent(t_param *p, cmd2)
{
	int	status;

	status = 0;
	waitpid(-1, &status, 0);
	dup2(p->f2, 1);
	dup2(end[0], 1);
	close(end[1]);
	close(p->f2);

	return (1);
}

void	pipex(t_param *p, char **av)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent == -1)
		return (perror("Fork: "));
	if (parent == 0)
		ft_child(p, cmd1);
	else
		ft_parent(p, cmd2);
}
