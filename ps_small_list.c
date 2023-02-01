/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_small_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:57:56 by jlaisne           #+#    #+#             */
/*   Updated: 2023/02/01 10:58:03 by juleslaisne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	sort_three_a(t_list **stack_a, t_list **stack_c)
{
	t_list	*temp;

	while (iter_stack(stack_a, stack_c) != 1)
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

static void	rev_rot_five(t_list **stack_a, int min)
{
	if (min == (*stack_a)->content)
		return ;
	if (min == (*stack_a)->next->content)
		rotate_stack_each(stack_a, 'a');
	if (min == (*stack_a)->next->next->content)
	{
		rotate_stack_each(stack_a, 'a');
		rotate_stack_each(stack_a, 'a');
	}
	else
	{
		while ((*stack_a)->content != min)
			reverse_stack_each(stack_a, 'a');
	}
}

static void	stack_push_min(t_list **stack_a, t_list **stack_b, int min)
{
	if (ft_lstlen(*stack_a) == 4)
	{
		if (min == (*stack_a)->content || min == (*stack_a)->next->content)
		{
			while ((*stack_a)->content != min)
				rotate_stack_each(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->content != min)
				reverse_stack_each(stack_a, 'a');
		}
	}
	else
		rev_rot_five(stack_a, min);
	push_stack_top(stack_b, stack_a, 'b');
}

void	sort_five_a(t_list **stack_a, t_list **stack_b, \
					t_list **stack_c, int len)
{
	int	min;

	while (len > 3)
	{
		min = find_min(stack_a);
		stack_push_min(stack_a, stack_b, min);
		len = ft_lstlen(*stack_a);
	}	
	sort_three_a(stack_a, stack_c);
	clear_stack_b(stack_a, stack_b);
}
