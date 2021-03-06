/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:26:14 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/15 14:58:08 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av, char **envp)
{
	t_param	p;

	if (ac != 5)
		return (0);
	p.f1 = open(av[1], O_RDONLY);
	p.f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC);
	if (p.f1 < 0 || p.f2 < 0)
		return (0);
	ft_init(&p);
	ft_parsing(envp, &p, av);
	if (p.f1 < 0 || p.f2 < 0)
		return (-1);
	pipex(&p, av);
	close (p.f1);
	close (p.f2);
	ft_exit(&p);
	return (0);
}
