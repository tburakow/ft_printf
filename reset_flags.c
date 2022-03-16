/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:04:27 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/16 15:38:43 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Resets the flags to zero between arguments.
*/
void reset_flags(t_flags *(*flags))
{
    (*flags)->l = 0;
	(*flags)->h = 0;
	(*flags)->bigl = 0;
	(*flags)->zero = 0;
	(*flags)->hash = 0;
	(*flags)->minus = 0;
	(*flags)->plus = 0;
	(*flags)->width = 0;
	(*flags)->precision = 0;
	(*flags)->space = 0;
	(*flags)->type = 0;
	(*flags)->neg = 0;
	(*flags)->base_size = 8;
	(*flags)->char_null = 0;
}