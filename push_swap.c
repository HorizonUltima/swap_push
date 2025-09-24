/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:45:29 by hgergink          #+#    #+#             */
/*   Updated: 2025/09/24 17:45:33 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_operror(void)
{
	write(2, "Error!", 6);
	return (1);
}

int	main(int argc, const char **argv)
{
	int	*list_ints;
	int	i = 0;

	if (ft_check_order(argc - 1, argv, &list_ints))
		return (1);
	//blah blah, useful functions.
	while (i < 10)
		printf("%d\n", list_ints[i++]);
	write(1, "OK!", 3);
	free(list_ints);
	return (0);
}
