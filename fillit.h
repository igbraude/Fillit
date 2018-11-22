/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aaudrain <aaudrain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/07 14:15:05 by aaudrain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 17:34:25 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <strings.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_tetriminos
{
	int				x[4];
	int				y[4];
	char			c;
}					t_tetriminos;

int					get_min_map(int n);
int					file_checker(int const fd);
int					parser(int fd, t_tetriminos tetri[2][26],
		int *tetrimino_nb);
int					ft_swap_list(t_tetriminos list[2][26],
		int nb_tetri, char num);
void				moove_coord(int *tetri_num, t_tetriminos list[2][26],
		int size_sqr,
		char map[size_sqr][size_sqr]);
void				print_map(int size_sqr, char map[size_sqr][size_sqr]);
void				stock_tetri_x(t_tetriminos tetri[2][26], int i,
		int size_sqr);
void				point_in_map(int size_sqr, char map[size_sqr][size_sqr]);
void				backtrack(t_tetriminos list[2][26], int nb_tetri,
		int size_sqr);
void				init_abs(t_tetriminos tetri[2][26], int i);
void				init_ord(t_tetriminos tetri[2][26], int i);
void				init_stock(t_tetriminos tetri[2][26], int tetrimino_nb);
void				stock_tetri_y(t_tetriminos tetri[2][26], int tetrimino_nb,
		int sousy);
void				put_char_map(int size_sqr, char map[size_sqr][size_sqr],
		t_tetriminos list[2][26], int nb);
void				tetri_in_map(int size_sqr, char map[size_sqr][size_sqr],
		t_tetriminos list[2][26], int nb);

#endif
