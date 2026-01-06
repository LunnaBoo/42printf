/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccribe <luccribe@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:20:42 by luccribe          #+#    #+#             */
/*   Updated: 2025/11/01 22:35:05 by luccribe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_node;

	current_node = *lst;
	while (current_node)
	{
		current_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = current_node;
	}
}
