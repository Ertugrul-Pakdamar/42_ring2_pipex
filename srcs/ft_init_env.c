/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:12:44 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/31 13:08:50 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	**ft_init_env(char **envp, t_vars *vars)
{
	char	**res;
	int		i;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			res = ft_split(ft_strchr(envp[i], '=') + 1, ':');
			i = -1;
			while (res[++i])
			{
				temp = ft_strjoin(res[i], "/");
				free(res[i]);
				res[i] = temp;
			}
			break ;
		}
		i++;
	}
	vars->env = res;
	return (res);
}
