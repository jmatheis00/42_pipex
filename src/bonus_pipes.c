/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:10:07 by jmatheis          #+#    #+#             */
/*   Updated: 2022/11/29 08:35:40 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

static void	firstprocess(int i, t_var *var, t_multi *multi)
{
	int	id;

	if (pipe(multi->secnd_fd) == -1)
	{
		free_after_piping(var);
		errorexit("Error occured with opening the pipe\n");
	}
	id = fork();
	if (id < 0)
	{
		free_after_piping(var);
		errorexit("An error occured with fork\n");
	}
	if (id == 0)
	{
		first_child(i, var, multi);
	}
	multi->first_fd[0] = multi->secnd_fd[0];
	multi->first_fd[1] = multi->secnd_fd[1];
}

static int	middleprocess(int *i, t_var *var, t_multi *multi)
{
	int	id;

	while (*i < var->no_of_cmds - 1)
	{
		if (pipe(multi->secnd_fd) == -1)
		{
			free_after_piping(var);
			errorexit("Error occured with opening the pipe\n");
		}
		id = fork();
		if (id < 0)
		{
			free_after_piping(var);
			errorexit("An error occured with fork\n");
		}
		if (id == 0)
			middle_child(*i, var, multi);
		close(multi->first_fd[0]);
		close(multi->first_fd[1]);
		multi->first_fd[0] = multi->secnd_fd[0];
		multi->first_fd[1] = multi->secnd_fd[1];
		(*i)++;
	}
	return (*i);
}

static void	lastprocess(int *i, t_var *var, t_multi *multi)
{
	int	id;

	id = fork();
	if (id < 0)
	{
		free_after_piping(var);
		errorexit("An error occured with fork\n");
	}
	if (id == 0)
		last_child(*i, var, multi);
}

void	multipipe(t_var *var, t_multi *multi)
{
	int	i;

	i = 0;
	firstprocess(i, var, multi);
	i++;
	i = middleprocess(&i, var, multi);
	lastprocess(&i, var, multi);
	close(multi->secnd_fd[0]);
	close(multi->secnd_fd[1]);
	close(multi->first_fd[0]);
	close(multi->first_fd[1]);
	close(var->outfile);
	close(var->infile);
	return ;
}
