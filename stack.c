/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbearded <sbearded@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:52:26 by sbearded          #+#    #+#             */
/*   Updated: 2019/03/13 23:51:44 by sbearded         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelcontent(void *c, size_t c_size)
{
	if (c != NULL)
	{
		free(c);
		(void)c_size;
	}
}

void	stack_push(t_list **stack, t_list *lst)
{
	t_list			**new;
	static t_list	*end;

	if (stack && *stack)
	{
		end->next = lst;
		end = end->next;
	}
	else
	{
		new = (t_list**)malloc(sizeof(t_list*));
		*new = lst;
		end = lst;
	}
}

t_list	*stack_pop(t_list **stack)
{
	t_list	*lst;

	lst = *stack;
	*stack = lst->next;
	return (lst);
}
