/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:39:29 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/19 11:11:19 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*z;
	char	**c;
	int	x;
	int	y;
	int	ret;

	z = "Elvis";
	c = &z;
	x = 6;
	y = 9;
	ret = 0;
	ret = ft_printf("elvis\n%i\n%x\n%X\n%%\n%p", 67, 120456, 120456, &c);
	if (ret > 0)
		return (1);
	return (0);
}
