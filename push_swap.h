/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:49:02 by hgergink          #+#    #+#             */
/*   Updated: 2025/09/24 18:49:04 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define MY_UINT_MAX 4294967295
# define MY_INT_MAX 2147483647
# define MY_INT_MIN -2147483648

int				ft_operror(void);
int				ft_skp_ws(const char *str, long int *k, long int *j, int *sign);
unsigned int	ft_count_ints(int argc, const char **argv);
int				ft_check_order(int argc, const char **argv, int **list_ints);

#endif
