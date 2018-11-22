/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   struct_init.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 14:06:31 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 17:40:18 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	init_stock(t_tetriminos tetri[2][26], int tetrimino_nb)
{
	int i;

	i = 0;
	while (i < tetrimino_nb)
	{
		tetri[1][i].x[0] = tetri[0][i].x[0];
		tetri[1][i].x[1] = tetri[0][i].x[1];
		tetri[1][i].x[2] = tetri[0][i].x[2];
		tetri[1][i].x[3] = tetri[0][i].x[3];
		tetri[1][i].y[0] = tetri[0][i].y[0];
		tetri[1][i].y[1] = tetri[0][i].y[1];
		tetri[1][i].y[2] = tetri[0][i].y[2];
		tetri[1][i].y[3] = tetri[0][i].y[3];
		tetri[1][i].c = tetri[0][i].c;
		i++;
	}
}

void	init_abs(t_tetriminos tetri[2][26], int i)
{
	tetri[0][i].x[0] = tetri[1][i].x[0];
	tetri[0][i].x[1] = tetri[1][i].x[1];
	tetri[0][i].x[2] = tetri[1][i].x[2];
	tetri[0][i].x[3] = tetri[1][i].x[3];
}

void	init_ord(t_tetriminos tetri[2][26], int i)
{
	tetri[0][i].y[0] = tetri[1][i].y[0];
	tetri[0][i].y[1] = tetri[1][i].y[1];
	tetri[0][i].y[2] = tetri[1][i].y[2];
	tetri[0][i].y[3] = tetri[1][i].y[3];
}
