#ifndef INPUTS_H
# define INPUTS_H

# define MIN_W 10
# include <sys/param.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <libft.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <signal.h>
# include <pwd.h>
# include <termios.h>
# include <termcap.h>
# include <signal.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <curses.h>
# define BYPASS struct	termios

typedef struct		s_params
{
	char			**av;
	int				ac;
	char			*v_term;
	char			buf[2048];
	struct termios	term;
	char			r_char[4];
	int				print;
	tcflag_t		old_term;
	BYPASS			*oldterm;
	int				c_pos_x;
	int				c_pos_y;
	int				l_count;
	int				col_count;
	int				max_size;
}					t_params;

typedef struct		s_str
{
	char			*str;
	char			*tmp;
	struct s_str	*next;
	struct s_str	*past;
}					t_str;

typedef struct		s_env
{
	char			**env;
	pid_t			pid;
	char			*input;
	int				ac;
	char			**av;
	char			**paths;
	char			*pwd;
	char			*oldpwd;
	char			*binpath;
	char			*home;
	char			*name;
	char			*path;
	t_params		*p;
	char			*str;
	size_t			index;
	size_t			max;
	t_str			*histo;
	t_str			*phisto;
	pid_t			cpid;
	char			*name_shell;
	char			*name_process;
}					t_env;

int			ft_arrows(t_env *e, char *inputs);
void		ft_arrows2(t_env *e, char kind);
char		*ft_chardup(char c);
int			ft_clear_input(t_env *e);
void		ft_clean_histo(t_env *e);
void		ft_update_input(t_env *e);
void		ft_endline(t_env *e);
int			ft_process_char(t_env *e, char *inputs);
int			ft_process_delete(t_env *e);
int			ft_process_back_delete(t_env *e);
int			ft_clear(t_env *e, char *inputs);
t_env		*ft_get_env(char **envp);
int			ft_quit(t_env *e, char *inputs);
int			ft_delete(t_env *e, char *inputs);
int			ft_get_inputs(t_env *e);
void		ft_lststr_add(t_str **lst, t_str *new);
t_str		*ft_lststr_new(char *str);
void		ft_goleft(t_env *e);
void		ft_goright(t_env *e);
int			ft_putc(int c);
void		ft_put_histo(t_env *e);
void		ft_special(t_env *e, int kind);

#endif