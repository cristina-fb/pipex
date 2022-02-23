/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:28:55 by crisfern          #+#    #+#             */
/*   Updated: 2022/02/23 15:33:02 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	leaks(void)
{
	system("leaks pipex");
}*/

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
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
		dup2(cmd->fd[1], STDOUT_FILENO);
		close(cmd->fd[1]);
		execve(cmd->path1, cmd->cmd1, envp);
		exit(1);
	}
}

void	child2(t_cmd *cmd, char **envp)
{
	int		id;
	int		fd_out;

	id = fork();
	if (id == -1)
		error(cmd, 1);
	else if (!id)
	{
		fd_out = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC);
		close(cmd->fd[1]);
		dup2(cmd->fd[0], STDIN_FILENO);
		close(cmd->fd[0]);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		execve(cmd->path2, cmd->cmd2, envp);
		exit(1);
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
		error(&cmd, 1);
	child1(&cmd, envp);
	child2(&cmd, envp);
	close(cmd.fd[0]);
	close(cmd.fd[1]);
	wait(NULL);
	free_cmd(&cmd);
	return (0);
}
