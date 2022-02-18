/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:41:25 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/18 13:49:18 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h> //Muista POISTAA TÄÄ!

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
	char			type;
}	t_flags;

void	signed_int(char *x, t_flags **flags);
void 	signed_octal(char *x, t_flags **flags);
void 	unsigned_dec(char *x, t_flags **flags);
void 	unsigned_hex(char *x, t_flags **flags);
void 	unsigned_hex_cap(char *x, t_flags **flags);
void 	float_dec_point(char *x, t_flags **flags);
void	character(char *x, t_flags **flags);
void 	string(char *x, t_flags **flags);
void	pointer(char *x, t_flags **flags);
void 	percent(char *x, t_flags **flags);
int		ft_printf(const char *format, ...);
int		ft_raise_flags(char *str, int j, t_flags **flags);
int		set_width(char *str, int j, t_flags **flags);
int		set_precision(char *str, int j, t_flags **flags);
int		check_for_char(char c, char *str);
void	reset_flags(t_flags **flags);
int		apply_flags_numeric(int post_format, t_flags **flags);
char 	*apply_flags(char *post_format, t_flags **flags);
void	print_out_numeric(int output);
void 	print_out(char *output);
int		create_flags(t_flags **flags);

typedef void t_apply_format(char *str, t_flags **flags);

#endif
