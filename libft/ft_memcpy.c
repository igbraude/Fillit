/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 12:55:35 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 14:50:35 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst2;
	unsigned char *src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	while (n > 0)
	{
		*dst2 = *src2;
		dst2++;
		src2++;
		n--;
	}
	return (dst);
}
