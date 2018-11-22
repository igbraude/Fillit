/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:55:49 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 14:49:02 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	size_t			i;

	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (src2 == dest2)
		return (dest);
	if (dest2 < src2)
	{
		while (i < len)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while ((int)--len >= 0)
		{
			dest2[len] = src2[len];
		}
	}
	return (dest);
}
