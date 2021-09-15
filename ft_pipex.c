/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:33:05 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/15 15:44:57 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_child(t_param *p, char **envp)
{
	int	check;
	int		i;

	check = dup2(p->f1, STDIN_FILENO);
	if (check < 0)
		return (0);
	check = dup2(p->end[1], STDOUT_FILENO);
	if (check < 0)
		return (0);
	close (p->end[0]);
	close (p->f1);
	i = - 1;
	while (p->ipath[++i])
		execve(p->finalpath1[i], p->args1, envp);
	perror("Error");
	return (1);
}

int	ft_parent(t_param *p, char **envp)
{
	int	status;
	int	i;

	status = 0;
	waitpid(-1, &status, 0);
	dup2(p->f2, STDOUT_FILENO);
	dup2(p->end[0], STDIN_FILENO);
	close(p->end[1]);
	close(p->f2);
	i = - 1;
	while (p->ipath[++i])
		execve(p->finalpath2[i], p->args2, envp);
	perror("Error");
	return (1);
}

void	pipex(t_param *p, char **envp)
{
	pid_t	parent;

	pipe(p->end);
	parent = fork();
	if (parent == -1)
		return (perror("Error "));
	if (parent == 0)
		ft_child(p, envp);
	else
		ft_parent(p, envp);
}
