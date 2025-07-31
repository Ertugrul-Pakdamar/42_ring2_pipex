/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epakdama <epakdama@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:19:06 by epakdama          #+#    #+#             */
/*   Updated: 2025/07/31 10:22:22 by epakdama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_exit_prog(char **envp, int code)
{
	int	i;

	i = 0;
	while (envp[i])
		free(envp[i++]);
	if (envp)
		free(envp);
	exit(code);
}
