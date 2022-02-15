/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:41:25 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/15 14:38:39 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	unsigned int	left_adjust;
	unsigned int	min_field_w;
	unsigned int	separ_w_prec;
	unsigned int	precision;
	unsigned int	min_value;
	unsigned int	short_long;
}	t_flags;

char	*signed_int(char *x);
char	*unsigned_int(char *x);
char	*unsigned_octal(char *x);
char	*unsigned_hex(char *x);
char	*float_point(char *x);
char	*float_decim(char *x);
char	*float_e_or_f(char *x);
char	*percent(char *x);
char	*character(char *x);
char	*string(char *x);
int		ft_printf(const char *format, ...);
t_flags	*create_flags(void);

typedef int	t_apply_format(char *str);

#endif