/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:29:06 by crisfern          #+#    #+#             */
/*   Updated: 2022/02/23 11:33:18 by crisfern         ###   ########.fr       */
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
	int		fd[2];
}	t_cmd;
void	init_cmd(t_cmd *cmd, char **argv, char	**envp);
void	free_cmd(t_cmd *cmd);
void	join_path(t_cmd *cmd, char *str);
void	get_path(t_cmd *cmd, char **envp, int id);
int		check_cmd_permissions(t_cmd *cmd, int id);
#endif
