/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:12:17 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/22 11:26:03 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int 	nbr;
	char 	*str;
	int		i;
	t_flags	*flags;

	nbr = 100;
	i = create_flags(&flags);
	str = hex_conversion(nbr, &flags);
	printf("\n%s\n", str);
	free(flags);
	free(str);
	while(1);
}