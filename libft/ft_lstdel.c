/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: igbraude <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 16:33:35 by igbraude     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/15 11:12:05 by igbraude    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	if (!*alst || !del)
		return ;
	while (*alst)
	{
		list = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = list;
	}
	*alst = NULL;
}
