/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:29:06 by crisfern          #+#    #+#             */
/*   Updated: 2022/02/25 10:51:47 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_cmd
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**path;
	char	*path1;
	char	*path2;
	char	fd_in;
	char	fd_out;
	int		fd[2];
}	t_cmd;
void	error(t_cmd *cmd, int err);
void	init_cmd(t_cmd *cmd, char **argv, char	**envp);
void	free_cmd(t_cmd *cmd);
int		join_path(t_cmd *cmd, char *str, int id);
int		get_path(t_cmd *cmd, char **envp);
int		check_file_permissions(t_cmd *cmd);
#endif
