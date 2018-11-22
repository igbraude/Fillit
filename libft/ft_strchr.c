/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:18:28 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 15:21:40 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	if (*s == '\0')
		return (0);
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s && *s != c)
	{
		s++;
		if (*s == '\0')
			return (NULL);
	}
	return ((char *)s);
}
