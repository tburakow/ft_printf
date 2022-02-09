/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testhead.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:41:25 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/09 16:27:47 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTHEAD_H
# define TESTHEAD_H
# include <stdarg.h>

int add(int first, int second);
int sub(int first, int second);
int multi(int first, int second);
int divide(int first, int second);

typedef int math_function(int first, int second);

#endif