/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:07:47 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/09 16:28:36 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testhead.h"
#include <stdio.h>

int	func(int argc, ...)
{
	va_list arg;
	int a;
	int b;
	int c;
	
	va_start(arg, argc);
	a = va_arg(arg, int);
	b = va_arg(arg, int);
	c = va_arg(arg, int);
	va_end(arg);
	
	return (a + b + c - argc);
}

int main(void)
{
	int i;

	i = func(11, 3, 4, 5);
	printf("\n%d\n\n", i);
}
