/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:42:17 by jmatheis          #+#    #+#             */
/*   Updated: 2023/08/11 14:59:27 by jmatheis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_var	var;

	if (argc != 5)
		errorexit("Wrong number of arguments");
	ft_memset(&var, 0, sizeof(t_var));
	var.envp = envp;
	var.infile = open(argv[1], O_RDONLY);
	if (var.infile < 0)
	{
		perror("Infile");
		return (EXIT_FAILURE);
	}
	var.outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (var.outfile < 0)
	{
		perror("Outfile");
		return (EXIT_FAILURE);
	}
	get_path(&var);
	var.no_of_cmds = 2;
	var_init(argv, &var, 2);
	pipes (&var);
	free_after_piping(&var);
	return (0);
}
