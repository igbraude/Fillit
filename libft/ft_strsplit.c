/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_split.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 16:03:30 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/11 14:30:38 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		countword(char const *s, char c)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (s[j])
	{
		if ((j == 0 && s[j] != c) || (s[j] != c && s[j - 1] == c))
			i++;
		j++;
	}
	return (i);
}

static int		l(char const *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

static char		*init_tab(char const *s, char c, int i, char *tab)
{
	int j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		tab[j] = s[i];
		i++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		w;
	int		i;

	w = 0;
	i = 0;
	if (s)
	{
		if (!(tab = (char **)malloc(sizeof(char *) * (countword(s, c) + 1))))
			return (0);
		while (s[i])
		{
			if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			{
				if (!(tab[w] = (char *)malloc(sizeof(char) * (l(s, c, i) + 1))))
					return (0);
				tab[w] = init_tab(s, c, i, tab[w]);
				w++;
			}
			i++;
		}
		tab[w] = 0;
		return (tab);
	}
	return (0);
}
