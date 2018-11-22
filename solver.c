/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   solver.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aaudrain <aaudrain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/15 13:39:23 by aaudrain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 17:40:57 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Get the minimal length of a map side from the
**	sqrt of the total ammount of the char in each
**	tetriminos to begin the smallest map possible
*/

int		get_min_map(int n)
{
	int size;

	size = 2;
	while (size * size < (n * 4))
		size++;
	if (n < size * size)
		return (size - 1);
	return (size);
}

int		check_valid_pos(int size_sqr, char map[size_sqr][size_sqr],
		int tetri_num, t_tetriminos list[2][26])
{
	if (map[list[0][tetri_num].y[0] - 1][list[0][tetri_num].x[0] - 1] == '.' &&
			map[list[0][tetri_num].y[1] - 1]
			[list[0][tetri_num].x[1] - 1] == '.' &&
			map[list[0][tetri_num].y[2] - 1]
			[list[0][tetri_num].x[2] - 1] == '.' &&
			map[list[0][tetri_num].y[3] - 1]
			[list[0][tetri_num].x[3] - 1] == '.')
		return (1);
	return (0);
}

void	moove_coord_ord(int *tetri_num, t_tetriminos list[2][26], int size_sqr,
		char map[size_sqr][size_sqr])
{
	if (size_sqr >= list[0][*tetri_num].y[0]
			&& size_sqr >= list[0][*tetri_num].y[0] + 1 &&
			size_sqr >= list[0][*tetri_num].y[1]
			&& size_sqr >= list[0][*tetri_num].y[1] + 1 &&
			size_sqr >= list[0][*tetri_num].y[2]
			&& size_sqr >= list[0][*tetri_num].y[2] + 1 &&
			size_sqr >= list[0][*tetri_num].y[3]
			&& size_sqr >= list[0][*tetri_num].y[3] + 1)
	{
		init_abs(list, tetri_num[0]);
		list[0][*tetri_num].y[0]++;
		list[0][*tetri_num].y[1]++;
		list[0][*tetri_num].y[2]++;
		list[0][*tetri_num].y[3]++;
	}
	else
	{
		tetri_in_map(size_sqr, map, list, *tetri_num - 1);
		init_ord(list, tetri_num[0]);
		init_abs(list, tetri_num[0]);
		*tetri_num -= 1;
		moove_coord(tetri_num, list, size_sqr, map);
	}
}

void	moove_coord(int *tetri_num, t_tetriminos list[2][26], int size_sqr,
		char map[size_sqr][size_sqr])
{
	if (*tetri_num < 0)
	{
		backtrack(list, tetri_num[1], size_sqr + 1);
	}
	if (size_sqr >= list[0][*tetri_num].x[0] &&
			size_sqr >= list[0][*tetri_num].x[0] + 1 &&
			size_sqr >= list[0][*tetri_num].x[1]
			&& size_sqr >= list[0][*tetri_num].x[1] + 1 &&
			size_sqr >= list[0][*tetri_num].x[2]
			&& size_sqr >= list[0][*tetri_num].x[2] + 1 &&
			size_sqr >= list[0][*tetri_num].x[3]
			&& size_sqr >= list[0][*tetri_num].x[3] + 1)
	{
		list[0][*tetri_num].x[0]++;
		list[0][*tetri_num].x[1]++;
		list[0][*tetri_num].x[2]++;
		list[0][*tetri_num].x[3]++;
	}
	else
	{
		moove_coord_ord(tetri_num, list, size_sqr, map);
	}
}

void	backtrack(t_tetriminos list[2][26], int nb_tetri, int size_sqr)
{
	int		tetri_num[2];
	int		i;
	char	map[size_sqr][size_sqr];

	i = 0;
	tetri_num[0] = 0;
	tetri_num[1] = nb_tetri;
	point_in_map(size_sqr, map);
	while (tetri_num[0] < nb_tetri)
	{
		while (!(check_valid_pos(size_sqr, map, tetri_num[0], list)))
		{
			moove_coord(tetri_num, list, size_sqr, map);
		}
		put_char_map(size_sqr, map, list, tetri_num[0]);
		tetri_num[0]++;
	}
	print_map(size_sqr, map);
	exit(1);
}
