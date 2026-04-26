/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 10:47:15 by fcatala-          #+#    #+#             */
/*   Updated: 2023/06/27 15:25:36 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush_swap.h"

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*current;
	t_list	*temp;

	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	free(stack);
}

void	ft_print_stack(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_printf("num = %d\tindex = %d\n", tmp->num, tmp->index);
		tmp = tmp->next;
	}
}
