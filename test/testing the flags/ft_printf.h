/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:41:25 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/17 12:17:44 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	unsigned int	l;
	unsigned int	ll;
	unsigned int	h;
	unsigned int	hh;
	unsigned int	L;
	unsigned int	zero;
	unsigned int	hash;
	unsigned int	minus;
	unsigned int	plus;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	space;
}	t_flags;

char 	*signed_int(char *x);
char 	*signed_octal(char *x);
char 	*unsigned_dec(char *x);
char 	*unsigned_hex(char *x);
char 	*unsigned_hex_cap(char *x);
char 	*float_dec_point(char *x);
char 	*character(char *x);
char 	*string(char *x);
char 	*pointer(char *x);
char 	*percent(char *x);
int		ft_printf(const char *format, ...);
int		ft_raise_flags(char *str, int j, t_flags *flags);
int		set_width(char *str, int j, t_flags *flags);
int		set_precision(char *str, int j, t_flags *flags);
int		check_for_char(char c, char *str);
t_flags	*create_flags(void);

typedef int	t_apply_format(char *str);

#endif
