/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parser.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aaudrain <aaudrain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 15:44:37 by aaudrain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 17:39:49 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Move the piece to the origin of the X axis.
*/

void		stock_tetri_x(t_tetriminos tetri[2][26], int i, int size_sqr)
{
	int j;
	int sousx;

	sousx = size_sqr;
	j = 0;
	while (j < 4)
	{
		if ((tetri[0][i].x[j] - sousx) < 1)
		{
			j = 0;
			sousx--;
			continue ;
		}
		j++;
	}
	tetri[0][i].x[0] -= sousx;
	tetri[0][i].x[1] -= sousx;
	tetri[0][i].x[2] -= sousx;
	tetri[0][i].x[3] -= sousx;
}

/*
**	Move the piece to the origin of the Y axis.
*/

void		stock_tetri_y(t_tetriminos tetri[2][26], int tetrimino_nb,
		int size_sqr)
{
	int j;
	int sousy;
	int i;

	i = 0;
	while (i < tetrimino_nb)
	{
		j = 1;
		sousy = 0;
		while (j < 4)
		{
			while (tetri[0][i].y[0] != 1)
			{
				sousy = tetri[0][i].y[0] - 1;
				tetri[0][i].y[0] = 1;
			}
			tetri[0][i].y[j] -= sousy;
			j++;
		}
		tetri[0][i].c = 65 + i;
		stock_tetri_x(tetri, i, size_sqr);
		i++;
	}
}

/*
**	Move the coords of a piece to the origin
**	and put it in a structure.
*/

int			parser(int fd, t_tetriminos tetri[2][26], int *tetrimino_nb)
{
	char	buff[22];
	int		ret;
	int		i;
	int		coord;

	*tetrimino_nb = 0;
	while ((ret = read(fd, buff, 21)) > 0)
	{
		if (*tetrimino_nb > 26)
			return (0);
		buff[ret] = '\0';
		coord = 0;
		i = -1;
		while (buff[++i] != '\0')
			if (buff[i] == '#')
			{
				tetri[0][*tetrimino_nb].x[coord] = i % 5 + 1;
				tetri[0][*tetrimino_nb].y[coord] = i / 5 + 1;
				coord++;
			}
		*tetrimino_nb += 1;
	}
	stock_tetri_y(tetri, *tetrimino_nb, 4);
	return (*tetrimino_nb);
}
