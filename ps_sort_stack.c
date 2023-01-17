/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:41:08 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/17 23:36:48 by juleslaisne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_list **stack_a, t_list **stack_b, t_list **stack_c)
{
	int		len;

	len = ft_lstlen(*stack_a);
	if (len < 4)
		sort_three_a(stack_a, stack_c);
	else if (len <= 5)
		sort_five_a(stack_a, stack_b, stack_c, len);
	else
		sort_large_stack(stack_a, stack_b, stack_c, len);
}

void	sort_large_stack(t_list **stack_a, t_list **stack_b, \
							t_list **stack_c, int len)
{
	int	max_index_bits;
	int	i;
	int	most_sig_bit;

	max_index_bits = ft_lstlen(*stack_a) - 1;
	i = 1;
	most_sig_bit = -1;
	while ((max_index_bits >> 1) > 0)
	{
		max_index_bits >>= 1;
		i++;
	}
	while (most_sig_bit++ < i && iter_stack(stack_a, stack_c) != 1)
	{
		while (len > 0)
		{
			if (((get_index(stack_a, stack_c) >> most_sig_bit) & 1) == 1)
				push_stack_top(stack_b, stack_a, 'b');
			else
				rotate_stack_each(stack_a, 'a');
			len--;
		}
		clear_stack_b(stack_a, stack_b);
		len = ft_lstlen(*stack_a);
	}
}
