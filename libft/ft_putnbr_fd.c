/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:15:56 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:32:40 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbreverse_fd(int nbisnb, int nbreverse)
{
	nbreverse = (nbreverse * 10) + (nbisnb % 10);
	return (nbreverse);
}

static int		ft_valeurmin_fd(int nb, int nbisnb, int fd)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
	}
	nb = nb / 10;
	nbisnb = nb;
	if (nbisnb < 0)
		nbisnb = -nbisnb;
	return (nbisnb);
}

void			ft_putnbr_fd(int nb, int fd)
{
	int nbreverse;
	int nbisnb;
	int last;

	last = nb % 10;
	nbreverse = 1;
	nbisnb = 0;
	nbisnb = ft_valeurmin_fd(nb, nbisnb, fd);
	while (nbisnb > 0)
	{
		nbreverse = ft_nbreverse_fd(nbisnb, nbreverse);
		nbisnb = nbisnb / 10;
	}
	while (nbreverse > 9)
	{
		ft_putchar_fd((nbreverse % 10) + 48, fd);
		nbreverse = nbreverse / 10;
	}
	if (last < 0)
		last = -last;
	if (nb != 0)
		ft_putchar_fd(last + 48, fd);
}
