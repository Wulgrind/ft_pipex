/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbrillai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:47:57 by qbrillai          #+#    #+#             */
/*   Updated: 2021/09/15 15:56:24 by qbrillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_param
{
	char	*path;
	char	**ipath;
	char	**args1;
	char	**args2;
	char	**finalpath1;
	char	**finalpath2;
	int		end[2];
	int		f1;
	int		f2;
	int		i;
	int		j;
	int		k;
	int		j2;
	int		row;
	int		col;
}				t_param;

int		ft_child(t_param *p, char **envp);
int		ft_parent(t_param *p, char **envp);
void	pipex(t_param *p, char **envp);
char	**ft_split(char const *s, char c);
void	ft_parsing(char **envp, t_param *p, char **av);
int		ft_path(t_param *p);
void	ft_init(t_param *p);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_exit(t_param *p);

#endif
