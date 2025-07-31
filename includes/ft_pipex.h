/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 09:51:48 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/31 13:02:44 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_vars
{
	char	**env;
	char	*adress1;
	char	*adress2;
	int		outfd;
	int		infd;
}			t_vars;

char		**ft_init_env(char **envp, t_vars *vars);
void		ft_exit_prog(t_vars *vars, int code);
void		ft_is_input_valid(int argc, char **argv);
void		ft_is_programs_valid(char **argv, t_vars *vars);
void		ft_pipex(t_vars *vars, char **argv);
void		ft_free_split(char **arr);

#endif
