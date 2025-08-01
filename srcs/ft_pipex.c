/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:33:24 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/01 12:19:46 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_child1(t_vars *vars, char **argv, int *fd)
{
	char	**cmd1;

	dup2(vars->infd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmd1 = ft_split(argv[2], ' ');
	if (!cmd1 || !cmd1[0])
	{
		ft_free_split(cmd1);
		ft_exit_prog(vars, -4);
	}
	execve(vars->adress1, cmd1, vars->envp);
	ft_free_split(cmd1);
	ft_exit_prog(vars, -7);
}

static void	ft_child2(t_vars *vars, char **argv, int *fd)
{
	char	**cmd2;

	dup2(fd[0], STDIN_FILENO);
	dup2(vars->outfd, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	cmd2 = ft_split(argv[3], ' ');
	if (!cmd2 || !cmd2[0])
	{
		ft_free_split(cmd2);
		ft_exit_prog(vars, -4);
	}
	execve(vars->adress2, cmd2, vars->envp);
	ft_free_split(cmd2);
	ft_exit_prog(vars, -8);
}

void	ft_pipex(t_vars *vars, char **argv)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		ft_exit_prog(vars, -1);
	pid1 = fork();
	if (pid1 == -1)
		ft_exit_prog(vars, -1);
	if (pid1 == 0)
		ft_child1(vars, argv, fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_exit_prog(vars, -1);
	if (pid2 == 0)
		ft_child2(vars, argv, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
