/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:46:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/10 13:00:38 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testhead.h"

t_flags *create_flags()
{
	t_flags	*flags;
	
	flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->test = 'A';
	return (flags);
}
