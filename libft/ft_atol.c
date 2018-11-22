/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atol.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:40:55 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 14:41:32 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	long i;
	long j;
	long moins;

	i = 0;
	j = 0;
	moins = 1;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 32 ||
			str[i] == 12 || str[i] == 13)
	{
		i++;
	}
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			moins = -moins;
		i++;
	}
	while (str[i] <= 57 && str[i] >= 48)
	{
		j = j * 10;
		j += str[i] - 48;
		i++;
	}
	return (j * moins);
}
