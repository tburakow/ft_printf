/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:46:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/16 19:22:16 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*create_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->l = 0;
	flags->ll = 0;
	flags->h = 0;
	flags->hh = 0;
	flags->L = 0;
	flags->zero = 0;
	flags->hash = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->precision = 0;
	
	return (flags);
}
