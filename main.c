/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:26:14 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 18:36:05 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av char **envp)
{
	int	f1;
	int	f2;
	t_param	p;

	p.f1 = open(av[1], O_RDONLY);
	p.f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC);
	ft_init(&p);
	ft_parsing(envp, &p, av);
	if (p.f1 < 0 || p.f2 < 0)
		return (-1);
	pipex(&p, av);
	close (p.f1);
	close (p.f2);
	return (0);
}
