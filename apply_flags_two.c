/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags_two.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:10:20 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/19 19:18:39 by tburakow         ###   ########.fr       */
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
		input = ft_strsub(input, 0, (*flags)->precision);
		return (input);
	}
	if (check_for_char((*flags)->type, "diouxX") == 1 && extra != NULL)
	{
		input = ft_strjoin(extra, input);
		ft_strdel(&extra);
	}
	return (input);
}

/*
** Applis the "plus" -flag.
*/
char	*apply_plus(char *input, t_flags **flags)
{
	char	*extra;
	int		i;

	i = 0;
	extra = ft_strnew(1);
	extra = (char *)ft_memset(extra, '+', 1);
	if (input[0] == '0' && (*flags)->precision == 0 && input[1] != '\0')
	{
		input[0] = '+';
	}
	else if (input[0] == ' ')
	{
		while (input[i] == ' ')
			i++;
		input[i - 1] = '+';
	}
	else
	{
		input = ft_strjoin(extra, input);
		ft_strdel(&extra);
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
		input = ft_strjoin(extra, input);
		ft_strdel(&extra);
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
		if ((*flags)->neg == 0)
		{
			if (input[0] == '0' || input[0] == ' ')
			{
				input[0] = ' ';
			}
			else
			{
				input = ft_strjoin(extra, input);
				ft_strdel(&extra);
			}
		}
	}
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
		input = ft_strjoin(extra, input);
	ft_strdel(&extra);
	return (input);
}
