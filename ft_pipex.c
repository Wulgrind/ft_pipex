int	ft_child(int f1, cmd1)
{
	int	check;

	check = dup2(f1, 0);
	if (check < 0)
		return (0);
	check = dup2(end[1], 1);
	if (check < 0)
		return (0);
	close (end[0]);
	close (f1);

	return(1);
}

int	ft_parent(int f2, cmd2)
{
	int	status;

	status = 0;
	waitpid(-1, &status, 0);
}

void	pipex(int f1, int f2)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent == -1)
		return (perror("Fork: "));
	if (parent == 0)
		ft_child(f1, cmd1);
	else
		ft_parent(f2, cmd2);
}
