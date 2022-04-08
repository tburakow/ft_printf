/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:10:20 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/08 14:05:08 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Applies the "precision" -flag.
*/
char	*apply_precision(char *input, t_flags **flags)
{
	char		*extra;
	long long	len;

	extra = NULL;
	len = (*flags)->precision - ft_strlen(input);
	if (len > 0)
	{
		extra = ft_strnew(len);
		extra = (char *)ft_memset(extra, '0', len);
	}
	else if (len < 0 && (*flags)->type == 's')
	{
		input = strsub_with_free(input, 0, (*flags)->precision);
		return (input);
	}
	if (check_for_char((*flags)->type, "diouxX") == 1 && extra != NULL)
	{
		input = strjoin_with_free(extra, input);
	}
	return (input);
}

/*
** Applies the "neg" -flag. 
*/
char	*apply_neg(char *input, t_flags **flags)
{
	char	*extra;
	int		i;

	i = 0;
	extra = ft_strnew(1);
	extra = (char *)ft_memset(extra, '-', 1);
	if (input[0] == '0' && ft_strlen(input) >= (*flags)->width && \
	(*flags)->precision == 0)
		input[0] = '-';
	else if (input[0] == ' ')
	{
		while (input[i] == ' ')
			i++;
		input[i - 1] = '-';
	}
	else
	{
		input = strjoin_with_free(extra, input);
	}
	return (input);
}

/*
** Applies the space -flag. It's only applied to 
** the following formats, d,i, and f
*/
char	*apply_space(char *input, t_flags **flags)
{
	char	*extra;

	extra = ft_strnew(1);
	extra = (char *)ft_memset(extra, ' ', 1);
	if ((*flags)->plus == 0)
	{
		if ((*flags)->neg == 0 && input[0] != ' ')
			input = strjoin_with_free(extra, input);
	}
	(*flags)->width--;
	return (input);
}

/*
** Applies the width -flag in case it has not been applied within other flag-
** handling functions.
*/
char	*apply_width(char *input, t_flags **flags)
{
	long long	leftover;
	char		*extra;

	if ((*flags)->hash != 0)
		input = apply_hash(input, flags);
	leftover = (*flags)->width - ft_strlen(input) - (*flags)->char_null;
	if (leftover > 0)
	{
		extra = ft_strnew(leftover);
		extra = (char *)ft_memset(extra, ' ', leftover);
	}
	else
		extra = NULL;
	if (extra != NULL)
		input = strjoin_with_free(extra, input);
	return (input);
}

void	apply_flags_two(char *post_format, t_flags **flags)
{
	if ((*flags)->zero == 0 && (*flags)->width != 0 && (*flags)->minus == 0)
		post_format = apply_width(post_format, flags);
	if ((*flags)->space != 0 && check_for_char((*flags)->type, "dif") == 1)
		post_format = apply_space(post_format, flags);
	if ((*flags)->neg != 0)
		post_format = apply_neg(post_format, flags);
	if ((*flags)->plus != 0 && (*flags)->neg == 0 && (*flags)->type != 'u')
		post_format = apply_plus(post_format, flags);
	if ((*flags)->hash != 0 && (*flags)->zero == 1)
		post_format = apply_hash(post_format, flags);
	print_out(post_format, flags);
	ft_strdel(&post_format);
}
