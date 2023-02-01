/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:26:36 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/31 12:05:16 by juleslaisne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
		push_swap(argv, argc);
	return (0);
}

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

void	free_list(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	free(lst);
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
	if (iter_stack(&stack_a, &stack_copy) == 1)
	{
		free_list(stack_a);
		free_list(stack_copy);
		exit(EXIT_SUCCESS);
	}
	else
	{
		sort_copy(&stack_copy);
		sort_stack(&stack_a, &stack_b, &stack_copy);
		free_list(stack_a);
		free_list(stack_copy);
		exit(EXIT_SUCCESS);
	}
}
