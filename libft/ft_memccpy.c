/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 14:18:02 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 12:04:05 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src;
		if (*(unsigned char *)src++ == (unsigned char)c)
			return (dst);
		n--;
	}
	return (NULL);
}
