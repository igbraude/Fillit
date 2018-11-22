/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list_push_params.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/17 15:52:04 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/17 16:06:09 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_create_elem(void *data)
{
	t_list *list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (0);
	list->content = data;
	list->next = NULL;
	return (list);
}

static void		ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *tmp;

	tmp = ft_create_elem(data);
	tmp->next = *begin_list;
	*begin_list = tmp;
}

t_list			*ft_list_push_params(int ac, char **av)
{
	t_list	*list;
	int		index;

	index = 0;
	list = 0;
	while (index < ac)
	{
		ft_list_push_front(&list, av[index]);
		index++;
	}
	return (list);
}
