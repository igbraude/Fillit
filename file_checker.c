/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   file_checker.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aaudrain <aaudrain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 15:43:02 by aaudrain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 16:53:00 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
**  If the element at the index is a #, check around
**  how many # there is and stock this amount in the
**  var in_read and stock the number of # in buf. If
**  the number of connections if different of 6 or 8
**  that means it is not a valide shape :
**
**      1 2 2 1
**      . . . .
**      . 2 2 .
**      . 2 2 .
**
**  output : 1  ->  tetri correct,  0 if not.
*/

static	int		check_block(char buf[22], int x)
{
	int		in_read;
	int		block;

	in_read = 0;
	block = 0;
	while (buf[x])
	{
		if (buf[x] == '#')
		{
			if ((x + 1) < 20 && buf[x + 1] == '#')
				in_read++;
			if ((x - 1) >= 0 && buf[x - 1] == '#')
				in_read++;
			if ((x + 5) < 20 && buf[x + 5] == '#')
				in_read++;
			if ((x - 5) >= 0 && buf[x - 5] == '#')
				in_read++;
			block++;
		}
		x++;
	}
	if (!(block == 4 && (in_read == 6 || in_read == 8)))
		return (0);
	return (1);
}

/*
**  Check if the str is filled only with correct char
**  '.', '#' or '\n'.
**
**  output : 1  ->  char correct,   0 if not.
*/

static	int		check_tetri(char stock_buff[22], int x)
{
	while (stock_buff[x])
	{
		if (x % 5 == 4 && stock_buff[x] != '\n')
		{
			return (0);
		}
		if (x % 5 < 4 && (stock_buff[x] != '.' && stock_buff[x] != '#'))
		{
			return (0);
		}
		x++;
	}
	return (1);
}

/*
**  Check if each tetriminos bodies is separated by
**  a '\n'.
**
**  output : 1  if correct, 0 if not.
*/

static	int		check_new_line(char stock_buff[22], int x)
{
	if (x == 0 && stock_buff[x] != '\n')
		return (0);
	x++;
	if (!(check_tetri(stock_buff + 1, x)))
		return (0);
	return (1);
}

/*
**  Scan the file with a buffer of a tetrimino's size
**  and apply those previous check and invalidate the
**  map if at least one of those isn't right.
**
**  output : 1  if the map is good, 0 if map_error.
*/

int				file_checker(int const fd)
{
	char	stock_buff[22];
	int		ret;
	int		x;
	int		buff_size;

	buff_size = 20;
	while ((ret = read(fd, stock_buff, buff_size)) > 0)
	{
		if (ret != buff_size)
			return (0);
		stock_buff[ret] = '\0';
		x = 0;
		if (buff_size == 20)
			if (!(check_tetri(stock_buff, x)))
				return (0);
		if (buff_size == 21)
			if (!(check_new_line(stock_buff, x)))
				return (0);
		buff_size = 21;
		if (!(check_block(stock_buff, x)))
			return (0);
	}
	if (buff_size == 20)
		return (0);
	return (1);
}
