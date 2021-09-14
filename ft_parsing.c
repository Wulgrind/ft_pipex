/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:15:36 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/14 17:33:06 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_pathlen(int row, char **envp)
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
	int	row;
	int	col;
	int	i;

	row = 0;
	col = 5;
	i = 0;
	while (envp[row])
	{
		if (envp[row][0] == 'P' && envp[row][1] == 'A'
			&& envp[row][2] == 'T' && envp[row][3] == 'H'
			&& envp[row][4] == '=')
			break;
		row++;
	}
	i = ft_pathlen(row, envp);
	p->path = malloc(sizeof(char) * i + 1);
	if (!p->path)
		return (-1);
	i = 0;
	while (envp[row][col])
	{
		p->path[i] = envp[row][col];
		col++;
		i++;
	}
	p->path[i] = '\0';
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
