/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:39:29 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/15 12:19:59 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testhead.h"

int	main(void)
{
	int	z;
	int	x;
	int	y;
	int	ret;

	z = 5;
	x = 6;
	y = 9;
	ret = 0;
	ret = ft_printf("elvis%a%b%c", z, x, y);
	if (ret > 0)
		return (1);
	return (0);
}
