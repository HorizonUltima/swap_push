/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 14:27:22 by hgergink          #+#    #+#             */
/*   Updated: 2025/10/29 15:20:13 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_slist(t_list **list)
{
	t_list	*temp;
	t_list	*other;

	temp = *list;
	other = (*list)->next;
	temp->next = other->next;
	other->next = temp;
	*list = other;
}

void	ft_plist(t_list **first, t_list **second)
{
	t_list	*tmp;

	tmp = *second;
	*second = (*second)->next;
	tmp->next = *first;
	*first = tmp;
}

void	ft_rlist(t_list **list)
{
	t_list	*head;
	t_list	*tail;

	head = *list;
	*list = (*list)->next;
	tail = *list;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->next = (void *)0;
}

void	ft_rrlist(t_list **list)
{
	t_list	*prev;
	t_list	*last;

	prev = (void *)0;
	last = *list;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (!prev)
		return ;
	prev->next = (void *)0;
	last->next = *list;
	*list = last;
}
