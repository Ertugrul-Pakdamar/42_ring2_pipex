/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:35:02 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/31 12:26:30 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_is_input_valid(int argc, char **argv)
{
	if (argc != 5)
		ft_exit_prog(NULL, -3);
	if (access(argv[1], R_OK) != 0)
		ft_exit_prog(NULL, -4);
	if (access(argv[4], W_OK) != 0)
		ft_exit_prog(NULL, -5);
}

void	ft_is_programs_valid(char **argv, t_vars *vars)
{
	int	i;
	int	res1;
	int	res2;

	res1 = 0;
	i = -1;
	while (vars->env[i++])
	{
		if (!res1)
			vars->adress1 = ft_strjoin(vars->env[i], argv[2]);
		if (access(vars->adress1, X_OK) == 0)
			res1 = 1;
	}
	res2 = 0;
	i = -1;
	while (vars->env[i++])
	{
		if (!res2)
			vars->adress2 = ft_strjoin(vars->env[i], argv[3]);
		if (access(vars->adress2, X_OK) == 0)
			res2 = 1;
	}
	if (!res1 || !res2)
		ft_exit_prog(vars, -6);
}
