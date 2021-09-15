/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:36:53 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/15 15:33:11 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_args(t_param *p)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	p->finalargs1 = malloc(sizeof(char *) * (ft_len(p->args1)));
	if (!p->finalargs1)
		return (-1);
	while (p->args1[j])
	{
		p->finalargs1[i] = p->args1[j];
		j++;
		i++;
	}
	p->finalargs1[i] = 0;
	i = 0;
	j = 1;
	p->finalargs2 = malloc(sizeof(char *) * (ft_len(p->args2)));
	if (!p->finalargs2)
		return (-1);
	while (p->args2[j])
	{
		p->finalargs2[i] = p->args2[j];
		j++;
		i++;
	}
	p->finalargs2[i] = 0;
	return (1);
}
