/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:06:57 by fcatala-          #+#    #+#             */
/*   Updated: 2023/10/04 09:40:02 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * new_list => pointer to new generated list. Return value
 * curr => pointer to iterate new_list
 * void *new_content used to store the result of *f()
 * 		Not included in first versions of the function
 * 		Key to avoid memory leaks in malloc at paco -s
 * 		I was not able to eliminate leaks without this variable
 * 		although I passed ft_lstclear
 * new_list = NULL to intialize and to return in case of !lst
 * 
 * Fills the list in 3  steps:
 * 		1) Uses new_content to store the result of f(lst->content)
 * 		2) If nothing fails, creates curr as a new element filled with
 * 		   new_content
 * 		   		=> If curr fails:
 * 		   				FREES (NEW_CONTENT) !!!!!
 * 		   				clears the list and return NULL
 * 		3) If nothing fails, adds curr the the end of newlist
 * 				=> Since add_back takes a double pointer, it requires
 * 				to pass the address of new_list (&new_list)
 * Finally it advances the original list
 *
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*curr;
	void	*new_content;

	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
		{
			if (new_list)
				ft_lstclear(&new_list, del);
			return (NULL);
		}
		curr = ft_lstnew(new_content);
		if (!curr)
		{
			free(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, curr);
		lst = lst->next;
	}
	return (new_list);
}
