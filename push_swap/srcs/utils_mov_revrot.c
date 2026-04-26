/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mov_revrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:31:56 by fcatala-          #+#    #+#             */
/*   Updated: 2023/06/26 17:53:41 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * Shift down all elements of a stack (a or b) or both by 1
*/
#include "libpush_swap.h"

static t_list	*ft_lstpenul(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

int	rev_rot(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*penul;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	penul = ft_lstpenul(head);
	ft_lstadd_front(stack, tail);
	penul->next = NULL;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (rev_rot(stack_a) == -1)
		return (-1);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (rev_rot(stack_b) == -1)
		return (-1);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rev_rot(stack_a);
	rev_rot(stack_b);
	write(1, "rrr\n", 4);
	return (0);
}
