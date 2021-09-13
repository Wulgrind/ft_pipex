/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:15:36 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 18:37:18 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_pathlen(int i, char **envp)
{
	int	i;

	i = 0;
	while (envp[row][i])
	{
		i++;
	}
	return (i - 5);
}

void	ft_pathfinder(char **envp, t_param *p)
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
	i = 0;
	while (envp[row][col])
	{
		p->path[i] = envp[row][col];
		col++;
		i++;
	}
	p->path[i] = '\0';
}

void	ft_parsing(char **envpi, t_param *p, char **av)
{
	ft_pathfinder(envp);
	p->ipath = ft_split(p->path, ":");
	p->args = ft_split(p->args, " ");

}
