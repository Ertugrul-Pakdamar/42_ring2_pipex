/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:12:44 by epakdama          #+#    #+#             */
/*   Updated: 2025/08/01 12:19:04 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	**ft_init_env(char **envp, t_vars *vars)
{
	char	**res;
	int		i;

	res = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			res = ft_split(ft_strchr(envp[i], '=') + 1, ':');
			vars->path = res;
			break ;
		}
		i++;
	}
	return (res);
}
