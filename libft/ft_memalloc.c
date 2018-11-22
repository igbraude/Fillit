/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 15:27:42 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 14:39:54 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	s = (unsigned char *)malloc(sizeof(unsigned char) * (size));
	if (s == NULL)
		return (0);
	ft_bzero(s, size);
	return (s);
}
