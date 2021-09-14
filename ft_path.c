/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:39:11 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/14 19:03:27 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_len(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_len2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_write2(t_param *p)
{
	
}

void	ft_write(t_param *p)
{
	p->i = 0;
	while (p->ipath[p->i])
	{
		p->j = 0;
		p->k = 0;
		while (p->ipath[p->i][p->j])
		{
			p->finalpath1[p->i][p->j] = p->ipath[p->i][p->j];
			p->finalpath2[p->i][p->j] = p->ipath[p->i][p->j];
			p->j++;
		}
		p->finalpath1[p->i][p->j] = '/';
		p->finalpath2[p->i][p->j] = '/';
		p->j++;
		p->j2 = p->j;
		while (p->args1[0][p->k])
		{
			p->finalpath1[p->i][p->j] = p->args1[0][p->k];
			p->j++;
			p->k++;
		}
		p->finalpath1[p->i][p->j] = '\0';
		p->k = 0;
		//ft_write2(p);
		while (p->args2[0][p->k])
		{
			p->finalpath2[p->i][p->j2] = p->args2[0][p->k];
			p->j2++;
			p->k++;
		}
		p->finalpath2[p->i][p->j2] = '\0';
		p->i++;
	}
	p->finalpath1[p->i] = 0;
	p->finalpath2[p->i] = 0;
}

int	ft_path(t_param *p)
{
	int	i;

	i = 0;
	p->finalpath1 = malloc(sizeof(char *) * (ft_len2(p->ipath) + 1));
	p->finalpath2 = malloc(sizeof(char *) * (ft_len2(p->ipath) + 1));
	while (p->ipath[i])
	{
		p->finalpath1[i] = malloc(sizeof(char)
				* (ft_len(p->ipath[i]) + ft_len(p->args1[0]) + 2));
		p->finalpath2[i] = malloc(sizeof(char)
				* (ft_len(p->ipath[i]) + ft_len(p->args2[0]) + 2));
		i++;
	}
	if (!p->finalpath1)
		return (-1);
	if (!p->finalpath2)
		return (-1);
	ft_write(p);
	return (1);
}
