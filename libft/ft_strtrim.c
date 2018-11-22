/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 13:47:45 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:19:44 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nospace(char const *s, size_t i)
{
	char *str;

	if (!(str = ft_strnew(i)))
		return (0);
	return (ft_strcpy(str, s));
}

static char		*ft_withspace(size_t i, size_t j, char const *s)
{
	char *str;

	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	if (i == 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	return (ft_strsub(s, j, i - j));
}

char			*ft_strtrim(char const *s)
{
	char			*str;
	size_t			i;
	size_t			j;

	if (s)
	{
		j = 0;
		if (!ft_strlen(s))
		{
			str = (char *)malloc(sizeof(char) * 1);
			str[0] = '\0';
			return (str);
		}
		i = ft_strlen(s);
		if (s[j] != ' ' && s[j] != '\n' && s[j] != '\t' && s[i - 1] != ' ' &&
				s[i - 1] != '\n' && s[i - 1] != '\t' && s[j] != '\0')
			return (ft_nospace(s, i));
		return (ft_withspace(i, j, s));
	}
	return (0);
}
