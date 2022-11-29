/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:01:43 by jmatheis          #+#    #+#             */
/*   Updated: 2022/11/07 19:31:28 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	errorexit(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

void	var_init(char **argv, t_var *var, int start)
{
	int	i;

	i = 0;
	var->cmdswithopts = ft_calloc(var->no_of_cmds,
			var->no_of_cmds * sizeof(char *));
	var->cmds = ft_calloc(var->no_of_cmds,
			var->no_of_cmds * sizeof(char *));
	var->path_of_cmds = ft_calloc(var->no_of_cmds,
			var->no_of_cmds * sizeof(char *));
	if (var->cmdswithopts == NULL || var->cmds == NULL
		|| var->path_of_cmds == NULL)
		exit (EXIT_FAILURE);
	while (i < var->no_of_cmds)
	{
		var->cmdswithopts[i] = ft_split(argv[start], ' ');
		var->cmds[i] = ft_strjoin("/", var->cmdswithopts[i][0]);
		var->path_of_cmds[i] = get_cmdpath(var, var->cmds[i]);
		i++;
		start++;
	}
	free_before_piping(var);
}

void	free_after_piping(t_var *var)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var->cmdswithopts && var->cmdswithopts[i])
	{
		while (var->cmdswithopts[i] && var->cmdswithopts[i][j])
		{
			free(var->cmdswithopts[i][j]);
			j++;
		}
		free(var->cmdswithopts[i]);
		j = 0;
		i++;
	}
	free(var->cmdswithopts);
	i = 0;
	while (var->path_of_cmds && var->path_of_cmds[i])
	{
		free(var->path_of_cmds[i]);
		i++;
	}
	free(var->path_of_cmds);
}

void	free_before_piping(t_var *var)
{
	int	i;

	i = 0;
	while (var->folders && var->folders[i])
	{
		free(var->folders[i]);
		i++;
	}
	free(var->folders);
	i = 0;
	while (var->cmds && var->cmds[i])
	{
		if (access(var->cmds[i], 0) != 0)
			free(var->cmds[i]);
		i++;
	}
	free(var->cmds);
}
