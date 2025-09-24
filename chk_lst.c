/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:49:10 by hgergink          #+#    #+#             */
/*   Updated: 2025/09/24 18:49:11 by hgergink         ###   ########.fr       */
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

int	ft_check_order(int argc, const char **argv, int **list_ints)
{
	unsigned int	i;
	long int		j;
	long int		k;
	unsigned int	size;

	size = ft_count_ints(argc, argv);
	if (!size || size == 1)
		return (ft_operror());
	*list_ints = (int *)malloc(size * sizeof(int));
	if (!*list_ints)
		return (ft_operror());
	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		(*list_ints)[i] = ft_atoi_l(argv[j + 1], &j, &k);
		if (ft_is_duplicate(*list_ints, i))
		{
			free(*list_ints);
			return (1);
		}
		i++;
	}
	return (0);
}
