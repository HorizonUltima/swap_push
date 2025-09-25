/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:49:10 by hgergink          #+#    #+#             */
/*   Updated: 2025/09/25 15:54:49 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_skip_space_l(const char *str, long int *k, long int *j)
{
	while (str[*k] == ' ' || (str[*k] >= 9 && str[*k] <= 13))
		(*k)++;
	if (!str[*k])
	{
		*k = 0;
		(*j) += 1;
	}
}

int	ft_atoi_l(const char *nptr, long int *j, long int *k)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	ft_skp_ws(nptr, k, j, &sign);
	while (nptr[*k] >= '0' && nptr[*k] <= '9')
		result = result * 10 + (nptr[(*k)++] - '0');
	ft_skip_space_l(nptr, k, j);
	return (result * sign);
}

int	ft_is_duplicate(int *list, int curr)
{
	int	i;

	i = 0;
	while (i < curr)
	{
		if (list[i++] == list[curr])
		{
			write(2, "Error!", 6);
			return (1);
		}
	}
	return (0);
}

int	ft_chk_ord(int ac, const char **av, int **lst, unsigned int *s)
{
	unsigned int	i;
	long int		j;
	long int		k;

	*s = ft_count_ints(ac, av);
	if (!*s || *s == 1)
		return (ft_operror());
	*lst = (int *)malloc((*s) * sizeof(int));
	if (!*lst)
		return (ft_operror());
	i = 0;
	j = 0;
	k = 0;
	while (i < *s)
	{
		(*lst)[i] = ft_atoi_l(av[j + 1], &j, &k);
		if (ft_is_duplicate(*lst, i))
		{
			free(*lst);
			return (1);
		}
		i++;
	}
	return (0);
}
