/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:45:51 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/09 15:24:56 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "testhead.h"

int add(int first, int second)
{
	return (first + second);
}

int sub(int first, int second)
{
	return (first - second);
}

int mult(int first, int second)
{
	return (first * second);
}

int divide(int first, int second)
{
	return (first / second);
}

int	main(void)
{
	int first, second, choice, result;

	first = 2;
	second = 3;
	choice = 1;

	math_function *my_array[4] =
	{
		add,
		sub,
		mult,
		divide
	};

	result = my_array[choice](first, second);
	
	printf("result is %d\n", result);

	printf("elvis%d\n%d\n", 12, 12);

	return (0);
}