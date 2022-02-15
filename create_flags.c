/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:46:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/15 15:19:16 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*create_flags(void)
{
	t_flags	*flags;

	flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (flags == NULL)
		return (NULL);
	flags->left_adjust;
	flags->min_field_w;
	flags->separ_w_prec;
	flags->precision;
	flags->min_value;
	flags->short_long;
	return (flags);
}
