/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_singlepipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:24:01 by jmatheis          #+#    #+#             */
/*   Updated: 2023/08/11 14:59:34 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

static void	man_first_child(int *fd, t_var *var)
{
	if (dup2(fd[1], STDOUT_FILENO) < 0 || close(fd[0]) < 0 || close(fd[1]) < 0
		|| dup2(var->infile, STDIN_FILENO) < 0)
	{
		free_after_piping(var);
		errorexit("ERROR: Check first child");
	}
	execve(var->path_of_cmds[0], var->cmdswithopts[0], var->envp);
}

static void	man_last_child(int *fd, t_var *var)
{
	if (dup2(fd[0], STDIN_FILENO) < 0 || close(fd[1]) < 0 || close(fd[0]) < 0
		|| dup2(var->outfile, STDOUT_FILENO) < 0)
	{
		free_after_piping(var);
		errorexit("ERROR: check last child");
	}
	execve(var->path_of_cmds[1], var->cmdswithopts[1], var->envp);
}

static void	parentprocess(int *fd, int id1, int id2, t_var *var)
{
	close(var->infile);
	close(var->outfile);
	close(fd[0]);
	close(fd[1]);
	waitpid(id1, NULL, 0);
	waitpid(id2, NULL, 0);
}

static void	childprocesses(t_var *var, int id1, int id2, int *fd)
{
	id1 = fork();
	if (id1 < 0)
	{
		free_after_piping(var);
		errorexit("An error occured with fork\n");
	}
	if (id1 == 0)
		man_first_child(fd, var);
	id2 = fork();
	if (id2 < 0)
	{
		free_after_piping(var);
		errorexit("An error occured with fork\n");
	}
	if (id2 == 0)
		man_last_child(fd, var);
}

void	pipes(t_var *var)
{
	int	fd[2];
	int	id1;
	int	id2;

	id1 = 0;
	id2 = 0;
	if (pipe(fd) == -1)
	{
		free_after_piping(var);
		errorexit("Error occured with opening the pipe\n");
	}
	childprocesses(var, id1, id2, fd);
	parentprocess(fd, id1, id2, var);
}
