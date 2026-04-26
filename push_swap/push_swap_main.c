/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:27:38 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/09 08:00:15 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
curr and temp point to stack
curr is the reference position and temp is moved forward
count tracks the number of smaller values encountered in temp
function to print stack_a (place at line 88: ft_print_stack(*stack_a)
 */
#include "./srcs/libpush_swap.h"

static void	index_stack(t_list **stack)
{
	int		count;
	t_list	*curr;
	t_list	*temp;

	curr = *stack;
	while (curr)
	{
		temp = *stack;
		count = 0;
		while (temp)
		{
			if (curr->num > temp->num)
				count++;
			temp = temp->next;
		}
		curr->index = count;
		curr = curr->next;
	}
}

static void	init_stack(t_list **stack, int argc, char **argv)
{
	int		i;
	char	**tmp;

	i = 0;
	if (argc == 2)
		tmp = ft_split(argv[1], 32);
	else
	{
		i++;
		tmp = argv;
	}
	while (tmp[i])
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(tmp[i])));
		i++;
	}
	index_stack(stack);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (0);
	ft_chck_args(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		ft_error(MAL);
	init_stack(stack_a, argc, argv);
	if (ft_chck_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	if (ft_lstsize(*stack_a) < 6)
		short_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
