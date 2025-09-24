/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:49:33 by hgergink          #+#    #+#             */
/*   Updated: 2025/09/24 19:28:09 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	skip_help(const char *s, long int *i, long int *k, long int *j)
{
	while (s[*k + *i] == ' ' || (s[*k + *i] >= 9 && s[*k + *i] <= 13))
		(*i)++;
	if (!s[*k + *i])
	{
		if (*k == 0)
		{
			*k = -1;
			*j = -1;
		}
		return (1);
	}
	return (0);
}

int	ft_skp_ws(const char *str, long int *k, long int *j, int *sign)
{
	long int	i;

	i = 0;
	if (skip_help(str, &i, k, j))
	{
		if (*k == -1)
			return (1);
		return (0);
	}
	if (str[*k + i] == '-' || str[*k + i] == '+')
	{
		if (str[*k + i] == '-')
			*sign -= 2;
		i++;
	}
	if (!(str[*k + i] >= '0' && str[*k + i] <= '9'))
	{
		*k = -1;
		*j = -1;
		return (1);
	}
	*k += i;
	return (0);
}

int	ft_atoi_c(const char *str, long int *k, long int *j)
{
	int			sign;
	long int	result;

	sign = 1;
	result = 0;
	if (ft_skp_ws(str, k, j, &sign))
		return (0);
	while (str[*k] >= '0' && str[*k] <= '9')
	{
		result = result * 10 + (str[(*k)++] - '0');
		if (((long)sign == 1 && result > (long int)MY_INT_MAX)
			|| ((long)sign == -1 && - result < (long int)MY_INT_MIN))
		{
			*k = -1;
			*j = -1;
			return (0);
		}
	}
	*j = *k;
	if (ft_skp_ws(str, k, j, &sign))
		return (0);
	return (1);
}

unsigned int	ft_count_ints(int argc, const char **argv)
{
	int				i;
	long int		j;
	long int		k;
	unsigned int	l;

	i = 0;
	l = 0;
	while (i < argc)
	{
		j = 0;
		k = 0;
		while (ft_atoi_c(argv[i + 1], &k, &j))
		{
			l++;
			if (k == j)
				break ;
			j = k;
		}
		if (j == -1)
			return (0);
		i++;
	}
	return (l);
}
