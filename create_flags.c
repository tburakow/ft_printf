/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:46:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/16 17:51:12 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*create_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->l;
	flags->ll;
	flags->h;
	flags->hh;
	flags->L;
	flags->zero;
	flags->hash;
	flags->minus;
	flags->plus;
	flags->width;
	flags->precision;
	
	return (flags);
}
