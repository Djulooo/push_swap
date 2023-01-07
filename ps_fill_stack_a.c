/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fill_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:50:35 by jlaisne           #+#    #+#             */
/*   Updated: 2022/12/31 15:12:44 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(char **argv, int argc,	\
					t_list **stack, t_list **stack_c)
{
	t_list	*ptr;

	ptr = NULL;
	if (argc == 2)
		check_single_arg(argv, ptr, stack, stack_c);
	else if (argc > 2)
		check_mult_args(argv, argc, stack, stack_c);
}

void	check_mult_args(char **argv, int argc,	\
						t_list **stack, t_list **stack_c)
{
	int		i;
	long	arg;
	t_list	*cpy;
	t_list	*ptr;

	i = 1;
	ptr = NULL;
	while (i < argc)
	{
		arg = 0;
		ft_atoi(argv[i], &arg);
		ptr = ft_lstnew((int)arg);
		ft_lstadd_back(stack, ptr);
		ft_lstcheck(*stack, arg);
		cpy = ft_lstnew((int)arg);
		ft_lstadd_back(stack_c, cpy);
		i++;
	}
}

void	check_single_arg(char **argv, t_list *ptr, \
						t_list **stack, t_list **stack_c)
{
	long	arg;
	int		i;
	char	**tab;
	t_list	*cpy;

	arg = 0;
	i = 0;
	tab = ft_split(argv[1], ' ');
	while (tab[i])
	{
		arg = 0;
		ft_atoi(tab[i], &arg);
		free(tab[i]);
		ptr = ft_lstnew((int)arg);
		ft_lstadd_back(stack, ptr);
		ft_lstcheck(*stack, arg);
		cpy = ft_lstnew((int)arg);
		ft_lstadd_back(stack_c, cpy);
		i++;
	}
	free(tab);
}

void	display_error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(EXIT_FAILURE);
}
