/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:21:07 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:48:36 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	char			*str;

	j = 0;
	i = 0;
	if (s)
	{
		str = ft_strnew(len);
		if (str == NULL)
			return (0);
		while (i < start)
		{
			i++;
		}
		while (s[i] && len-- > 0)
			str[j++] = s[i++];
		str[j] = '\0';
		return (str);
	}
	return (0);
}
