/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:12:44 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/01 09:26:33 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	**ft_init_env(char **envp, t_vars *vars)
{
	char	**res;
	int		i;
	char	*temp;

	res = NULL;
	i = 0;
	while (envp[i] != NULL)
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
			vars->env = res;
			break ;
		}
		i++;
	}
	return (res);
}
