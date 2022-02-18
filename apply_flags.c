/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_(*flags).c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:06:30 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/18 13:32:12 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** checks which *flags to apply and applies them (PARANTELE!)
*/
int apply_flags_numeric(int post_format, t_flags **flags)
{
	if ((*flags)->l != 0)
		post_format = post_format * 1;
	if ((*flags)->ll != 0)
		post_format = post_format * 2;
	if ((*flags)->h != 0)
		post_format = post_format * 3;
	if ((*flags)->hh != 0)
		post_format = post_format * 4;
	if ((*flags)->L != 0)
		post_format = post_format * 5;
	if ((*flags)->space != 0)
		post_format = post_format * 6;
	if ((*flags)->plus != 0)
		post_format = post_format * 7;
	if ((*flags)->minus != 0)
		post_format = post_format * 8;
	if ((*flags)->hash != 0)
		post_format = post_format * 9;
	if ((*flags)->zero != 0)
		post_format = post_format * 10;
	return (post_format);
}

char *apply_flags(char *post_format, t_flags **flags)
{
	if ((*flags)->l != 0)
		post_format = "(*flags) l";
	if ((*flags)->ll != 0)
		post_format = "(*flags) ll";
	if ((*flags)->h != 0)
		post_format = "(*flags) h";
	if ((*flags)->hh != 0)
		post_format = "(*flags) hh";
	if ((*flags)->L != 0)
		post_format = "(*flags) L";
	if ((*flags)->space != 0)
		post_format = "(*flags) space";
	if ((*flags)->plus != 0)
		post_format = "(*flags) plus";
	if ((*flags)->minus != 0)
		post_format = "(*flags) minus";
	if ((*flags)->hash != 0)
		post_format = "(*flags) hash";
	if ((*flags)->zero != 0)
		post_format = "(*flags) zero";
	return (post_format);
}
