/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:10:20 by fcatala-          #+#    #+#             */
/*   Updated: 2023/06/27 20:16:43 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_SWAP_H
# define LIBPUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define ERR "Error\n"
# define MAL "Error: unable to allocate memory\n"
# define SWP "Error: unable to swap\n"

typedef struct s_list
{
	int				num;
	int				index;
	struct s_list	*next;
}				t_list;

void	ft_error(char *msg);
void	ft_free_stack(t_list **stack);
void	ft_print_stack(t_list *head);
void	ft_chck_args(int argc, char **argv);
int		ft_chck_sorted(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_b, t_list **stack_a);
int		pb(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
int		get_dist(t_list **stack, int index);
int		get_min(t_list **stack, int val);
int		get_max_bits(t_list **stack);
void	short_sort(t_list **stack_a, t_list **stack_b);
void	radix_sort(t_list **stack_a, t_list **stack_b);
t_list	*ft_lstnew(int num);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *head);
void	ft_lstadd_back(t_list **lst, t_list *new);
#endif
