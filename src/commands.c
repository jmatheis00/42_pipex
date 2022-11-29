/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:42:53 by jmatheis          #+#    #+#             */
/*   Updated: 2022/11/07 19:27:40 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	get_path(t_var *var)
{
	int	i;

	i = 0;
	while (var->envp && var->envp[i])
	{
		if (ft_strncmp("PATH", var->envp[i], 3) == 0)
		{
			var->path = ft_strchr(var->envp[i], '/');
			var->folders = NULL;
			if (var->path != NULL)
				var->folders = ft_split(var->path, ':');
			return ;
		}
		i++;
	}
}

// check absolute paths & cmds without path
char	*get_cmdpath(t_var *var, char *cmd)
{
	int		i;
	char	*cmdpath;

	cmdpath = NULL;
	i = 0;
	if (var->envp == NULL || var->folders == NULL
		|| ft_strchr(cmd, '/') != NULL)
	{
		cmdpath = cmd;
		if (access(cmdpath, 0) == 0)
			return (cmdpath);
	}
	while (var->folders && var->folders[i])
	{
		cmdpath = (ft_strjoin(var->folders[i], cmd));
		if (access(cmdpath, 0) == 0)
			return (cmdpath);
		free (cmdpath);
		i++;
	}
	free_before_piping(var);
	ft_printf("Check commands!\n");
	exit (EXIT_FAILURE);
}
