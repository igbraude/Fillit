/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:01:42 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 13:45:05 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s));
		if (str == NULL)
			return (0);
		while (s[i])
		{
			str[i] = f(i, s[i]);
			i++;
		}
		return (str);
	}
	return (0);
}
