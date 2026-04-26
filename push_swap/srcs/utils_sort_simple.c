/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_simple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:03:32 by fcatala-          #+#    #+#             */
/*   Updated: 2023/09/14 12:32:33 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

static void	sort_3(t_list **stack_a)
{
	int		min[2];
	t_list	*head;

	head = *stack_a;
	min[0] = get_min(stack_a, -1);
	min[1] = get_min(stack_a, min[0]);
	if (ft_chck_sorted(stack_a))
		return ;
	if (head->index == min[0] && head->next->index != min[1])
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == min[1] && head->next->index == min[0])
		sa(stack_a);
	else if (head->index == min[1] && head->next->index != min[0])
		rra(stack_a);
	else if (head->index != min[1] && head->next->index == min[0])
		ra(stack_a);
	else
	{
		ra(stack_a);
		sa(stack_a);
	}
}

static void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	dist = get_dist(stack_a, get_min(stack_a, -1));
	if (ft_chck_sorted(stack_a))
		return ;
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
		rra(stack_a);
	if (ft_chck_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_b, stack_a);
}

static void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	dist;

	dist = get_dist(stack_a, get_min(stack_a, -1));
	if (dist == 1)
		ra(stack_a);
	else if (dist == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (dist == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (dist == 4)
		rra(stack_a);
	if (ft_chck_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	short_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else
		sort_5(stack_a, stack_b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head = *stack_a;
	size = ft_lstsize(head);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_b, stack_a);
		i++;
	}
}
