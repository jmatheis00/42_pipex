/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:41:33 by jmatheis          #+#    #+#             */
/*   Updated: 2022/11/29 08:26:24 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "../lib/printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "../lib/getnextline/get_next_line.h"

typedef struct s_var
{
	char	**envp;
	char	*path;
	char	**folders;

	char	**cmds;
	char	**path_of_cmds;
	char	***cmdswithopts;

	int		infile;
	int		outfile;
	int		no_of_cmds;
}				t_var;

typedef struct s_multi
{
	int		first_fd[2];
	int		secnd_fd[2];

	char	*heredoc;
}				t_multi;

// CHECK COMMANDS
void	get_path(t_var *var);
char	*get_cmdpath(t_var *var, char *cmd);

// INIT & FREE
void	var_init(char **argv, t_var *var, int start);
void	free_after_piping(t_var *var);
void	free_before_piping(t_var *var);
void	errorexit(char *message);

// MANDATORY
void	pipes(t_var *var);

// BONUS
void	multipipe(t_var *var, t_multi *multi);
void	first_child(int i, t_var *var, t_multi *multi);
void	middle_child(int i, t_var *var, t_multi *multi);
void	last_child(int i, t_var *var, t_multi *multi);

#endif