/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:41:25 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/22 22:20:02 by tburakow         ###   ########.fr       */
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

void	signed_int(va_list *arg, t_flags **flags);
void 	unsigned_octal(va_list *arg, t_flags **flags);
void 	unsigned_dec(va_list *arg, t_flags **flags);
void 	unsigned_hex(va_list *arg, t_flags **flags);
void 	unsigned_hex_cap(va_list *arg, t_flags **flags);
void 	float_dec_point(va_list *arg, t_flags **flags);
void	character(va_list *arg, t_flags **flags);
void 	string(va_list *arg, t_flags **flags);
void	pointer(va_list *arg, t_flags **flags);
void 	percent(t_flags **flags);
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
int		octal_conversion(unsigned d);
char	*hex_conversion(unsigned d);
unsigned	convert_length(unsigned d);
char    *hex_cap_conversion(unsigned d);
char	*ptr_conversion(unsigned long d);
typedef void t_apply_format(va_list *arg, t_flags **flags);

#endif
