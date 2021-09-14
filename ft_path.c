/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:39:11 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/14 18:13:17 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_len(char	*str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	ft_len2(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

void	ft_write(t_param *p)
{
	int	i;
	int	j;
	int	k;
	int	j2;

	i = 0;
	while (p->ipath[i])
	{
		j = 0;
		k = 0;
		while (p->ipath[i][j])
		{
			p->finalpath1[i][j] = p->ipath[i][j];
			p->finalpath2[i][j] = p->ipath[i][j];
			j++;
		}
		p->finalpath1[i][j] = '/';
		p->finalpath2[i][j] = '/';
		j++;
		j2 = j;
		while (p->args1[0][k])
		{
			p->finalpath1[i][j] = p->args1[0][k];
			j++;
			k++;
		}
		p->finalpath1[i][j] = '\0';
		k = 0;
		while (p->args2[0][k])
		{
			p->finalpath2[i][j2] = p->args2[0][k];
			j2++;
			k++;
		}
		p->finalpath2[i][j2] = '\0';
		i++;
	}
	p->finalpath1[i] = 0;
	p->finalpath2[i] = 0;
}

int	ft_path(t_param *p)
{
	int	i;

	i = 0;
	p->finalpath1 = malloc(sizeof(char *) * (ft_len2(p->ipath) + 1));
	p->finalpath2 = malloc(sizeof(char *) * (ft_len2(p->ipath) + 1));
	while (p->ipath[i])
	{
		p->finalpath1[i] = malloc(sizeof(char) * (ft_len(p->ipath[i]) + ft_len(p->args1[0]) + 2));
		p->finalpath2[i] = malloc(sizeof(char) * (ft_len(p->ipath[i]) + ft_len(p->args2[0]) + 2));
		i++;
	}
	if (!p->finalpath1)
		return (-1);
	if (!p->finalpath2)
		return (-1);
	ft_write(p);
	return (1);
}
