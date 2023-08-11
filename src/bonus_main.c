/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:01:31 by jmatheis          #+#    #+#             */
/*   Updated: 2023/08/11 14:58:54 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

// open infile & outfile, set no_of_cmds & envp
static void	redirections(int argc, char **argv, char **envp, t_var *var)
{
	var->envp = envp;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		var->no_of_cmds = argc - 4;
		var->outfile = open(argv[argc - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0666);
	}
	else
	{
		var->no_of_cmds = argc - 3;
		var->infile = open(argv[1], O_RDONLY);
		if (var->infile < 0)
			errorexit("ERROR: Check infile");
		var->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	}
	if (var->outfile < 0)
		errorexit("ERROR: Check outfile");
	get_path(var);
}

// create temp.txt & fill it
static void	heredoc(char **argv, t_var *var, char *tmp)
{
	char	*gnl;
	int		tmp_fd;

	tmp_fd = open(tmp, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	gnl = get_next_line(STDIN_FILENO);
	while (gnl)
	{
		gnl[ft_strlen(gnl) - 1] = '\0';
		if (ft_strncmp(gnl, argv[2], ft_strlen(argv[2]) + 1) == 0)
		{
			free(gnl);
			var->infile = tmp_fd;
			close (var->infile);
			return ;
		}
		ft_putstr_fd(gnl, tmp_fd);
		free(gnl);
		ft_putstr_fd("\n", tmp_fd);
		gnl = get_next_line(STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_var	var;
	t_multi	multi;

	if (argc < 5 || (argc < 6 && ft_strncmp(argv[1], "here_doc", 9) == 0))
		errorexit("not enough arguments");
	ft_memset(&var, 0, sizeof(t_var));
	ft_memset(&multi, 0, sizeof(t_multi));
	redirections(argc, argv, envp, &var);
	multi.heredoc = argv[1];
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		var_init(argv, &var, 3);
		heredoc(argv, &var, "temp.txt");
	}
	else
		var_init(argv, &var, 2);
	multipipe(&var, &multi);
	while (waitpid(0, NULL, 0) != -1)
		continue ;
	free_after_piping(&var);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		unlink("temp.txt");
	return (0);
}

// system("leaks pipex");	