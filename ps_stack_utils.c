/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:22:45 by jlaisne           #+#    #+#             */
/*   Updated: 2022/12/31 14:00:32 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	iter_stack(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next != NULL)
	{
		if (temp->content > temp->next->content)
			break ;
		temp = temp->next;
	}
	if (temp->next == NULL)
		return (1);
	return (0);
}

int	find_min(t_list **stack_a)
{
	t_list	*temp;
	int		min;

	temp = *stack_a;
	min = temp->content;
	while (temp->next)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

int	get_index(t_list **stack_a, t_list **stack_c)
{
	t_list	*temp;
	t_list	*temp_a;
	int		i;

	temp = *stack_c;
	temp_a = *stack_a;
	i = 0;
	while (temp_a->content != temp->content)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	get_index_last(t_list **stack_a, t_list **stack_c)
{
	t_list	*temp;
	t_list	*temp_a;
	int		i;

	temp = *stack_c;
	temp_a = ft_lstlast(*stack_a);
	i = 0;
	while (temp_a->content != temp->content)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	clear_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	while (temp)
	{
		push_stack_top(stack_a, stack_b, 'a');
		temp = *stack_b;
	}
}
