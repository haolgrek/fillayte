/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:20:49 by tandrieu          #+#    #+#             */
/*   Updated: 2016/01/07 17:14:11 by rluder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
# include <string.h>
# include <unistd.h>
# include <sys/types.h> /*WATCH OUT !! CHECK EVERY FILE FOR THOSE FUCKERS*/
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 600

typedef struct		s_list
{
	char			**array;
	int				index;
	struct s_list	*next;
}					t_list;

int					main(int argc, char **argv);
int					han_shot_first(char **argv);
char				*get_buff(int const fd);

int					check_block_hori(char *tab);
int					check_block_vert(char *tab);
int					check_tetriminos_nb(char *tab);
int					check_tetriminos_valid2(t_list *list,
						char *buf, int *value);
int					check_tetriminos_valid(t_list *list);

void				print(t_list *list);
char				**ft_create_btab(char *file);
char				**ft_fill_btab(char **btab, char *file, int *value);
t_list				*ft_list_insert_back(t_list *list, char *file);
t_list				*ft_create_elem(char *file);
t_list				*create_list(char *file);

int					ft_count_hori(t_list *list);
int					ft_count_vert(t_list *list);
t_list				*ft_move(t_list *list);
t_list				*ft_move_vert(t_list *list, int x);
t_list				*ft_move_hori(t_list *list, int x);

char				**backtracking(char **tab, t_list *list,
						int sqrt, char letter);
char				**suppr_tetri(char **tab, char letter, int *value);
char				**add_tetri(char **tab, t_list *list,
						int letter, int *value);
int					can_be_put(char **tab, t_list *list, int *value);

void				print_tab(char **tab, int sqrt);
char				**create_final_tab(int sqrt);
char				**solve(t_list *list, char *file);
#endif
