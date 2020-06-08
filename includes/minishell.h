/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celeloup <celeloup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 09:45:30 by celeloup          #+#    #+#             */
/*   Updated: 2020/05/28 14:53:48 by celeloup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/src/libft.h"
# include <signal.h>

# define GREEN "\033[1;32m"
# define BLUE "\033[1;36m"
# define YELLOW "\033[0;33m"
# define RED "\033[1;31m"
# define END "\033[0m"

# define SPACE      	32
# define TAB        	9
# define NEWLINE    	10
# define IFS(x)			(x == SPACE || x == TAB || x == NEWLINE)
# define BKSLASH		92
# define SINGLE_QUOTE	39
# define DOUBLE_QUOTE	34
# define DOLLAR			36
# define QUOTE(x)		(x == SINGLE_QUOTE || x == DOUBLE_QUOTE)
# define ESCAPE_CHAR(x)	(x == 'a' || x == 'b' || x == 'e' || x == 'f' || x == 'n' || x == 'r' || x == 't' || x == 'v' || x == BACKSLASH || x == 'x' || x == 'c')
# define RDIR(x)		(x == '>' || x == '<')
# define CMD_SEP(x)		(x == '|' || x == ';')

# define RDIR_IN		1
# define RDIR_OUT		2
# define APP_RDIR_OUT	3

typedef	struct		s_rdir{
	int				type;
	char			*value;
	struct s_rdir	*next;
}					t_rdir;

typedef	struct		s_cmd{
	char			**argv;
	int				argc;
	t_rdir			*rdir;
	int				pipe;
	struct s_cmd	*next;
}					t_cmd;

void	fonction_test_celia();

/* parsing.c */
t_cmd			*parse_input(char *input, char *env[]);

/* debug.c */
void			print_args(int argc, char **argv);
void			print_cmd_rdir(t_rdir *rdir);
void			print_cmd(t_cmd *cmd, int i);

/* free.c */
void			free_cmd(t_cmd *cmd_list);
void			free_rdir(t_rdir *rdir);

/* init.c */
t_cmd			*init_cmd(char *input);
t_rdir			*init_rdir();

#endif