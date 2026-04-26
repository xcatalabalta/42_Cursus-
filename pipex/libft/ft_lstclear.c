/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:47:15 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/04 09:36:39 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * *tmp to be able to set *lst to NULL
 * *swp to preserve iteration in the list
 *  int size to fix iterations until the end of the list
 *  memory leaks when swp was not used
 *  Use of ft_lstdelone saves one line
 *
 *  To improve:
 *  1) I could use *lst where tmp and tmp where swp, but...
 *  2) I have seen one example with recursivity, but I do not understand it
 *     and I am not able to reproduce it blindly.
 */

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*swp;
	int		size;

	tmp = *lst;
	if (tmp)
	{
		size = ft_lstsize(tmp);
		while (size-- > 0)
		{
			swp = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = swp;
		}
	}
	*lst = NULL;
}
