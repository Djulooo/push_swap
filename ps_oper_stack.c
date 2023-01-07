/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oper_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:12:24 by jlaisne           #+#    #+#             */
/*   Updated: 2022/12/31 13:59:27 by jlaisne          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_stack(t_list *stack, char c)
{
	int	temp;

	if (stack->next != NULL)
	{
		temp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = temp;
	}
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	swap_both_stack(t_list *stack_a, t_list *stack_b)
{
	swap_top_stack(stack_a, 's');
	swap_top_stack(stack_b, 's');
	ft_putstr_fd("ss\n", 1);
}

void	push_stack_top(t_list **stack_a, t_list **stack_b, char c)
{
	t_list	*temp;
	t_list	*temp_a;
	t_list	*temp_b;

	if (stack_b == NULL)
		return ;
	temp_b = NULL;
	temp = *stack_b;
	if (temp->next)
		temp_b = temp->next;
	*stack_b = temp_b;
	temp_a = *stack_a;
	*stack_a = temp;
	temp->next = temp_a;
	if (c == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	rotate_stack_each(t_list **stack, char c)
{
	t_list	*temp;
	t_list	*temp_l;
	t_list	*temp_s;

	temp = *stack;
	temp_s = temp->next;
	temp_l = temp;
	while (temp_l->next)
		temp_l = temp_l->next;
	temp_l->next = temp;
	temp->next = NULL;
	*stack = temp_s;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rotate_stack_both(t_list **stack_a, t_list **stack_b)
{
	rotate_stack_each(stack_a, 's');
	rotate_stack_each(stack_b, 's');
	ft_putstr_fd("rr\n", 1);
}
