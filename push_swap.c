/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:26:36 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/05 13:27:54 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_copy(t_list **stack_c)
{
	t_list	*temp;
	int		holder;

	temp = *stack_c;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
		{
			holder = temp->content;
			temp->content = temp->next->content;
			temp->next->content = holder;
			temp = *stack_c;
		}
		else
			temp = temp->next;
	}
}

void	push_swap(char **argv, int argc)
{
	t_list	*stack_a;
	t_list	*stack_copy;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_copy = NULL;
	if (argc > 1)
		check_args(argv, argc, &stack_a, &stack_copy);
	if (iter_stack(&stack_a) == 1)
		exit(EXIT_SUCCESS);
	else
	{
		sort_copy(&stack_copy);
		sort_stack(&stack_a, &stack_b, &stack_copy);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argv, argc);
}
