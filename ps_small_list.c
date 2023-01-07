/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:57:56 by jlaisne           #+#    #+#             */
/*   Updated: 2022/12/31 15:07:59 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_list **stack_a)
{
	t_list	*temp;

	while (iter_stack(stack_a) != 1)
	{
		temp = *stack_a;
		temp->before = ft_lstlast(*stack_a);
		if (temp->before->content < temp->content)
			reverse_stack_each(stack_a, 'a');
		else
		{
			reverse_stack_each(stack_a, 'a');
			swap_top_stack(*stack_a, 'a');
		}
	}
}

void	sort_five_a(t_list **stack_a, t_list **stack_b, \
					t_list **stack_c, int len)
{
	int	min;

	while (len > 3)
	{
		min = find_min(stack_a);
		stack_push_min(stack_a, stack_b, stack_c, min);
		len = ft_lstlen(*stack_a);
	}	
	sort_three_a(stack_a);
	swap_top_stack(*stack_b, 'b');
	clear_stack_b(stack_a, stack_b);
}

void	stack_push_min(t_list **stack_a, t_list **stack_b, \
						t_list **stack_c, int min)
{
	t_list	*temp;

	temp = *stack_c;
	if (ft_lstlen(*stack_a) == 4)
	{
		if (min == (*stack_a)->content || min == (*stack_a)->next->content)
		{
			while ((*stack_a)->content != ft_lstlast(*stack_c)->content)
				rotate_stack_each(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->content != ft_lstlast(*stack_c)->content)
				reverse_stack_each(stack_a, 'a');
		}
	}
	else
	{
		while (temp->next->next)
			temp = temp->next;
		while ((*stack_a)->content != temp->content)
			rotate_stack_each(stack_a, 'a');
	}
	push_stack_top(stack_b, stack_a, 'b');
}
