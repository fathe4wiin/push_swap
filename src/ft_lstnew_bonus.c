/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_node_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:14:35 by bfathi            #+#    #+#             */
/*   Updated: 2025/10/20 21:14:36 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_node(void *content)
{
	t_list	*new_node_node;

	new_node_node = malloc(sizeof(t_list));
	if (!new_node_node)
		return (NULL);
	new_node_node->content = content;
	new_node_node->next = NULL;
	return (new_node_node);
}
