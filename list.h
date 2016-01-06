/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:20:49 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/05 15:50:47 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <string.h>
# include <unistd.h>
# include <sys/types.h> //WATCH OUT !! CHECK EVERY FILE FOR THOSE FUCKERS
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 10000

typedef struct		s_list
{
	char			**array;
	int				index;
	struct s_list 	*next;
}					t_list;

int			main(int argc, char **argv);
int			han_shot_first(char **argv);
char		*get_BUFF(int const fd);
static char	*ft_nofile(int const fd, char *file, char *buf);

int			check_block_hori(char *tab);
int			check_block_vert(char *tab);
int			check_tetriminos_nb(char *tab);
int			check_tetriminos_valid2(t_list *list, char *buf);
int			check_tetriminos_valid(t_list *list);

void		print(t_list *list);
char		**ft_create_btab(char *file);
char		**ft_fill_btab(char **btab, char *file);
t_list		*ft_list_insert_back(t_list *list);
t_list		*ft_create_elem(char **btab);
t_list		*ft_create_list(char **tab, t_list *list);

int			ft_count_hori(t_list *list);
int			ft_count_vert(t_list *list);
t_list		*ft_move(t_list *list);
t_list		*ft_move_vert(t_list *list, int x);
t_list		*ft_move_hori(t_list *list, int x);
t_list		*everything_is_done_in_here_WTF(char *tab);

char		**backtracking(char **tab, t_list *list, int sqrt);
char		**suppr_tetri(char **tab, char letter, int *value);
char		**add_tetri(char **tab, t_list *list, int letter, int *value);
int			can_be_put(char **tab, t_list *list, int *value);

#endif
