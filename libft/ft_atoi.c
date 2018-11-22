/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 16:41:33 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 16:10:50 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int moins;

	i = 0;
	j = 0;
	moins = 1;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 32 ||
			str[i] == 12 || str[i] == 13)
		i++;
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
