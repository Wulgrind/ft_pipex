/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:58:11 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/15 15:33:26 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit3(t_param *p)
{
	int	i;
	
	i = -1;
	if (p->finalpath2 != NULL)
	{
		while (p->finalpath2[++i])
			free(p->finalpath2[i]);
		free(p->finalpath2);
	}
}

void	ft_exit2(t_param *p)
{
	int	i;
	
	i = -1;
	if (p->args2 != NULL)
	{
			while (p->args2[++i])
				free(p->args2[i]);
			free(p->args2);
	}
	i = -1;
	if (p->finalpath1 != NULL)
	{
		while (p->finalpath1[++i])
			free(p->finalpath1[i]);
		free(p->finalpath1);
	}
	ft_exit3(p);
}

void	ft_exit(t_param *p)
{
	int	i;
	i = -1;
	if (p->path != NULL)
		free (p->path);
	if (p->ipath != NULL)
	{
		while (p->ipath[++i])
			free(p->ipath[i]);
		free (p->ipath);
	}
	i = -1;
	if (p->args1 != NULL)
	{
		while (p->args1[++i])
			free(p->args1[i]);
		free (p->args1);
	}
	ft_exit2(p);
}
