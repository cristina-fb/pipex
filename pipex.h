/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crisfern <crisfern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:29:06 by crisfern          #+#    #+#             */
/*   Updated: 2021/12/15 12:12:38 by crisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_cmd
{
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
}	t_cmd;

#endif
