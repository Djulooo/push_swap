/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juleslaisne <juleslaisne@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:49:08 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/17 23:29:06 by juleslaisne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content, t_list *lst, t_list *lst_c)
{
	t_list	*ptr;

	ptr = (void *)malloc(sizeof(t_list));
	if (!ptr)
		display_error(lst, lst_c);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstcheck(t_list *lst, t_list *lst_c, int arg)
{
	if (lst == NULL)
		return ;
	else
	{
		while (lst->next != NULL)
		{
			if (lst->content == arg && lst->next != NULL)
				display_error(lst, lst_c);
			lst = lst->next;
		}
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

int	ft_lstlen(t_list *lst)
{
	int	x;

	x = 0;
	if (lst == NULL)
		return (x);
	else
	{
		x++;
		while (lst->next != NULL)
		{
			lst = lst->next;
			x++;
		}
	}
	return (x);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}
