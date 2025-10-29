/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:45:29 by hgergink          #+#    #+#             */
/*   Updated: 2025/10/29 17:17:43 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_operror(void)
{
	write(2, "Error!", 6);
	return (1);
}

void	sort_lesser(t_list **a, t_list **b, unsigned int size)
{
	if ((*a)->rank > (*a)->next->rank && (*a)->rank > (*a)->next->next->rank)
	{
		ft_rlist(a);
		write(1, "ra\n", 3);
	}
	else if ((*a)->next->rank > (*a)->next->next->rank)
	{
		ft_rrlist(a);
		write(1, "rra\n", 4);
	}
	if ((*a)->rank > (*a)->next->rank)
	{
		ft_slist(a);
		wrtie(1, "sa\n",3);
	}
}

void	ft_push_swap(t_list **a, unsigned int size)
{
	t_list	*b;

	b = (void *)0;
	if (size == 2)
	{
		ft_slist(a);
		write(1, "sa\n", 3);
	}
	else if (size <= 3)
		sort_lesser(a, &b, size);
	/*else if (size <= 20)
		sort_s_chunks(a, &b, size);
	else if (size <= 100)
		sort_m_chunks(a, &b, size);
	else if (size <= 500)
		sort_l_chunks(a, &b, size);
	else
		radix_sort(a, &b, size);*/
	ft_clearlst(&b);
}

int	is_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (list->rank > list->next->rank)
			return (0);
		list = list->next;
	}
	return (1);
}

int	main(int argc, const char **argv)
{
	int				*list_ints;
	unsigned int	size;
	t_list	*acol;

	if (ft_chk_ord(argc - 1, argv, &list_ints, &size))
		return (1);
	acol = ft_ranked(list_ints, size);
	if (!acol)
		return (1);
	if (is_sorted(acol))
	{
		ft_clearlst(&acol);
		free(list_ints);
		return (0);
	}
	//blah blah, useful functions.
	ft_push_swap(&acol, size);
	write(1, "OK!", 3);
	ft_clearlst(&acol);
	free(list_ints);
	return (0);
}
