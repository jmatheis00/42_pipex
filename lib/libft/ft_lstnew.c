/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliama <juliama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:01:53 by jmatheis          #+#    #+#             */
/*   Updated: 2022/04/20 13:45:49 by juliama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	return (temp);
}

//content = content to create the node with
//returning the new node
//variable next is initialized to NULL 
/* int main (void)
{
	t_list *list;

	list = NULL;

	list = add_link("aaaa\n");
	list = add_link("bbbb\n");
	list = add_link("cccc\n");

	print_list(list);
	return (0);
} */
