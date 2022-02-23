/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:29:06 by crisfern          #+#    #+#             */
/*   Updated: 2022/02/21 15:39:15 by crisfern         ###   ########.fr       */
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

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
typedef struct s_cmd
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	**path;
}	t_cmd;

#endif
