/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/07 16:38:45 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:44:52 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len;
	size_t lensrc;

	len = ft_strlen(dst);
	lensrc = 0;
	if (size > len)
	{
		ft_strncat(dst, src, (size - len - 1));
	}
	while (*src)
	{
		lensrc++;
		src++;
	}
	if (size < len)
		return (lensrc + size);
	return (len + lensrc);
}
