/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:19:06 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/31 12:19:34 by epakdama         ###   ########.fr       */
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
		ft_printf("program not found\n");
	if (code == -7)
		ft_printf("Error executing first command\n");
	if (code == -8)
		ft_printf("Error executing second command\n");
}

void	ft_exit_prog(t_vars *vars, int code)
{
	int	i;

	if (vars)
	{
		i = 0;
		while (vars->env[i])
			free(vars->env[i++]);
		if (vars->env)
			free(vars->env);
		if (vars->adress1)
			free(vars->adress1);
		if (vars->adress2)
			free(vars->adress2);
		free(vars);
	}
	ft_exit_outs(code);
	exit(code);
}
