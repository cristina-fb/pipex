/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:28:55 by crisfern          #+#    #+#             */
/*   Updated: 2022/02/25 11:08:57 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	leaks(void)
{
	system("leaks pipex");
}*/

void	error(t_cmd *cmd, int err)
{
	if (err == 0)
	{
		write(1, "Error!\n", 7);
		exit(1);
	}
	else if (err == 1)
	{
		free_cmd(cmd);
		exit(1);
	}
}

void	child1(t_cmd *cmd, char **envp)
{
	int		id;
	int		fd_in;

	id = fork();
	if (id == -1)
		error(cmd, 1);
	else if (!id)
	{
		close(cmd->fd[0]);
		fd_in = open(cmd->infile, O_RDONLY | O_NONBLOCK);
		if (cmd->fd_in < 0)
		{
			close(cmd->fd_out);
			error(cmd, 1);
		}
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		dup2(cmd->fd[1], STDOUT_FILENO);
		close(cmd->fd[1]);
		execve(cmd->path1, cmd->cmd1, envp);
	}
}

void	child2(t_cmd *cmd, char **envp)
{
	int		id;

	id = fork();
	if (id == -1)
		error(cmd, 1);
	else if (!id)
	{
		close(cmd->fd[1]);
		dup2(cmd->fd[0], STDIN_FILENO);
		close(cmd->fd[0]);
		dup2(cmd->fd_out, STDOUT_FILENO);
		close(cmd->fd_out);
		execve(cmd->path2, cmd->cmd2, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	cmd;

	//atexit(leaks);
	if (argc != 5)
		error(&cmd, 0);
	init_cmd(&cmd, argv, envp);
	if (pipe(cmd.fd) == -1)
	{
		close(cmd.fd_out);
		error(&cmd, 1);
	}
	child1(&cmd, envp);
	child2(&cmd, envp);
	close(cmd.fd[0]);
	close(cmd.fd[1]);
	wait(NULL);
	free_cmd(&cmd);
	return (0);
}
