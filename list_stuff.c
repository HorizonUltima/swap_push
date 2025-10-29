/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:41:56 by hgergink          #+#    #+#             */
/*   Updated: 2025/10/21 20:16:35 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_newlst(int *list, unsigned int curr, unsigned int size)
{
	t_list	*newlst;
	unsigned int	i;
	unsigned int	rnk;

	i = 0;
	rnk = 0;
	newlst = (t_list *)malloc(sizeof(t_list));
	if (!newlst)
		return ((void *)0);
	newlst->num = list + curr;
	while (i < size)
	{
		if (list[curr] > list[i])
			rnk++;
		i++;
	}
	newlst->rank = rnk;
	newlst->next = (void *)0;
	return (newlst);
}

int	ft_addback(t_list *lst, t_list *new)
{
	if (!lst || !new)
		return (1);
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	return (0);
}

void	*ft_clearlst(t_list **lst)
{
	t_list *broom;
	if (!*lst)
		return ((void *)0);
	while (*lst)
	{
		broom = *lst;
		*lst = (*lst)->next;
		free(broom);
	}
	return ((void *)0);
}

t_list	*ft_ranked(int *list, unsigned int size)
{
	unsigned int	i;
	t_list	*lststrt;

	i = 0;
	lststrt = ft_newlst(list, i++, size);
	while (i < size)
	{
		if (ft_addback(lststrt, ft_newlst(list, i, size)))
			return (ft_clearlst(&lststrt));
		i++;
	}
	return (lststrt);
}
