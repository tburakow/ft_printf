/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:39:29 by tburakow          #+#    #+#             */
/*   Updated: 2022/02/18 23:14:59 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char	*z;
	int	x;
	int	y;
	int	ret;

	z = "Elvis";
	x = 6;
	y = 9;
	ret = 0;
	ret = ft_printf("elvis\n%i\n%x\n%X\n%%\n%p", 67, 120456, 120456, &z);
	if (ret > 0)
		return (1);
	return (0);
}
