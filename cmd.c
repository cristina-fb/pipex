/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:28:55 by crisfern          #+#    #+#             */
/*   Updated: 2022/02/25 11:13:11 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_cmd(t_cmd *cmd, char **argv, char	**envp)
{
	int	flag;

	flag = 0;
	cmd->infile = argv[1];
	cmd->outfile = argv[4];
	cmd->cmd1 = ft_split(argv[2], ' ');
	cmd->cmd2 = ft_split(argv[3], ' ');
	if (cmd->cmd1 && cmd->cmd2)
	{
		cmd->fd_out = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC);
		flag |= check_file_permissions(cmd);
		flag |= get_path(cmd, envp);
		if (flag)
		{
			close(cmd->fd_out);
			error(cmd, 1);
		}
	}
	else
		error(cmd, 1);
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

int	join_path(t_cmd *cmd, char *str, int id)
{
	int		i;
	char	*aux;
	char	*path;

	i = 0;
	while (cmd->path && cmd->path[i])
	{
		aux = ft_strjoin(cmd->path[i++], "/");
		path = ft_strjoin(aux, str);
		free(aux);
		if (access(path, X_OK) == 0)
		{
			if (!id)
				cmd->path1 = path;
			else
				cmd->path2 = path;
			return (0);
		}
		free(path);
	}
	ft_putstr_fd(str, 1);
	ft_putstr_fd(": command not found\n", 1);
	return (1);
}

int	get_path(t_cmd *cmd, char **envp)
{
	int	i;
	int	flag;

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
				break ;
			}
			i++;
		}
		join_path(cmd, cmd->cmd1[0], 0);
		flag = join_path(cmd, cmd->cmd2[0], 1);
		if (flag)
			return (1);
		return (0);
	}
	cmd->path = 0;
	return (0);
}

int	check_file_permissions(t_cmd *cmd)
{
	int	flag;

	flag = 0;
	if (access(cmd->infile, R_OK) != 0)
	{
		perror(cmd->infile);
		flag = 1;
	}
	if (cmd->fd_out < 0)
	{
		perror(cmd->outfile);
		flag = 1;
	}
	return (flag);
}
