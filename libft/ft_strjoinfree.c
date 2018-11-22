/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoinfree.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/11 14:33:55 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/12 15:32:36 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	tmp = (char *)s1;
	tmp2 = (char *)s2;
	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	ft_strdel(&tmp);
	ft_strdel(&tmp2);
	return (str);
}
