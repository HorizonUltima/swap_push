/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:45:29 by hgergink          #+#    #+#             */
/*   Updated: 2025/09/25 15:53:23 by hgergink         ###   ########.fr       */
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
	int				*list_ints;
	unsigned int	size;

	if (ft_chk_ord(argc - 1, argv, &list_ints, &size))
		return (1);
	//blah blah, useful functions.
	write(1, "OK!", 3);
	free(list_ints);
	return (0);
}
