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
** Applis the "precision" -flag.
*/
char	*apply_precision(char *input, t_flags **flags)
{
	char		*extra;
	long long	len;

	len = (*flags)->precision - ft_strlen(input);
	if (len > 0)
	{
		extra = ft_strnew(len);
		extra = (char *)ft_memset(extra, '0', len);
	}
	else
		extra = NULL;
	if (check_for_char((*flags)->type, "diouxX") == 1)
	{
		if (extra != NULL)
		{
			input = ft_strjoin(extra, input);
			free(extra);
		}
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
	if (input[0] == '0' && (*flags)->precision == 0)
	{
		input[0] = '+';
	}
	else if (input[0] == ' ')
	{
		while(input[i] == ' ')
			i++;
		input[i - 1] = '+';
	}
	else
	{
		input = ft_strjoin(extra, input);
		free(extra);
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
	if (input[0] == '0' && (*flags)->precision == 0)
	{
		input[0] = '-';
	}
	else if (input[0] == ' ')
	{
		while(input[i] == ' ')
			i++;
		input[i - 1] = '-';
	}
	else
	{
		input = ft_strjoin(extra, input);
		free(extra);
	}
	return (input);
}

/*
** Applies the space -flag. It's only applied to the following formats, d,i, and f
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
				free(extra);
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

	leftover = (*flags)->width - ft_strlen(input);
	if (leftover > 0)
	{
		extra = ft_strnew(leftover);
		extra = (char *)ft_memset(extra, ' ', leftover);
	}
	else
		extra = NULL;
	if (extra != NULL)
		input = ft_strjoin(extra, input);
	free(extra);
	return (input);
}

/*
** Applies the hash -flag
*/
char	*apply_hash(char *input, t_flags **flags)
{
	if ((*flags)->type == 'o')
	{
		input = ft_strjoin("0", input);
	}
	if ((*flags)->type == 'x')
	{
		input = ft_strjoin("0x", input);
	}
	if ((*flags)->type == 'X')
	{
		input = ft_strjoin("0X", input);
	}
	return (input);
}

/*
** Applies the minus flag
*/
char	*apply_minus(char *input, t_flags **flags)
{
	long long	leftover;
	char		*extra;

	leftover = (*flags)->width - ft_strlen(input);
	if ((*flags)->plus == 1 || (*flags)->neg == 1)
		leftover--;
	if (leftover > 0)
	{
		extra = ft_strnew(leftover);
		extra = (char *)ft_memset(extra, ' ', leftover);
	}
	else
		extra = NULL;
	if (extra != NULL)
		input = ft_strjoin(input, extra);
	free(extra);
	return (input);
}

/*
** Applies the zero -flag
*/
char	*apply_zero(char *input, t_flags **flags)
{
	long long	leftover;
	char		*extra;

	extra = NULL;
	leftover = (*flags)->width - ft_strlen(input);
	if ((*flags)->minus == 0)
	{
		if ((*flags)->width != 0)
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
/*	if ((*flags)->l != 0)
 		post_format = ft_strjoin(post_format, "helou");
	if ((*flags)->ll != 0)
		post_format = post_format * 2;
	if ((*flags)->h != 0)
		post_format = post_format * 3;
	if ((*flags)->hh != 0)
		post_format = post_format * 4;
	if ((*flags)->L != 0)
		post_format = post_format * 5;*/ 
	if ((*flags)->hash != 0)
		post_format = apply_hash(post_format, flags);
	if ((*flags)->precision != 0)
		post_format = apply_precision(post_format, flags);
	if ((*flags)->minus != 0)
		post_format = apply_minus(post_format, flags);
	if ((*flags)->zero != 0)
		post_format = apply_zero(post_format, flags);
	if ((*flags)->zero == 0 && (*flags)->width != 0 && (*flags)->minus == 0)
		post_format = apply_width(post_format, flags);
	if ((*flags)->space != 0 && check_for_char((*flags)->type, "dif") == 1)
		post_format = apply_space(post_format, flags);
	if ((*flags)->neg != 0)
		post_format = apply_neg(post_format, flags);
	if ((*flags)->plus != 0 && (*flags)->neg == 0)
		post_format = apply_plus(post_format, flags);
	return (post_format);
}
