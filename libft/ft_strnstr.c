/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:54:16 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 14:10:55 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	int		m;

	j = 0;
	m = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j] != '\0' && j < len)
	{
		m = 0;
		while (haystack[j] == needle[m] && j < len)
		{
			m++;
			j++;
			if (needle[m] == '\0')
				return ((char *)haystack + j - m);
		}
		j -= m;
		j++;
	}
	return (NULL);
}
