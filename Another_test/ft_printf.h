/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:41:25 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/22 10:41:03 by tburakow         ###   ########.fr       */
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
	unsigned int	h;
	unsigned int	bigl;
	unsigned int	zero;
	unsigned int	hash;
	unsigned int	minus;
	unsigned int	plus;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	space;
	char			type;
	unsigned int	neg;
	unsigned int	empty_prec;
	unsigned int	base_size;
	long long		output;
	int				char_null;
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
void	apply_flags(char *post_format, t_flags **flags);
void	print_out_numeric(int output);
void 	print_out(char *output, t_flags **flags);
int		create_flags(t_flags **flags);
unsigned long long octal_conversion(unsigned long long d);
char	*hex_conversion(long long d, t_flags **flags);
unsigned	convert_length(long long d);
char    *hex_cap_conversion(long long d, t_flags **flags);
char	*ptr_conversion(long long d, t_flags **flags);
char	*apply_zero(char *input, t_flags **flags);
char	*apply_minus(char *input, t_flags **flags);
char	*apply_hash(char *input, t_flags **flags);
char	*apply_width(char *input, t_flags **flags);
char	*apply_space(char *input, t_flags **flags);
char	*apply_neg(char *input, t_flags **flags);
char	*apply_plus(char *input, t_flags **flags);
char	*apply_precision(char *input, t_flags **flags);
typedef void t_formats(va_list *arg, t_flags **flags);
char    *to_ascii(long double number, t_flags **flags);
char    *add_fractions(char *temp, long double mant, t_flags **flags);
long double bankers_round(long double number, t_flags **flags);
void	special_putchar(char c, t_flags **flags);
char	*strsub_with_free(char *s, unsigned int start, size_t len);
char	*strjoin_with_free(char *s1, char *s2);

#endif
