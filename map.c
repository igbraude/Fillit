/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aaudrain <aaudrain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/20 14:36:14 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 16:54:13 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	point_in_map(int size_sqr, char map[size_sqr][size_sqr])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size_sqr)
	{
		j = 0;
		while (j < size_sqr)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	print_map(int size_sqr, char map[size_sqr][size_sqr])
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < size_sqr)
	{
		j = 0;
		while (j < size_sqr)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	tetri_in_map(int size_sqr, char map[size_sqr][size_sqr],
		t_tetriminos list[2][26], int nb)
{
	int i;

	i = 0;
	if (nb == -1)
		return ;
	while (i < 4)
	{
		map[list[0][nb].y[i] - 1][list[0][nb].x[i] - 1] = '.';
		i++;
	}
}

void	put_char_map(int size_sqr, char map[size_sqr][size_sqr],
		t_tetriminos list[2][26], int nb)
{
	int i;

	i = 0;
	while (i < 4)
	{
		map[list[0][nb].y[i] - 1][list[0][nb].x[i] - 1] = list[0][nb].c;
		i++;
	}
}
