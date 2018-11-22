/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 15:40:16 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 15:40:40 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int j;
	int m;
	int k;

	j = 0;
	m = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[j] != '\0')
	{
		k = j;
		m = 0;
		while (haystack[j] == needle[m])
		{
			m++;
			j++;
			if (needle[m] == '\0')
				return ((char *)haystack + j - m);
		}
		j -= m;
		j++;
	}
	return (0);
}
