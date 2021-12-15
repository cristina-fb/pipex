/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:28:55 by crisfern          #+#    #+#             */
/*   Updated: 2021/12/15 13:16:05 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	leaks(void)
{
	system("leaks pipex");
}

void	free_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (cmd->cmd1)
	{
		while (cmd->cmd1[i])
		{
			free(cmd->cmd1[i]);
			i++;
		}
		free(cmd->cmd1);
	}
	i = 0;
	if (cmd->cmd2)
	{
		while (cmd->cmd2[i])
		{
			free(cmd->cmd2[i]);
			i++;
		}
		free(cmd->cmd2);
	}
}

void	init_cmd(t_cmd *cmd, char **argv)
{
	cmd->infile = argv[1];
	cmd->outfile = argv[4];
	cmd->cmd1 = NULL;
	cmd->cmd2 = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	int		id;
	int		status;

	atexit(leaks);
	if (argc != 5)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	init_cmd(&cmd, argv);
	cmd.cmd1 = ft_split(argv[2], ' ');
	if (cmd.cmd1)
	{
		cmd.cmd2 = ft_split(argv[3], ' ');
		if (cmd.cmd2)
		{
			id = fork();
			if (!id)
				execve("/bin/ls", cmd.cmd1, envp);
			wait(&status);
		}
	}
	free_cmd(&cmd);
	return (0);
}
