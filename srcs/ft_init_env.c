/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:12:44 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/31 12:29:26 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	**ft_init_env(char **envp)
{
	char	**res;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			res = ft_split(ft_strchr(envp[i], '=') + 1, ':');
			i = -1;
			while (res[++i])
				res[i] = ft_strjoin(res[i], "/");
			break ;
		}
		i++;
	}
	return (res);
}
