/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoll.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 15:07:45 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/08 15:43:24 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

long long	ft_atoll(const char *str)
{
	long long i;
	long long j;
	long long moins;

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
