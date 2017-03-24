/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykondrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:15:21 by ykondrat          #+#    #+#             */
/*   Updated: 2017/02/10 14:56:22 by ykondrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*buf;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	buf = f(lst);
	new_lst = ft_lstnew(buf->content, buf->content_size);
	if (new_lst)
	{
		tmp = new_lst;
		lst = lst->next;
		while (lst)
		{
			buf = f(lst);
			tmp->next = ft_lstnew(buf->content, buf->content_size);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new_lst);
}
