/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 17:58:45 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:32:15 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbreverse(int nbisnb, int nbreverse)
{
	nbreverse = (nbreverse * 10) + (nbisnb % 10);
	return (nbreverse);
}

static int		ft_valeurmin(int nb, int nbisnb)
{
	if (nb == 0)
	{
		ft_putchar('0');
	}
	if (nb < 0)
	{
		ft_putchar('-');
	}
	nb = nb / 10;
	nbisnb = nb;
	if (nbisnb < 0)
		nbisnb = -nbisnb;
	return (nbisnb);
}

void			ft_putnbr(int nb)
{
	int nbreverse;
	int nbisnb;
	int last;

	last = nb % 10;
	nbreverse = 1;
	nbisnb = 0;
	nbisnb = ft_valeurmin(nb, nbisnb);
	while (nbisnb > 0)
	{
		nbreverse = ft_nbreverse(nbisnb, nbreverse);
		nbisnb = nbisnb / 10;
	}
	while (nbreverse > 9)
	{
		ft_putchar((nbreverse % 10) + 48);
		nbreverse = nbreverse / 10;
	}
	if (last < 0)
		last = -last;
	if (nb != 0)
		ft_putchar(last + 48);
}
