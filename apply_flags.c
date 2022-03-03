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
** Applies the zero -flag
*/
char	*apply_zero(char *input, t_flags **flags)
{
	size_t	leftover;
	char	*extra;

	extra = NULL;
	leftover = (*flags)->width - ft_strlen(input);
	if ((*flags)->precision == 0)
	{
		if ((*flags)->width == 0)
			input = 0;
		else
		{
			extra = ft_strnew(leftover);
			extra = (char *)ft_memset(extra, '0', leftover);
			input = ft_strjoin(extra, input);
			free(extra);
		}
	}
	return (input);
}
/*
** checks which *flags to apply and applies them (PARANTELE!)
*/
char	*apply_flags(char *post_format, t_flags **flags)
{
/* 	if ((*flags)->l != 0)
		post_format = ft_strjoin(post_format, "helou");
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
		post_format = post_format * 9; */
	if ((*flags)->zero != 0)
		post_format = apply_zero(post_format, flags);
	return (post_format);
}
