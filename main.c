/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aaudrain <aaudrain@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/12 23:35:11 by aaudrain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 17:34:56 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int				fd;
	int				size;
	int				tetriminos_nb;
	t_tetriminos	tetri[2][26];

	if (ac != 2)
	{
		write(1, "usage: fillit input_file\n", 25);
		return (0);
	}
	while (file_checker(fd = open(av[1], O_RDONLY)))
	{
		close(fd);
		if (!(parser(fd = open(av[1], O_RDONLY), tetri, &tetriminos_nb)))
			break ;
		close(fd);
		init_stock(tetri, tetriminos_nb);
		size = get_min_map(tetriminos_nb);
		backtrack(tetri, tetriminos_nb, size);
	}
	write(1, "error\n", 6);
	return (0);
}
