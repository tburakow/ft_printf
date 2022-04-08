/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:45:03 by tburakow          #+#    #+#             */
/*   Updated: 2022/04/08 14:03:46 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Applies the hash -flag
*/
char	*apply_hash(char *input, t_flags **flags)
{
	char	*add;

	add = NULL;
	(*flags)->hash = 0;
	if ((*flags)->type == 'o' && input[0] != '0')
	{
		add = ft_strnew(1);
		add = ft_strcpy(add, "0");
		input = strjoin_with_free(add, input);
	}
	if ((*flags)->type == 'x')
	{
		add = ft_strnew(2);
		add = ft_strcpy(add, "0x");
		input = strjoin_with_free(add, input);
	}
	if ((*flags)->type == 'X')
	{
		add = ft_strnew(2);
		add = ft_strcpy(add, "0X");
		input = strjoin_with_free(add, input);
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

	if ((*flags)->hash != 0)
		input = apply_hash(input, flags);
	leftover = (*flags)->width - ft_strlen(input);
	if ((*flags)->space == 1)
		leftover--;
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
		input = strjoin_with_free(input, extra);
	(*flags)->zero = 0;
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
	leftover = (*flags)->width - ft_strlen(input) - (*flags)->hash;
	if ((*flags)->precision != 0 && (*flags)->type != 'f')
		return (apply_width(input, flags));
	else if ((*flags)->minus == 0)
	{
		if ((*flags)->width != 0 && leftover > 0)
		{	
			extra = ft_strnew(leftover);
			extra = (char *)ft_memset(extra, '0', leftover);
			if ((*flags)->space == 1)
			{
				extra[0] = ' ';
				(*flags)->space = 0;
			}
			if ((*flags)->hash != 0)
				extra = apply_hash(extra, flags);
			input = strjoin_with_free(extra, input);
		}
	}
	(*flags)->width = 0;
	return (input);
}

/*
** Applies the "plus" -flag.
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
		(*flags)->min_chars--;
	}
	else if (input[0] == ' ')
	{
		while (input[i] == ' ')
			i++;
		input[i - 1] = '+';
		(*flags)->min_chars--;
	}
	else
	{
		input = strjoin_with_free(extra, input);
		(*flags)->min_chars--;
	}
	return (input);
}

/*
** checks which *flags to apply and applies them (PARANTELE!)
*/
void	apply_flags(char *from_format, t_flags **flags)
{
	char	*post_format;

	post_format = ft_strnew(ft_strlen(from_format));
	post_format = ft_strcpy(post_format, from_format);
	if ((*flags)->empty_prec != 0 && check_for_char((*flags)->type, "pc%") == 0)
	{
		if ((*flags)->hash == 0 || ((*flags)->type == 'o' \
		&& (*flags)->hash == 1))
		{
			ft_strdel(&post_format);
			post_format = ft_strnew(0);
		}
	}
	if ((*flags)->precision != 0 && (*flags)->empty_prec == 0)
		post_format = apply_precision(post_format, flags);
	if ((*flags)->hash != 0 && (*flags)->zero == 0)
		post_format = apply_hash(post_format, flags);
	if ((*flags)->minus != 0)
		post_format = apply_minus(post_format, flags);
	if ((*flags)->zero != 0 && (*flags)->f_check == 0)
		post_format = apply_zero(post_format, flags);
	apply_flags_two(post_format, flags);
}
