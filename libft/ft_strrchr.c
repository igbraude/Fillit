/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:43:03 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 15:02:59 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while ((int)i >= 0)
	{
		if (c == s[i])
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
