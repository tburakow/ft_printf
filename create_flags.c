/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:46:16 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/04 15:23:25 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	create_flags(t_flags **flags)
{
	*flags = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (*flags == NULL)
		return (0);
	(*flags)->l = 0;
	(*flags)->h = 0;
	(*flags)->L = 0;
	(*flags)->zero = 0;
	(*flags)->hash = 0;
	(*flags)->minus = 0;
	(*flags)->plus = 0;
	(*flags)->width = 0;
	(*flags)->precision = 0;
	(*flags)->type = 0;
	(*flags)->neg = 0;
	(*flags)->empty_prec = 0;
	return (1);
}
