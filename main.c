/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:39:29 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/04 11:38:53 by tburakow         ###   ########.fr       */
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
	//ret = ft_printf("elvis\n%i\n%x\n%X\n%%\n%p\n\n", 67, 120456, 120456, NULL);
	//printf("\n");
	//printf("elvis\n%i\n%x\n%X\n%%\n%p\n", 67, 120456, 120456, NULL);
	ret = ft_printf("\nMe: X% iX\n\n", -25);
	printf("It: X% iX\n", -25);
	printf("It: X% iX\n", -25);
	if (ret > 0)
		return (1);
	return (0);
}
// for integer # -flag doesn't work.