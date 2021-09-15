/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:16:30 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/15 15:48:08 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_init(t_param *p)
{
	p->path = NULL;
	p->ipath = NULL;
	p->args1 = NULL;
	p->args2 = NULL;
	p->finalpath1 = NULL;
	p->finalpath2 = NULL;
}
