/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:25:14 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/30 12:57:09 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;
	t_list	*temp_2;

	temp = *alst;
	while (temp->next != NULL)
	{
		temp = *alst;
		temp_2 = temp->next;
		del(temp->content, ft_strlen(temp->content));
		free(temp);
		*alst = temp_2;
	}
}
