/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:35:02 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/31 14:56:34 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_is_input_valid(int argc, char **argv)
{
	if (argc != 5)
		ft_exit_prog(NULL, -3);
	if (access(argv[1], R_OK) != 0)
		ft_exit_prog(NULL, -4);
	if (!argv[2] || !argv[2][0] || !argv[3] || !argv[3][0])
		ft_exit_prog(NULL, -3);
}

static void	ft_check_path(t_vars *vars, char **argv, int *res, int type)
{
	char	*temp;
	int		i;

	i = -1;
	while (vars->env[++i])
	{
		if (*res == 0)
		{
			if (type == 1)
				temp = ft_strjoin(vars->env[i], argv[2]);
			if (type == 2)
				temp = ft_strjoin(vars->env[i], argv[3]);
			if (access(temp, X_OK) == 0)
			{
				if (type == 1)
					vars->adress1 = temp;
				else if (type == 2)
					vars->adress2 = temp;
				*res = 1;
			}
			else
				free(temp);
		}
	}
}

void	ft_is_programs_valid(char **argv, t_vars *vars)
{
	int	res1;
	int	res2;

	res1 = 0;
	ft_check_path(vars, argv, &res1, 1);
	res2 = 0;
	ft_check_path(vars, argv, &res2, 2);
	if (!res1 || !res2)
		ft_exit_prog(vars, -6);
}
