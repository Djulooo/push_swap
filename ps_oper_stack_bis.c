/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oper_stack_bis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:44:42 by jlaisne           #+#    #+#             */
/*   Updated: 2022/12/31 13:59:49 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_stack_each(t_list **stack, char c)
{
	t_list	*temp;
	t_list	*temp_l;
	t_list	*temp_b;

	temp = *stack;
	temp_l = temp;
	temp_b = temp;
	while (temp_l->next)
	{
		temp_b = temp_l;
		temp_l = temp_l->next;
	}
	temp_l->next = temp;
	temp_b->next = NULL;
	*stack = temp_l;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	reverse_stack_both(t_list **stack_a, t_list **stack_b)
{
	reverse_stack_each(stack_a, 's');
	reverse_stack_each(stack_b, 's');
	ft_putstr_fd("rrr\n", 1);
}
