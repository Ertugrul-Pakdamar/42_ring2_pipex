/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:19:06 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/01 15:21:14 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

static void	ft_exit_outs(int code)
{
	if (code == -2)
		ft_printf("Your envpath is invalid.\n");
	if (code == -3)
		ft_printf("Your input is invalid.\n");
	if (code == -4)
		ft_printf("Infile permission denied or not found\n");
	if (code == -5)
		ft_printf("Outfile permission denied or not found\n");
	if (code == -6)
		ft_printf("Program not found\n");
	if (code == -7)
		write(2, "Error executing first command\n", 31);
	if (code == -8)
		write(2, "Error executing second command\n", 31);
}

void	ft_exit_prog(t_vars *vars, int code)
{
	if (vars != NULL)
	{
		ft_free_split(vars->path);
		if (vars->adress1 != NULL)
			free(vars->adress1);
		if (vars->adress2 != NULL)
			free(vars->adress2);
		if (vars->infd >= 3)
			close(vars->infd);
		if (vars->outfd >= 3)
			close(vars->outfd);
		free(vars);
	}
	ft_exit_outs(code);
	exit(code);
}
