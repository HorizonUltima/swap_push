/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgergink <hgergink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:49:02 by hgergink          #+#    #+#             */
/*   Updated: 2025/10/29 14:37:03 by hgergink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# define MY_UINT_MAX 4294967295
# define MY_INT_MAX 2147483647
# define MY_INT_MIN -2147483648

typedef	struct s_list
{
	int			*num;
	unsigned int	rank;
	struct s_list	*next;
}	t_list;

int				ft_operror(void);
int				ft_skp_ws(const char *str, long int *k, long int *j, int *sign);
unsigned int	ft_count_ints(int argc, const char **argv);
int				ft_chk_ord(int ac, const char **av, int **lst, unsigned int *s);
void			*ft_clearlst(t_list **lst);
t_list			*ft_ranked(int *list, unsigned int size);
void	ft_slist(t_list **list);
void	ft_plist(t_list **first, t_list **second);
void	ft_rlist(t_list **list);
void	ft_rrlist(t_list **list);

#endif
