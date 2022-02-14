/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:28:55 by crisfern          #+#    #+#             */
/*   Updated: 2022/02/02 10:45:27 by crisfern         ###   ########.fr       */
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

void	error(t_cmd *cmd, int err)
{
	free_cmd(cmd);
	if (err == 0)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	else if (err == 1)
		exit(1);
}

void	get_path(t_cmd *cmd, char **envp)
{
	int		i;

	i = 0;
	if (envp)
	{
		while (envp[i])
		{
			if ((envp[i][0] == 'P') && (envp[i][1] == 'A')
				&& (envp[i][2] == 'T') && (envp[i][3] == 'H')
				&& (envp[i][4] == '='))
			{
				cmd->path = ft_split(&envp[i][5], ':');
				return ;
			}
			i++;
		}
	}
	cmd->path = 0;
}

void	init_cmd(t_cmd *cmd, char **argv, char	**envp)
{
	cmd->infile = argv[1];
	cmd->outfile = argv[4];
	cmd->cmd1 = ft_split(argv[2], ' ');
	cmd->cmd2 = ft_split(argv[3], ' ');
	if (cmd->cmd1 && cmd->cmd2)
		get_path(cmd, envp);
}

void	check_permissions(char *file, int flag)
{
	if (access(file, flag) != 0)
	{
		perror(file);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;
	int		id;
	int		fd[2];
	int		fd_in;

	//atexit(leaks);
	if (argc != 5)
		error(&cmd, 0);
	init_cmd(&cmd, argv, envp);
	check_permissions(cmd.infile, R_OK);
	if (pipe(fd) == -1)
		error(&cmd, 1);
	id = fork();
	if (id == -1)
		error(&cmd, 1);
	else if (!id)
	{
		close(fd[0]);
		fd_in = open(cmd.infile, O_RDONLY);
		execve("/bin/ls", cmd.cmd1, envp);
		perror("Caca");
	}
	else
	{
		close(fd[1]);
	}
	wait(NULL);
	free_cmd(&cmd);
	return (0);
}
