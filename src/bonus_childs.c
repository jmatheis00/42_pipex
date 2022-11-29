/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_childs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:10:07 by jmatheis          #+#    #+#             */
/*   Updated: 2022/11/29 08:26:40 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	first_child(int i, t_var *var, t_multi *multi)
{
	if (ft_strncmp(multi->heredoc, "here_doc", 9) == 0)
		var->infile = open("temp.txt", O_RDONLY);
	if (dup2(multi->secnd_fd[1], STDOUT_FILENO) < 0
		|| close(multi->secnd_fd[1]) < 0
		|| close(multi->secnd_fd[0]) < 0
		|| dup2(var->infile, STDIN_FILENO) < 0)
	{
		free_after_piping(var);
		perror("ERROR: Check first child");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(multi->heredoc, "here_doc", 9) == 0)
		close(var->infile);
	execve(var->path_of_cmds[i], var->cmdswithopts[i], var->envp);
}

void	middle_child(int i, t_var *var, t_multi *multi)
{
	if (dup2(multi->secnd_fd[1], STDOUT_FILENO) < 0
		|| dup2(multi->first_fd[0], STDIN_FILENO) < 0
		|| close(multi->first_fd[1]) < 0
		|| close(multi->first_fd[0]) < 0
		|| close(multi->secnd_fd[1]) < 0
		|| close(multi->secnd_fd[0]) < 0)
	{
		free_after_piping(var);
		perror("ERROR: Check middle child");
		exit(EXIT_FAILURE);
	}
	execve(var->path_of_cmds[i], var->cmdswithopts[i], var->envp);
}

void	last_child(int i, t_var *var, t_multi *multi)
{
	if (dup2(var->outfile, STDOUT_FILENO) < 0
		|| dup2(multi->first_fd[0], STDIN_FILENO) < 0
		|| close(multi->first_fd[0]) < 0
		|| close(multi->first_fd[1]) < 0)
	{
		free_after_piping(var);
		perror("ERROR: Check last child");
		exit(EXIT_FAILURE);
	}
	execve(var->path_of_cmds[i], var->cmdswithopts[i], var->envp);
}
