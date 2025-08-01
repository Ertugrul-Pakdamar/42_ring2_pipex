/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:52:08 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/01 12:04:00 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_vars	*vars;

	ft_is_input_valid(argc, argv);
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		ft_exit_prog(NULL, -1);
	vars->env = NULL;
	vars->adress1 = NULL;
	vars->adress2 = NULL;
	vars->outfd = -1;
	vars->infd = -1;
	ft_init_env(envp, vars);
	if (!vars->env)
		ft_exit_prog(vars, -2);
	ft_is_programs_valid(argv, vars);
	vars->outfd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	vars->infd = open(argv[1], O_RDONLY);
	ft_pipex(vars, argv);
	ft_exit_prog(vars, 0);
}
