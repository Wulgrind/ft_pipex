/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:15:36 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/14 19:16:30 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pathlen(int row, char **envp)
{
	int	i;

	i = 0;
	while (envp[row][i])
	{
		i++;
	}
	return (i - 5);
}

int	ft_pathfinder(char **envp, t_param *p)
{
	p->row = 0;
	p->col = 5;
	p->i = 0;
	while (envp[p->row])
	{
		if (envp[p->row][0] == 'P' && envp[p->row][1] == 'A'
			&& envp[p->row][2] == 'T' && envp[p->row][3] == 'H'
			&& envp[p->row][4] == '=')
			break;
		p->row++;
	}
	p->i = ft_pathlen(p->row, envp);
	p->path = malloc(sizeof(char) * p->i + 1);
	if (!p->path)
		return (-1);
	p->i = 0;
	while (envp[p->row][p->col])
	{
		p->path[p->i] = envp[p->row][p->col];
		p->col++;
		p->i++;
	}
	p->path[p->i] = '\0';
	return (1);
}

void	ft_parsing(char **envp, t_param *p, char **av)
{
	ft_pathfinder(envp, p);
	p->ipath = ft_split(p->path, ':');
	p->args1 = ft_split(av[2], ' ');
	p->args2 = ft_split(av[3], ' ');
	ft_path(p);
}
