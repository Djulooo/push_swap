/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:58:16 by jlaisne           #+#    #+#             */
/*   Updated: 2023/01/24 11:16:47 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	struct s_list	*before;
	struct s_list	*next;
}	t_list;

/* ---- split - utils ---- */
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* ---- utils ---- */
void	ft_putstr_fd(char *s, int fd);
void	ft_atoi(const char *s, long *arg, t_list *lst, t_list *lst_c);

/* ---- list utils ---- */
void	free_list(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content, t_list *lst, t_list *lst_c);
void	ft_lstcheck(t_list *lst, t_list *lst_c, int arg);
int		ft_lstlen(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

/* ---- check error && fill stack A ---- */
void	display_error(t_list *stack, t_list *stack_c);
void	check_args(char **argv, int argc, t_list **stack, t_list **stack_c);
void	check_mult_args(char **argv, int argc, \
						t_list **stack, t_list **stack_c);
void	check_single_arg(char **argv, t_list *ptr, \
						t_list **stack, t_list **stack_c);

/* ---- push swap operators ---- */
void	swap_top_stack(t_list *stack, char c);
void	swap_both_stack(t_list *stack_a, t_list *stack_b);
void	push_stack_top(t_list **stack_a, t_list **stack_b, char c);
void	rotate_stack_each(t_list **stack, char c);
void	rotate_stack_both(t_list **stack_a, t_list **stack_b);
void	reverse_stack_each(t_list **stack, char c);
void	reverse_stack_both(t_list **stack_a, t_list **stack_b);

/* ---- push swap ---- */
void	push_swap(char **argv, int argc);
int		iter_stack_a(t_list **stack_a, t_list **stack_b);
int		iter_stack(t_list **stack, t_list **stack_c);
void	sort_stack(t_list **stack_a, t_list **stack_b, t_list **stack_c);
void	clear_stack_b(t_list **stack_a, t_list **stack_b);
void	sort_copy(t_list **stack_c);

int		get_index(t_list **stack_a, t_list **stack_c);
int		get_index_last(t_list **stack_a, t_list **stack_c);
int		find_min(t_list **stack_a);

/* ---- push swap small list---- */
void	sort_three_a(t_list **stack_a, t_list **stack_c);
void	sort_five_a(t_list **stack_a, t_list **stack_b, \
					t_list **stack_c, int len);
void	stack_push_min(t_list **stack_a, t_list **stack_b, \
					t_list **stack_c, int min);
void	sort_large_stack(t_list **stack_a, t_list **stack_b, \
						t_list **stack_c, int len);

#endif