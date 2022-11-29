/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatheis <jmatheis@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:42:17 by jmatheis          #+#    #+#             */
/*   Updated: 2022/11/08 07:59:49 by jmatheis         ###   ########.fr       */
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

// system("leaks pipex");

// ++++++++++++++++++++++++++++++++++
// *****
// CHAR **ENVP
// *****
// ->user environemnt
// -> PATH: checking cmd paths
// *****
// OPEN FLAGS
// *****
// A call to creat() is equivalent to
// calling open() with flags
// equal to O_CREAT|O_WRONLY|O_TRUNC.
// *****
// OPEN PERMISSIONS
// ****
// 0 --> file, d --> directory
// 0666 is an octal number, 
// 6 = rw
// 7 = rwx
// Owner perm | Group perm | worl perm
// when open existing file -> perm makes no sense
// when create a file -> random set of perm