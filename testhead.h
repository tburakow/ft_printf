/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testhead.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:41:25 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/10 12:55:15 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTHEAD_H
# define TESTHEAD_H
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	char	test;
}	t_flags;

int 	add(int first, int second);
int 	sub(int first, int second);
int		mult(int first, int second);
int		divide(int first, int second);
int		ft_printf(const char *restrict format, ...);
t_flags *create_flags();

typedef int math_function(int first, int second);

#endif