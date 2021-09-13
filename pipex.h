/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:47:57 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/13 18:36:27 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef	struct	s_param
{
	char	*path;
	char	**ipath;
	char	**args;
}				t_param;

int		ft_child(t_param *p, cmd1);
int		ft_parent(t_param *p, cmd2);
void	pipex(t_param *p, char **av);
char	**ft_split(char const *s, char c);
void	ft_parsing(char **envp, t_param *p, char **av);

#endif
